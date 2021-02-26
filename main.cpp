#include<iostream>
#include "itclub.h"
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
//#include<conio.h>
using namespace std;

int main()
{
    usermember obj;
    moderator o;
    int a;
    cout<<"\t\t\t IT CLUB MANAGEMENT SYSTEM"<<endl;
    cout<<"\t\t\t   WELCOME TO JU IT CLUB"<<endl;
    cout<<"\t\t\t   \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<endl;
    cout<<"\t\t\t   Login..."<<endl;
    cout<<"\t\t\t   1. General Member"<<endl;
    cout<<"\t\t\t   2. Moderator"<<endl;
    cout<<"\t\t\t   0. Exit"<<endl;
    cout<<"\t\t\t   Choose your option...";
    cin>>a;
    if(a==0)
    {
        return 0;
    }
    else if(a==1)
        obj.password();
    else if(a==2)
        o.password();
    else
        cout<<"Invalid Option!"<<endl;
        //End of main//
        //This is to update//
}

