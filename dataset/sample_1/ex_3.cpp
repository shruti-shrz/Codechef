#include <bits/stdc++.h>
using namespace std;
#define int       long long
#define w(x)      int x;cin >> x;while (x--)
#define rep(d,a,n)  for(int d=a;d<=n;d++) 
const int inf=1e18;
void oj()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return;
}

int check(int num){
    int cont=2000;
    while(cont-- && num!=1){
        if(num%2==0){
            num/=2;
        }else{
            num*=3;
            num++;
            if(num%2==0){num/=2;}
            else{return -1;}
        }
    }
    return num;
}
int32_t main()
{
    // oj();
    w(t){
        int n;
        cin>>n;
        int ans=check(n);
        if(ans==1){
            cout<<"Yes\n";
        }else if(ans==-1){
            cout<<"No\n";
        }else{
            cout<<"No\n";
        }    
    }
    return 0;
}
