#include "grafo-lista.h"

int qtd_nos(Grafo *g) {
    if (!g) return 0;
    Grafo *p = g;
    int maior = 0;
    while (p) {
        if(p->id > maior) {
        	maior = p->id;
        }
        p = p->prox;
    }
    return maior;
}

int existeAresta(Grafo *g, int v1, int v2) {
	if(!g) return 0;
	Grafo *p = busca(g, v1);
	if(!p) return 0;
	Viz *v = p->prim; 
	while(v) {
		if(v->id == v2) return 1;
		v = v->prox_viz;
	}
	return 0;
}

void buscaEmProfundidade(Grafo *g, int v, int visita[], int cont){
	Grafo* p;
	visita[v] = cont;
	for (p = g; p != NULL; p = p->prox){
		if (existeAresta(g ,v, p->id) && !visita[p->id]) {
			buscaEmProfundidade(g, p->id, visita, cont);
		}	
	}
}

void iniciarVetor(int v[], int n) {
	int i;
	for(i = 1; i <= n; i++) { // inicializa o vetor de elementos visitados 
		v[i] = 0;
	}
}

int calculaComponentes(Grafo *g) {
	if(!g) return 0;
	Grafo *p = g;
	int max = qtd_nos(g);
	int visita[max];
	int i, cont = 0;
	iniciarVetor(visita, max);
	while(p) {
		if(visita[p->id] == 0) {
			buscaEmProfundidade(p, p->id, visita, ++cont); // verifica se existe um caminho do primeiro no a todos os outros nos do grafo
		}
		p = p->prox;
	}
	return cont;
}

int ehConexo(Grafo *g) {
	return (calculaComponentes(g) == 1);
}

Grafo *copiaGrafo(Grafo *g) {
	Grafo *p = g, *aux = inicializa();
	while(p) {
		aux = ins_no(aux, p->id);
		p = p->prox;
	}
	p = g;
	while(p) {
		Viz *v = p->prim;
		while(v) {
			if(!existeAresta(aux, p->id, v->id)) {
				ins_aresta(aux, p->id, v->id);	
			}
			v = v->prox_viz;
		}
		p = p->prox;
	}
	return aux;
}

void pontes(Grafo *g) {
	if(!ehConexo(g)) return;
	Grafo *p = g, *aux = copiaGrafo(g);
	int  i, j;
	int numPontes = 0;
	int max = qtd_nos(g);
	FILE *arq = fopen("out/pontes.txt", "w");
	
	while(p) {
		Viz *v = p->prim;
		while(v) {
			if(existeAresta(g, p->id, v->id)) {
				retira_aresta(aux, p->id, v->id);
				if(!ehConexo(aux) && (p->id < v->id)) {
					printf("( %d, %d )", p->id, v->id);
					fprintf(arq,"( %d, %d )", p->id, v->id);
					numPontes++;
				}
				ins_aresta(aux, p->id, v->id);
			}
			v = v->prox_viz;
		}
		p = p->prox;
	}
	
	printf("\n----- pontes do grafo -----\n");
	for(i = 1; i < max; i++) {
		for(j = i + 1; j <= max; j++) {

		}
	}
	printf("\nNumero de pontes: %d\n", numPontes);
	fprintf(arq,"\nNumero de pontes: %d\n", numPontes);
	fclose(arq);
}
