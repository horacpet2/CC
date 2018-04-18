/*
 ** CC is simple compliler for CC programming language
 ** 
 ** The entire compiler consists of several parts, whitch each other communicate:
 ** - Communication interface
 ** - Preprocesor
 ** - Lexical analyzer
 */ 




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
 **
 ** Communication interface layer function and datastructure declaration
 ** 
 */ 

struct _com_interface_ com_interface
{

};

typedef struct _com_interface_ com_interface;

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
 */ 

struct _core_
{
	com_interface* communication;


	uint8_t core_state;
};
typedef struct _core_ core; 

enum _output_status_
{
	status_success = 0,

	status_unknown_error = 255
}
	
/* Core layer function declaration */ 

/*
 * function: core_new - constructor for core class
 * return: core* - pointer to new core class object
 */ 
core* core_new();





void ci_print_help();


/*
 **
 ** Preprocesor layer
 ** 
 */




int main(int argv, char** argc)
{
	core* core_instance = core_new();
	

	return core_instance->core_state;
}


/* Core layer function definition */

/*
 **
 ** Core new 
 **
 */ 
core* core_new()
{
	core* this = (core*) malloc(sizeof(core));
	
	this->core_state = out_val_success;
	return this;
}

