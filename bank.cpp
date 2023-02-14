#include <iostream>
using namespace std;

// Global variables
const int length = 5;
int allIndex, optionSelect;

string signInName;
string signInPassword;
string name[length];
string role[length];
string password[length];
float accountMoney[length];

// Functions
void firstMenu();
void header();
void signUp(int signup_count);
bool checksignIn();
void updatePass();
void adminMenu();
void employee();
void userMenu();
void exit();
float subtract(float accountMoney, float withdraw);
void firstOption();
void mainSecondOption(int counting, int signup_count);
float balance();
float moneyTransfer();
void pasLenSignUp(int signup_count);

main()
{
    // main variables
    int counting, signup_count = 0;
    int flag = 0;
    while (true)
    {
        system("cls");

        header();
        firstMenu();
        cout << "Enter key: ";
        cin >> counting;
        // all if calling commands

        while (true)
        {

            if (counting < 4 && counting >= 1)
            {
                if (counting == 1 && signup_count < length)
                {
                    signUp(signup_count);
                    signup_count++;
                    exit();
                    break;
                }
                else if (counting == 2)
                {
                    mainSecondOption(counting, signup_count);
                    exit();
                    break;
                }

                else if (counting == 3)
                {
                    flag++;
                    system("cls");
                    break;
                }
                else if (signup_count >= length)
                {
                    cout << "Sorry! You cannot sign Up because limit has been exceeded." << endl;
                    exit();
                    break;
                }
            }
            else
            {
                cout << "Invalid command! " << endl;
                exit();
                break;
            }
        }
        if (flag > 0)
        {
            break;
        }
    }
}

void header()
{
    cout << "****************************************************************" << endl;
    cout << "*                    Bank Management System                    *" << endl;
    cout << "****************************************************************" << endl;
}

void firstMenu()
{
    cout << "     Main Menu" << endl;
    cout << "*******************************" << endl;
    cout << "1. Do you want to sign up?" << endl;
    cout << "2. Do you want to sign in?" << endl;
    cout << "3. Do you want to exit?" << endl;
}

void adminMenu()
{
    cout << "     Admin Menu" << endl;
    cout << "*******************************" << endl;
    cout << "1. Withdraw money?" << endl;
    cout << "2. Check balance?" << endl;
    cout << "3. Money transfer?" << endl;
    cout << "4. Add accounts?" << endl;
    cout << "5. Update password." << endl;
    cout << "6. Exit" << endl;
}
void employee()
{
    cout << "     Employee Menu" << endl;
    cout << "*******************************" << endl;
    cout << "1. Withdraw money." << endl;
    cout << "2. Check balance." << endl;
    cout << "3. Money transfer." << endl;
    cout << "4. Add account." << endl;
    cout << "5. Update password." << endl;
    cout << "6. Exit" << endl;
}

void userMenu()
{
    cout << "     User's Options" << endl;
    cout << "*******************************" << endl;
    cout << "1. Withdraw money." << endl;
    cout << "2. Check balance." << endl;
    cout << "3. Money transfer." << endl;
    cout << "4. Update password." << endl;
    cout << "5. Exit" << endl;
}

void pasLenSignUp(int signup_count)
{
    while (true)
    {
        if (password[signup_count].size() != 8)
        {
            cout << "Enter password of 8 characters." << endl;
            cout << "Enter Password: ";
            cin >> password[signup_count];
        }
        else
        {
            break;
        }
    }
}

void signUp(int signup_count)
{
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name[signup_count]);
    cout << "Enter password: ";
    cin >> password[signup_count];
    pasLenSignUp(signup_count);
    cout << "Enter role: ";
    cin >> role[signup_count];
    cout << "Enter amount in account: ";
    cin >> accountMoney[signup_count];
    cout << "You have successfuly created an account." << endl;
}

bool checksignIn()
{
    bool result = false;
    for (int i = 0; i < length; i++)
    {
        if (name[i] == signInName && password[i] == signInPassword)
        {
            allIndex = i;
            result = true;
            break;
        }
    }
    return result;
}

void exit()
{
    char ex;
    cout << "Press any key to exit..";
    cin >> ex;
}

void firstOption()
{
    float withdraw;
    while (true)
    {
        cout << "Enter amount: ";
        cin >> withdraw;

        if (accountMoney[allIndex] >= withdraw)
        {
            subtract(accountMoney[allIndex], withdraw);
            cout << "Operation has been successfuly completed." << endl;
            cout << "Amount left in your account is: " << subtract(accountMoney[allIndex], withdraw) << endl;
            accountMoney[allIndex] = accountMoney[allIndex] - withdraw;
            exit();
            break;
        }
        else
        {
            cout << "you don't have enough money!" << endl;
        }
    }
}

void mainSecondOption(int counting, int signup_count)
{
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, signInName);
    cout << "Enter your password: ";
    cin >> signInPassword;
    if (checksignIn())
    {
        if (role[allIndex] == "admin")
        {

            while (true)
            {
                system("cls");
                header();
                adminMenu();
                cout << "Enter key: ";
                cin >> optionSelect;
                if (optionSelect == 1)
                {
                    firstOption();
                }
                else if (optionSelect == 2)
                {
                    cout << "Amount in your account is: " << balance() << endl;
                    exit();
                    break;
                }
                else if (optionSelect == 3)
                {
                    moneyTransfer();
                }
                else if (optionSelect == 4)
                {
                    if (signup_count < length)
                    {
                        signUp(signup_count);
                    }
                    else
                    {
                        cout << "You cannot add account as limit has been exceeded." << endl;
                    }
                    exit();
                    break;
                }
                else if (optionSelect == 5)
                {
                    updatePass();
                    exit();
                    break;
                }
                else if (optionSelect == 6)
                {
                    break;
                }
            }
        }
        else if (role[allIndex] == "employee")
        {
            while (true)
            {
                system("cls");
                header();
                employee();
                cout << "Enter key: ";
                cin >> optionSelect;
                if (optionSelect == 1)
                {
                    firstOption();
                }
                else if (optionSelect == 2)
                {
                    cout << "Amount in your account is: " << balance() << endl;
                    exit();
                    break;
                }
                else if (optionSelect == 3)
                {
                    moneyTransfer();
                }
                else if (optionSelect == 4)
                {
                    if (signup_count < length)
                    {
                        signUp(signup_count);
                    }
                    else
                    {
                        cout << "You cannot add account as limit has been exceeded." << endl;
                    }
                    exit();
                    break;
                }
                else if (optionSelect == 5)
                {
                    updatePass();
                    exit();
                    break;
                }
                else if (optionSelect == 6)
                {
                    break;
                }
            }
        }
        else
        {
            while (true)
            {
                system("cls");
                header();
                userMenu();
                cout << "Enter key: ";
                cin >> optionSelect;
                if (optionSelect == 1)
                {
                    firstOption();
                }
                else if (optionSelect == 2)
                {
                    cout << "Amount in your account is: " << balance() << endl;
                    exit();
                    break;
                }
                else if (optionSelect == 3)
                {
                    moneyTransfer();
                }
                else if (optionSelect == 4)
                {
                    updatePass();
                    exit();
                    break;
                }
                else if (optionSelect == 5)
                {
                    break;
                }
            }
        }
    }
    else
    {
        cout << "Invalid information" << endl;
    }
}

float balance()
{
    if (checksignIn())
    {
        return accountMoney[allIndex];
    }
}

void updatePass()
{
    if (checksignIn())
    {
        cout << "Enter new password: ";
        cin >> password[allIndex];
    }
    while (true)
    {
        if (password[allIndex].size() != 8)
        {
            cout << "Enter password of 8 characters." << endl;
            cout << "Enter new password: ";
            cin >> password[allIndex];
        }
        else
        {
            break;
        }
    }
}

float moneyTransfer()
{
    firstOption();
}

float subtract(float accountMoney, float withdraw)
{
    float left = accountMoney - withdraw;
    return left;
}