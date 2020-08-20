#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 998244353ll 
#define pb push_back
#define vl vector<ll>
#define pll pair<ll,ll>
#define mp make_pair
using namespace std;
#define pi (long double)3.14159265358979323846 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1; 
    x = x % p;  
    while (y > 0) 
    {
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll w,c;
        cin>>w>>c;
        ll pos[c][2];
        for(ll i=0;i<c;i++)
        {
            cin>>pos[i][0]>>pos[i][1];
        }
        ll ans = (w*(w-1))/2;
        ans *= ((w-1)*w)/2;
        cout<<ans<<endl;
    }
}
