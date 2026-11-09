#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
	private:
		string accountNumber;
		string holderName;
		double balance;
	
	public:
		// Parameterized constructor for class BankAccount
		BankAccount(string number, string name, double amount):
			accountNumber(number), holderName(name), balance(amount) {}
		
		bool deposit(double amount) {
			if (amount > 0) {
				balance += amount;
				cout << "Successfully deposited " << amount << " TZS into " << holderName << "'s account.\n" << endl;
				return true;
			} else {
				cout << "Negative amounts not allowed! Try again.\n" << endl;
				return false;
			}
	    }
		
		void withdraw(double amount) {
			if (amount <= balance) {
				balance -= amount;
				cout << "Successfully withdrawn " << amount << " TZS from " << holderName << "'s account.\n" << endl;
				return;
			}
			cout << "Insufficient funds! Try a lower amount or check balance\n" << endl;
	    }
	    
	    const void displayBalance() {
	    	cout << holderName << "'s current balance: " << balance << " TZS" << endl << endl;
		}
		
		/* GETTER AND SETTER METHODS */
		const string getAccountNumber() {
			return accountNumber;
		}
		
		const double getBalance() {
			return balance;
		}
		
		const string getHolderName() {
			return holderName;
		}
};

// Custom function for the menu functionality
void menu(BankAccount &a, bool &loop) {
	cout << "Select an action from below:\n1. Deposit\n2. Withdraw\n3. View balance\n4. Exit" << endl;
	cout << "Your choice: ";
	int choice;
	cin >> choice;
	
	switch (choice)  {
		case 1: {
			cout << "\n\n> DEPOSIT MONEY INTO ACCOUNT" << endl;
			
			while (true) {
			    cout << "Enter amount to deposit: ";
				double amt;
				cin >> amt;
				
				if (a.deposit(amt)) {
					break;
				}
			}
			break;
		}
		
		case 2: {
			cout << "\n\n> WITHDRAW MONEY FROM ACCOUNT" << endl;
			cout << "Enter amount to withdraw: ";
			double amt;
			cin >> amt;
			a.withdraw(amt);
			break;
		}
		
		case 3: {
			cout << "\n\n> VIEW BALANCE\n" << endl;
			a.displayBalance();
			break;
		}
		
		case 4: {
			cout << "\n\nExiting program....." << endl;
			loop = false;
			break;
		}
	}
}

int main()
{
	cout << showpoint;
	cout.precision(8);
	
	BankAccount acc1("1001", "Brian Franklin", 5000000.0);
	BankAccount acc2("1002", "Alexandra Woods", 4500000.0);
	BankAccount accounts[] = {acc1, acc2};
	
	// Demonstrating encapsulation by ensuring private attributes cannot be accessed directly outside the class
	// The following line of code yields an error when uncommented
	// That is because the compiler prevents access of private attributes from outside the class except through get and set methods
	// cout << "Trying to access the balance from acc1: " << acc1.balance << endl;
	
	// Accessing the balance through a getter method
	cout << "Accessing the balance through a getter method, since direct access is prohibited by the compiler." << endl;
	cout << "Balance for acc1: " << acc1.getBalance() << " TZS"<< endl;
	cout << "------------------------------------------------\n\n\n" << endl;
	
	
	// Demonstrating how customers can deposit and withdraw money from their accounts
	cout << "-------- WELCOME TO THE BANK ACCOUNT MANAGEMENT SYSTEM --------" << endl
		<< "Select an account number to proceed..." << endl;
	string accNumber;
	cin >> accNumber;
	
	bool found = false;
	bool loop = true;
	
	for (int i = 0; i < 2; ++i) {
		if (accNumber == accounts[i].getAccountNumber()) {
			found = true;
			cout << "\nYou have selected " << accounts[i].getHolderName() << "'s account." << endl << endl;
			
			while (loop) {
				menu(accounts[i], loop);
			}
		}
	}
	
	if (found == false) {
		cout << "Could not find account with account number " << accNumber << endl;
	}
	
	return 0;
}