objects = main.o emitter.o error.o \
		init.o lex.yy.o Symtable.o parser.tab.o

CFLAGS = -Wall


.cpp.o:
	g++ -c $(CFLAGS) $< -o $@

main: $(objects)
	g++ -o main $(objects)

parser.tab.c parser.h: parser.y
	bison --defines=parser.h parser.y -r all

lex.yy.o: lex.yy.c
	g++ -c $(FLAGS) lex.yy.c -o lex.yy.o

parser.tab.o: parser.tab.c parser.h
	g++ -c $(FLAGS) parser.tab.c -o parser.tab.o

$(objects): global.h parser.h

lex.yy.c: lex.l
	flex lex.l

.PHONY: clean

clean:
	-rm main $(objects) lex.yy.c parser.h parser.tab.c