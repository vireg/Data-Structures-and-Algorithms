#include<stdio.h>
#include<stdlib.h>
#include"SORT_lib.h"

int num_comp = 0;   //total number of comparisons used to sort the given input file by QuickSort

void quicksort(int* array, int arrayLength)
{
     int i;
     int* median;
     if(arrayLength<=1) return;
     //uncomment to use the final element of the given array as the pivot element
     //swap(&array[0],&array[arrayLength-1]);
     
     //uncomment to compute the pivot element using the "median-of-three" pivot rule
     /*
     if(arrayLength%2) median = findMedian(&array[0],&array[arrayLength/2],&array[arrayLength-1]);
     else median = findMedian(&array[0],&array[arrayLength/2-1],&array[arrayLength-1]);
     swap(&array[0],median);
     */
     
     int pivot = array[0];
     int part=0,ptr=1;
     for(;ptr<arrayLength;ptr++) {
                     if(array[ptr]<=pivot) 
                     swap(&array[++part],&array[ptr]);
     }
     swap(&array[part],&array[0]);                     //array[part]<=pivot
     if(part!=0 && part!=arrayLength-1){                         //pivot!=array[0] && pivot!=array[n-1]
     num_comp += part-1;
     quicksort(array,part);
     num_comp += arrayLength-part-2;
     quicksort(&array[part+1],arrayLength-part-1);
     }
     else if(pivot==array[0]){
          num_comp += arrayLength-2;
          quicksort(&array[1],arrayLength-1);
          }          
     else if(pivot==array[arrayLength-1]){
          num_comp += arrayLength-2;
          quicksort(array,arrayLength-1);
          }
}

void swap(int* a, int* b)
{
     int temp;
     temp = *a;
     *a = *b;
     *b = temp;
}

int* findMedian(int* num1,int* num2,int* num3)
{
    if( (*num2>=*num1 && *num2<=*num3) || (*num2<=*num1 && *num2>=*num3) )
    return num2;
    else if ( (*num1>=*num2 && *num1<=*num3) || (*num1<=*num2 && *num1>=*num3) )
    return num1;
    else return num3;
}

void mergesort(int* intArray, int n)
{
    int n1,n2;
    if(n<=1) return;
    if(n%2!=0){
               n1=n/2; n2=n/2+1;
               }
    else n1=n2=n/2;
          
    mergesort(intArray,n1);
    mergesort(&intArray[n/2],n2);
    merge(intArray,&intArray[n/2],n1,n2);
    
}

void merge(int* intArray1, int* intArray2, int n1,int n2)
{
    int i=0,j=0,k=0,n=n1+n2;
    int tmpArr[n1+n2];
    while(k<n && i<n1 && j<n2){            //condition k<n is redundant
        if(intArray1[i]<=intArray2[j]){
                                       tmpArr[k] = intArray1[i];
                                       k++;i++;
                                       }
        else{
             tmpArr[k] = intArray2[j];
             k++;j++;
             }    
    }
    if(i==n1 && j<n2) for(;k<n;k++,j++) tmpArr[k] = intArray2[j];      //one of the two conditions can be removed
    else if(i<n1 && j==n2) for(;k<n;k++,i++) tmpArr[k] = intArray1[i];
    
    for(k=0;k<n;k++) intArray1[k]=tmpArr[k];

}
