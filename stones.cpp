#include <iostream>
#include <algorithm>
using namespace std;

int CS(int cap, int stones[] , int n){
sort(stones , stones+n);
reverse(stones , stones+n);
int st = 0 , en = n-1;
int Count = 0;
while(st<en){
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
    int stones[] = {3,5,4,2,1};
    cout<<CS(6 , stones , 6);
    return 0;
}
