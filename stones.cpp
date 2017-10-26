#include <iostream>
#include <algorithm>
using namespace std;


void rvereseArray(int arr[], int start, int end)
{
   int temp;
   if (start >= end)
     return;
   temp = arr[start];
   arr[start] = arr[end];
   arr[end] = temp;
   rvereseArray(arr, start+1, end-1);
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int CS(int cap, int stones[] , int n){

quickSort(stones , 0 ,n);
rvereseArray(stones ,0 ,n-1);
int st = 0 , en = n-1;
int Count = 0;
while(st<=en){
    if(stones[st] + stones[en] <= cap){
        st++; en--; Count++;
    }
    else{
        st++;
        Count++;
    }

}
return Count;
}

int main()
{
    int stones[] = {50, 32, 81, 63};
    cout<<CS(90 , stones , 4);
    return 0;
}
