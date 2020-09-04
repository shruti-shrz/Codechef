<<<<<<< HEAD
#include <bits/stdc++.h> 
using namespace std; 
  
void printFun(int test) 
{ 
    if (test < 1) 
        return; 
    else { 
        cout << test << " ";
        test = test - 1;
        printFun(test);
        return; 
    } 
} 
  
int main() 
{ 
    int test = 3; 
    printFun(test); 
    for(int i=0;i<3;i++)
    {
        cout << "hello";
    }
} 
=======
#include<iostream>

using namespace std;

int main(){
    int a = 5;
    int b = 6;
    int c = a*b;
    cout<<c<<"\n";
}
>>>>>>> c94df1d088c834a7ed4e48b2f8f6a5be1e4dfcb4
