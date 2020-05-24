
(import modul)
(import adresar.modul)



(defn fce1 
	(print "hello world"))


(defn fce2 [par1 par2]
	(if (qt par2 par2) "vetsi" "mensi"))


(if (qt a b) (fce1) (fce2))


(*
** toto je komentář 
*)

(defn fce4 [par] 
	(print par)
	(increment par))

(struct trida [int a char b	double c])


(extern defn fce4 [int a char b double c] 
	(trida prm [a, b, c]))




(defn fce5 []
 	(char ptr (ref 0x54887512354)))


(defn fce3 [par]
	(if (qt par 5) (fce4 par) true))

void print_n(int n)
{
	printf("%d\n", n);

	if(n < 5)
		print_n(n+1);
}


(defn print_n [int n]
 	(println n)

 	(if (lt n 5 
		 (printf_n (increment n)))))


(print_n 10)


(* matematicko-logické rovnice/výrazy *)

(and a b c d)
a && b && c && d

((a && b) || (c && d))
(or (and a b) (and c d))


(* součet prvních n přirozených čísel *)

(defn sum_n [int n]
 	(if (qt n 0) 
		(add n sum_n((decrement n)))))

int sum_n(int n)
{
	if(n > 0)
		return n + sum_n(n-1);
}

(* součin prvních n přirozených čísel - faktoriál *)

(defn factorial [int n]
 	(if (lt n 0) 0 (if (eq n 0) 1 (mul n (factorial (sub n 1))))))


int factorial(int n)
{
	if(n < 0)
		return 0;

	if(n == 0)
		return 1;
	else
		factorial(n - 1) * n;
}


(* Collatzův problém *)

(defn collatz [int n]
 	(if (ne n 1) (println n))

	(if (ne n 1)
		(if (eq (mod n 2) 0)
		 	(collatz (div n 2))
			(collatz (add 1 (mul n 3))))))


void collatz(int n)
{
	if(n != 1)
	{
		printf("%d\n", n);

		if((n % 2) = 0)	
			collatz(n/2); 
		else 
			collatz((n*3)+1);
	}
}

(* globální konstanty *)

(extern defn contanta [] 10)

(* volání konstanty *)
(constanta)

(* je třeba doladit typový systém a používání proměnných *)

(**************************************************************************************)


(* komentář *)

(version)

(asm kód asembleru)

(struct struktura [int a int b int c])

(int promena 0)

(int ukazatel (address promena))

(int16 var1 14343)
(int32 var2 var1)


(ref adresa)

(defn funkce [int parametr1 char parametr2] 
	(* tělo funkce *))

(extern defn funkce [int parametr1 char parametr2] 
	(* tělo funkce *))


(* proměnný počet parametrů je tvořen pomocí pole ukazatelů jako vstupní hodnoty *)

(defn funkce [list params] (* tělo funkce s proměnným počtem parametrů *))

(if condition (fce_if) (fce_else))


(import module)
(import direcotry.module)
































