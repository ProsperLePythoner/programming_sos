#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const double MIN_BALANCE = 50000;

class Account {
	private:
		int accNumber;
		string holderName;
		double balance;
	
	public:
		Account(int number, string holder, double bal) : accNumber(number), holderName(holder), balance(bal) {}
		
		void info()
		{
			cout << "\n----- INFO FOR USER ACCOUNT #" << getAccNumber() << " -----" << endl
				 << "Account holder name: " << getHolderName() << endl
				 << "Balance: " << setprecision(9) << getBalance() << " TZS" << endl << endl;
		}
		
		const int getAccNumber() {
			return accNumber;
		}
		
		const string getHolderName() {
			return holderName;
		}
		
		const double getBalance() {
			return balance;
		}
};

int main()
{
	cout << showpoint;
	
	// Create 5 entries for accounts
	Account acc1(1, "Jonathan Cash", 2000000.0);
	Account acc2(2, "Maria Donnie", 50000.0);
	Account acc3(3, "Brendan Christopher", 450000.0);
	Account acc4(4, "Benjamin Tennyson", 10000000.0);
	Account acc5(5, "Raphael Benedict", 950000.0);
	
	// Gather entries into an array
	Account accounts[] = {acc1, acc2, acc3, acc4, acc5};
	
	cout << "********** WELCOME TO THE BANK ACCOUNT MANAGEMENT SYSTEM **********" << endl
		 << "\nSelect an option from below" << endl
		 << "1. Check account\n2. Lowest asset profile\n3. Exit\n\nYour choice: ";
	int choice;
	cin >> choice;
	
	switch(choice) {
		case 1: {
			// Prompt for and search for user account
			cout << "\n1. CHECK ACCOUNT" << endl
				 << "Enter account number to search for: ";
			int number;
			cin >> number;
			
			if (number <= 0 || number > 5) {
				cout << "\nAccount non existent!\n" << endl;
			} else {
				accounts[number - 1].info();
			}
			break;
		}
		
		case 2: {
			cout << "\n2. LOWEST ASSET PROFILE\n";
			
			// Loop thru items to identify the one with the absolute minimum balance requirement
			for (int i = 0; i < 5; ++i) {
				if (accounts[i].getBalance() == MIN_BALANCE) {
					cout << "\nDetails for account with minimum balance requirement (50,000 TZS)....." << endl;
					accounts[i].info();
				}
			}
			break;
		}
		
		case 3: {
			cout << "\nExiting program..." << endl;
			return 0;
			break;
		}
		
		default: {
			cout << "Invalid option selected." << endl;
			break;
		}
	}
	
	return 0;
}