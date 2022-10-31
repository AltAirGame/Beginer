#include <iostream>
#include <string.h>
#include <fstream>
#include <unistd.h>
using namespace std;

void Login();
void Regesteration();
void Forgot();
void ClearScreen();
void LoginPanel();
void ShowText();
int GetUserInput();

class Shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;
public:
    void Menu();
    void Adminstratur();
    void Buyer();
    void Add();
    void Edit();
    void Remove();
    void List();
    void Recept();

};
void Shopping::Menu() {
    int choice;
}

int main() {





    return 0;
}

void LoginPanel() {

    ShowText();
    int choice = GetUserInput();
    switch (choice) {
        case 1:
            Login();
            break;
        case 2:
            Regesteration();
            break;
        case 3:
            Forgot();
            break;
        case 4:
            ClearScreen();
            cout<<"\t\t\t Thank You !\n\n";
        default:
            exit(0);
            break;

    }
}
int GetUserInput() {
    int choice=0;
    cin >> choice;
    cout<<endl;
    return choice;
}
void ShowText() {
    cout << "\t\t\t\t                   Welcome To Login Page                                  \n";
    cout<<"\t\t\t ------------------------------Menu----------------------------------------\n";
    cout<<"\t\t\t| Press 1 to LOGIN                                                         |\n";
    cout<<"\t\t\t| Press 2 to REGISTER                                                      |\n";
    cout<<"\t\t\t| Press 3 if you forgot your PASSWORD                                      |\n";
    cout<<"\t\t\t| Press 4 to EXIT                                                          |\n";
    cout<<"\t\t\t|\t\t\t           Pleas enter your choice                             |\n";
    cout<<"\t\t\t --------------------------------------------------------------------------\n";
}
void Login()
{
    int count=0;
    string userId,password,id,pass;
    ClearScreen();
    cout<<"Pleas Enter the UserName and Password\n";
    cout<<"USERNAME :";
    cin>>userId;
    cout<<"\n";
    cout<<"PASSWORD :";
    cin>>password;
    ifstream input("records.txt");
    if (input.fail())
    {
        ClearScreen();
        cout<<"We didnt Found Any Saved Files";
        main();

    } else
    {
        cout<<"We  Found  Saved Files \n";

    }

    while (input>>id>>pass)
        {
            if (id==userId && pass==password)
            {
                count=1;
                ClearScreen();
            }

        }
    input.close();

    if (count==1)
    {
        cout<<userId<<" Your Login was Successful \n Thanks For Logging In";
        main();
    }
    else
    {
        cout<<"Login Error \n Pleas Check Your UserName !";
        main();
    }



}
void Regesteration()
{
    string rUserId,rPassword;
    ClearScreen();
    cout<<"Pleas Enter the UserName and Password\n";
    cout<<"USERNAME :";
    cin>>rUserId;
    cout<<"\n";
    cout<<"PASSWORD :";
    cin>>rPassword;
    ofstream f1("records.txt",ios::app);
    f1<<rUserId<<' '<<rPassword<<endl;
    ClearScreen();
    cout<<"Registration is Successful";
    main();


}
void Forgot()
{

    int option=0;
    ClearScreen();
    cout<<"\t\t\t You forgot the password ? no worries \n";
    cout<<"\t\t\t Press 1 to Search your Id by Username \n";
    cout<<"\t\t\t Press 2 to go Back to Main Menu    \n";
    cout<<"\t\t\t Enter Your Choice ";
    cin>>option;
    switch (option)
    {
        case 1:
        {  int count=0;
            string sUserId,sId,sPass;
            cout<<"Enter the last UserName which you remember : ";
            cin>>sUserId;
            ifstream f2("records.txt");
            if (f2.fail())
            {
                cout<<"we didn't find the file";
            }
            while (f2>>sId>>sPass)
            {
                if (sId==sUserId)
                {
                    count=1;
                }
            }
            f2.close();
            if (count==1)
            {
                cout<<sUserId<<" Your Login was Successful \n Thanks For Logging In";
                main();
            }
            else
            {
                cout<<"Login Error \n Pleas Check Your UserName !";
                main();
            }

            break;
        }
        case 2: {
            cout << "";
            break;
        }
        default:
            break;
    }


}
void ClearScreen()
{
    system("clear");
}