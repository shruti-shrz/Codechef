#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c,i,s=0,j,k,a,b;
        cin>>n>>c;
        int A[c];
        int B[c];
        bool visited[n][n]={0};
        for(i=0;i<c;i++){
        cin>>A[i]>>B[i];
        visited[A[i]][B[i]]=1;
        }
        if(c=n*n)
        s=n*n*(n-1)*(n-1)/4;
        else{
       for(i=0;i<n;i++)
       {
           for(j=0;j<n;j++)
           {
               if(visited[i][j])
               {
                   for(k=i+1;k<n;k++)
                   {
                       if(visited[k][j])
                       {
                           for(a=j+1;a<n;a++)
                           {
                               if(visited[i][a] && visited[k][a])
                                 s++;
                           }
                       }
                   }
               }
           }
       }}
        cout<<s<<"\n";
    }
    return 0;
}
