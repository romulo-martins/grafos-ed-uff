#include "grafo-lista.h"
#include "grafo-ops.h"

int main() {
	
	Grafo *g = inicializa();
	
	int i, num_nos, num_arestas, no1, no2;
	
	// busca a quantidade de nos do 
	scanf("%d %d", &num_nos, &num_arestas);
	
	//adiciona os nos
	for (i = 0; i < num_nos; i++) {
		scanf("%d", &no1);
		g = ins_no(g, no1);
	}	
	//adiciona as arestas 
	for (i = 0; i < num_arestas; i++) {
		scanf("%d %d", &no1, &no2);
		ins_aresta(g, no1, no2);
	}

	printf("\n----- Grafo original -----\n");
	imprime(g);
	
	if(ehConexo(g)) {
		printf("\nO grafo eh conexo!\n");
		pontes(g);
	}
	else {
		printf("\nNao eh conexo!\n");
		printf("\nO grafo possui %d componentes conexas \n", calculaComponentes(g));
	}
	libera(g);
	
	return 0;
}
