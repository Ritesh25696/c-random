#include<iostream>
using namespace std;

void printAll(string s, int exc , int c){
    if(c == 0){
        cout<<s<<" ";
        return;
    }
    printAll(s+'1' , exc+1 , c-1);
    if(exc > 0)
    printAll(s+'0' , exc-1 , c-1);
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s = "";
	    printAll(s , 0, n);
	    cout<<endl;
	}
	return 0;
}
