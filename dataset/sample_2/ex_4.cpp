#include<iostream>
using namespace std;
int main()
{
    long long int t,w,c,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>w>>c;
      //  long long int a[w][w]={0};
        while(c--)
        {
            cin>>i>>j;
           // a[i][j]=1;
        }
         k=(w*(w-1))/2;
    cout<<k*k<<endl;
    }
   
}

