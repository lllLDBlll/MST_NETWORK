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
//#include "src/lista_enc.h" // Leonardo
//#include "src/no.h"	// Leonardo

void cria_adj_dados(bool input, grafo_t *g);

int main(void) {
	int i,j;

	grafo_t *g;

    char *ip = "IP: 192.168.0.254";
    char *mask = "Mask: 255.255.255.0";
    char *mac = "MAC: 00:1C:B3:09:85:15";

	g = cria_grafo(6); // cria grafo passando o número de vertices
	cria_adj_dados(0, g); // 0 - Entrada Manual || 1 - Importar de Arquivo

  	exportar_grafo_dot("prims_g.txt", g); // exporta grafo de entrada para prims

	prims(g, 0);

	exportar_grafo_dot("prims_t.txt", g); // exporta árvore de prims
/**************************************************************************************/
	g = cria_grafo(6);
	cria_adj_dados(0, g);

  	exportar_grafo_dot("kruskal_g.txt", g); // exporta grafo de entrada para kruskal

	kruskal(g, 5); // grafo e numero de vertice s

  	exportar_grafo_dot("kruskal_t.txt", g); // exporta árvore de kruskal

	libera_grafo(g);
	system("pause");
	return EXIT_SUCCESS;
}

void cria_adj_dados(bool input, grafo_t *g){
	if(input){
		importar_grafo("grafo_input.txt", g);
  		importar_dados("dados.txt", g);
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

	/*Imprimi matriz 
	int m = 5; // tamanho da matriz quadrada
	for (i=0; i < m; i++){
		for (j=0; j < m; j++)
			printf("[%d] [%d] : %d label[%d]\n", i,j, adjacente(g,i,j), adjacente_w(g, i, j));
	}
  	*/