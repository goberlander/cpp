/* 
PROGRAM: Banksy
AUTHOR: Glenn Walter Oberlander Jr.
DATE: 5.2.2018
*/

/*This program will allow the user to navigate a menu to enter a new customer, edit a customer's information, or show all of the current data stored.*/
#include <iostream>
#include <string>
using namespace std;

struct CustomerInfo
{
    string name, address, city, state;
    string zip, phone;
    double balance;
    string lastPayment;
};

void newAccount();
void editAccount(int );
void showAccount(int );
void menuPrompt();

CustomerInfo customerAccounts[20]; // Array to hold structores

int customerNumber; // Keeps track of number of accounts created

int main()
{
    menuPrompt(); // Basically begins entire program
}

void menuPrompt() // PRINTS MAIN MENU
{
    int choice;
    cout << "1. Enter new account information\n" << "2. Change account information\n" << "3. Display all account information\n" << "4. Exit the program\n";
    cin >> choice;
    cin.ignore();
    switch(choice)
    {
        case 1: // NEW ACCOUNT
            newAccount();
            break;
        case 2: // EDIT ACCOUNT DETAILS
            int accountNumber;
            if(customerNumber <= 0) // Validates if at least one account exists.
            {
                cout << "No accounts to edit. Please enter a new account.\n";
                cout << "Press enter to continue...\n";
                if(cin.get() == '\n')
                    menuPrompt();
                else
                    return;
            }
            cout << "Customer number: ";
            cin >> accountNumber;
            cin.ignore();
            if(accountNumber > customerNumber) // If user input is greater than current saved accounts
            {
                cout << "\nThat account doesn't exist. Please create a new account.\n\n";
                cout << "Press enter to continue...\n";
                if(cin.get() == '\n')
                    menuPrompt();
                else
                    return;
            }
            editAccount(accountNumber);
            menuPrompt();
            break;
        case 3: // SHOW ALL SAVED ACCOUNTS
            showAccount(customerNumber);
            break;
        case 4: // TERMINATE PROGRAM
            break;
        default:
            return;
    }
}

void newAccount()
{
    cout << "Customer name: ";
    getline(cin, customerAccounts[customerNumber].name);

    cout << "Address: ";
    getline(cin, customerAccounts[customerNumber].address);

    cout << "City: ";
    getline(cin, customerAccounts[customerNumber].city);

    cout << "State: ";
    getline(cin, customerAccounts[customerNumber].state);

    cout << "Zip: ";
    getline(cin, customerAccounts[customerNumber].zip);

    cout << "Phone: ";
    getline(cin, customerAccounts[customerNumber].phone);

    cout << "Account balance: ";
    cin >> customerAccounts[customerNumber].balance;
    cin.ignore(); // Clears null terminator stuck in stream

    cout << "Last Payment: ";
    getline(cin, customerAccounts[customerNumber].lastPayment);
    
    cout << "You have entered information for customer number: " << customerNumber << endl;
    customerNumber++;
    menuPrompt();  
}

void editAccount(int accountNumber)
{
    cout << "Customer name: ";
    getline(cin, customerAccounts[accountNumber].name);
    
    cout << "Address: ";
    getline(cin, customerAccounts[accountNumber].address);
    
    cout << "City: ";
    getline(cin, customerAccounts[accountNumber].city);
    
    cout << "State: ";
    getline(cin, customerAccounts[accountNumber].state);

    cout << "Zip: ";
    getline(cin, customerAccounts[accountNumber].zip);
    
    cout << "Phone: ";
    getline(cin, customerAccounts[accountNumber].phone);

    cout << "Account balance: ";
    cin >> customerAccounts[accountNumber].balance;
    cin.ignore(); // Clears null terminator stuck in stream

    cout << "Last payment: ";
    getline(cin, customerAccounts[accountNumber].lastPayment);
}

void showAccount(int customerNumber)
{
    for(int i = 0; i < customerNumber; i++) // Iterates to max amount of accounts entered
    {
        cout << "Name: " << customerAccounts[i].name << endl;
        cout << "Address: " << customerAccounts[i].address << endl;
        cout << "City: " << customerAccounts[i].city << endl;
        cout << "State: " << customerAccounts[i].state << endl;
        cout << "Zip: " << customerAccounts[i].zip << endl;
        cout << "Phone: " << customerAccounts[i].phone << endl;
        cout << "Account balance: " << customerAccounts[i].balance << endl;
        cout << "Last payment: " << customerAccounts[i].lastPayment << endl << endl;
    }
    cout << "Press enter to continue...\n";
    if(cin.get() == '\n')
        menuPrompt();
    else
        return;
}

