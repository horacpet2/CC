#!/bin/sh

#check dependency


# compile source
MAIN="./src/main.c"
LEXICAL_ANALYZER="./src/module_tree/lexical_analyzer/lexical_analyzer.c"
ASSEMBLER="./src/module_tree/assembler/assembler.c"
LINKER="./src/module_tree/linker/linker.c"
PREPROCESOR="./src/module_tree/preprocesor/preprocesor.c"
SEMANTIC_ANALYZER="./src/module_tree/semantic_analyzer/semantic_analyzer.c"
SYNTAX_ANALYZER="./src/module_tree/syntax_analyzer/syntax_analyzer.c"
CORE="./src/module_tree/core.c"


gcc -o CC $MAIN $LEXICAL_ANALYZER $ASSEMBLER $LINKER $PREPROCESOR $SEMANTIC_ANALYZER $SYNTAX_ANALYZER $CORE  


#instal to system
