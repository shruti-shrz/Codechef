#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool mark[10005];

void DP(int x)
{
    if(x > 10000  ||  mark[x])return;
    mark[x]=true;
    DP(2*x);
    if((x-1)%3 == 0)DP((x-1)/3);
}

int main()
{
    FAST();
    DP(1);
    int n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(mark[n])cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

