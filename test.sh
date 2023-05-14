echo --------------TEST_IMPORT---------------
echo ----------------TEST_1------------------
./a.out tests/test_import/no_parameters.fa
echo ----------------TEST_2------------------
./a.out tests/test_import/different_parameters.fa
echo ----------------TEST_3------------------
./a.out tests/test_import/many_parameters.fa
echo ----------------TEST_4------------------
./a.out tests/test_import/invalid_type.fa
echo ----------------TEST_5------------------
./a.out tests/test_import/invalid_type1.fa
echo ----------------TEST_6------------------
./a.out tests/test_import/no_as.fa
echo ----------------TEST_7------------------
./a.out tests/test_import/no_bracket.fa
echo ----------------TEST_8------------------
./a.out tests/test_import/no_comma.fa
echo ----------------TEST_9------------------
./a.out tests/test_import/no_kw_import.fa

echo --------------TEST_CF-------------------

echo ----------------TEST_10------------------
./a.out tests/test_cf/simple_cf_grammar.fa
echo ----------------TEST_11------------------
./a.out tests/test_cf/cf_inner_if.fa
echo ----------------TEST_12------------------
./a.out tests/test_cf/cf_inner_for.fa

echo --------------TEST_IF-------------------
echo ----------------TEST_13------------------
./a.out tests/test_if/simple_if_grammar.fa
echo ----------------TEST_14------------------
./a.out tests/test_if/test_inner_if.fa
echo ----------------TEST_15------------------
./a.out tests/test_if/test_comparator.fa
echo ----------------TEST_16------------------
./a.out tests/test_if/complex_id.fa


echo --------------TEST_FOR-------------------
echo ----------------TEST_17------------------
./a.out tests/test_for/simple_for_grammar.fa
echo ----------------TEST_18------------------
./a.out tests/test_for/inner_for.fa

echo --------------TEST_WHILE-------------------
echo ----------------TEST_19------------------
./a.out tests/test_while/simple_while_grammar.fa

echo --------------TEST_SUB_DEF-------------------
echo ----------------TEST_20------------------
./a.out tests/test_sub_def/ok.fa
echo ----------------TEST_21------------------
./a.out tests/test_sub_def/many_funcs.fa
echo ----------------TEST_22-----------------
./a.out tests/test_sub_def/no_body.fa
echo ----------------TEST_23------------------
./a.out tests/test_sub_def/no_statement_seq.fa
echo ----------------TEST_24------------------
./a.out tests/test_sub_def/with_df.fa

echo --------------TEST_COMPLEX-------------------
echo ----------------TEST_25------------------
./a.out tests/complex_tests/1.fa
