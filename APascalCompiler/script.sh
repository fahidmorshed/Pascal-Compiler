yacc -d parser.y
echo 1
lex scanner.l
echo 2
g++ y.tab.c lex.yy.c

./a.out <in.txt> out.txt
echo 3