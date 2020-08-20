#include<bits/stdc++.h>
using namespace std;

int main() {

ios_base :: sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int i,j,a,b,num,w,t,x,y;
cin>>t;
while(t--){
    
    cin>>w>>num;
    char arr[w+1][w+1];
    for(i=0;i<w;i++){
        for(j=0;j<w;j++){
            arr[i][j]='.';
        }
    }
    while(num--){
        cin>>x>>y;
        arr[x][y]='*';
    }
    int c=0;
    for(i=0;i<w;i++){
        for(j=0;j<w;j++){
            for(a=i+1;a<w;a++){
                for(b=j+1;b<w;b++){
                    if(arr[i][j]=='*' and arr[a][b]=='*' and arr[a][j]=='*' and 
                        arr[i][b]=='*'){
                        c++;
                    }
                }
            }
        }
    }
    cout<<c<<endl;
    
    
}


return 0;
}
