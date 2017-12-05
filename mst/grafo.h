/*
 * grafo.h
 *
 *  Created on: Nov 18, 2016
 *      Author: xtarke
 */

#ifndef GRAFO_H_
#define GRAFO_H_


#define MAX_VERTICES 50

#define TRUE 1
#define FALSE 0

typedef struct vertices vertice_t;
typedef struct arestas aresta_t;
typedef struct grafos grafo_t;

grafo_t *cria_grafo(int vertices);
void libera_grafo (grafo_t *g);
int cria_adjacencia(grafo_t *g, int u, int v, int w); //Leonardo
void vertice_datas(grafo_t *g, int v, char *str1, char *str2, char *str3); // Leonardo
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);
void prims(grafo_t *g, int v);
int adjacente_w(grafo_t *g, int u, int v); // Leonardo
void exportar_grafo_dot(const char *filename, grafo_t *g); //Leonardo
void importar_grafo(const char *filename); //Leonardo

#endif /* GRAFO_H_ */
