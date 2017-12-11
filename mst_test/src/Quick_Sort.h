/*
 ============================================================================
 Name        : Quick_Sort.h
 Author      : Leonardo D. Batista
 Version     : 1.0
 Description : Quick Sort Program - ANSI-Style
 ============================================================================
 */

#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

void QuickSort(int* array, int pivot_l, int pivot_r);
int partition(int* array, int pivot_l, int pivot_r);
int median(int* array, int pivot_l, int pivot_r);
//void swap(int* array_t, int a, int b); //Definido no Bubble_Sort.h

#endif //QUICK_SORT_H_INCLUDED
