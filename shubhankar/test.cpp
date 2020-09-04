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