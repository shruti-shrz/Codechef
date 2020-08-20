#include<bits/stdc++.h>
#define fastio     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x)     (x).begin() , (x).end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define endl       '\n'
#define MAX        1000000
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
typedef long long int ll;
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; 
    __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ 
    ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v
    ...);}


const ll mod = 1e9+7;
const double eps = 1e-9;



void solve(){
    ll a,b;
    cin>>a>>b;
    if(b<a)swap(a,b);
    int ans=0;
    bool flag=1;
    while(b!=a) {
        ans++;
       if((b&1)==0)b>>=1;
       else if(b&1)break;
    }
    flag=(a==b);
    if(ans==0) {
        cout<<0<<"\n";
        return;
    }
    if(flag) {
        int cur=0;
        //debug(ans);
        while(ans>=3) {
            ans-=3 , cur++;
        }
        while(ans>=2) {
            ans-=2 , cur++;
        }
        while(ans>=1) {
            ans-=1 , cur++;
        }
        cout<<cur<<"\n";
    }
    else cout<<-1<<"\n";

}


const int maxN=501;
int n,t;
int arr[maxN][maxN];

int df(int r,int c) {
    int ans=0;
    vector<int>v,d;
    for(int i=c+1;i<n;i++) {
        if(arr[r][i])v.push_back(i);
    }
    for(int i=r+1;i<n;i++) {
        if(arr[i][c])d.push_back(i);
    }
    for(int i=0;i<(int)v.size();i++) {
        for(int j=0;j<(int)d.size();j++) {
            if(arr[d[j]][v[i]])ans++; 
        }
    }
    return ans;
}

void sec() {
    cin>>n>>t;
    for(int i=0;i<t;i++) {
        int a,b;
        cin>>a>>b;
        arr[a][b]=1;
    }


    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]) {
                ans+=df(i,j);
            }
        }
    }
    cout<<ans<<"\n";

    
}






int main(){
    fastio
    int test=1;
    cin>>test;
    while(test--)
        sec();
    return 0;
}

