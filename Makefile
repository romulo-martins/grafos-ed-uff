build-test: test/teste-grafo.c src/grafo-lista.h src/grafo-ops.h
	gcc -o bin/teste_grafo.out test/teste-grafo.c src/grafo-lista.c src/grafo-ops.c -lm

run-test: build-test
	./bin/teste_grafo.out < test/teste.txt

test: run-test 
