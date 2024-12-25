#include <iostream>
using namespace std;
class Info
{ 
   protected:
   static int rooms[10];
   static int count;
   string name="unknown";
   int age=0,ssn=0,no_nights=0, num=0;
   const int price=200;
   public:
   void add();
   
   void remove();

};
int Info::rooms[10] ={0,0,0,0,0,0,0,0,0,0};
int Info::count=0;
void Info::remove()
{ int num=0;
  do
  {
    cout<<"select the number of rooms to remove (1:10):";
   cin >> num;
  } while (rooms[num-1]==0||num>10);
   count--;
   rooms[num-1]=0;
   for(int i=0; i<10; i++)
   {
    cout<<"room "<<i+1;
    if(rooms[i]==0)
    {
        cout<<"     available"<<endl;
    }
    else if(rooms[i]==1)
    cout<<"     not available"<<endl;
   }
   cout<<"All guests in hotel are : "<<count<<endl;
  
}

    
void Info::add()
{
    
    cout<<"Enter name:";
    cin >> name;
    cout<<"Enter age:";
    cin >> age;
    cout<<"Enter ssn:";
    cin >> ssn;
    cout<<"Enter number of nights:";
    cin>>no_nights;
    cout<<"**********************************************************"<<endl;
  for(int i=0; i<10; i++)
   {
    cout<<"room "<<i+1;
    if(rooms[i]==0)
    {
        cout<<"     available"<<endl;
    }
    else if(rooms[i]==1)
    cout<<"     not available"<<endl;
   }
   cout<<"**********************************************************"<<endl;
   do
   {
    cout<<"select number of room: ";
   cin>>num;
   } while (rooms[num-1]!=0||num>10);
   rooms[num-1]=1;
   count++;
}
class Admin :public Info
{
  private:
  int operat;
  public:
  
   Admin()
  {
    do
    {
    cout<<"(1) Add geust"<<endl;
    cout<<"(2) Remove geust"<<endl;
    cout<<"choose the number: ";
    cin>>operat;
    if(operat==1)
    {
      add();
    }
    else if(operat==2)
    {
        remove();
    }

     } while (operat!=2&&operat!=1);
  }
  friend class Guest;
};
 class Guest
{
   private:
   double rate=0;
   public:
   
    void display(Admin&t)
    {
      cout<<"**********************************************************"<<endl;
      cout<<"your name is : "<<t.name<<endl;
     cout<<"your ssn is : "<<t.ssn<<endl;
     cout<<"your age is : "<<t.age<<endl;
     cout<<"your number of room is : "<<t.num<<endl;
     cout<<"the price is : "<<t.price*t.no_nights<<"$"<<endl;

    }
   
   void Rate()
   {
    do
    {
      cout<<"Please rate the hotel (1:5): ";
     cin>>rate;
    } while (rate>5||rate<0);
   }
  ~Guest()
  {
    cout<<"Thanks for your rate!"<<endl;
    cout<<"**********************************************************"<<endl;
  }
};
int main()
{
    int choose;
    string username, password;
    char char1;
    do
    {
        do
        {
          cout<<"Hello!."<<endl;
          cout<<"Are you admin or  close the window?"<<endl;
          cout<<"(1)admin"<<endl<<"(2)close"<<endl;
         cin>>choose;
        } while (choose!=1&&choose!=2);
        if (choose==2)
        {
            break;
        }
     if(choose==1)
     {
       do
       { 
        cout<<"**********************************************************"<<endl;
         cout<<"Hi admin!"<<endl;
        cout<<"please enter your username and password: ";
        cin>>username;
        cin>>password;
       } while (username!="user1"||password!="111");
        Admin ob1;
        Guest ob2;
        cout<<"Are you want display information about guest (Y/N)"<<endl;
        cin>>char1;
        if(char1=='y'||char1=='Y')
        {ob2.display(ob1);
         ob2.Rate();
        }
     }
    }while (choose!=2);

  return 0;    
}