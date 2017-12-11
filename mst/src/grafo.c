#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "grafo.h"
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
	int adj_t;
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
	int i, j;
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

		g->matriz_adj[v][id].flag = TRUE;
		g->matriz_adj[id][v].flag = TRUE;
		g->vertices[v].flag = TRUE;
		g->vertices[id].flag = TRUE;
		v = id; // próximo vertice
		k++;
	}

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
	
	int v_n=1, a_n=0;
	int i, j, k=0, v=-1, u=0, u_old = 0, v_old = 0, pmt=0;

	//while(k != (g->n_vertices)){
	while(a_n != g->n_vertices-1){
		int w, menor = 0xFFFF;//INT_MAX;
		for (i=0; i < g->n_vertices; i++){
			for (j=0; j < g->n_vertices; j++){
				w = adjacente_w(g, i, j);
				if ((adjacente(g, i, j)) && !g->matriz_adj[i][j].flag && !pmt/* g->vertices[i].flag*/){
					if(w < menor){// condição de definição do menor
						menor = w;
						v = i;
						u = j;
					}
				}else{
					if (pmt != 0){

					}

				}
			}
			//j = i + 1;
			if (i == (g->n_vertices-1)){
				if (a_n == v_n-1){
					//cycle = 1;
					puts("Kinder");
				}else{
					puts("PUTS");
					//printf("peso: %d v: %d u:%d v_n:%d a_n:%d \n", menor, v, u, v_n, a_n);
					//g->vertices[u].flag = FALSE;
					//g->vertices[v].flag = FALSE;
					//v = 0;
					//u = 0;
					//cycle = 1;
				}
				a_n = arest_flag(g, v, u);
				v_n = vert_flag(g, v, u);

				if (a_n == v_n){
					puts("Hello");
					g->matriz_adj[v][u].adj = FALSE;
					g->matriz_adj[u][v].adj = FALSE;
					g->matriz_adj[v][u].flag = FALSE;
					g->matriz_adj[u][v].flag = FALSE;
					a_n = arest_flag(g, 0, 0);
					}

				//puts("Just One Shot!");
				/*printf("peso: %d v: %d u:%d v_n:%d a_n:%d \n", menor, v, u, v_n, a_n);
				g->vertices[u].flag = TRUE;
				g->vertices[v].flag = TRUE;
				g->matriz_adj[v][u].flag = TRUE; // marca a adjacencia com o menor peso // criar função de flag
				g->matriz_adj[u][v].flag = TRUE; // marca a adjacencia com o menor peso
				//puts("End Show!");
			*/}
		}
		k++;
		//cycle(g, k, g->n_vertices-1);
		

		//
		/*if (a_n != v_n-1){
		puts("imuah");
			g->matriz_adj[v][u].flag = FALSE; // marca a adjacencia com o menor peso // criar função de flag
			g->matriz_adj[u][v].flag = FALSE; // marca a adjacencia com o menor peso
			//g->vertices[u].flag = FALSE;
			//g->vertices[v].flag = FALSE;
		}*/
/*
		for (i=0; i < g->n_vertices; i++){
			v_n = v_n + g->vertices[i].flag;
			for (j=0; j < g->n_vertices; j++){
				a_n = a_n + g->matriz_adj[i][j].flag;
			}
		}*/


		printf("peso: %d v: %d u:%d v_n:%d a_n:%d \n", menor, v, u, v_n, a_n);


	}// end while
	/*g->matriz_adj[4][5].flag = FALSE;
	g->matriz_adj[5][4].flag = FALSE;
	g->matriz_adj[5][1].flag = FALSE;
	g->matriz_adj[1][5].flag = FALSE;
*/
	//cycle(g, 1, 5);

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

int cycle(grafo_t *g, int v, int u){
	int i,j,k;
	if (!g->vertices[v].flag || !g->vertices[u].flag){
		puts("Sem Vertice!");
		return 0;
	}
	if (g->matriz_adj[v][u].flag){
		puts("Chegou!!!!");
		//return TRUE;
	}

	for (i=0; i < g->n_vertices; i++){
		if (g->matriz_adj[v][i].flag){
			if (v == u){
				return 0;
			}
			cycle(g, i, 0);	
			puts("ALADIN!");
		}
	}
	/*for (i=0; i < g->n_vertices; i++){
		for (j=0; j < g->n_vertices; j++){
			for (k=0; k < g->n_vertices; k++){
				if (g->matriz_adj[i][j].flag){
					if (g->matriz_adj[j][k].flag){
						if (g->matriz_adj[k][i].flag){
							puts("ALADIN!");
						}
					}
				}
			}
		}
	}*/
		
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
        g->matriz_adj[u][v].flag = TRUE;
    }

    for (i=0; i < g->n_vertices; i++){
		for (j=0; j < g->n_vertices; j++){
		    if (g->matriz_adj[i][j].flag){
                count++;
		    }
		}
    }
    return count/2; // retorna o número de vertices
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

int cria_adjacencia(grafo_t *g, int u, int v, int w){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices ){
		return FALSE;
	}

	g->matriz_adj[u][v].weight = w; 
	g->matriz_adj[v][u].weight = w;
	g->matriz_adj[u][v].adj = TRUE;
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