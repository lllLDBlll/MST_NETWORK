/*
 ============================================================================
 Name        : Minimum Spannig Tree - MST
 Application : Computer Networking Topology
 Author      : Leonardo D. Batista
 Version     : 1.0
 Copyright   : Renan Augusto Starke, todos os direitos reservados
 Description : grafos com lista encadeadas, ANSI-style
             : estruturas disponiveis:
             : pilha e fila
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "pilha/pilha.h"
#include "fila/fila.h"
#include "grafo/grafo.h"

int main(void) {

	grafo_t *grafo;
	vertice_t* vertice;

	fila_t *fila;
	int id;

	grafo = cria_grafo(0);
	fila = cria_fila();
	//Adiciona todos os vertices no grafo
	for(int i = 1; i <= 4; i++){ // i = 1 ?
		vertice = grafo_adicionar_vertice(grafo, i);
		enqueue(vertice, fila);
	}
	/*
	vertice = grafo_adicionar_vertice(grafo, 1);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 2);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 3);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 4);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 5);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo, 6);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,7);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,8);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,9);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,10);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,11);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,12);
	enqueue(vertice, fila);

	vertice = grafo_adicionar_vertice(grafo,13);
	enqueue(vertice, fila);
	*/

        // constrói grafo
	//adiciona_adjacentes(grafo, vertice, n_param, vertice_d, peso, vertice_d, peso, vertice_d, peso);
	while (!fila_vazia(fila))	{
		vertice = dequeue(fila);
		id = vertice_get_id(vertice);
		switch(id){
			case 1:
				adiciona_adjacentes(grafo, vertice, 6, 2, 1, 3, 5, 4, 7);
				break;
			case 2:
				adiciona_adjacentes(grafo, vertice, 6, 1, 1, 3, 3, 4, 2);
				break;
			case 3:
				adiciona_adjacentes(grafo, vertice, 6, 1, 5, 2, 3, 4, 1);
				break;
			case 4:
				adiciona_adjacentes(grafo, vertice, 6, 1, 7, 2, 2, 3, 1);
				break;
			default:
				break;
		}
	}

	exportar_grafo_dot("grafo.dot", grafo);

	importar_grafo_dot("grafo_input.dot"); //Add Leonardo
	
	puts("MAIN");
	system("pause");

	libera_fila(fila);
	libera_grafo(grafo);
	return EXIT_SUCCESS;
}

