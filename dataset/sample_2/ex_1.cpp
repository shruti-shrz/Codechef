#include <iostream>
using namespace std;

int main() {
    // your code goes here
   long long int t,i,j;
    cin>>t;
    while(t--)
    {
        long long int w,c;
        cin>>w>>c;
        while(c--)
        cin>>i>>j;
        cout<<w*w*(w-1)*(w-1)/4<<endl;
    }
    return 0;
}

