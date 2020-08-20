#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int w,c,i,j,s=0,a;
        cin>>w>>c;
        a=c;
        while(a--)
        {
            cin>>i>>j;
        }
        //cout<<i<<","<<(w*w)<<endl;
        if(c==(w*w))
        {
            for(i=w-1;i>=2;i--)
            {
                for(j=i-1;j>=1;j--)
                {
                    s=s+i*j;
                }
            }
            s=2*s;
            s=s+((w-1)*w*(2*w-1))/6;
            cout<<s<<endl;
        }
    }
    // your code goes here
    return 0;
}

