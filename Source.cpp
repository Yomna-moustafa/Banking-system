#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include<string.h>
using namespace std;
int d , c ;
struct definition
{

    string name;

    string password;

    int balance;

    bool ishere;

};
definition clint[150];
definition admin[15];
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void save_clints();
void save_admins();
void st_step();
void search_d(int x);
void search_c(string name, string password);
void add_new();
void close();
void list_a();
void modifay();
void admins(int x);
void clints(int x);
void clints2(string name, string password);
void clint_firest_menu();
int main_menu();
void save_clints()
{
  
    ofstream out("clints.txt", ios::trunc);
    
    for (int i = 1;i < c-1;i++)
    {
        
        out << clint[i].name << endl;
    
        out << clint[i].password << endl;
        
        out << clint[i].ishere << endl;
        
        out << clint[i].balance << endl;

    }
    out.close();
}
void save_admins()
{
    ofstream out("admins.txt", ios::trunc);
    
    for (int i = 0;i < d;i++)
    {

        out << admin[i].name<<endl;

        out << admin[i].password << endl;

    }
    out.close();
}
void st_step()
{
    //Defoult clints
    int co = 1,co2=0;
    
    ifstream in("clints.txt");
    while (!in.eof())
    {
        in >> clint[co].name;
        in >> clint[co].password;
        in >> clint[co].ishere;
        in >> clint[co].balance;
        co++;
    }
    c = co;
    in.close();
    //Defult admins
    ifstream n("admins.txt");
    while (!n.eof())
    {
        n >> admin[co2].name;
        n >> admin[co2].password;
      
        co2++;
    }
    d = co2;
    n.close();

  
}
void add_new()
{
    c++;

    string name, password;

    cout << "Enter the client name : ";

    cin >> name;

    cout << "Please enter the client password : ";

    cin >> password;


    clint[c].name = name;

    clint[c].password = password;

    clint[c].balance = 0;

    clint[c].ishere = true;

    ofstream out("clints.txt",ios::app);
    out << name<<endl;
    out << password<<endl;
    out << 1<<endl;
    out << 0<<endl;
    out.close();
    system("CLS");

    SetConsoleTextAttribute(h, 02);


    cout << "Completed\n";

    SetConsoleTextAttribute(h, 07);

    
}
void close()
{
    string name;

    cout << "Enter the account name : ";

    cin >> name;

    bool isfind = false;

    for (int i = 0;i <= c;i++)

    {

        if (clint[i].name == name)

        {
            isfind = true;

            /*for (int j=i;j<c;j++)
            {
                clint[j].balance=clint[j+1].balance;
                clint[j].name=clint[j+1].name;
                clint[j].password=clint[j+1].password;
            }
            c--;*/
            clint[i].ishere = false;

            save_clints();

            system("CLS");

            SetConsoleTextAttribute(h, 02);

            cout << "Completed\n";

            SetConsoleTextAttribute(h, 07);
            

        }
    }
    if (isfind == false)
    {
        SetConsoleTextAttribute(h, 04);

        cout << "This name is not true press enter to try again...";

        SetConsoleTextAttribute(h, 07);

        cin.get();
        cin.get();

        system("CLS");

        close();
    }
}
void list_a()
{
    cout << "Name\t\tPassword\t\tBalance\n";
    for (int i = 1;i <= c;i++)
    {
        if (clint[i].ishere == true)
        {

            cout << clint[i].name << "\t\t" << clint[i].password << "\t\t\t" << clint[i].balance << "\n";
        }
    }

    cout << "Press enter to back... ";
    cin.get();
    cin.get();
    system("CLS");
}
void modifay()
{

    bool isfind = false;

    string name, password;

    cout << "Enter the client account name : ";

    cin >> name;

    for (int i = 0;i <= c;i++)

    {

        if (clint[i].name == name)

        {

            isfind = true;

            cout << "Name\t\tPassword\t\tBalance\n";

            cout << clint[i].name << "\t\t" << clint[i].password << "\t\t\t" << clint[i].balance << "\n";

            cout << "1)change account name\n2)change account password\n3)change account balance\n4)Back\n";

            while (true)

            {

                int j, m;

                cin >> j;

                if (j == 1)

                {

                    cout << "Enter the new name : ";

                    cin >> name;

                    clint[i].name = name;

                    SetConsoleTextAttribute(h, 02);

                    cout << "Completed\n";

                    SetConsoleTextAttribute(h, 07);

                    save_clints();

                }

                else if (j == 2)

                {

                    cout << "Enter the new password : ";

                    cin >> password;

                    clint[i].password = password;

                    SetConsoleTextAttribute(h, 02);

                    cout << "Completed\n";

                    SetConsoleTextAttribute(h, 07);
                    
                    save_clints();
                }

                else if (j == 3)

                {

                    cout << "Enter the new balance : ";

                    cin >> m;

                    clint[i].balance = m;

                    SetConsoleTextAttribute(h, 02);

                    cout << "Completed\n";

                    SetConsoleTextAttribute(h, 07);

                    save_clints();

                }

                else if (j == 4)

                {

                    system("CLS");
                    break;
                }

            }
        }
    }

    if (isfind == false)
    {
        SetConsoleTextAttribute(h, 04);

        cout << "This name is not true press enter to try again...";

        SetConsoleTextAttribute(h, 07);

        cin.get();
        cin.get();
        
        system("CLS");

        modifay();
    }
}
void search_d(int x)
{

    string name, password;

    bool isfined = false;

    char cr;

    cout << "Please enter the name : ";

    cin >> name;

    for (int i = 0;i < d;i++)

    {
        if (admin[i].name == name)
        {

            while (true) {

                cout << "Please enter the password : ";

                cin >> password;

                if (admin[i].password == password)

                {
                    isfined = true;

                    system("CLS");

                    SetConsoleTextAttribute(h, 02);

                    cout << "Hi " << name << endl;

                    SetConsoleTextAttribute(h, 07);

                    break;
                    //admin list function
                }
                else
                {
                    system("CLS");

                    SetConsoleTextAttribute(h, 04);

                    cout << "Hi " << name << " Your password is wrong try again press enter to try again ...";

                    SetConsoleTextAttribute(h, 07);

                    

                    cin.get();
                    cin.get();

                    system("CLS");
                }
            }
        }
    }
    if (isfined == false)
    {
        system("CLS");

        SetConsoleTextAttribute(h, 04);

        cout << "Sorry this account is not found Press enter to try again...";

        SetConsoleTextAttribute(h, 07);

        cin.get();
        cin.get();

        system("CLS");
        admins(1);

    }

}
void search_c(string name, string password)
{

    bool isfined = false;

    for (int i = 0;i <= c;i++)

    {

        if (clint[i].name == name)

        {

            if (clint[i].password == password)

            {
                isfined = true;

                system("CLS");

                SetConsoleTextAttribute(h, 02);

                cout << "Hi " << name << endl;
                //client list function
                SetConsoleTextAttribute(h, 07);
            }

        }

    }

    if (isfined == false)

    {

        SetConsoleTextAttribute(h, 04);

        cout << "Sorry this account is not found press enter to try again...";

        SetConsoleTextAttribute(h, 07);

        cin.get();
        cin.get();

        system("CLS");

        clints(1);

    }


}
void admins(int x)
{

    string name, password;

    bool isfined = false;

    if (x == 1) {

        search_d(x);

        cout << "1)Add a New Account.\n2)Modify An Account.\n3)Close An Account.\n4)List All Accounts.\n5)Log out\n";

        while (true)

        {

            int y;

            cin >> y;

            if (y == 1)

            {

                system("CLS");

                int n;

                cout << "1)For client\n2)For admin\n";

                cin >> n;

                if (n == 1)

                {
                    system("CLS");

                    add_new();

                   

                }

                else

                {

                    system("CLS");

                    admins(2);

                }

            }

            else if (y == 2)

            {

                system("CLS");

                modifay();
            }

            else if (y == 3)

            {

                system("CLS");

                close();

            }

            else if (y == 4)

            {

                system("CLS");

                list_a();

            }

            else if (y == 5)

            {

                system("CLS");

                main_menu();

            }

            else

            {

                SetConsoleTextAttribute(h, 04);

                cout << "Your choice is not available please try again \n";

                SetConsoleTextAttribute(h, 07);
            }

            cout << "1)Add a New Account.\n2)Modify An Account.\n3)Close An Account.\n4)List All Accounts.\n5)Log out\n";

        }

    }

    else if (x == 2)

    {

        cout << "Enter the name : ";

        cin >> name;

        admin[d].name = name;

        cout << "Enter the password : ";

        cin >> password;

        admin[d].password = password;

        d++;

        ofstream out("admins.txt", ios::app);
        
        out << name << endl;
        
        out << password << endl;

        out.close();
        system("CLS");

        SetConsoleTextAttribute(h, 02);

        cout << "Completed\n\n";

        SetConsoleTextAttribute(h, 07);

       

    }
}
void clints2(string name, string password)
{

    int t;

    for (int i = 1;i <= c;i++)

    {

        if (clint[i].name == name)

        {

            t = i;

        }

    }

    cout << "1)Balance Enquiry.\n2)Withdraw Amount.\n3)Deposit Amount\n4)Transfer to another account\n5)Back\n6)Log out\n";


    int y;

    char cr;

    cin >> y;

    if (y == 1)

    {

        system("CLS");

        cout << "Your balance equal " << clint[t].balance << endl;

        cout << "Press enter to back... ";

        cin.get();
        cin.get();

        system("CLS");

        clints2(name, password);
    }

    else if (y == 2)

    {

        system("CLS");

        cout << "Enter the amount you want to withdraw\n";

        int withdraw;

        cin >> withdraw;

        if (clint[t].balance >= withdraw)

        {

            clint[t].balance = clint[t].balance - withdraw;

            cout << "Your balance is now equal " << clint[t].balance << endl;

            save_clints();
        }

        else

        {
            SetConsoleTextAttribute(h, 04);

            cout << "Your balance is not enough to withdraw this amount\n";

            SetConsoleTextAttribute(h, 07);

            clints2(name, password);
        }
    }

    else if (y == 3)

    {
        system("CLS");

        cout << "Enter the amount you want to deposit\n";

        int deposit;

        cin >> deposit;

        clint[t].balance = clint[t].balance + deposit;

        cout << "Your balance is now equal " << clint[t].balance << endl;

        save_clints();

        cout << "Press enter to back...";

        cin.get();
        cin.get();

        system("CLS");

        clints2(name, password);

    }

    else if (y == 4)

    {

        system("CLS");

        string name2;

        int amount, z;

        cout << "please enter the anther account name : ";

        cin >> name2;

        cout << "please enter amount to transfer : ";

        cin >> amount;
        bool isfind = false;
        for (int i = 0;i <= c;i++)

        {

            if (clint[i].name == name2)

            {

                z = i;
                isfind = true;
                break;

            }

        }
        if (isfind = false)
        {
            system("CLS");

            SetConsoleTextAttribute(h, 04);
            
            cout << "This account can't be find try again\n";
            
            SetConsoleTextAttribute(h, 07);
            
            clints2(name, password);

        }

        if (clint[t].balance >= amount)

        {

            clint[t].balance -= amount;

            clint[z].balance += amount;

            cout << "Your balance now equal " << clint[t].balance << endl;

            cout << name2 << " balance now equal " << clint[z].balance << endl;

            save_clints();

            cout << "Press enter to back...";

            cin.get();
            cin.get();

            system("CLS");

            clints2(name, password);

        }

        else

        {

            SetConsoleTextAttribute(h, 04);

            cout << "Your balance is not enough to withdraw this amount\n";

            SetConsoleTextAttribute(h, 07);

            clints2(name, password);
        }

    }

    else if (y == 5)

    {
        system("CLS");

        clint_firest_menu();
    }

    else if (y == 6)

    {

        system("CLS");

        main_menu();
    }
    else

    {

        SetConsoleTextAttribute(h, 04);

        cout << "Your chois are not available press enter to try again...";

        SetConsoleTextAttribute(h, 07);

        cin.get();
        cin.get();

        system("CLS");

        clints2(name, password);

    }


}

void clints(int x)
{

    string name, password;

    
    if (x == 1 || x == 2)

    {

       cout << "Please enter your name : ";

        cin >> name;

        cout << "Please enter your password : ";

        cin >> password;

        if (x == 1) {



            search_c(name, password);

        }

        else

        {

            c++;

            clint[c].name = name;

            clint[c].password = password;

            clint[c].balance = 0;

            clint[c].ishere = true;

            ofstream out("clints.txt", ios::app);
            out << name << endl;
            out << password<<endl;
            out << 1<<endl;
            out << 0<<endl;
            out.close();
            system("CLS");

            SetConsoleTextAttribute(h, 02);

            cout << "Hi " << name << endl << endl;

            SetConsoleTextAttribute(h, 07);

        }

        clints2(name, password);

    }

}
void clint_firest_menu()
{

    cout << "1)Login\n2)Regest\n3)Back\n";

    int x;

    cin >> x;

    if (x == 3)

    {

        system("CLS");

        main_menu();

    }

    else if (x == 1 || x == 2)

    {

        system("CLS");

        clints(x);
    }

    else

    {

        system("CLS");

        SetConsoleTextAttribute(h, 04);

        cout << "Your choice does not exist try again\n";

        SetConsoleTextAttribute(h, 07);

        clint_firest_menu();
    }
}
int main_menu()
{

    int x;

    cout << "1)For admins\n2)For clints\n3)Exit\n";

    cin >> x;

    if (x == 3)

    {

        
        return 0;


    }

    else if (x == 1)

    {

        system("CLS");

        admins(1);

    }

    else if (x == 2)

    {

        system("CLS");

        clint_firest_menu();
    }

    else

    {

        system("CLS");

        SetConsoleTextAttribute(h, 04);

        cout << "Your choice does not exist try again\n";

        SetConsoleTextAttribute(h, 07);

        main_menu();
    }

}
/*void amount() {
    int amount;
    int choice;
    int amountch;
    int custom_amount;
    char quit;
    do {
        cout << "If you want to deposite fixed amount Press 1 \n 2 other";
        cin >> choice;

        if (choice == 1) {
            cout << "\n Do you want to deposite :-\n (1)500\n(2)100\n(3)100\n(4)5000\n";
            cin >> amountch;

        }
        else if (choice == 2) {
            cout << "Enter amount you want to deposite\nMust be x500\n";
            cin >> custom_amount;

            if (custom_amount % 500 != 0) {
                cout << "Sorry this number invaild \n Please enter number in x500 \n";


            }
            else
                cout << "\ncompleted\n";
            r

        }
        else
            cout << "\nSorry invaild option\n ";
        cout << "Do you want another operations (y/n)\n";
        cin >> quit;
        if (quit == 'y') {
            continue;
        }
        else
            break;
    } while (true);*/

int main()
{

    st_step();
   
    main_menu();
    

    return 0;
}
