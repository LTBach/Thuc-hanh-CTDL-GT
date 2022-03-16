#include <bits/stdc++.h>
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "STDSort.h"
using namespace std;
double* a=new double[1000000];
void test_input(int i)
{
    string name = "input" + to_string(i) + ".txt";
    ifstream input(name);
    for(int j=0; j<1000000; i++)
    {
        input>>a[i];
    }
    input.close();
}
double couttime(void (*func)(double array[], int n))
{
    double* tmp=new double[1000000];
    for (int i = 0; i < 1000000; i++)
        tmp[i] = a[i];
    clock_t time_begin = clock();
    func(tmp,1000000);
    clock_t time_end = clock();
    return double(time_end - time_begin) / CLOCKS_PER_SEC * 1000;
    delete []tmp;
}
int main()
{
    ofstream output("result.txt");
    output<<"Test"<<'\t'<<"Quicksort"<<'\t'<<"Heapsort"<<'\t'<<"Mergesort"<<'\t'<<"csort"<<'\n';
    for(int i=1;i<=10;i++){
        test_input(i);
        output<<i<<'\t'<<setw(8);
        output<<couttime(QuickSort)<<"\t"<<setw(8);
        output<<couttime(HeapSort)<<"\t"<<setw(8);
        output<<couttime(MergeSort)<<"\t"<<setw(6);
        output<<couttime(STDSort)<<'\n';
    }
    output.close();
    delete[] a;
    return 0;
}
