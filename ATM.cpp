#include <iostream>
using namespace std;

class ATM
{
private:
    char name[40], acctype[40];
    int balance, accno, pin;
public:
    void createAccount()
    {
        cout << "Enter Account Holder's Name: ";
        cin.getline(name, 40);
        cout << "Enter Account Type: ";
        cin.getline(acctype, 40);
        cout << "Enter Account Number: ";
        cin >> accno;

        do
        {
            cout << "Set 4-digit PIN: ";
            cin >> pin;
        } while (pin < 1000 || pin > 9999);

        cout << "Enter Opening Balance: ";
        cin >> balance;

        cout << "\nAccount Created Successfully!\n";
    }

    bool verifyPin()
    {
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin)
            return true;
        else
            return false;
    }

    void deposit()
    {
        int amount;
        cout << "Enter Deposit Amount: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid deposit amount!\n";
            return;
        }

        balance += amount;
        cout << "Deposit Successful! Current Balance: " << balance << endl;
    }

    void withdraw()
    {
        int amount;
        cout << "Enter Withdraw Amount: ";
        cin >> amount;

        if (amount <= 0 || amount > balance)
        {
            cout << "Invalid amount or insufficient balance!\n";
            return;
        }

        balance -= amount;
        cout << "Withdraw Successful! Current Balance: " << balance << endl;
    }

    void checkBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    void displayAccount()
    {
        cout << "\n----- Account Details -----\n";
        cout << "Name: " << name << endl;
        cout << "Account Type: " << acctype << endl;
        cout << "Account Number: " << accno << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    ATM atm;
    int choice;
    bool access = false;

    atm.createAccount();

    cout << "\n----- ATM LOGIN -----\n";
    for (int i = 0; i < 3; i++)
    {
        if (atm.verifyPin())
        {
            access = true;
            break;
        }
        else
            cout << "Wrong PIN! Attempts left: " << 2 - i << endl;
    }

    if (!access)
    {
        cout << "Account Locked! Too many wrong attempts." << endl;
        return 0;
    }

    do
    {
        cout << "\n----- ATM MENU -----\n";
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: atm.deposit(); break;
        case 2: atm.withdraw(); break;
        case 3: atm.checkBalance(); break;
        case 4: atm.displayAccount(); break;
        case 5: cout << "Thank you for using ATM!\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
