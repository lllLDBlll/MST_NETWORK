/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: xtarke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "lista_enc.h" // Leonardo
#include "no.h"	// Leonardo

struct vertices {
	int id;
	char *string1;
	char *string2;
	/* mais informacoes, se necessario */
};

struct arestas {
	int adj;
	int weight;
	/* mais informacoes, se necessario */
};

struct grafos{
	int n_vertices;
	vertice_t *vertices;
	aresta_t **matriz_adj;	/* Matriz de adjacencia */
};


grafo_t *cria_grafo(int vertices)
{
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


int cria_adjacencia(grafo_t *g, int u, int v, int w, char *p1, char *p2){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].weight = w; 
	g->vertices[u].string1 = p1;
	g->vertices[v].string2 = p2; 
	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

int adjacente(grafo_t *g, int u, int v){

	if (u > MAX_VERTICES || v > MAX_VERTICES)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

int adjacente_w(grafo_t *g, int u, int v){

	if (u > MAX_VERTICES || v > MAX_VERTICES)
		return FALSE;

	return ((g->matriz_adj[u][v].weight));
}

void exportar_grafo_dot(const char *filename, grafo_t *g){ //Leonardo

	FILE *file;
/*
	vertice_t *vertices;
	aresta_t *aresta;
	lista_enc_t *lista_arestas;

	int peso;
*/
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

	//TESTANDO
//typedef struct vertices vertice_t; // id
//typedef struct arestas aresta_t; // adj
//typedef struct grafos grafo_t;//n_vertices vertice_t *vertices; aresta_t **matriz_adj;	
	vertice_t *v;
	aresta_t *a;
	//obter_dado(no);
	//g->vertices[i].string1

	int i, j;
	for (i=0; i < g->n_vertices; i++){
		for (j=0; j < g->n_vertices; j++){
			if(g->matriz_adj[i][j].adj == 0){
			}else{
				fprintf(file, "\t%d -- %d [label = %d];\n", i, j, g->matriz_adj[i][j].weight);
			}
			printf("[%d] [%d] : %d label[%d]\n", i, j, g->matriz_adj[i][j].adj, g->matriz_adj[i][j].weight);
		}
	}
	fprintf(file, "}\n");

	//fprintf(file, "\t%d -- %d [label = %d];\n",
	//	vertice_get_id(vertice), vertice_get_id(adjacente), peso);


	//obtem todos os nos da lista
	/*no_vert = obter_cabeca(grafo->vertices);
	while (no_vert){
		vertice = obter_dado(no_vert);

		//obtem todos as arestas
		lista_arestas = vertice_get_arestas(vertice);

		no_arest = obter_cabeca(lista_arestas);
		while (no_arest) {
			aresta = obter_dado(no_arest);

			//ignora caso já exportada
			if (aresta_get_status(aresta) == EXPORTADA) {
				no_arest = obtem_proximo(no_arest);
				continue;
			}

			//marca como exportada esta aresta
			aresta_set_status(aresta, EXPORTADA);
			adjacente = aresta_get_adjacente(aresta);

			//marca contra-aresta também como exporta no caso de grafo não direcionados
			contra_aresta = procurar_adjacente(adjacente, vertice);
			aresta_set_status(contra_aresta, EXPORTADA);

			//obtem peso
			peso = aresta_get_peso(aresta);
			// verice -- vertice [label = "Valor"];
			fprintf(file, "\t%d -- %d [label = %d];\n",
					vertice_get_id(vertice),
					vertice_get_id(adjacente),
					peso);

			no_arest = obtem_proximo(no_arest);
		}
		no_vert = obtem_proximo(no_vert);
	}*/
	fclose(file);
}