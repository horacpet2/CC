# CC
Clean Code programming language translator

# C�le a popis
C�lem je vytvo�it hybridn� univerz�ln� a m�ltiplatformn� programovac� jazyk kombinuj�c� prvky ji� existuj�c�ch programovac�ch jazyk� a programovac�ch paradigmat. Zam��en� programovac�ho jazyka CC je od syst�mov�ho programov�n� bl�zk� procesoru (optimalizovan� generov�n� strojov�ho k�du) ale z�rove� pro pou�it� p�i programov�n� na vy��� �rovni abstrakce.

Syntaktick� a s�mantick� pravidla v�sledn�ho programovac�ho jazyka by m�la b�t co nejjednodu��� pro snadn� a rychl� programov�n� libovoln�ho algoritmu, ale z�rove� by programovac� jazyk m�l umo��ovat rychl� a optim�ln� vyj�d�en� algoritmu ve strojov�m k�du.

Programovac� jazyk je v�zan� na p�eklada�, kter� je c�lem vytvo�it v tomto projektu.

Do p�eklada�e CC je c�lem zakomponovat preprocesor k�du, jeho� obdoba se nach�z� v jazyce C nebo C++, mo�nost tvorby prom�nn�ch, struktur a objekt� (t��d), paradigma funkcion�ln�ho programov�n�.

Samotn� p�eklada� implementuje krom� samotn� p�ekladov� funkcionality dal�� ��sti pro anal�zu k�du. Jednou z n�stroj� pro usnadn�n� v�voje je DI (dependency injection) framework, kter� umo��uje sn�ze p�ed�vat z�vislosti v rozs�hlej��ch programech, nebo sou�et logick�ch a fyzick�ch ��dk� zdrojov�ho k�du.

V ka�d� ��sti p�eklada�e je definov�n bin�rn� vyhled�vac� strom s hashovac� tabulkou ve kter� jsou ulo�eny he�e z�kladn�ch p��kaz� a p�i anal�ze zdrojov�ho k�du jsou do he�ovac� tabulky a stromu p�id�v�ny nov� hodnoty podle kter�ch je vyhled�v�no.

P�eklada� samotn� negeneruje ��dn� k�d, ale rozbaluje funkce, kter� jsou obsa�eny v z�kladn� knihovn�. D�ky tomu je mo�n� prostou v�m�nou z�kladn� knihovny nastavit p�eklada�, aby generoval program pro zcela jinou hardwarovou nebo softwarovou platformu, nebo aby generoval zdrojov� k�d v jin�m programovac�m jazyce.

P�eklada� nejprve interpretuje t�la funkc�, kter� jsou v z�kladn� knihovn� definov�na pomoc� jazyka symbolick�ch adres. Vygenerovan� zdrojov� k�d v jazyce symbolick�ch adres pak defaultn� pokra�uje do asemblerovsk�ho p�eklada�e a linkeru, ale voliteln� lze vygenerovat pouze takto p�edkompilovan� k�d.

# Popis architektury
Cel� p�eklada� se skl�d� z n�kolika vrstev:
*LINK

*ASM - p�eklada� jazyka symbolick�ch adres, jedn� se o platformn� z�vislou vrstvu, kterou je nutn� upravit pro ka�dou c�lovou platformu

*TRANS - vygeneruje k�d v jazyce symbolick�ch adres.

*PREPROC - p�edzpracuje zdrojov� k�dy

*TOOL - n�stroje, kter� manipuluj� se zdrojov�m k�dem


# Preprocesor 

Preprocesor obsahuje vestav�n� p��kazy, kter� umo��uj� po��te�n� anal�zu, filtraci a dopln�n� zdrojov�ch k�d�. Pro jednotnost rozhran� programovac�ho jazyka maj� p��kazy pro preprocesor stejn� form� jako zbytek jazyka. Mezi p��kazy pro preprocesor pat��:

* Koment��e

* P��kazy pro podm�n�n� p�eklad

* Jedno��dkov� makra

* V�ce��dkov� makra

* Vestav�n� makra

Preprocesor z�rove� umo��uje v�po�et konstantn�ch v�raz� (v�razy tvo�en� konstantami zm�m�mi v dob� p�ekladu).

Preprocesor je realizov� jako stavov� automat kdy jsou nebo nen� �ten zdroj.

Koment��e jsou definov�na pouze v�ce��dkov� pomoc� konstrukce (* koment�� *)

P��kazy pro podm�n�n� p�eklad (podm�n�n� koment��e) funguj� podobn� jako koment��e, ale vyjmut� ��sti ze zdrojov�ch k�d� se provede pouze za p�edpokladu spln�n� dan� podm�nky. Mezi p��kazy pro podm�n�n� p�eklad pat��:

(ifcon podm�nka)
	k�d
(elif podm�nka)
	k�d
(else)
	k�d
(endif)


Vestav�n� makra jsou takov� makra, kter� nelze realizovat pomoc� existuj�c�ch p��kaz� p�eklada�e, jedn� se tedy o element�rn� p��kazy:

(defined makro) - zkontroluje zda konstanta existuje

(asm programov� k�d v jazyce symbolick�ch adres)
 
V programu jsou makra vytv��ena kontrukc�:

(macro jm�no [voliteln� parametry] t�lo makra)


do m�sta vol�n� makra je nakop�rov�n cel� obsah makra kter� se nach�z� za jm�nam makra a� do v�skytu ukon�ovac� z�vorky. To umo��uje vytv��et i v�ce��dkov� makra, kter� jsou alternativou funkc�. Pokud se p��mo za jm�nem vyskytnou hranat� z�vorky jedn� se o makro s parametry, kter� lze v makru volat.









