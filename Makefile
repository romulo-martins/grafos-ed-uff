teste-grafo: src/teste-grafo.c src/grafo-lista.h src/grafo-ops.h 
	gcc -o bin/teste_grafo.out src/teste-grafo.c src/grafo-lista.c src/grafo-ops.c
	./bin/teste_grafo.out < src/teste.txt
