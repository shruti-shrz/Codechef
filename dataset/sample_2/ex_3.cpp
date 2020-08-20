#include<bits/stdc++.h>
using namespace std;

#define sync {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define ll long long int
#define mod 1000000007

int w,c;

void solve()
{
    cin>>w>>c;
    int i,j;
    while(c--)
        cin>>i>>j;
    
    ll ans = (w*w*(w-1)*(w-1))/4;
    cout<<ans;
}

int main()
{
    sync;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}






