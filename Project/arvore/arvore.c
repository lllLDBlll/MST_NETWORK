/*
 * arvore.c
 *
 *  Created on: Nov 25, 2016
 *      Author: xtarke
 */

#include <stdio.h>
#include <stdlib.h>

#include "vertice.h"
#include "arvore.h"


#define FALSE 0
#define TRUE 1


struct arvores {
	int id;
	vertice_t *raiz;
	lista_enc_t *vertices;
};

vertice_t* arvore_procura_vertice(arvore_t *arvore, int id);

arvore_t *cria_arvore(int id)
{
	arvore_t *p = NULL;

	p = (arvore_t*) malloc(sizeof(arvore_t));

	if (p == NULL)	{
		perror("cria_grafo:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->vertices = cria_lista_enc();

	return p;
}

vertice_t* arvore_adicionar_vertice_id(arvore_t *arvore, int id)
{
	vertice_t *vertice;
	no_t *no;

#ifdef DEBUG
	printf("grafo_adicionar_vertice: %d\n", id);
#endif

	if (arvore == NULL)	{
			fprintf(stderr,"grafo_adicionar_vertice: grafo invalido!");
			exit(EXIT_FAILURE);
	}

	if (arvore_procura_vertice(arvore, id) != NULL) {
		fprintf(stderr,"grafo_adicionar_vertice: vertice duplicado!\n");
		exit(EXIT_FAILURE);
	}

	vertice = cria_vertice(id);
	no = cria_no(vertice);

	add_cauda(arvore->vertices, no);

	return vertice;
}

vertice_t* arvore_adicionar_vertice(arvore_t *arvore, vertice_t *vertice)
{
	no_t *no;

#ifdef DEBUG
	printf("grafo_adicionar_vertice: %d\n", id);
#endif

	if (arvore == NULL)	{
			fprintf(stderr,"grafo_adicionar_vertice: grafo invalido!");
			exit(EXIT_FAILURE);
	}

	no = cria_no(vertice);

	add_cauda(arvore->vertices, no);

	return vertice;
}

vertice_t* arvore_procura_vertice(arvore_t *arvore, int id)
{
	no_t *no_lista;
	vertice_t *vertice;
	int meu_id;

	if (arvore == NULL)	{
		fprintf(stderr,"procura_vertice: grafo invalido!");
		exit(EXIT_FAILURE);
	}

	if (lista_vazia(arvore->vertices) == TRUE)
		return FALSE;

	no_lista = obter_cabeca(arvore->vertices);

	while (no_lista)
	{
		//obtem o endereco da lista
		vertice = obter_dado(no_lista);

		//obterm o id do vertice
		meu_id = vertice_get_id(vertice);

		if (meu_id == id) {
			return vertice;
		}

		no_lista = obtem_proximo(no_lista);
	}

	return NULL;
}

void arvore_adiciona_filhos(arvore_t * arvore, vertice_t *vertice, int esq, int dir)
{
	vertice_t *esquerda;
	vertice_t *direita;

	if (arvore == NULL)	{
		fprintf(stderr,"arvore_adiciona_filhos: arvore invalida!");
		exit(EXIT_FAILURE);
	}

	if (esq != -1){
		esquerda = arvore_procura_vertice(arvore, esq);
		vertice_set_pai(esquerda, vertice);
		vertice_set_esq(vertice, esquerda);
	}

	if (dir != -1){
		direita = arvore_procura_vertice(arvore, dir);
		vertice_set_pai(direita, vertice);
		vertice_set_dir(vertice, direita);
	}
}

void arvore_exportar_grafo_dot(const char *filename, arvore_t *grafo)
{
	
    
    
    
    
    
}

void libera_arvore(arvore_t* arvore){

	
    
    
    
}


void arvore_set_raiz (arvore_t *arvore, vertice_t* vertice){
	if (arvore == NULL){
			fprintf(stderr, "libera_arvore: arvore invalida\n");
			exit(EXIT_FAILURE);
	}

	arvore->raiz = vertice;

}

vertice_t* arvore_get_raiz (arvore_t *arvore){
	if (arvore == NULL){
			fprintf(stderr, "arvore_get_raiz: arvore invalida\n");
			exit(EXIT_FAILURE);
	}

	return arvore->raiz;
}

lista_enc_t *arvore_obter_vertices (arvore_t *arvore){

	if (arvore == NULL){
		fprintf(stderr, "arvore_obter_vertices: arvore invalida\n");
		exit(EXIT_FAILURE);
	}


	return arvore->vertices;
}

