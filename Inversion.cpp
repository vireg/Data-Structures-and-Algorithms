#include<stdio.h>
#include<conio.h>
#include"SORT_lib.h"

int sort_n_count(int* intArray, int n)
{
    int x,y,z,n1,n2;
    if(n<=1) return 0;
    if(n%2!=0){
               n1=n/2; n2=n/2+1;
               }
    else n1=n2=n/2;
          
    x = sort_n_count(intArray,n1);
    y = sort_n_count(&intArray[n/2],n2);
    z = merge_n_countSplitInv(intArray,&intArray[n/2],n1,n2);
    return x+y+z;
}

int merge_n_countSplitInv(int* intArray1, int* intArray2, int n1,int n2)
{
    int i=0,j=0,k=0,inv_count=0,n=n1+n2,count_left;
    int tmpArr[n1+n2];
    while(k<n && i<n1 && j<n2){
        if(intArray1[i]<=intArray2[j]){
                                       tmpArr[k] = intArray1[i];
                                       k++;i++;
                                       }
        else{
             tmpArr[k] = intArray2[j];
             k++;j++;
             count_left=n1-i;
             inv_count += count_left;
             }    
    }
    if(i==n1 && j<n2) for(;k<n;k++,j++) tmpArr[k] = intArray2[j];
    else if(i<n1 && j==n2) for(;k<n;k++,i++) tmpArr[k] = intArray1[i];
    
    for(k=0;k<n;k++) intArray1[k]=tmpArr[k];
    return inv_count;
}
