/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: xtarke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "grafo.h"
#include "lista_enc.h" // Leonardo
#include "no.h"	// Leonardo

struct vertices {
	int id;
	char *ip;
	char *mac;
	char *gtw;
	bool flag;
	/* mais informacoes, se necessario */
};

struct arestas {
	int adj;
	int weight;
	bool flag;
	/* mais informacoes, se necessario */
};

struct grafos{
	int n_vertices;
	vertice_t *vertices;
	aresta_t **matriz_adj;	/* Matriz de adjacencia */
};


grafo_t *cria_grafo(int vertices){
	int i;
	aresta_t **matriz_adj;

	grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	g->n_vertices = vertices;
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	memset(g->vertices, 0, vertices * sizeof(vertice_t));

	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(vertice_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

void prims(grafo_t *g, int v){
	int i, j, *flag;
	//aresta_t **matriz_adj;

	if (g == NULL){
		perror("prims");
		exit(EXIT_FAILURE);
	}
	
	if (v > g->n_vertices){
		perror("prims vertices");
		exit(EXIT_FAILURE);
	}
	int k=0;
	while(k != g->n_vertices){
		uint8_t w, id, menor = 0xFF;
		for (i=0; i < g->n_vertices; i++){
			printf("v:%d, i:%d\n", v, i);
			//printf("vertice flag: %d\n",g->vertices[i].flag);
			w = g->matriz_adj[v][i].weight;
			//printf("Peso: %d; Flag: %d\n", w, g->matriz_adj[v][i].flag);
			if ((adjacente(g,v,i)) && (g->matriz_adj[v][i].flag == 0) && (g->vertices[i].flag == 0)){ // verifica se existe a adjacencia
				//menor = menor > w ? w : menor; // condição de definição do menor
				//if (menor < menor > w ){
			puts("if\n");
				if(w <= menor){
					menor = w;
					id = i; // vertice adjacente com o menor peso na aresta
				}
				if (menor == w){
				}else{
					printf("Removido: (%d, %d)\n", v, i);
					rem_adjacencia(g, v, i); // remove a adjacencia atual por que o peso é maior
				}
			}
		}
		/*if(g->matriz_adj[0][v].weight > menor){
			printf("Removido: (%d, %d)\n", 0, v);
			rem_adjacencia(g,0,v); // remove a  adjacencia atual por que o peso é maior
		}*/

		//g->matriz_adj[v][id].adj = TRUE;
		if(menor != 0xFF){
			g->matriz_adj[v][id].flag = TRUE;
			g->matriz_adj[id][v].flag = TRUE;
			g->vertices[v].flag = TRUE;
			g->vertices[id].flag = TRUE;
			printf("Vertice: %d Peso: %d\n", id, menor);
		}
		//system("pause");
		v = id; //novo vertice
		k++;
}
	for (i=0; i < g->n_vertices; i++){
		for (j=0; j < g->n_vertices; j++){
			g->matriz_adj[i][j].adj = FALSE;
			if(g->matriz_adj[i][j].flag){
				g->matriz_adj[i][j].adj = TRUE;
			}
			printf("Flag[%d][%d]: %d\n", i, j, g->matriz_adj[i][j].flag);
		}
	}



	//Kruskal
	/*for (i=0; i < g->n_vertices; i++){
			for (j=0; j < g->n_vertices; j++){
				if (g->matriz_adj[i][j].adj){ // verifica se existe a adjacencia
				w = g->matriz_adj[v][j].weight;
				menor = menor > w ? w : menor; // condição de definição do menor
			}
		}
	}*/
	//printf("adj: %d - weight: %d", g->matriz_adj[0][1].adj, g->matriz_adj[0][1].weight);

}

void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}


int cria_adjacencia(grafo_t *g, int u, int v, int w){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices ){
		return FALSE;
	}

	g->matriz_adj[u][v].weight = w; 
	g->matriz_adj[v][u].weight = w;
	//g->matriz_adj[u][v].flag = FALSE;
	//g->vertices[u].ip = p1;
	//g->vertices[v].mac = p2; 
	g->matriz_adj[u][v].adj = TRUE;
	g->matriz_adj[v][u].adj = TRUE;

	return TRUE;
}

void vertice_datas(grafo_t *g, int v, char *str1, char *str2, char *str3){ // Leonardo

	if (g == NULL){
		perror("vertice_datas");
		exit(EXIT_FAILURE);
		system("pause");
	}

	if (v > g->n_vertices){
		perror("v - vertice_datas");
		exit(EXIT_FAILURE);
	}
	if (str1 == NULL || str2 == NULL || str3 == NULL){
		printf("String Inválida\n");
		system("pause");
		exit(-1);
	}
	//g->vertices[v].id = v;
	g->vertices[v].ip = str1;
	g->vertices[v].mac = str2; 
	g->vertices[v].gtw = str3; 
}
int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;
	g->matriz_adj[v][u].adj = FALSE;

	return TRUE;
}

int adjacente(grafo_t *g, int u, int v){

	if (u > MAX_VERTICES || v > MAX_VERTICES)
		return FALSE;

	return ((g->matriz_adj[u][v].adj) || (g->matriz_adj[v][u].adj));
}

int adjacente_w(grafo_t *g, int u, int v){

	if (u > MAX_VERTICES || v > MAX_VERTICES)
		return FALSE;

	return ((g->matriz_adj[u][v].weight));
}

void exportar_grafo_dot(const char *filename, grafo_t *g){ //Leonardo

	FILE *file;

	if (filename == NULL || g == NULL){
		fprintf(stderr, "exportar_grafo_dot: ponteiros invalidos\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "w");

	if (file == NULL){
		perror("exportar_grafo_dot:");
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

	int i=0, j=0;
	for (i; i < g->n_vertices; i++){
		for (j; j < g->n_vertices; j++){
			if(g->matriz_adj[i][j].adj == 0){
			}else{
				if(i!=j){
					fprintf(file, "\t%d -- %d [label = %d];\n", i, j, g->matriz_adj[i][j].weight);
				}
			}
			if(i!=j){
				printf("[%d] [%d] : %d label[%d]\n", i, j, g->matriz_adj[i][j].adj, g->matriz_adj[i][j].weight);
			}
		}
		j = i+1;
	}

	for (i=0; i < g->n_vertices; i++){
		if(g->vertices[i].ip == NULL || g->vertices[i].mac == NULL || g->vertices[i].gtw == NULL){
		}else{
			printf("V(%d) -> %s : %s : %s\n", i, g->vertices[i].ip, g->vertices[i].mac, g->vertices[i].gtw);
		}
	}

	fprintf(file, "}\n");

	fclose(file);
}

void importar_grafo(const char *filename){ //Leonardo
/*
	FILE *file;

	if (filename == NULL || g == NULL){
		fprintf(stderr, "exportar_grafo_dot: ponteiros invalidos\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "w");

	if (file == NULL){
		perror("exportar_grafo_dot:");
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

	int i=0, j=0;
	for (i; i < g->n_vertices; i++){
		for (j; j < g->n_vertices; j++){
			if(g->matriz_adj[i][j].adj == 0){
			}else{
				if(i!=j){
					fprintf(file, "\t%d -- %d [label = %d];\n", i, j, g->matriz_adj[i][j].weight);
				}
			}
			if(i!=j){
				printf("[%d] [%d] : %d label[%d]\n", i, j, g->matriz_adj[i][j].adj, g->matriz_adj[i][j].weight);
			}
		}
		j = i+1;
	}

	for (i=0; i < g->n_vertices; i++){
		if(g->vertices[i].ip == NULL || g->vertices[i].mac == NULL || g->vertices[i].gtw == NULL){
		}else{
			printf("V(%d) -> %s : %s : %s\n", i, g->vertices[i].ip, g->vertices[i].mac, g->vertices[i].gtw);
		}
	}

	fprintf(file, "}\n");

	fclose(file);
	*/
}