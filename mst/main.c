/*
 ============================================================================
 Name        : main.c
 Author      : Leonardo Domingos Batista
 Co-Author   : Renan Augusto Starke
 Version     : 1.0
 Copyright   : IFSC - Leonardo e Renan, todos os direitos reservados
 Description : Exemplo de uma rede MST com matriz de adjacencia, ANSI-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "src/grafo.h"

void cria_adj_dados(bool input, grafo_t *g);

int main(void) {
	/*Example test parameters:
	- input files: grafo_test.txt and dados_test.txt
	- cria_grafo(15);
	- cria_adj_dados(1, g);
	- prims(g, 4);
	*/
	printf("Welcome to MST - Minimum Spanning Tree of Computer's Network\n");
	printf("Author: Leonardo Domingos Batista\n\n");

	grafo_t *g;
	grafo_t *h;

	g = cria_grafo(15); // cria grafo passando o número de vertices
	h = cria_grafo(15);

	cria_adj_dados(1, g); // 0 - Entrada Manual || 1 - Importar de Arquivo
	cria_adj_dados(1, h);
	
	printf("Graph input to Prims:\n");
  	exportar_grafo_dot("output/prims_g.txt", g); // exporta grafo de entrada para prims

  	printf("\nGraph input to Kruskal:\n");
  	exportar_grafo_dot("output/kruskal_g.txt", h); // exporta grafo de entrada para kruskal
	
	//boruvka(f);
	prims(g, 4); //(grafo, vertice)

	/*Kruskal Incomplete*/
	kruskal(h); // (grafo)	

	printf("\nTree MST output Prims:\n");
	exportar_grafo_dot("output/prims_t.txt", g); // exporta árvore de prims

	printf("\nTree MST output Kruskal:\n");
  	exportar_grafo_dot("output/kruskal_t.txt", h); // exporta árvore de kruskal

	libera_grafo(g);
	libera_grafo(h);

	system("pause"); // just for windows system
	return EXIT_SUCCESS;
}

void cria_adj_dados(bool input, grafo_t *g){
	if(input){
		importar_grafo("input/grafo.txt", g);
  		importar_dados("input/dados.txt", g);
	}else{
	    vertice_dados(g, 0, "IP: 192.168.0.254/24", "MAC: 00:1D:B3:09:85:15", "GATEWAY: 192.168.0.1/24");
	    vertice_dados(g, 1, "IP: 192.168.0.100/24", "MAC: 00:1C:B9:09:23:17", "GATEWAY: 192.168.0.1/24");
	    vertice_dados(g, 2, "IP: 192.168.0.4/33", "MAC: 3333333333333333", "GATEWAY: 192.168.0.1/24");
	    vertice_dados(g, 3, "IP: 192.168.0.4/11", "MAC: 1111111111111111", "GATEWAY: 192.168.0.1/24");
	    vertice_dados(g, 4, "IP: 192.168.0.4/00", "MAC: 0000000000000000", "GATEWAY: 192.168.0.1/24");
	    
		cria_adjacencia(g, 0, 1, 13);
		cria_adjacencia(g, 0, 2, 15);
		cria_adjacencia(g, 0, 3, 15);
		cria_adjacencia(g, 0, 4, 3);
	    cria_adjacencia(g, 1, 2, 1);
	    cria_adjacencia(g, 1, 3, 4);
	    cria_adjacencia(g, 1, 4, 4);
	    cria_adjacencia(g, 2, 3, 8);
	    cria_adjacencia(g, 2, 4, 11);
	    cria_adjacencia(g, 3, 4, 12);
	}
}