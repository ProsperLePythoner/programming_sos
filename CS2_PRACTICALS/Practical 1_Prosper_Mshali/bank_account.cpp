//
// Created by Prosper.dev and Collins.cpp on 10/08/2026.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

class BankAccount {
	private:
		int accountNumber;
		string ownerName;
		double balance;
	
	public:
		// Create a constructor using initializer syntax
		BankAccount(int accNum, string owner, double bal) : 
		accountNumber(accNum), ownerName(owner), balance(bal) {
			cout << "Successfully created account for user " << ownerName << "!\n" << endl;
		}
		
		void deposit(double amount) {
			if (amount > 0) {
				balance += amount; // test using "bal" later
				cout << "Successfully deposited " << amount << " TZS into "
					<< ownerName << "'s account!\n" << endl;
			} else {
				cout << "[ERROR] Deposit amount must be positive and greater than 0.\n" << endl;
			}
		}
		
		void withdraw(double amount) {
			if (amount > 0 && amount < balance) {
				balance -= amount;
				cout << "Successfully withdrawn " << amount << " TZS from "
					<< ownerName << "'s account!\n" << endl;
			} else {
				if (amount < 0) {
					cout << "[ERROR] Withdraw amount must be positive!\n" << endl;
					return;
				}
				cout << "[ERROR] Insufficient funds!\n" << endl;
			}
		}
		
		void displayBalance() {
			cout << ownerName << "'s BANK ACCOUNT " << endl;
			cout << "Current balance: " << balance << " TZS." << endl << endl;
		}
};

int main()
{
	// Declare necessary variables
	string name;
	int accNumber;
	double initBalance;
	int choice;
	
	// Print a welcome message to the user, input necessary data
	cout << "----- Welcome to the Bank Account management system! -----" << endl;
	cout << "Enter account number: ";
	cin >> accNumber;
	cout << "Enter account owner name: ";
	cin >> name;
	cout << "Enter initial account balance: ";
	cin >> initBalance;

	// Create user account
	BankAccount account1(accNumber, name, initBalance);

	// Display menu until user exits
	bool menu = true;

	while (menu) {
		cout << "\nChoose an action from below:\n"
			<< "\n1. Deposit money into account\n2. Withdraw money from account"
			<< "\n3. Display balance\n4. Exit" << endl << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
			case 1: {
				double depositAmount;
				cout << "\nDEPOSIT MONEY ....." << endl;
				cout << "Enter amount to deposit: ";
				cin >> depositAmount;
				account1.deposit(depositAmount);
				break;
			}
			case 2: {
				double withdrawAmount;
				cout << "\nWITHDRAW MONEY ....." << endl;
				cout << "Enter amount to withdraw: ";
				cin >> withdrawAmount;
				account1.withdraw(withdrawAmount);
				break;
			}
			case 3: {
				cout << "\nDISPLAY BALANCE ....." << endl;
				account1.displayBalance();
				break;
			}
			case 4: {
				cout << "\nEXIT PROGRAM ....." << endl;
				cout << "Goodbye!";
				menu = false;
				break;
			}
			default: {
				cout << "\nInvalid choice!" << endl;
				break;
			}
		}
	}
}