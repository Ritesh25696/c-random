// C++ program to demonstrate __builtin_popcount()
#include <bits/stdc++.h>
using namespace std;

vector<long> maxMin(vector<string> operations, vector<int> x){
    vector<long> res;
    set<long> s;
            for(int i=0 ; i<operations.size() ; i++){
            if(operations[i] == "push"){
            s.insert(x[i]);
        }
        else if(operations[i] == "pop"){
            s.erase(x[i]);
        }
        res.push_back((*s.begin())*(*s.rbegin()));
    }
    return res;
}

int main()
{
vector<string> s {"push","push","push","pop"};
vector<int> p {1,2,3,1};
vector<long> res = maxMin(s,p);
for(int i=0  ; i<res.size() ; i++)cout<<res[i];

return 0;
}
