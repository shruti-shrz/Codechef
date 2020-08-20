#include<bits/stdc++.h>
using namespace std;

int main()
{
     
     int t,n,c,x,y;
     vector< pair<int,int> > pairs; 
     cin >> t;
     //long int memo[1010][1001]; 
     
     for(int tt = 0 ; tt < t ; tt ++)
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
                  res += memo[p1.second][p2.second];
                  memo[p1.second][p2.second] += 1; 
               }
           }
         
         
         cout << res << endl; 
     }


    return 0;
}

