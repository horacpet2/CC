/*
** CC is simple compliler for CC programming language
**
** The entire compiler consists of several parts, whitch each other communicate:
** - Core layer
** - Preprocesor
** - DI framework
** - Lexical analyzer
**
**
** Author: Petr Horacek
** File: main.c
** Created: 13.04.2018
** Last update: 20.04.2018
** Version: 0.2.1
**
** 
*/ 




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>




/*
**
** Constants values
**
*/ 

enum _core_state_
{
	state_ok = 0,
	state_exit_success,
	state_in_param_error,
	state_no_input_file,

	state_unknown_error = 255
};


/*
**
** Utiliti code
**
*/ 

struct _node_;
typedef struct _node_ node;

struct _node_
{
	void* data;
	node* left;
	node* right;
};

/*
 * function: constructor for node class
 * return: node* - pointer to new node class object
 */ 
node* node_new();



struct _linked_list_
{
	node* root;
	node* last;
	node* c_node;
	uint16_t size;
};
typedef struct _linked_list_ linked_list;

/*
 * function: linked_list_new - constructor for linked_list class
 * return: linked_list* - pointer to new linked_list class object
 */ 
linked_list* linked_list_new();
	
/*
 * function: linked_list_add - add new data into linked list structure
 * param: linked_list* this - pointer to linked_list class object
 * param: void* data - data saved into linked_list node
 */ 
void linked_list_add(linked_list* this, void* data);

/*
 * function: linked_list_get_next - return data from next node in order in linked list
 * param: linked_list* this - pointer to linked_list class object
 * return: void* - pointer to data from next linked_list node
 */ 
void* linked_list_get_next(linked_list* this);

/*
 * function: linked_list_get_pre - return data from previous node in order in linked list
 * param: linked_list* this - pointer to linked_list class object
 * return: void* - pointer to data from previous linked_list node
 */ 
void* linked_list_get_pre(linked_list* this);	

/*
**
** Core of the compiler
**
** Core contains all parts (layers) of the the compiler and its internal state and 
** settings given from command line parameters. 
** 
** Compiler communicates with user via communication interface layer, which parse 
** input commands. Every state changes ocures printing some label to output. 
** 
** 
** When is run the compilation, then is created number of paralel thread, how many 
** files was given on the input. Every thread processing one file and on the end 
** are every processed source codes split in one source.
**
**
** uint8_t core_state - internal state of compiler core with code definition in enum _core_state_
** linked_list* file_list - linked list contains list of input files for compilation
** linked_list* path_list - linked list contains list of path with external sources
** char* o_file_name - string with output file name, default value is "out"
** bool quiet_mode - specifies quiet mode of compilation, no output messages from compiler
** bool s_break - output of compilation is source code in assembler form
** bool p_break - output of compilation is preprocessed source code 
** bool print_code_info - analyze source code and print information about project
** char* error_log - string with length 255 character for store error message
**
*/ 

struct _core_
{
	uint8_t core_state;
	linked_list* file_list;
	linked_list* path_list;
	char* o_file_name;
	bool quiet_mode;
	bool s_break;
	bool p_break;
	bool print_code_info;
	char* error_log;
};
typedef struct _core_ core; 

	
/* Core layer function declaration */ 

/*
 * function: core_new - constructor for core class
 * return: core* - pointer to new core class object
 */ 
core* core_new();

/*
 * function: core_parse_opt - function for pasing input commandline parameters and set the core state
 * param: core* this - pointer to core class object
 * param: int argv - number of input commandline parameters
 * param: char** argc - list of input commandline parameters
 */ 
void core_parse_opt(core* this, int argv, char** argc); 

/*
 * function: core_clean_up - clean the core before program exit
 * param: core* this - pointer to core class object
 */ 
void core_clean_up(core* this);

/*
 * function: core_print_help - rutine for help message printing
 */ 
void core_print_help();



/*
**
** Preprocesor layer, contains all functions for preprocessing of source codes.
** 
** states of preprocessing:
** - 0 - reading
** - 1 - ignoring source code and waiting to (end) or (else) preprocesor command
** 
** Commands for preprocesor:
** - (conc condition) - condition compilation, switch off reading of source code if the 
**   condition is false and sets internal state of preprocessing to 1
** - (else) - if the internal state of preprocessing is set to 1, then the state is set 
**   to 0 and readinch of source code is switched on, it the state is 0 then the state is switched to 1
** - (endif) - set the state of preprocessing to 0
** - (defined macro) - check if the macro is defined, if defined return true else return false
** - (* comment *) - comments in source code, ignored text
** - (macro id [param_1, param_2, ... param_n] "body of macro") - define the macro with name of id, all text 
**   in body of macro section is 
**   inserted to points of call
** - (undef name) - undefine (remove) the given macro
** - (include path/file) - include text from the given file into the source code
** - (mark) - return 128-bit pseudorandom value, used for jump identificatiors and other purposes
** Preprocesor also removing all aditional white spaces: space keys, tabulators
**
** All macros commands should be used in macro definitions
*/


/* Core layer function definition */

core* core_new()
{
	core* this = (core*) malloc(sizeof(core));
	
	this->core_state = state_no_input_file;
	this->file_list = linked_list_new();
	this->path_list = linked_list_new();
	this->o_file_name = "out";
	this->error_log = (char*) malloc(sizeof(char)*255);

	return this;
}

/*
**
** Parse input parameters and set the state of core layer for the folowing compilation process
**
** Function sets the value of core_state variable and it specifies what action will folow
** After parameters parse must be the core_state set on status_ok, every other values ocures
** termination of compilation process.
**
** Options should be given inside one string, for example: cc -qst 4
**
** In input string command line parameter is tested firest character. If the firest character is '-' then 
** the input parameter is some compilation settings in otherwise it is interpreted as input file name.
** String with compilation settings is tested character by character in the loop, the settings interpretation
** is faster and more dynamic then simple testing with standard strcpy or getopt function.
**
** Input settings and parameters:
** -i [path] = input path to included sourcecode and libraries
** -h = prints help for commandline input parameters interface
** -q = quiet mode, no output messages
** -o [name] = output file name, default output file name is set to out
** -s = break compilation process before assembly translation and save as the assembler source code 
** -p = break compilation process before lexical analyzation and save as the preprocesed source code
** -a = code analyze, return source code info (number of files, number of logical and fyzical lines of code)
** every other parameters are file names from work directory
**
*/ 

void core_parse_opt(core* this, int argv, char** argc)
{
	if(argv > 1)
	{
		int index = 1;
		while(index < argv)
		{
			if(*argc[index] == '-')
			{
				argc[index]++;

				while(*argc[index] != '\0')
				{
					if(*argc[index] == 'i')
					{
						index++;
						if(index < argv)
						{
							linked_list_add(this->path_list, argc[index]);
						}
						else
						{
							this->core_state = state_in_param_error;
							return;
						}
					}
					else if(*argc[index] == 'h')
					{
						this->core_state = state_exit_success;
						return;
					}
					else if(*argc[index] == 'q')
					{
						this->quiet_mode = true;
					}
					else if(*argc[index] == 'o')
					{
						index++;
						if(index < argv)
						{
							this->o_file_name = argc[index];
						}
						else
						{
							this->core_state = state_in_param_error;
							return;
						}
					}
					else if(*argc[index] == 's')
					{
						this->s_break = true;
					}
					else if(*argc[index] == 'p')
					{
						this->p_break = true;
					}
					else if(*argc[index] == 'a')
					{
						this->print_code_info = true;
					}				
					else
					{
						this->core_state = state_in_param_error;
						sprintf(this->error_log, "Undefined option: \"%s\"", argc[index]);
						return;
					}

					argc[index]++;	
				}
			}
			else
			{
				this->core_state = state_ok;
				linked_list_add(this->file_list, argc[index]);
			}	

			index++;
		}
	}
	else
	{
		this->core_state = state_in_param_error;
	}
}

void core_print_help()
{
	printf("Help for CC:\n\n");
	printf("-i [path] - path for included file from other directory\n");
	printf("-q - quiet mode, no output messages\n");
	printf("-o [name] - output file name\n");
	printf("-s - break compilation process before assembly translation and save as assembly source code\n");
	printf("-p - break compilation process before lexical analyzation and save as preprocesed source code\n");
	printf("-c - code analyze, return useful information about source code\n");
	printf("-h - print this help\n");
	printf("every other input parameters are interpreted as input file name in work directory\n");
	printf("\n\nOptions should be placed into one string, for example: cc file_1 file_2 -qst 2");
}

void core_clean_up(core* this)
{

}


/*
**
** Utilities, general alghoritms and datastructures which are not part of base C library for
** simple compilation without dependance
**
*/ 


/*
**
** Base node for several dynamic data structure - linked list, queue, binary tree
** 	data atribut is reference to saved data
**	left atribut refers to left oriented node in the order
**	right atribut refers to right oriented node in the order
**
*/ 
node* node_new()
{
	node* this = (node*) malloc(sizeof(node));

	this->data = NULL;
	this->left = NULL;
	this->right = NULL;

	return this;
}

linked_list* linked_list_new()
{
	linked_list* this = (linked_list*) malloc(sizeof(linked_list));
	
	this->root = NULL;
	this->last = NULL;
	this->size = 0;

	return this;
}

void linked_list_add(linked_list* this, void* data)
{
	node* new_node = node_new();
	new_node = data;

	if(this->root == NULL)
	{
		this->root = new_node;
	}
	else
	{
		new_node->left = this->last;
		this->last->right = new_node;	
	}

	this->last = new_node;
	this->c_node = new_node;
	this->size++;
}

void* linked_list_get_next(linked_list* this)
{
	if(this->c_node != NULL)
	{
		if(this->c_node->right != NULL)
		{
			node* t_node = this->c_node;
			this->c_node = this->c_node->right;
			return t_node->data;
		}
	}

	return NULL;
}

void* linked_list_get_pre(linked_list* this)
{
	if(this->c_node != NULL)
	{
		if(this->c_node->left != NULL)
		{
			node* t_node = this->c_node;
			this->c_node = this->c_node->left;
			return t_node->data;
		}
	}

	return NULL;
}

/* Main function */

int main(int argv, char** argc)
{
	core* core_instance = core_new();
	core_parse_opt(core_instance, argv, argc);

/*
**
** Compilation
** 
*/ 
	if(core_instance->core_state == state_ok)
	{
		
	}	
	
/*
**
** Error code handling
**
*/ 
	switch(core_instance->core_state)
	{
		case state_ok:
			printf("Compilation success\n");
			break;
		case state_exit_success:
			core_print_help();
			break;
		case state_in_param_error:
			printf("%s\n", core_instance->error_log);
			break;

		case state_no_input_file:
			printf("No input file!\n");
			break;

		case state_unknown_error:
		/* common output */	
		default:
			printf("Unknown error!\n");
			core_print_help();
	}

	core_clean_up(core_instance);

	return core_instance->core_state;
}


