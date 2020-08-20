#include<bits/stdc++.h>
using namespace std;
unsigned short T,W,C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--)
    {
        cin>>W>>C;
        cout<<(W-1)*(W-1)*W*W/4<<"\n";
        while(C--)
            cin>>W>>W;
    }
    return 0;
}
