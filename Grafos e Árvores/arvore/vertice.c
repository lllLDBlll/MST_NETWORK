/*
 * vertice.c
 *
 *  Created on: Jul 5, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>

#include "vertice.h"
#include "../lista_enc/lista_enc.h"

#define TRUE 1
#define FALSE 0

struct vertices {
	int id;

	vertice_t *direita;
	vertice_t *esquerda;
	vertice_t* pai;

	/* Dados associados ao vertice */
	int chave;
};


vertice_t *cria_vertice(int id)
{
	vertice_t *p = NULL;

	p = malloc(sizeof(vertice_t));

	if (p == NULL) {
		perror("cria_vertice:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->direita = NULL;
	p->esquerda = NULL;
	p->pai = NULL;

	return p;
}

int vertice_get_id(vertice_t *vertice)
{
	if (vertice == NULL)
	{
		fprintf(stderr, "vertice_obter_id: vertice invalido!\n");
		exit(EXIT_FAILURE);
	}

	return vertice->id;
}


void vertice_set_pai(vertice_t *vertice, vertice_t *pai) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_pai: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->pai = pai;
}

void vertice_set_esq(vertice_t *vertice, vertice_t *esq) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_esq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->esquerda = esq;
}

void vertice_set_dir(vertice_t *vertice, vertice_t *dir) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_esq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->direita = dir;
}


vertice_t* vertice_get_esq(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_esq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->esquerda;
}

vertice_t* vertice_get_dir(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_dir: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->direita;
}


int vertice_get_chave (vertice_t * vertice){


	if (vertice == NULL){
			fprintf(stderr, "vertice_get_freq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->chave;
}

void vertice_set_chave (vertice_t * vertice, int chave){


	if (vertice == NULL){
			fprintf(stderr, "vertice_set_freq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->chave = chave;
}

vertice_t *vertice_get_pai(vertice_t *vertice){

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_freq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->pai;
}

int vertice_eh_folha(vertice_t *vertice){

	if (vertice == NULL){
		fprintf(stderr, "eh_folha: vertice invalido\n");
		exit(EXIT_FAILURE);
	}

	if (vertice->direita == NULL && vertice->esquerda == NULL)
		return TRUE;

	return FALSE;

}
