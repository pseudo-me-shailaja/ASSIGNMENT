# ASSIGNMENT
Developes by Shailaja Choudhary

#include<iostream>
using namespace std;

int main()
{   int *ptr=NULL;

    int x[5];
    cout<<"Enter number:";
     for(int i=0;i<5;i++)
    {  
        cin>>x[i];
    }
    ptr=&x[0]; 
    cout<<"You entered:";
    for(int i=0;i<5;i++)
    {  
        cout<<*ptr<<endl;
        ptr++;
    }
    return 0;
}
