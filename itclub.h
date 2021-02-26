#ifndef ITCLUB_H
#define ITCLUB_H
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<conio.h>
using namespace std;
enum ampm{AM, PM};
struct time
{
    int h, m;
    ampm ap;
};
class Time
{
private:
    int hr, min;
    ampm ap;
public:
    void input();
    void output() const;
    Time operator - (Time t2) const;
};
void Time::input()
{
    string str;
    cin>>hr>>min;
    cin>>str;
    if(str=="AM") ap=AM;
    if(str=="PM") ap=PM;
}
void Time :: output() const
{
    cout<<"Hour: "<<hr<<"    Min: "<<min<<endl;
}
Time Time :: operator - (Time t2) const
{
    int x1,x2;
    x1 = hr*60+min;
    x2 = t2.hr*60+t2.min;
    if(ap == PM) x1=x1+(12*60);
    if(t2.ap == PM) x2=x2+(12*60);
    int time_difference=(x2-x1);
    if(time_difference<0)time_difference=time_difference+(24*60);
    Time dif;
   dif.hr = time_difference/60;
   dif.min = time_difference%60;
    return dif;
}
class Event:public Time
{
protected:
    string title, ven, date;
    int part, room;
    int hr1, min1, hr2, min2;
    string str1, str2;
public:
    Event():title(""),part(0),room(0) {}
    void getevent();
    void showevent();
};
void Event::getevent()
{
    fstream file;
    file.open("event.txt", ios::out|ios::app);
        cout<<"\t\t\t   Enter event title: ";
        cin>>title;
        file<<title<<' ';
        cout<<"\t\t\t   Enter event venue: ";
        cin>>ven;
        file<<ven<<' ';
        cout<<"\t\t\t   Enter event starting time: ";
        cin>>hr1>>min1;
        cin>>str1;
        file<<hr1<<' '<<min1<<' '<<str1<<' ';
        cout<<"\t\t\t   Enter event ending time: ";
        cin>>hr2>>min2;
        cin>>str2;
        file<<hr2<<' '<<min2<<' '<<str2<<' ';
        cout<<"\t\t\t   Enter event date(dd/mm/yyyy): ";
        cin>>date;
        file<<date<<' ';
        cout<<"\t\t\t   Enter number of participants: ";
        cin>>part;
        file<<part<<' ';
        cout<<"\t\t\t   Enter room number: ";
        cin>>room;
        file<<room<<'\n';
        cout<<"\t\t\t   Event created Successfully!"<<endl;
        file.close();
}
void Event::showevent()
{
    int size;
    ifstream file;
    file.open("event.txt", ios::in|ios::binary);
    if(file.peek() == std::ifstream::traits_type::eof())
    {
        cout<<"\t\t\t   No Upcoming Events"<<endl;
    }
    else
        {
            file>>title>>ven>>hr1>>min1>>str1>>hr2>>min2>>str2>>date>>part>>room;
        while(!file.eof())
            {
            cout<<endl<<"\t\t\t   \xcd\xcd\xcd\xcd\xcd\xcdUpcoming Event\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
            cout<<endl<<"\t\t\t   Event Name: "<<title<<endl;
            cout<<"\t\t\t   Event Venue: "<<ven<<endl;
            cout<<"\t\t\t   Event Time: "<<hr1<<" "<<min1<<" "<<str1<<" to "<<hr2<<" "<<min2<<" "<<str2<<endl;
            cout<<"\t\t\t   Event Date: "<<date<<endl;
            cout<<"\t\t\t   Participants: "<<part<<endl;
            cout<<"\t\t\t   Room No: "<<room<<endl;
            file>>title>>ven>>hr1>>min1>>str1>>hr2>>min2>>str2>>date>>part>>room;
            }
        }
    file.close();
}
class person
{
protected:
    string name;
    int id;
    string dept;
    string phone;
public:
    void addmember();
    void viewmember();
    virtual void show()
    {
        cout<<"Person"<<endl;
    }
};
void person::addmember()
{
    char c;
    fstream file;
    file.open("member.txt", ios::out|ios::app|ios::binary);
    do
    {
        cout<<"\t\t\t   Member's Name: ";
        cin.ignore();
        getline(cin, name);
        file<<name<<' ';
        cout<<"\t\t\t   Member's ID: ";
        cin>>id;
        file<<id<<' ';
        cout<<"\t\t\t   Member's Department: ";
        cin.ignore();
        getline(cin, dept);
        file<<dept<<' ';
        cout<<"\t\t\t   Member's Phone Number: ";
        cin>>phone;
        file<<phone<<' ';
        cout<<"\t\t  Do you want to another(y/n)?   ";
        cin>>c;
    }while(c!='n');
    file.close();
}
void person::viewmember()
{
    fstream file;
    file.open("member.txt", ios::in|ios::binary);
    if (file.peek()==std::ifstream::traits_type::eof())
    {
        cout<<"\t\t\t   No Member in the File!"<<endl;
    }
    else
   {
    file>>name>>id>>dept>>phone;
    while(!file.eof())
    {
        cout<<"Member Name: "<<name<<endl;
        cout<<"Member ID: "<<id<<endl;
        cout<<"Member Department: "<<dept<<endl;
        cout<<"Member Phone Number: "<<phone<<endl;
        file>>name>>id>>dept>>phone;
    }
   }
    file.close();
}
class usermember:public person, public Event
{
private:
    string passwor;
public:
    usermember():passwor("mem") {}
    void password();
    void usermenu();
    void show()
    {
        cout<<"User"<<endl;
    }
};
void usermember::password()
{
    string pass;
    char ch;
    cout<<"\t\t\t   Enter the password to login: ";
    ch=_getch();
    while(ch!=13)
    {
        pass.push_back(ch);
        cout<<'*';
        ch=_getch();
    }
    if(pass==passwor)
    {
        cout<<endl<<"\t\t\t   Password Matched!!"<<endl<<endl;
        usermenu();
    }
    else
    {
        cout<<"\t\t\t   Invalid Password!!"<<endl;
        cout<<"\t\t\t   Enter correct password."<<endl;
        password();
    }
}
void usermember::usermenu()
{
    int choice;
    cout<<"\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MAIN MENU \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
    cout<<"\t\t\t   1. View All Members"<<endl;
    cout<<"\t\t\t   2. View Upcoming Event"<<endl;
    cout<<"\t\t\t   3. Close application\n";
    cout<<"\t\t\t    Enter Your Option: ";
    cin>>choice;
    cout<<"\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
    if(choice==1)
    {
person:
        viewmember();
    }
    else if(choice==2)
    {
Event:
        showevent();
    }
    else if(choice==3)
    {
         cout<<"\t************************Thank You******************************"<<endl;
        return;
    }
}
class moderator:public person, public Event
{
private:
    string passwrd;
public:
    moderator():passwrd("mod") {}
    void password();
    void moderatormenu();
    void show()
    {
        cout<<"Moderator"<<endl;
    }
};
void moderator::password()
{
    string pass;
    char ch;
    cout<<"\t\t\t   Enter the password to login: ";
    ch=_getch();
    while(ch!=13)
    {
        pass.push_back(ch);
        cout<<'*';
        ch=_getch();
    }
    if(pass==passwrd)
    {
        cout<<endl<<"\t\t\t   Password Matched!!"<<endl<<endl;
        moderatormenu();
    }
    else
    {
        cout<<"\t\t\t   Invalid Password!!"<<endl;
        cout<<"\t\t\t   Enter correct password."<<endl;
        password();
    }
}
void moderator::moderatormenu()
{
    int choice;
    cout<<"\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd MAIN MENU \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
    cout<<"\t\t\t   1. Add a Member"<<endl;
    cout<<"\t\t\t   2. Delete All Members"<<endl;
    cout<<"\t\t\t   3. Create an Event"<<endl;
    cout<<"\t\t\t   4. view upcoming Event"<<endl;
    cout<<"\t\t\t   5. Delete all Events"<<endl;
    cout<<"\t\t\t   6. Close application"<<endl;
    cout<<"\t\t\t      Enter Your Option: ";
    cin>>choice;
    cout<<"\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
    if(choice==1)
    {
     person:addmember();
    }
    else if(choice==2)
    {
        remove("member.txt");
        cout<<"\t\t\t   Member list has been deleted"<<endl;
    }
    else if(choice==3)
    {
        getevent();
    }
    else if(choice==4)
    {
        showevent();
    }
    else if(choice==5)
    {
        remove("event.txt");
        cout<<"\t\t\t   Event list has been deleted"<<endl;
    }
    else if(choice==6)
    {
        cout<<"\t************************Thank You******************************"<<endl;
        return;
    }
}

#endif // ITCLUB_H
