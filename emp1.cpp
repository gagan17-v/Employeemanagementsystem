#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

class Employee_management
{
private:
    // Variables for employee details
    char name[30];
    char id[5];
    char department[10];
    char role[20];
    int age, ctc;
    char experience[20];
    char gender[20];

public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

void Employee_management::menu() //Project Menu
{
    int password_user(); //login declaration
    password_user();
    //login screen
    while (true)
    {
        int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n" << endl;
        cout << "\t\t\t\t\t ************* Employee Main Menu ***************** " << endl;
        cout << "\n\n" << endl;
        cout << "\t\t\t\t\t 1. Enter New Record \n\n" << endl;
        cout << "\t\t\t\t\t 2. Display Record \n\n" << endl;
        cout << "\t\t\t\t\t 3. Modify Record \n\n" << endl;
        cout << "\t\t\t\t\t 4. Search Record \n\n" << endl;
        cout << "\t\t\t\t\t 5. Delete Record \n\n" << endl;
        cout << "\t\t\t\t\t 6. Exit \n\n" << endl;

        cout << "\n" << endl;
        cout << "\n" << endl;
        cout << "\n" << endl;
        cout << "\t\t\t\t\tEnter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\t\t\t To add another record enter Y or enter N to exit : ";
                cin >> x;
            } while (x == 'y'||x=='Y');
            waitForEnter();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            system("cls");
            cout << "\n\t\t\t EMPLOYEE MANAGEMENT SYSTEM - GAGAN V & GAGAN KM <<\n\n";
            Sleep(10);
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void Employee_management::insert() // add data of employe
{
    system("cls");
    fstream file;
    cout << "\n" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t ADD EMPLOYEE DETAILS" << endl;
    cout << "\n\n\n\t\t\t\t\t\t\t Enter Name of Employee: ";
    cin >> name;
    cout << "\n\n";
    cout << "\n\t\t\t\t\t\t\t Enter Employee ID [max 4 digits]: ";
    cin >> id;
    cout << "\n\n";
    cout << "\n\t\t\t\t\t\t\t Enter Department: ";
    cin >> department;
    cout << "\n\n";
    cout << "\n\t\t\t\t\t\t\t Enter Employee Age: ";
    cin >> age;
    cout << "\n\n";
    cout << "\n\t\t\t\t\t\t\t Enter Employee Gender: ";
    cin>> gender;
    cout << "\n\n";
    cout<<"\n\t\t\t\t\t\t\t Enter Employee role: ";
    cin>> role;
    cout << "\n\n";
    cout <<"\n\t\t\t\t\t\t\t Enter Employee Salary: ";
    cin >> ctc;
    cout << "\n\n";
    cout << "\n\t\t\t\t\t\t\t Enter Employee Experience: ";
    cin >> experience;
    file.open("Employee_Record.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << department << " " << age << " " << gender <<" "<< role <<" " << ctc << " " << experience << "\n";
    file.close();
}

void Employee_management::display() // Display data of employe
{
    system("cls");
    int total = 1;
    fstream file;
    cout << "\n" << endl;
    cout << "\t\t\t\t\t\t\t EMPLOYEE DETAILS" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> department >> age >> gender >> role >> ctc >> experience;
        cout << "\n ---------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout << "\n||    NAME    ||    ID    ||       DEPARTMENT        ||      AGE      ||     GENDER       ||           ROLE          ||           SALARY       ||    EXPERIENCE     ||";
        cout << "\n ---------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        while (!file.eof())
        {
            cout << "\n";
            cout << total++ << ". " << name << "\t  " << id << "\t\t  " << department << "\t\t    " << age << "\t\t    " << gender << "\t\t    " << role <<"\t\t    " << ctc <<"\t\t     "<<experience;
            file >> name >> id >> department >> age >> gender >> role >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Employee_management::modify() // Modify data of employe
{
    system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n\n" << endl;
    cout << "\t\t\t\t\t\t\t\t Employee Modify Data" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\n\t\tEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> department >> age >> gender >> role >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n\t\t\t\t\t\t\t Enter Name of Employee: ";
                cin >> name;
                cout << "\n\n";
                cout << "\n\t\t\t\t\t\t\t Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n\n";
                cout << "\n\t\t\t\t\t\t\t Enter Department : ";
                cin >> department;
                cout << "\n\n";
                cout << "\n\t\t\t\t\t\t\t Enter Employee Age: ";
                cin >> age;
                cout << "\n\n";
                cout<< "\n\t\t\t\t\t\t\t Enter Employee Gender: ";
                cin>> gender;
                cout << "\n\n";
                cout<< "\n\t\t\t\t\t\t\t Enter Employee Role: ";
                cin>> role;
                cout << "\n\n";
                cout << "\n\t\t\t\t\t\t\t Enter Employee Salary: ";
                cin >> ctc;
                cout << "\n\n";
                cout << "\n\t\t\t\t\t\t\t Enter Employee Experience: ";
                cin >> experience;
                cout << "\n\n";
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << " " << name << " " << id << " " << department << " " << age << " " << gender << " " << role << " " << ctc<< " " << experience << "\n";
                found++;
            }
            else
            {
                file1 << " " << name << " " << id << " " << department << " " << age << " " << gender << " " << role << " " << ctc << " " << experience << "\n";
            }
            file >> name >> id >> department >> age >> gender >> role >> ctc >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
    }
    waitForEnter();
}

void Employee_management::search() // Search data of employe
{                                  //Displays all details according to Employee's id
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n" << endl;
    cout << " \t\t\t\t\t\t\t\tEmployee Search Data " << endl;
    file.open("Employee_Record.txt", ios::in);
    cout << "\n\n\t\t\tEnter Employee ID: ";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> department >> age >> gender >> role >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n\n";
                cout << "\t\t\t\t\t\t\tEmployee Name: " << name << "\n";
                cout <<"\n\n";
                cout << "\t\t\t\t\t\t\tEmployee ID.: " << id << "\n";
                cout <<"\n\n";
                cout << "\t\t\t\t\t\t\tEmployee Department: " << department << "\n";
                cout <<"\n\n";
                cout << "\t\t\t\t\t\t\tEmployee Age: " << age << "\n";
                cout <<"\n\n";
                cout << "\t\t\t\t\t\t\tEmployee Gender: " << gender <<"\n";
                cout <<"\n\n";
                cout << "\t\t\t\t\t\t\tEmployee Role: "<< role <<"\n";
                cout <<"\n\n";
                cout << "\t\t\t\t\t\t\tEmployee Salary: " << ctc << "\n";
                cout <<"\n\n";
                cout << "\t\t\t\t\t\t\tEmployee Experience: " << experience << "\n";
                cout << "\n\n";
            }
            file >> name >> id >> department >> age >> gender >> role >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Employee_management::deleted() // Delete data of employe
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n\n" << endl;
    cout << "\t\t\t\t\t\t\t\t REMOVE EMPLOYEE DATA \n\n" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> department >> age >> gender >> role >> ctc >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << department << " " << age << " " << gender << " " << role << " " << ctc << " " << experience << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully deleted record.........";
            }
            file >> name >> id >> department >> age >> gender >> role >> ctc >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
        waitForEnter();
    }
}

void Employee_management::waitForEnter()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}

int password_user() // Employee Authentication
{
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
      int selection;
    char ch;
    system("cls");
      cout << "\n\t\t\t\t\t\t\t\t\t\t  EMPLOYEE MANAGEMENT SYSTEM  \n\n\n\t\t\t\t\t\t\t\t";
    
    
    for (int a = 1; a < 15; a++)
                {
                    Sleep(300);
                     
                    
                    cout << "...";
                    cout <<"...";
                }
     cout << "\n\n\t\t\t\t\t\t\t\t\t\t    1 . Sign up ";
     cout << "\n\n\t\t\t\t\t\t\t\t\t\t    2.  Login ";
     cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t    Enter your choice: ";
                    
    
    
    cin >> selection;
    
    // if user press [1], then it would lead them to register.
    if (selection == 1)
    {
        system("cls");
        cout << "\n";
        cout << "\n\t\t\t\t\t\t\t SIGN UP";
        cout << "\n";
        cout << "\n\n\t\t\t\t\t\tEnter userame: ";
        cin >> name_reg;
        cout << "\n\t\t\t\t\t\t\tEnter password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass_reg.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file.open("Ep_data.txt", ios::app);
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();
        cout << "\n\n\t\t\t\t\t Registered  succesfully..............";
        getch();
        password_user();
    }
    // if user press [2], then it would lead them to login.
    else if (selection == 2)
    {
        system("cls");
        file.open("Ep_data.txt", ios::in);
        cout << "\n";
        cout << "\n\t\t\t\t\t\t\tLOGIN NOW";
        cout << "\n";
        cout << "\n\n\t\t\t\t\tEnter  userame: ";
        cin >> name;
        cout << "\n\t\t\t\t\t\tEnter password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if (pass == pass_reg && name == name_reg)
            {
                cout << " \n\n\n\t\t\t\t\t\t\tValidating username & password\t\t\t\t\t\t\t\t\t\n\n\n";
                cout<< "\t\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "***********";
                }
                cout << "\n\nAccess Granted..\n\n";
                system("PAUSE");
                system("cls");
            }
           
            file >> name_reg >> pass_reg;
        }
        file.close();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        password_user();
    }
    return 0;
}
int main()
{
    // Call the function
    Employee_management system;
    system.menu();
    return 0;
}
