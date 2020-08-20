#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll w;
        ll c;
        cin>>w>>c;
        for(ll i=0;i<c;i++)
        {
            int a,b;
            cin>>a>>b;
        }
        ll ans=(w*(w-1));
        ans*=(w-1);
        ans/=2;
        ans*=w;
        ans/=2;
        cout<<ans<<endl;
    }
}
