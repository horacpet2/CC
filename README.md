# CC
Clean Code programming language translator

# Cíle a popis
Cílem je vytvoøit hybridní univerzální a mùltiplatformní programovací jazyk kombinující prvky již existujících programovacích jazykù a programovacích paradigmat. Zamìøení programovacího jazyka CC je od systémového programování blízké procesoru (optimalizované generování strojového kódu) ale zároveò pro použití pøi programování na vyšší úrovni abstrakce.

Syntaktická a sémantická pravidla výsledného programovacího jazyka by mìla být co nejjednodušší pro snadné a rychlé programování libovolného algoritmu, ale zároveò by programovací jazyk mìl umožòovat rychlé a optimální vyjádøení algoritmu ve strojovém kódu.

Programovací jazyk je vázaný na pøekladaè, který je cílem vytvoøit v tomto projektu.

Do pøekladaèe CC je cílem zakomponovat preprocesor kódu, jehož obdoba se nachází v jazyce C nebo C++, možnost tvorby promìnných, struktur a objektù (tøíd), paradigma funkcionálního programování.

Samotný pøekladaè implementuje kromì samotné pøekladové funkcionality další èásti pro analýzu kódu. Jednou z nástrojù pro usnadnìní vývoje je DI (dependency injection) framework, která umožòuje snáze pøedávat závislosti v rozsáhlejších programech, nebo souèet logických a fyzických øádkù zdrojového kódu.

V každé èásti pøekladaèe je definován binární vyhledávací strom s hashovací tabulkou ve které jsou uloženy heše základních pøíkazù a pøi analýze zdrojového kódu jsou do hešovací tabulky a stromu pøidávány nové hodnoty podle kterých je vyhledáváno.

Pøekladaè samotný negeneruje žádný kód, ale rozbaluje funkce, které jsou obsaženy v základní knihovnì. Díky tomu je možné prostou výmìnou základní knihovny nastavit pøekladaè, aby generoval program pro zcela jinou hardwarovou nebo softwarovou platformu, nebo aby generoval zdrojový kód v jiném programovacím jazyce.

Pøekladaè nejprve interpretuje tìla funkcí, které jsou v základní knihovnì definována pomocí jazyka symbolických adres. Vygenerovaný zdrojový kód v jazyce symbolických adres pak defaultnì pokraèuje do asemblerovského pøekladaèe a linkeru, ale volitelnì lze vygenerovat pouze takto pøedkompilovaný kód.

# Popis architektury
Celý pøekladaè se skládá z nìkolika vrstev:
*LINK

*ASM - pøekladaè jazyka symbolických adres, jedná se o platformnì závislou vrstvu, kterou je nutné upravit pro každou cílovou platformu

*TRANS - vygeneruje kód v jazyce symbolických adres.

*PREPROC - pøedzpracuje zdrojové kódy

*TOOL - nástroje, které manipulují se zdrojovým kódem


# Preprocesor 

Preprocesor obsahuje vestavìné pøíkazy, které umožòují poèáteèní analýzu, filtraci a doplnìní zdrojových kódù. Pro jednotnost rozhraní programovacího jazyka mají pøíkazy pro preprocesor stejný formá jako zbytek jazyka. Mezi pøíkazy pro preprocesor patøí:

* Komentáøe

* Pøíkazy pro podmínìný pøeklad

* Jednoøádková makra

* Víceøádková makra

* Vestavìná makra

Preprocesor zároveò umožòuje výpoèet konstantních výrazù (výrazy tvoøené konstantami zmámími v dobì pøekladu).

Preprocesor je realizová jako stavový automat kdy jsou nebo není èten zdroj.

Komentáøe jsou definována pouze víceøádková pomocí konstrukce (* komentáø *)

Pøíkazy pro podmínìný pøeklad (podmínìné komentáøe) fungují podobnì jako komentáøe, ale vyjmutí èásti ze zdrojových kódù se provede pouze za pøedpokladu splnìní dané podmínky. Mezi pøíkazy pro podmínìný pøeklad patøí:

(ifcon podmínka)
	kód
(elif podmínka)
	kód
(else)
	kód
(endif)


Vestavìná makra jsou taková makra, která nelze realizovat pomocí existujících pøíkazù pøekladaèe, jedná se tedy o elementární pøíkazy:

(defined makro) - zkontroluje zda konstanta existuje

(asm programový kód v jazyce symbolických adres)
 
V programu jsou makra vytváøena kontrukcí:

(macro jméno [volitelné parametry] tìlo makra)


do místa volání makra je nakopírován celý obsah makra který se nachází za jménam makra až do výskytu ukonèovací závorky. To umožòuje vytváøet i víceøádková makra, které jsou alternativou funkcí. Pokud se pøímo za jménem vyskytnou hranaté závorky jedná se o makro s parametry, které lze v makru volat.









