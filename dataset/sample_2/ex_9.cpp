#include <iostream>
#include<string.h>
using namespace std;
int main() {
    int T,N,L;
    cin>>T;
    while(T--){
    int W,C,a,b;
    cin>>W>>C;
    int A[W][W];
    memset(A,0,sizeof(A));
    for(int i=0;i<C;i++){
        cin>>a>>b;
        A[a][b]=1;
    }
    int count=0;
    for(int i=0;i<W;i++){
        for(int j=0;j<W;j++){
               if(A[i][j]==1){
                   for(int m=j+1;m<W;m++){
    if(A[i][m]==1){for(int t=i+1;t<W;t++){if(A[t][j]==1 && A[t][m]==1){count
        ++;}}
                           
                       }
                   }
                   
               }
        }
    }
    cout<<count<<endl;
    }
    return 0;
}
