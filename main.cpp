#include <iostream>
#include <fstream>
using namespace std;

void Register()
{
    string username, password;
    cout<<"Create a username: \n";
    cin>>username;
    cout<<"Create a password: \n";
    cin>>password;

    ofstream file(username + ".txt");
    file<<username;
    file<<endl;
    file<<password;
    cout<<"Registered successfully\n";
    file.close();
}

bool isLoggedIn()
{
    string username, password;
    string u,p;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    ifstream obj(username + ".txt");
    obj>>u;
    obj>>p;

    if(u==username && p==password)
        return true;
    else
        return false;
}

int main()
{
    int x;
    cout << "1.Registration\n";
    cout << "2.Login\n";
    cout << "Enter your choice: ";
    cin >> x;

    switch(x)
    {
    case 1:
        Register();
        main();
        break;

    case 2:

        bool status;
        status = isLoggedIn();

        if(status == 0)
        {
            cout<<"Login Failed!!!\nEnter valid details\n";
            return 0;
        }
        else
        {
            cout<<"Login Successfull\n";
            return 1;
        }
        break;

    default:
        cout<<"Enter Valid choice\n";
    }
}
