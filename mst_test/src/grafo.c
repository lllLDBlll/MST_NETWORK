#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "grafo.h"
#include "Quick_Sort.h"
//#include "src/lista_enc.h"
//#include "src/no.h"

//#define DEBUG
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
	//int n_vert; // numero de vertices visitados
	int n_arestas; // numero de arestas visitadas
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
	g->n_arestas = 0;
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
	int i, j;
	//aresta_t **matriz_adj;

	if (g == NULL){
		perror("prims");
		exit(EXIT_FAILURE);
	}

	if (v >= g->n_vertices){
		perror("prims vertices");
		system("pause");
		exit(EXIT_FAILURE);
	}

	int k=0;
	while(k != g->n_vertices-1){
		uint8_t w, id, menor = 0xFF;
		for (i=0; i < g->n_vertices; i++){

			w = g->matriz_adj[v][i].weight;

			#ifdef DEBUG
				printf("v:%d, i:%d\n", v, i);
				printf("Peso: %d; Flag: %d\n", w, g->matriz_adj[v][i].flag);
			#endif // DEBUG

			if ((adjacente(g,v,i)) && (!g->matriz_adj[v][i].flag) && (!g->vertices[i].flag)){ // verifica se existe a adjacencia
				if(w <= menor){// condição de definição do menor
					menor = w;
					id = i; // vertice adjacente com o menor peso na aresta
				}
				if (menor == w){
					/*nothing*/
				}else{
					//printf("Removido: (%d, %d)\n", v, i);
					rem_adjacencia(g, v, i); // remove a adjacencia atual por que o peso é maior
				}
			}
		}

		//g->matriz_adj[v][id].flag = TRUE;
		//g->matriz_adj[id][v].flag = TRUE;
		vert_flag(g, v, id);
		//g->vertices[v].flag = TRUE;
		//g->vertices[id].flag = TRUE;
		arest_flag(g, v, id);
		v = id; // próximo vertice
		k++;
	}

    printf("Prims - Numero de vertices: %d Numero de arestas: %d\n", vert_flag(g,0,0), arest_flag(g,0,0));

	for (i=0; i < g->n_vertices; i++){
		for (j=0; j < g->n_vertices; j++){
			g->matriz_adj[i][j].adj = FALSE;
			if(g->matriz_adj[i][j].flag){
				g->matriz_adj[i][j].adj = TRUE;
			}
			//printf("Flag[%d][%d]: %d\n", i, j, g->matriz_adj[i][j].flag);
		}
	}



}

void kruskal(grafo_t *g){

	if (g == NULL){
		perror("prims");
		exit(EXIT_FAILURE);
	}

	int menor[g->n_arestas], temp, i=0, j=0, w = 0xFFFF;

	//printf("aresta: %d", g->n_arestas);

	for (i=0; i < g->n_vertices; i++){
		for (j; j < g->n_vertices; j++){
			w = adjacente_w(g, i, j);
			if (menor[i] > w && (i != j)){
				menor[i] = w;
			}
		}
		printf("Menor: %d", menor[i]);
		j = i + 1;
	}



	int k=0, v=0, u=0, l, x = 1, y = 0, cycle=0;
	while(k != (g->n_vertices)){
		int w, menor = 0xFFFF;//INT_MAX;
		for (i=0; i < g->n_vertices; i++){
			for (j; j < g->n_vertices; j++){
				if ((adjacente(g, i, j)) && !g->matriz_adj[i][j].flag && (i != j) && (x > y)/* && x > y && !g->vertices[i].flag && !g->vertices[j].flag*/){
					w = adjacente_w(g, i, j);
					if(w < menor){// condição de definição do menor
						menor = w;
						v = i;
						u = j;
						printf("menor: %d\n",menor);
					}
				}else{
					if (x == y){
						cycle = 1;
						g->matriz_adj[v][u].flag = FALSE;
						//x = vert_flag(g, 0, 0);
						//y = arest_flag(g, 0, 0);
					//printf("Flag[%d][%d]: %d peso: %d x-vert: %d y-arest: %d \n", v, u,g->matriz_adj[v][u].flag, menor, x, y);
					}

				}
                /*if (i == (g->n_vertices - 1) && j == (g->n_vertices - 1)){ // Fim dos For
                    if (x == y){
                        puts("X = Y\n");
						g->matriz_adj[v_old][u_old].flag = FALSE;
						g->matriz_adj[u_old][v_old].flag = FALSE;
						printf("v old: %d u old: %d", v_old, u_old);
						printf("v: %d u:%d peso: %d \n",v, u, menor);
						printf("Flag[%d][%d]: %d\n", v, u, g->matriz_adj[v][u].flag);
						
						g->vertices[v].flag = FALSE;
						g->vertices[u].flag = FALSE;
                    }else{
                   		//x = vert_flag(g, 0, 0);
                    	//y = arest_flag(g, 0, 0);
                    }
                    printf("Flag[%d][%d]: %d\n", v, u, g->matriz_adj[v][u].flag);
				}*/
			}
			j = i + 1;
		}
		k++;
		if (x > y && !cycle){
			x = vert_flag(g, v, u);
			y = arest_flag(g, v, u);
		}else{
			cycle = 0;
		}
		printf("Flag[%d][%d]: %d peso: %d x-vert: %d y-arest: %d \n", v, u, g->matriz_adj[v][u].flag, menor, x, y);
		/*if (y != x - 1){
			puts("REMANDO!\n");
			g->matriz_adj[v][u].flag = FALSE;
			g->matriz_adj[u][v].flag = FALSE;
		}*/
	}
    printf("Kruskal - Numero de vertices: %d Numero de arestas: %d\n", vert_flag(g,0,0), arest_flag(g,0,0));

	for (i=0; i < g->n_vertices; i++){
		for (j=0; j < g->n_vertices; j++){
			g->matriz_adj[i][j].adj = FALSE;
			if(g->matriz_adj[i][j].flag){
				g->matriz_adj[i][j].adj = TRUE;
			}
			//printf("Flag[%d][%d]: %d\n", i, j, g->matriz_adj[i][j].flag);
		}
	}
}

int vert_flag(grafo_t *g, int v, int u){
    int i, j, count=0;

    if (g == NULL){
        return FALSE;
	}

    if (v == 0 && u == 0){
            /*nothing*/
    }else{
        g->vertices[u].flag = TRUE;
        g->vertices[v].flag = TRUE;
    }

    for (i=0; i < g->n_vertices; i++){
        if (g->vertices[i].flag){
			count++;
		}
	}

    return count; // retorna o número de arestas
}


int arest_flag(grafo_t *g, int v, int u){
    int i, j, count=0;
    if (g == NULL){
        return FALSE;
	}

    if (v == 0 && u == 0){
        /*nothing*/
    }else{
        g->matriz_adj[v][u].flag = TRUE;
        //g->matriz_adj[u][v].flag = TRUE;
    }

    for (i=0; i < g->n_vertices; i++){
		for (j=0; j < g->n_vertices; j++){
		    if (g->matriz_adj[i][j].flag){
                count++;
		    }
		}
    }
    return count; // retorna o número de vertices
}

int vert_v(grafo_t *g){
	int i, count=0;

	if (g == NULL){
		return FALSE;
	}

	for (i=0; i < g->n_vertices; i++){
		if (g->vertices[i].flag){
			count++;
		}
	}
	if (count >= g->n_vertices){
		return TRUE;
	}else{
		return FALSE;
	}
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

int cria_adjacencia(grafo_t *g, int v, int u, int w){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices ){
		return FALSE;
	}
	
	g->n_arestas++;
	//g->matriz_adj[u][v].weight = w;
	g->matriz_adj[v][u].weight = w;
	//g->matriz_adj[u][v].adj = TRUE;
	g->matriz_adj[v][u].adj = TRUE;

	return TRUE;
}

void vertice_dados(grafo_t *g, int v, char *str1, char *str2, char *str3){

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

	g->vertices[v].ip = str1;
	g->vertices[v].mac = str2;
	g->vertices[v].gtw = str3;
}
int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices){
		return FALSE;
	}

	g->matriz_adj[u][v].adj = FALSE;
	g->matriz_adj[v][u].adj = FALSE;

	return TRUE;
}

int adjacente(grafo_t *g, int u, int v){ // retorna se existe adjacencia

	if (u > MAX_VERTICES || v > MAX_VERTICES){
		return FALSE;
	}

	return ((g->matriz_adj[u][v].adj) || (g->matriz_adj[v][u].adj));
}

int adjacente_w(grafo_t *g, int u, int v){ // retorna o peso

	if (u > MAX_VERTICES || v > MAX_VERTICES){
		return FALSE;
	}

	return ((g->matriz_adj[u][v].weight));
}

void exportar_grafo_dot(const char *filename, grafo_t *g){

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
			if(adjacente(g,i,j) != 0){
				if(i != j){ // Não imprimi o mesmo vertice
					fprintf(file, "\t%d -- %d [label = %d];\n", i, j, adjacente_w(g,i,j));
				}
				if(i != j){
					printf("\t[%d] [%d] : %d label[%d]\n", i, j, adjacente(g,i,j), adjacente_w(g,i,j));
				}
			}
		}
		j = i+1; // evita duplicar a aresta no print
	}
/*

	for (i=0; i < g->n_vertices; i++){
		if(g->vertices[i].ip == NULL || g->vertices[i].mac == NULL || g->vertices[i].gtw == NULL){
		}else{
			printf("\tV(%d) -> %s : %s : %s\n", i, g->vertices[i].ip, g->vertices[i].mac, g->vertices[i].gtw);
		}
	}

	printf("\n");
*/
	fprintf(file, "}\n");

	fclose(file);
}

void importar_dados(const char *filename, grafo_t *g){

	FILE *file;
	int v;
	char *ip, *mac, *gtw;

 	ip = (char*)calloc(100, sizeof(char));
 	mac = (char*)calloc(100, sizeof(char));
 	gtw = (char*)calloc(100, sizeof(char));

	if (filename == NULL ||g == NULL){
		fprintf(stderr, "importar_dados: ponteiros invalidos\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");

	if (file == NULL){
		perror("importar_dados:");
		system("pause");
		exit(EXIT_FAILURE);
	}

	while(!feof(file)){
		fscanf(file,"%d,%[^,],%[^,],%s\n", &v, ip, mac, gtw);
		printf("%d,%s,%s,%s\n", v, ip, mac, gtw);
		#ifdef DEBUG
			printf("IP: %s\n", ip);
			printf("MAC: %s\n", mac);
			printf("GTW: %s\n", gtw);
		#endif // DEBUG
		vertice_dados(g, v, ip, mac, gtw);
	}

	printf("Dados Importados!\n");
	fclose(file);
}


void importar_grafo(const char *filename, grafo_t *g){

	FILE *file;
	int u, v, w;

	if (filename == NULL ||g == NULL){
		fprintf(stderr, "importar_grafo: ponteiros invalidos\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");

	if (file == NULL){
		perror("importar_grafo:");
		exit(EXIT_FAILURE);
	}

	while(!feof(file)){
		fscanf(file,"%d,%d,%d\n", &u, &v, &w);
		//printf("%d,%d,%d\n", u, v, w);
		cria_adjacencia(g, u, v, w);
	}

	printf("Grafo Importado!\n");
	fclose(file);
}