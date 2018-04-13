# CC
Clean Code programming language translator

# Cíle a popis
Cílem je vytvoøit hybridní univerzální a mùltiplatformní programovací jazyk kombinující prvky již existujících programovacích jazykù a programovacích paradigmat. Zamìøení programovacího jazyka CC je od systémového programování blízké procesoru (optimalizované generování strojového kódu) ale zároveò pro použití pøi programování na vyšší úrovni abstrakce.

Programovací jazyk je vázaný na pøekladaè, který je cílem vytvoøit v tomto projektu.

Do pøekladaèe CC je cílem zakomponovat preprocesor kódu, jehož obdoba se nachází v jazyce C nebo C++, možnost tvorby promìnných, struktur a objektù (tøíd), paradigma funkcionálního programování.

Samotný pøekladaè implementuje kromì samotné pøekladové funkcionality další èásti pro analýzu kódu. Jednou z nástrojù pro usnadnìní vývoje je DI (dependency injection) framework, která umožòuje snáze pøedávat závislosti v rozsáhlejších programech, nebo souèet logických a fyzických øádkù zdrojového kódu.

# Popis architektury
Celý pøekladaè se skládá z nìkolika vrstev:
*LINK
*ASM - pøekladaè jazyka symbolických adres, jedná se o platformnì závislou vrstvu, kterou je nutné upravit pro každou cílovou platformu
*TRANS - vygeneruje kód v jazyce symbolických adres.
*PREPROC - pøedzpracuje zdrojové kódy
*TOOL - nástroje, které manipulují se zdrojovým kódem



