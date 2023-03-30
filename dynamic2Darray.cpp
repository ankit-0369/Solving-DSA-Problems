#include<bits/stdc++.h>

using namespace std;

int main(){
 int m;
 cin>>m;
 int** twodarr= new int*[m];
  for(int i=0; i<m; i++){
    
    
    twodarr[i]= new int[5];
    //to input array
    for(int j=0; j<5; j++){
        cin>>twodarr[i][j];
    }
  }
    for(int i=0; i<m; i++){

        for(int j=0; j<5; j++){
            cout<<twodarr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    for(int i=0; i<m; i++){
        delete [] twodarr[i];
    }
    delete [] twodarr;
return 0;
}