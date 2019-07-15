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
					#/usr/bin/g++ -std=gnu++11 -Wall -Wextra -g -o wic \
					#Main.cpp include/libwic.a \
					#symbol-table/SymbolTable.cpp \
					#code-generator/CodeGenerator.cpp \
					#ast/AbstractSyntaxTree.cpp \
					#ast/node/ASTNode.cpp  \
					#ast/node/node-subtypes/symbol-table-node/ASTSymbolTableNode.cpp \
					#ast/node/node-subtypes/operator-node/ASTOperatorNode.cpp \
					#ast/node/node-subtypes/operator-node/ASTArithmeticNode.cpp \
					#ast/node/node-subtypes/operator-node/ASTRelationalNode.cpp \
					#ast/node/node-subtypes/leaf-node/ASTLeafNode.cpp \
					#ast/node/node-subtypes/clause-node/ASTClauseNode.cpp \
					#error-manager/ErrorManager.cpp \
					#ast/node/node-subtypes/structural-node/ASTStructuralNode.cpp \

					#mv *.a *.o build

qcompile:
					/usr/bin/gcc -Wall -Wextra -g -o bin/my_program \
					file.q.c \
					include/Qlib.c

clean:
					rm -rf build bin wic.output *.o
