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
int cria_adjacencia(grafo_t *g, int v, int u, int w);
void vertice_dados(grafo_t *g, int v, char *str1, char *str2, char *str3);
int rem_adjacencia(grafo_t *g, int u, int v);
int adjacente(grafo_t *g, int u, int v);
void prims(grafo_t *g, int v);
void kruskal(grafo_t *g);
int vert_v(grafo_t *g);
int vert_flag(grafo_t *g, int v, int u);
int arest_flag(grafo_t *g, int v, int u);
int adjacente_w(grafo_t *g, int u, int v);
void exportar_grafo_dot(const char *filename, grafo_t *g);
void importar_grafo(const char *filename, grafo_t *g);
void importar_dados(const char *filename, grafo_t *g);

#endif /* GRAFO_H_ */
