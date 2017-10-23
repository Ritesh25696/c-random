#include <iostream>
#include<cmath>
using namespace std;

int MinMemory(int arr[] , int n){
    long long sum =0;
    int k=0;
    for(int i=0 ; i<n ; i++){
        sum+=arr[i];
    }
    while(sum != 0){
        sum/=2;
        k++;
    }
    int res = 1;
    for(int i=0 ; i<k ; i++)res*=2;
    return res;
}

int main()
{
    int arr[] =  {4,35,4,9};
    cout<<MinMemory(arr,4);
}
