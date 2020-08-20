#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int f=0;
        while(ceil(log2(n)) == floor(log2(n)))
        {
                n=(n*3)+1;
                if(n<0)
                {
                    f=1;
                    break;
                }
        }
        if(f==0)
            cout<<"Yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}
