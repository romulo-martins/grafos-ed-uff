#include <stdio.h>
#include <stdlib.h>

// no vizinho
typedef struct viz {
	int id;
	struct viz *prox_viz;
}Viz;

typedef struct grafo {
	int id;
	Viz *prim; // referencia para o primeiro vizinho de um no
	struct grafo *prox;
}Grafo;

Grafo *inicializa();
Grafo *ins_no(Grafo *g, int no);
Grafo *busca(Grafo *g, int no);
void ins_aresta(Grafo *g, int no1, int no2);
Grafo *retira_no(Grafo *g, int no);
void retira_aresta(Grafo *g, int no1, int no2);
void libera(Grafo *g);
void imprime(Grafo *g);
