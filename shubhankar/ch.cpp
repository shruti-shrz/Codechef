#include <iostream>
using namespace std;
void fun(int k)
{
    if(k==0)
        return 1;
    if(k==1)
        return 1;
    return fun(k-1) + fun(kk-2);
} 

int main() {
        // your code goes here
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            int arr[n],sum=0;
            for(int i=0;i<n;i++)
            {
                cin>>arr[i];
                sum=sum+arr[i];
            }
            if(sum%n==0)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        return 0;
}