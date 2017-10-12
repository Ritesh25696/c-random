#include<iostream>
#include<vector>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n,-1);
        for(int i=0 ; i<n-1 ; i+=2){
            cin>>A[i];
        }
        for(int i=1 ; i<n ; i+=2){
            cin>>A[i];
        }
        if(n%2 != 0){
            cin>>A[n-1];
        }
        for(int i=0 ; i<n ; i++)cout<<A[i]<<" ";
        cout<<endl;
    }
	return 0;
}
