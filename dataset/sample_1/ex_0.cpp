#include <bits/stdc++.h>
using namespace std;

int main() {
long long int t,x;
cin>>t;
while(t!=0)
{
    cin>>x;
    if(x==0)
    cout<<"No";
    else
    {
    long long int k=log2(x);
    if(pow(2,k)==x)
    cout<<"Yes";
    else
    {
        while(x%2==0)
        {
            x/=2;
        }
        x=x*3+1;
        k=log2(x);
        if(pow(2,k)==x)
        cout<<"Yes";
        else
        {
            
        if(x%2!=0)
        cout<<"No";
        else
        {
            while(x%2==0)
            {
                x/=2;
            }
             x=x*3+1;
        k=log2(x);
        if(pow(2,k)==x)
        cout<<"Yes";
        else
        cout<<"No";
        }
        }
    }
    }
    cout<<endl;
    t--;
}
    return 0;
}
