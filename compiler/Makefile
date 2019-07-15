all:
					mkdir build
					mkdir bin
					$(MAKE) bison
					$(MAKE) flex #$(F)
					$(MAKE) compile

bison:
					bison -d -v -t src/flex-bison/bwic.y
					mv bwic.tab.* build

flex:
					flex src/flex-bison/wic.l
					mv lex.yy.* build

compile:
					/usr/bin/gcc -Wall -Wextra -g -o bin/wic \
					src/main.c \
					src/symbol-table/SymbolTableManager.c \
					src/code-generator/CodeGeneratorManager.c \
					src/code-generator/CodePrinter.c \
					src/code-generator/StackManager.c \
					build/lex.yy.c build/bwic.tab.c
					#gcc -o wic build/lex.yy.c build/wic.tab.c -lfl -lm
					#/usr/bin/g++ -std=gnu++11 -c build/wic.tab.c build/lex.yy.c
					#mv *.o build
					#ar rvs include/libwic.a build/wic.tab.o build/lex.yy.o
#

qcompile:
					/usr/bin/gcc -Wall -Wextra -g -o bin/my_program \
					file.q.c include/Qlib.c

clean:
					rm -rf build bin wic.output *.o
