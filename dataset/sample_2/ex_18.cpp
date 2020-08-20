#include<bits/stdc++.h>
using namespace std;

int main()
{
     
     int t,n,c,x,y;
     vector< pair<int,int> > pairs; 
     cin >> t;
     //long int memo[1010][1001]; 
     
     for(int i = 0 ; i < t ; i ++)
     {  
         //memset(memo,0l,sizeof memo); 
         cin >> n >> c ;
         pairs.clear();
         
         vector<vector<int>> memo(n+1,vector<int>(n+1,0)); 
         
         for(int i = 0 ; i < c ; i ++) {
             cin >> x >> y ;
             pairs.push_back({x,y});
         }
         
         long int res = 0 ;
         for(auto &p1: pairs )
           for(auto &p2: pairs)
           {
               if( (p1.first == p2.first) and ( p1.second < p2.second ) )
               {
                  //res += memo[p1.second][p2.second];
                  memo[p1.second][p2.second] += 1; 
               }
           }
         
         for(int i = 0 ; i < n ; i ++)
            for(int j = i+1 ; j < n ; j ++)
            {   
                long int t = memo[i][j];
                auto tt = (t * (t-1) ) /2 ; 
                res += tt ; 
            }
         cout << res << endl; 
     }


    return 0;
}

