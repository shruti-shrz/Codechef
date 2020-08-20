#include<bits/stdc++.h>
using namespace std;
long long int limit=1000000000;
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        int val=1;
        bool temp=false;
        if(val%2==0)
        {
            temp=true;
        }
        else
        {
            long long int x=val*3+1;
            if(x%2==0)
            {
                temp=true;
            }
            else
            {
                temp=false;
            }
        }
        if(temp)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}
