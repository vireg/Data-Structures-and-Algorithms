#ifndef SORT_lib_H
#define SORT_lib_H

void mergesort(int*,int);
void merge(int*,int*,int,int);
void swap(int*,int*);
void quicksort(int*,int);
int* findMedian(int*,int*,int*);

//Functions for counting inversions
int sort_n_count(int*,int);
int merge_n_countSplitInv(int*,int*,int,int);

#endif
