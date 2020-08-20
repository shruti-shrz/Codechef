#include <bits/stdc++.h>
#define ppi pair<int,int>
using namespace std;

int main() {
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<int,priority_queue<ppi,vector<ppi>,greater<ppi>>> m;
        int W,C;
        cin>>W>>C;
        int arr[W][W];
        for(int i=0;i<W;i++)
        {
            for(int j=0;j<W;j++)
            {
                arr[i][j]=0;
            }
        }
        for(int i=0;i<C;i++)
        {
            int row,col;
            cin>>row>>col;
            arr[row][col]=1;
            m[col].push(make_pair(row,col));
        }
        int ans=0;
       for(int i=0;i<W;i++)
       {
           vector<ppi> v; 
           if(m.find(i)==m.end()) continue;
           while(!m[i].empty())
           {
               v.push_back(m[i].top());
               m[i].pop();
           }
           for(int j=0;j<v.size();j++)
           {
               for(int k=j+1;k<v.size();k++)
               {
                   for(int t=i+1;t<W;t++)
                   {
                       if(m.find(t)!=m.end()&&m[t].size()>=2)
                       {
                           //check
                    if(arr[v[j].first][t]==1&&arr[v[k].first][t]==1){
                    ans++;
                }
                       }
                   }
              
               }
           }
           
       }
       cout<<ans<<endl;
    }
    return 0;
}

