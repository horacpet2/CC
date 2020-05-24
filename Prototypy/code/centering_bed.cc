()
(defn public help_function [a b c])
(defn public function [a b c])


(defn do_centering [])
(defn do_centering_x [])
(defn do_centering_y [])


(defn initialize_centering [])


(defn is_centered [sig_vacuum, sig_glass_pressence]
	(and (eq sig_vacuum true) (eq sig_glass_pressence true)))



(defn public parse_source_code [source_code index_table]
	(if (ne souce_code null) (add (parse_function source_code)) index_table)


(*
** rozloží zdrojový kód na podřetězce, které obsahují kód jednotlivých funkcí
*)
(defn parse_souce_code_to_functions [source_code])


(defn parse_functions [function_record])

(defn parse_source_code [source_code language_keyword_trie])




(defn analyze_code [args]
	(parse_source_code (read_file (get args 2) (define_trie (list "(" ")" "defn" "import" "[" "]" "*")))

(defn make_indexing [index_table])

(defn main [args]
	(make_indexing analyze_code[args]))


(defn parse_source_code [source_code]
	(parse_functions (parse_source_code_to_functions source_code))







(defn main [args]
	(if (ge size(args) 2) (function args) 0))
