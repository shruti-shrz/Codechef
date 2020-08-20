#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long t, n, m, i, j, f, k, l;
    cin>>t;
    
    for(;t--;)
    {
        long long cou=0;
        cin>>n>>f;
        bool v[n][n];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                v[i][j]=false;
            }
        }
        long r[f], c[f];
        
        for(i=0; i<f; i++)
        {
            cin>>r[i]>>c[i];
            v[r[i]][c[i]]=true;
        }
        
        for(i=0; i<f; i++)
        {
            for(j=i+1; j<f; j++)
            {
                if(v[r[i]][c[j]]==true && v[r[j]][c[i]]==true && r[i]!=r[j] && 
                    c[i]!=c[j])
                {
                    cou++;
                }
            }
            
        }
        cout<<cou/2<<endl;
        
        
        
    }
}
