# CC
Clean Code programming language translator

# C�le a popis
C�lem je vytvo�it hybridn� univerz�ln� a m�ltiplatformn� programovac� jazyk kombinuj�c� prvky ji� existuj�c�ch programovac�ch jazyk� a programovac�ch paradigmat. Zam��en� programovac�ho jazyka CC je od syst�mov�ho programov�n� bl�zk� procesoru (optimalizovan� generov�n� strojov�ho k�du) ale z�rove� pro pou�it� p�i programov�n� na vy��� �rovni abstrakce.

Programovac� jazyk je v�zan� na p�eklada�, kter� je c�lem vytvo�it v tomto projektu.

Do p�eklada�e CC je c�lem zakomponovat preprocesor k�du, jeho� obdoba se nach�z� v jazyce C nebo C++, mo�nost tvorby prom�nn�ch, struktur a objekt� (t��d), paradigma funkcion�ln�ho programov�n�.

Samotn� p�eklada� implementuje krom� samotn� p�ekladov� funkcionality dal�� ��sti pro anal�zu k�du. Jednou z n�stroj� pro usnadn�n� v�voje je DI (dependency injection) framework, kter� umo��uje sn�ze p�ed�vat z�vislosti v rozs�hlej��ch programech, nebo sou�et logick�ch a fyzick�ch ��dk� zdrojov�ho k�du.

# Popis architektury
Cel� p�eklada� se skl�d� z n�kolika vrstev:
*LINK
*ASM - p�eklada� jazyka symbolick�ch adres, jedn� se o platformn� z�vislou vrstvu, kterou je nutn� upravit pro ka�dou c�lovou platformu
*TRANS - vygeneruje k�d v jazyce symbolick�ch adres.
*PREPROC - p�edzpracuje zdrojov� k�dy
*TOOL - n�stroje, kter� manipuluj� se zdrojov�m k�dem



