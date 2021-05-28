# ASSIGNMENT
Developes by Shailaja Choudhary
#include <iostream>
using namespace std;

int prime(int n)
{    
    int isprime=1;
    for(int j=2;j<n;j++)
    {
        if(n%j==0)
        {   isprime=0;
            break;
        }

    }
    return isprime;
}
int main()
{  
    int a;
    cout<<"Enter the number=";
    cin>>a;
    int flag=0; 
    for(int i=2;i<=a/2;i++)
    {
        if(prime(i)==1)
        {
            if(prime(a-i)==1)
            {   
              cout<<a<<"="<<i<<"+"<<a-i<<endl;
              flag=1; 
            }
        }
    }
    if(flag==0)
    {
      cout<<"Can't express as sum of two prime number"<<endl;
    }

    return 0;
}
