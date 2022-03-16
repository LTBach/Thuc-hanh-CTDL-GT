#include <bits/stdc++.h>
using namespace std;
int partition(double arr[],int low,int high)
{
    double pivot=arr[high];
    int i=(low - 1);
 
    for (int j=low;j<=high-1;j++){
        if (arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void QuickSort(double arr[],int low,int high)   //quickSort(a,0,n-1);
{
    if (low<high){
        int pi=partition(arr, low, high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}
void QuickSort(double a[], int n)
{
    QuickSort(a,0,n-1);
}
