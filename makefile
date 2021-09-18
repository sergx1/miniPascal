minipascal: lex.yy.o parser.tab.o izraz.o naredba.o
	g++ -Wall -o $@ $^
parser.tab.o: parser.tab.cpp parser.tab.hpp izraz.hpp naredba.hpp
	g++ -Wall -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -dv $<
lex.yy.o: lex.yy.c parser.tab.hpp izraz.hpp naredba.hpp
	g++ -Wall -c -o $@ $<
lex.yy.c: lexer.lex
	flex $<
naredba.o: naredba.cpp naredba.hpp izraz.hpp
	g++ -Wall -c -o $@ $<
izraz.o: izraz.cpp izraz.hpp
	g++ -Wall -c -o $@ $<

.PHONY: clean
clean:
	rm -f *~ *.c *.o parser.tab.hpp parser.tab.cpp *.output minipascal
