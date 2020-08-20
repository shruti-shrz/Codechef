#include <iostream>
#include <map>
#include <cstring>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        int w, c;
        cin>>w>>c;
        map<pair<int, int>, int> points;
        ll ans = 0;
        int field[w][w];
        memset(field, 0, sizeof(field));
        for (int i=0; i<c; i++){
            int u, v;
            cin>>u>>v;
            field[u][v] = 1;
        }
        for (int i=0; i<w; i++){
            for (int j=0; j<w; j++){
                if (field[j][i]){
                    for(int k=j+1; k<w; k++){
                        if (field[k][i]){
                            auto p1 = make_pair(j, k);
                            ans += points[p1];
                            points[p1] +=1;
                            //cout<<j<<" "<<k<<endl;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
