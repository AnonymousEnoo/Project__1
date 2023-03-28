#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class Master
{
    int no_of_seats;
    int fare;
    string Train_no;
    string source;
    string destination;

public:
    void set_data()
    {
        cout << "Enter train No:" << endl;
        cin >> Train_no;
        cout << "Enter source staion:" << endl;
        cin >> source;
        cout << "Enter destination staion:" << endl;
        cin >> destination;
        cout << "Enter total no. of seats:" << endl;
        cin >> no_of_seats;
        cout << "Enter fare" << endl;
        cin >> fare;
        ofstream out;
        out.open(Train_no);
        out << Train_no << endl;
        out << no_of_seats << endl;
        out << source << endl;
        out << destination << endl;
        out << fare << endl;
        out.close();
        cout << "Train information Added into database ";
    }
};
int Check_Train(string Train_no)
{
    string train_no;
    ifstream in;
    in.open(Train_no);
    getline(in, train_no);
    in.close();
    if (train_no == Train_no)
    {
        return 0;
    }
    return 1;
}
void display(string train)
{
    string a, b, c, d;
    int e;
    ifstream in;
    in.open(train);
    getline(in, a);
    getline(in, b);
    getline(in, c);
    getline(in, d);
    in >> e;
    in.close();
    cout << "Train no." << a << endl;
    cout << "From " << c
         << " To " << d << endl;
    cout << "No. of seats left : " << b << endl;
    cout << "fare : " << e << endl;
}
int booking()
{
    string train;
    cout << "Please enter train no: ";
    cin >> train;
    if (Check_Train(train))
    {
        cout << "No such train found";
        exit(0);
    }
    cout << "Train details" << endl;
    display(train);
    int no_of_seats;
    int fare;
    string Train_no;
    string source;
    string destination;
    ifstream out;
    out.open(train);
    getline(out, Train_no);
    out >> no_of_seats;
    out >> source;
    out >> destination;
    out >> fare;
    out.close();
    int a, b;
    cout << "Enter the no. of seats want to book: ";
    cin >> a;
    no_of_seats = no_of_seats - a;
    b = a * fare;
    cout << "Seats booked " << a << endl;
    cout << "Total fare : " << b << endl;
    cout << "Ticket booked successfully " << endl
         << "Happy Journey ";
    ofstream in;
    in.open(train);
    in << Train_no << endl;
    in << no_of_seats << endl;
    in << source << endl;
    in << destination << endl;
    in << fare << endl;
    in.close();
}
int check(string user)
{
    string a;
    ifstream out;
    out.open(user);
    getline(out, a);
    out.close();
    if (user == a)
    {
        return 1;
    }
    return 0;
}
void Registration()
{
    cout << "_____Registration Page_____" << endl;
    string user, pass;
    cout << "Enter your username" << endl;
    cin >> user;
    if (check(user)) // To check if there is another userId exist with the same name
    {
        cout << "Username Already exist!!" << endl
             << "Please try with a differnt username " << endl;
        return Registration();
    }
    cout << "Enter your password" << endl;
    cin >> pass;
    ofstream out;
    out.open(user); // creating a file to store username and password
    out << user << endl;
    out << pass;
    out.close();
    cout << "User successfully created ";
}
int Login(string var1, string var2, string a, string b)
{
    // for (int i = 0; i < var1.length(); i++)
    // {
    //     if (var1[i] != a[i])
    //     {
    //         return 1;
    //     }
    // }
    for (int i = 0; i < var2.length(); i++)
    {
        if (var2[i] != b[i])
        {
            return 1;
        }
    }
    return 2;
}
int Check_Login()
{
    cout << "____________Log In____________" << endl;
    string a;
    cout << "Enter your username ";
    cin >> a;
    if (check(a) == 0)
    {
        cout << "User Id does not exist "
             << "Register yourself " << endl;
        Registration();
    }

    string b;
    cout << "Enter your password ";
    cin >> b;
    string var1, var2;
    ifstream in;
    in.open(a);
    getline(in, var1);
    getline(in, var2);
    in.close();
    int c = Login(var1, var2, a, b); // To check username and password
    switch (c)
    {
    // case 1:
    //     cout << "Inavalid Username ";
    //     break;
    case 1:
        return 0;
        // break;
    case 2:
        cout << "Logged in successfully " << endl;
        return 1;
        break;
    default:
        cout << "Technical Error";
        break;
    }
}
int MLogin(string var1, string var2, string a, string b)
{
    for (int i = 0; i < var1.length(); i++)
    {
        if (var1[i] != a[i])
        {
            return 1;
        }
    }
    for (int i = 0; i < var2.length(); i++)
    {
        if (var2[i] != b[i])
        {
            return 1;
        }
    }
    return 2;
}
int Master_login_check(string user)
{
    string a;
    ifstream out;
    out.open("Master.txt");
    getline(out, a);
    out.close();
    if (user != a)
    {
        return 1;
    }
    return 0;
}
int Master_login()
{

    cout << "____________Master Log In____________" << endl;
    string a;
    cout << "Enter your username ";
    cin >> a;
    if (Master_login_check(a))
    {
        cout << "Id doesn't exist";
        exit(0);
    }
    string b;
    cout << "Enter your password ";
    cin >> b;
    string var1, var2;
    ifstream in;
    in.open("Master.txt");
    getline(in, var1);
    getline(in, var2);
    in.close();
    int d = MLogin(var1, var2, a, b);
    if (d == 1)
    {
        cout << "Invlid Password" << endl;
        return 0;
    }
    return 1;
}
int main()
{
    int z;
    cout << "Press 1 for new registration and 2 for Login and 3 for master login " << endl;
    cin >> z;
    switch (z)
    {
    case 1:
        Registration();
        cout << endl;
    case 2:
        if (Check_Login() == 1)
        {
            int x;
            cout << "Press 1 for seats availability and 2 for new booking " << endl;
            cin >> x;
            if (x == 1)
            {
                string train;
                cout << "Train no: ";
                cin >> train;
                display(train);
            }
            else if (x == 2)
            {
                booking();
            }
            else
            {
                cout << "Kya kr raha hai bhai tu";
            }
        }
        else
        {
            cout << "Invalid Password" << endl;
        }

        break;
    case 3:
        if (Master_login() == 1)
        {
            Master obj;
            obj.set_data();
        }

        break;
    default:
        cout << "Please enter a valid input" << endl;
        return main();
    }
    return 0;
}