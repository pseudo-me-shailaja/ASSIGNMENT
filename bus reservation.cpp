#include<bits/stdc++.h>
using namespace std;
static int p=0;// so that no matter in which function it is used it value will be copied once 
                //and will keep increasing 
class res
{
  char busno[5],driver[25],arrival[5],depart[5],from[15],to[15],seat[8][4][10];        //seat 3d liye since 32 =8*4 in one bust we 
                                         //can have 10 buses total 320 seats 
  public:     // function we will need
  void addBusInfo();// input bus ki details
  void empty();// assign value =empty to empty seats 
  void reserveBus();   // apne liye reserve krne ko
  void showSeatsinfo();  // yeh batayega konsi seat empty h konsi fill
  void showAvailableBuses(); // yeh buses ke bare me batayega... kaha jati h kitte baje and stuff 
  void position(int );   //yeh na sari seats ki information dega ... void showBusinfo(); me use hoga 
}bus[10];//object of res

void line(char ch)
{
   for(int i=1;i<=100;i++)
   {cout<<ch; }
   cout<<endl;
}

  // input bus ki details
void res::addBusInfo()
{   cout<<"\t\t\t\tBUS DETAILS"<<endl;
    cout<<"\t\t\t\tEnter bus number = ";
    cin>>bus[p].busno;
    cout<<"\t\t\t\tEnter driver's name = ";
    cin>>bus[p].driver;
    cout<<"\t\t\t\tEnter arrival time = ";
    cin>>bus[p].arrival;
    cout<<"\t\t\t\tEnter departure time = ";
    cin>>bus[p].depart;
    cout<<"\t\t\t\tEnter from which place = ";
    cin>>bus[p].from;
    cout<<"\t\t\t\tEnter to which place = ";
    cin>>bus[p].to;
    bus[p].empty();
    p++;         // show that value of static p can increase 
}
void res::empty()    // assign value =empty to empty seats
{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j],"Empty");

    }

  }

}
void res::reserveBus()  // apne liye reserve krne ko
{  char number[5];

   cout<<"\t\t\t\tEnter bus no :";
   top:
   cin>>number;
   int n;
   int seat;
   for(n=0;n<=p;n++)
   {
       if(strcmp(bus[n].busno,number)==0)
       break;
   }
   
   while(n<=p)
   {
     cout<<"\n\t\t\t\tEnter seat number :";
     cin>>seat;
         if(seat>32)
         {
             cout<<"\t\t\t\tThere are only 32 seats in bus"<<endl;
             //cout<<""<<endl;
         }
         else
        {
              if (strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)

               {

                 cout<<"\t\t\t\tEnter passanger's name: ";

                 cin>>bus[n].seat[seat/4][(seat%4)-1];

                 break;

               }
             else
               {
                   cout<<"\t\t\t\tbus no "<<seat<<" already booked";
               }
           
        }
    }
     if(n>p)
      {
          cout<<"\t\t\t\tEnter a correct bus number =";
          goto top;
      }
}
void res::showSeatsinfo()
{
    int n;
    char number[5];
    cout<<"\t\t\t\tEnter bus number =";
    cin>>number;
    
    for(n=0;n<=p;n++)
    {
        if(strcmp(bus[n].busno,number)==0)
        {
            break;
        }
    }
    while(n<=p)
    {
        line('*');
        cout<<"\t\t\t\tbus number="<<bus[n].busno<<endl;
        line('*');
        bus[0].position(n);
        int a=0;
        for(int i=0;i<8;i++)
        {   
            for(int j=0;j<4;j++)
            { 
              a++;
              if(strcmp(bus[n].seat[i][j],"Empty")!=0)
              {
                  cout<<"\t\t\tseat number "<<a<<" is booked by"<<bus[n].seat[i][j]<<endl;
              }
            }
        }
        break;
    }
        if(n>p)
        {
            cout<<"\t\t\t\tNo such bus available";
        }
}


void res::showAvailableBuses()
{
    for(int n=0;n<p;n++)
    {   line('-');
        cout<<"\n\t\tBus no = "<<bus[n].busno<<"\t\t\t\tDriver's name = "<<bus[n].driver;
        cout<<"\n\t\tArrival Time = "<<bus[n].arrival<<"\t\t\tDeparture Time = "<<bus[n].depart;
        cout<<"\n\t\tFrom = "<<bus[n].from<<"\t\t\tTo = "<<bus[n].to<<endl;
        
    }
}
 
void res::position(int l)
{  int s=0; int r=0;
    for(int i=0;i<8;i++)
    {  cout<<endl;
        for(int j=0;j<4;j++)
        {
          s++;
          if(strcmp(bus[l].seat[i][j],"Empty"))
          {
            cout.width(5);
            cout.fill(' ');
            cout<<s<<".";
            cout.width(10);
            cout.fill(' ');
            cout<<bus[l].seat[i][j];
            r++;
          }
          else
          {
            cout.width(5);
            cout.fill(' ');
            cout<<s<<".";
            cout.width(10);
            cout.fill(' ');
            cout<<bus[l].seat[i][j];  
          }
        }
    }
    cout<<endl<<"\t\t\t"<<r<<" seats are booked"<<endl;
    
}
int main()
{    
    int choice;
    while(1)
    {
         line('*');
         cout<<"\n\t\t\t\t";
         cout<<"    uBUS RESERVATION  "<<"\n\t\t\t\t";
         cout<<"1. INSTALL"<<"\n\t\t\t\t";
         cout<<"2. RESERVATION"<<"\n\t\t\t\t";
         cout<<"3. SHOW RESERVED SEAT"<<"\n\t\t\t\t";
         cout<<"4. SHOW DETAILS OF BUS"<<"\n\t\t\t\t";
         cout<<"5. EXIT\n";
         line('*');
         cout<<"\n\t\t\t\tEnter your choice : ";
         cin>>choice;
         line('*');
    
      switch(choice)
      {
      case 1: bus[p].addBusInfo();
              break;
      case 2: bus[p].reserveBus();
                break;
      case 3: bus[0].showSeatsinfo();
                break;            
      case 4: bus[p].showAvailableBuses();
                break;
      case 5: {cout<<"\t\t\t\tVisit Again  ";
               exit(0);}
      }
    }
    return 0;
}
