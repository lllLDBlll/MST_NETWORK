/*
 ============================================================================
 Name        : Quick_Sort.c
 Author      : Leonardo D. Batista
 Version     : 1.0
 Description : Quick Sort Program - ANSI-Style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Bubble_Sort.h"
#include "Quick_Sort.h"
//#define DEBUG

/*
#ifdef DEBUG
    printf("Something is wrong!");
#endif
*/
void QuickSort(int *array, int pivot_l, int pivot_r){
    int p;
    if (array == NULL) {
      perror("QuickSort:");
        exit(1);
    }

    if (pivot_l < pivot_r){
      p = partition(array, pivot_l, pivot_r);
      QuickSort(array, pivot_l, p);
      QuickSort(array, p + 1, pivot_r);
    }
}

int partition(int* array, int pivot_l, int pivot_r){
    int med, pivot, i, j;

    if (array == NULL) {
      perror("main:");
      exit(1);
    }

    med = median(array, pivot_l, pivot_r); //Calcula a mediana do vetor O(3)

    pivot = array[med]; //Pivô do meio
    i = pivot_l - 1;  //Retira do vetor os pivôs laterais
    j = pivot_r + 1;  

    for(;;){
      do{
      i = i + 1;
      }while (array[i] < pivot);

      do{
      j = j - 1;
      }while (array[j] > pivot);

      if (i >= j){
        return j;
      }
      swap(array, i, j);
    }
}

int median(int* array, int pivot_l, int pivot_r){
  int med;
  med = (pivot_l + pivot_r)/2;
  if (array[pivot_r] < array[pivot_l]){
    swap(array, pivot_l, pivot_r);
  }
  if (array[med] < array[pivot_l]){
    swap(array, med, pivot_l);
  }
  if (array[pivot_r] < array[med]){
    swap(array, pivot_r, med);
  }
  return med;
}

/*
// Definido no Bubble_Sort.h
void swap(int* array_t, int a, int b){
    int c = array_t[a];
    array_t[a] = array_t[b];
    array_t[b] = c;
}*/
