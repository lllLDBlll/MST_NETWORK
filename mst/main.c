/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Leonardo Domingos Batista
 Co-Author   : Renan Augusto Starke
 Version     : 1.0
 Copyright   : IFSC - Leonardo e Renan, todos os direitos reservados
 Description : grafos com matriz de adjacencia, ANSI-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"
#include "lista_enc.h" // Leonardo
#include "no.h"	// Leonardo

int main(void) {
	int i,j;
	grafo_t *g;

	g = cria_grafo(4); //Número de vertices

	/*    Adicionar arestas    */
	/* 		Leonardo           */

	no_t* elemento = NULL;
    lista_enc_t* lista = NULL;

    char *ip = "IP: 192.168.0.254";
    char *mask = "Mask: 255.255.255.0";
    char *mac = "MAC: 00:1C:B3:09:85:15";
    int k = 1921680254;
    int *test;
    test = &k; // *test = 10
    //printf("ptr: %d\n", *test);

    lista = cria_lista_enc();
    //MST -> Peso(Weight) - Source(scr) e Destiny(dest)
    //cria_adjacencia(grafo, vertice, vertice) nao eh direcional esse metodo
    //Usar rem_adjacencia(); e também adjacente(grafo_t *g, int u, int v){
    //Verificar as variaveis nas structs
    //acrescentar no struct vertice id a posição dos vertices adj em arestar tambem

	cria_adjacencia(g, 0, 1, 10, "nothing", "nothing");
	elemento = cria_no((void*)ip);
    add_cauda(lista, elemento);

	cria_adjacencia(g, 0, 2, 20, "nothing", "nothing");
	elemento = cria_no((void*)mask);
    add_cauda(lista, elemento);

	cria_adjacencia(g, 1, 2, 5, ip, mac);
	elemento = cria_no((void*)mac);
    add_cauda(lista, elemento);
    
    vertice_datas(g, 0, "IP: 192.168.0.254/24", "MAC: 00:1D:B3:09:85:15", "GATEWAY: 192.168.0.1/24");
    vertice_datas(g, 1, "IP: 192.168.0.100/24", "MAC: 00:1C:B9:09:23:17", "GATEWAY: 192.168.0.1/24");
    vertice_datas(g, 2, "IP: 192.168.0.4/24", "MAC: 00:3C:A3:02:85:16", "GATEWAY: 192.168.0.1/24");
    //vertice_datas(g, 3, "IP: 192.168.0.4/24", "MAC: 00:3C:A3:02:85:16", "GATEWAY: 192.168.0.1/24");

	prims(g, 0);

  	imprimi_lista(lista);
  	exportar_grafo_dot("Rapaz.txt", g); //graph.dot

	/* Imprimi matriz */
	int m = 4; // tamanho da matriz quadrada
	/*for (i=0; i < m; i++){
		for (j=0; j < m; j++)
			printf("[%d] [%d] : %d label[%d]\n", i,j, adjacente(g,i,j), adjacente_w(g, i, j));
	}
*/
	libera_grafo(g);
	system("pause");
	return EXIT_SUCCESS;
}
