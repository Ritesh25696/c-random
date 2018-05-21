#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> mat {{0,1,1},{1,0,1},{1,1,0}};

void printcommunity(int k, vector<int> lab){
    cout<<"printing community"<<endl;
    for(int j=0 ; j<mat[0].size() ; j++){
        if(mat[k][j] == 1 && lab[j] != 0)cout<<j<<",";
    }cout<<endl;
}

int main()
{

    //printing input
    for(int i=0 ; i<mat.size() ; i++){
        for(int j=0 ; j<mat[0].size() ; j++){
            cout<<mat[i][j]<<",";
        }cout<<endl;
    }
    vector<int> deg; //for storing degree of all matrix
    //storing degree of all matrix
    for(int i=0 ; i<mat.size() ; i++){
            int k = 0;
        for(int j=0 ; j<mat[0].size() ; j++){
            if(mat[i][j] == 1)k++;
        }
    deg.push_back(k);
    }
    cout<<"printing degree of all nodes"<<endl;
    for(int i=0 ; i<deg.size() ; i++)cout<<deg[i]<<" ";
    cout<<endl;
    //0 leader
    //1 follower
    //2 unlabelled
    vector<int> label(mat.size() , -1);
    vector<int> follow(mat.size() , -1);
    for(int i=0 ; i<mat.size() ; i++){
        if(deg[i] == 0){
                label[i] = 2;
                follow[i] = -1;}
        else{
            int max_deg = deg[i];
            int pos = i;
            for(int j=0 ; j<mat[0].size() ; j++){
                if(mat[i][j] == 1 && deg[j] > max_deg){
                    max_deg = deg[j];
                    pos = j;
                    label[i] = 1;
                    follow[i] = j;
                }
            }
            if(label[i] == -1){
                label[i] = 0;
                follow[i] = i;
            }
        }
    }
    cout<<"printing label "<<endl;
    for(int i=0 ; i<label.size() ; i++)cout<<label[i]<<",";
    cout<<endl;
    cout<<"printing follow "<<endl;
    for(int i=0 ; i<follow.size() ; i++)cout<<follow[i]<<",";
    cout<<endl;
    printcommunity(1 , label);

    vector<vector<int>> nmat = {{0,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> freq = {{0,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> time = {{0,1,1},{1,0,1},{1,1,1}};
    vector<int> ndeg;
    //checking if old label and follow are consistent
    // creating new degree matrix

     for(int i=0 ; i<nmat.size() ; i++){
            int k = 0;
        for(int j=0 ; j<nmat[0].size() ; j++){
            if(nmat[i][j] == 1)k++;
        }
    ndeg.push_back(k);
    }
    cout<<"printing new degree of all nodes"<<endl;
    for(int i=0 ; i<ndeg.size() ; i++)cout<<ndeg[i]<<" ";
    cout<<endl;

    bool createnew = false;
    for(int i=0 ; i<deg.size() ; i++){
        if(deg[i] != ndeg[i])
            createnew = true;
    }

    if(!createnew){
            cout<<"hey"<<endl;
        for(int i=0 ; i<nmat.size() ; i++){
        if(ndeg[i] == 0){
                if(label[i] != 2 && follow[i] != -1){
                    createnew = true;
                    break;
                }
                }
        else{
            int max_deg = ndeg[i];
            int pos = i;
            int thresholdtime = 0.5;
            int thresholdfreq = 0.5;
            for(int j=0 ; j<nmat[0].size() ; j++){
                //used case for time and frequency
                if(mat[i][j] == 1 && ndeg[i] == max_deg){

                    int timei = 0, timej = 0;
                    int freqi = 0, freqj = 0;
                    for(int k= 0 ; k<time[0].size(); k++){
                        timei += time[i][k];
                        freqi += freq[i][k];
                        timej += time[j][k];
                        freqj += freq[j][k];
                    }
                    int factori = thresholdtime*timei + thresholdfreq*freqi;
                    int factorj = thresholdtime*timej + thresholdfreq*freqj;
                }
                if(mat[i][j] == 1 && ndeg[j] > max_deg){
                    max_deg = ndeg[j];
                    pos = j;
                    if(label[i] != 1){
                        createnew = true;
                        break;
                    }
                    follow[i] = j;
                }
            }
            if(label[i] == -1){
                    if(label[i] != 0 && follow[i] != i){
                        createnew = true;
                        break;
                    }
            }
        }
    }
    cout<<"printing label "<<endl;
    for(int i=0 ; i<label.size() ; i++)cout<<label[i]<<",";
    cout<<endl;
    cout<<"printing follow "<<endl;
    for(int i=0 ; i<follow.size() ; i++)cout<<follow[i]<<",";
    cout<<endl;
    }

    if(createnew){
        for(int i=0 ; i<nmat.size() ; i++){
        if(ndeg[i] == 0){
                label[i] = 2;
                follow[i] = -1;}
        else{
            int max_deg = ndeg[i];
            int pos = i;
            for(int j=0 ; j<nmat[0].size() ; j++){
                if(nmat[i][j] == 1 && ndeg[j] > max_deg){
                    max_deg = ndeg[j];
                    pos = j;
                    label[i] = 1;
                    follow[i] = j;
                }
            }
            if(label[i] == -1){
                label[i] = 0;
                follow[i] = i;
            }
        }
    }
    cout<<"printing label "<<endl;
    for(int i=0 ; i<label.size() ; i++)cout<<label[i]<<",";
    cout<<endl;
    cout<<"printing follow "<<endl;
    for(int i=0 ; i<follow.size() ; i++)cout<<follow[i]<<",";
    cout<<endl;
    }

    return 0;
}
