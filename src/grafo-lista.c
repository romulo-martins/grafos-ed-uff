#include "grafo-lista.h"

Grafo *inicializa() {
	return NULL;
}

/* insere um nó no grafo*/
Grafo *ins_no(Grafo *g, int no) {
	Grafo *novo = (Grafo*)malloc(sizeof(Grafo));
	novo->id = no;
	novo->prim = NULL;
	novo->prox = g;
	return novo;
}

/* busca um nó no grafo */
Grafo *busca(Grafo *g, int no) {
	Grafo *p = g;
	while((p != NULL) && (p->id != no)) {
		p = p->prox;
	}
	return p;
}

/* insere aresta com os nos ja informados no grafo */
void ins_aresta(Grafo *g, int no1, int no2) {
	Grafo *p = busca(g, no1), *q = busca(g, no2);
	if((!p) || (!q)) return;
	Viz *novo = (Viz*)malloc(sizeof(Viz));
	novo->id = no2;
	novo->prox_viz = p->prim;
	p->prim = novo;
	
	novo = (Viz*)malloc(sizeof(Viz));
	novo->id = no1;
	novo->prox_viz = q->prim;
	q->prim = novo;
}

/* retira a aresta entre dois nós informados */
void retira_aresta(Grafo *g, int no1, int no2) {
	Grafo *p = busca(g, no1), *q = busca(g, no2);
	if((!p) || (!q)) return;
	/* parte para tirar o vizinho adjacente do no1 */
	Viz *viz = p->prim, *ant = NULL;
	while((viz != NULL) && (viz->id != no2)) {
		ant = viz;
		viz = viz->prox_viz;
	}
	if(!viz) return;
	if(!ant) {
		p->prim = p->prim->prox_viz;
	}
	else {
		ant->prox_viz = viz->prox_viz;
	}
	free(viz);
	
	/*parte para tirar o vizinho adjacente do no2*/
	viz = q->prim, ant = NULL;
	while((viz != NULL) && (viz->id != no1)) {
		ant = viz;
		viz = viz->prox_viz; 
	} 
	if(!viz) return;
	if(!ant) {
		q->prim = q->prim->prox_viz;
	}
	else {
		ant->prox_viz = viz->prox_viz;
	}
	free(viz);
}

/* retira um nó do grafo */
Grafo *retira_no(Grafo *g, int no) {
	Grafo *p = g, *ant = NULL;
	while((p != NULL) && (p->id != no)) {
		ant = p;
		p = p->prox;
	}
	if(!p) return g;
	Viz *viz = p->prim;
	while(viz != NULL) {
		int id = viz->id;
		viz = viz->prox_viz;
		retira_aresta(g, p->id, id);
	}
	if(!ant) {
		g = p->prox;
	}
	else {
		ant->prox = p->prox;
	}
	free(p);
	return g;
}

/* desaloca da memoria o grafo criado */
void libera(Grafo *g) {
	Grafo *p = g;
	while(p != NULL) {
		Viz *v = p->prim;
		while(v != NULL) {
			Viz *v_temp = v; /* v_temp -> vizinho temporario */
			v = v->prox_viz;
			free(v_temp);
		}
		Grafo *g_temp = p; /* g_temp -> grafo temporario*/
		p = p->prox;
		free(g_temp);
	}
}

/* mostra os elementos do grafo e seus respectivos vizinhos*/
void imprime(Grafo *g) {
	Grafo *p = g;
	if(!p) return;
	while(p != NULL) {
		printf(" %d ", p->id);
		Viz *viz = p->prim;
		while(viz != NULL) {
			printf("-> %d ", viz->id);
			viz = viz->prox_viz;
		}
		p = p->prox;
		printf("\n");
	}
}


