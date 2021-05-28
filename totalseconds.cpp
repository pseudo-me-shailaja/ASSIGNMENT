#include <iostream>
using namespace std;

class myclass
{
    int hours;
    int minutes;
    int seconds;
    public:
    void get(int h1,int m1,int s1)
    {
        hours=h1;
        minutes=m1;
        seconds=s1;
        
    }
    void time_dis()
    {
        if(hours>=0&&hours<=9||minutes>=0&&minutes<=9||seconds>=0&&seconds<=9)
        {
            cout<<"The time is = "<<"0"<<hours<<":0"<<minutes<<":0"<<seconds<<endl;
        }
        else
        {
            cout<<"The time is = "<<hours<<":"<<minutes<<":"<<seconds<<endl;
        }
    }
    void totalsec()
    {
        int total=hours*3600+minutes*60+seconds;
        cout<<"Time in total seconds: "<<total<<endl;
    }
};

int main()
{ 
    myclass obj;
    int h;
    int m;
    int s;
    cout<<"Enter time:"<<endl<<"Hours? ";
    cin>>h;
    cout<<"Minutes? ";
    cin>>m;
    cout<<"Seconds? ";
    cin>>s;
    obj.get(h,m,s);
    obj.time_dis();
    obj.totalsec();
    
    return 0;
}
