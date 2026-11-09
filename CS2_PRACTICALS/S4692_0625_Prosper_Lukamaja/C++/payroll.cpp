#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const int OVERTIME_THRESHOLD = 40;
const double TAX_RATE = 1.5 / 100.0;
string companyName = "Web Developers R Us Inc.";

class Employee {
	private:
		string employeeID;
		string name;
		double hourlyRate;
		double hoursWorked;
	
	public:
		// Constructor with initializer syntax
		Employee(string empID, string empName, double hrRate, double hrsWorked) :
		employeeID(empID), name(empName), hourlyRate(hrRate), hoursWorked(hrsWorked) {}
		
		double calculateGrossPay()
		{
			int overtimeHours;
			if (getHoursWorked() > 40) {
				overtimeHours = getHoursWorked() - OVERTIME_THRESHOLD;
				return hourlyRate * 40 + ((hourlyRate * 1.5) * overtimeHours);
			}
			return hoursWorked * hourlyRate;
		}
		
		double calculateNetPay()
		{
			return calculateGrossPay() - TAX_RATE * calculateGrossPay();
		}
		
		// Enforce encapsulation through getter methods
		string getName() {
			return name;
		}
		
		string getID() {
			return employeeID;
		}
		
		double getHourlyRate() {
			return hourlyRate;
		}
		
		int getHoursWorked() {
			return hoursWorked;
		}
};

vector<Employee> employees;

void registerEmployeeData()
{
	cout << "\n\n------ REGISTER EMPLOYEE DATA ------" << endl;
	cout << "How many employees do you want to create? ";
	int numEmployees;
	cin >> numEmployees;

	if (numEmployees < 1) {
		cout << "You must have at least 1 employee!" << endl;
		return;
	}
	
	// Loop for all N employees' data
	int i = 1;
	while (i <= numEmployees) {
		cout << "\nInput data for employee " << i << "..." << endl;

		string id, eName;
		double hrRate;
		int hrsWorked;
		cout << "Employee ID: ";
		cin >> id;
		cout << "Employee name: ";
		cin >> eName; // GETLINE IS OVER HEREEEE!!!
		
		while (true) {
			cout << "Hourly pay rate for " << eName << " in USD: ";
			cin >> hrRate;
			// Validate hourly pay rate
			if (hrRate < 0) {
				cout << "Hourly pay rate must be greater than zero! Try again." << endl;
				continue;
			}
			break;
		}
		
		while (true) {
			cout << "Total hours worked by " << eName << ": ";
			cin >> hrsWorked;
			
			// Validate hours worked
			if ((hrsWorked < 0) || (hrsWorked > 160)) {
				cout << "Hours worked must be between 0 and 160 only! Try again.\n" << endl;
				continue;
			}
			break;
		}
		
		// Increment the counter variable
		i++;

		// Create an object for this employee and push it onto the vector
		Employee employee(id, eName, hrRate, hrsWorked);
		employees.push_back(employee);
		cout << "Successfully created employee " << eName << "! \n" << endl;
	}
}

double calculateTotalExpenditure()
{
	double totalExpenditure;
	for (int i = 0; i < employees.size(); ++i)
		totalExpenditure += employees[i].calculateGrossPay();
	return totalExpenditure;
}

string findHighestEarningEmployee()
{
	double highestPayment = 0;
	int index;
	for (int i = 0; i < employees.size(); ++i) {
		if (employees[i].calculateGrossPay() > highestPayment) {
			highestPayment = employees[i].calculateGrossPay();
			index = i;
		}
	}
	return employees[index].getName();
}

void expenditurePerEmployee()
{
	if (employees.empty()) {
		cout << "No employee data! Please register employees." << endl;
		return;
	}
	cout << "\n\n---------- COMPANY EXPENDITURE PER EMPLOYEE FOR " << companyName << "----------" << endl;
	for (int i = 0; i < employees.size(); ++i)
	{
		cout << setw(100) << "\nEmployeeID " << employees[i].getID() << " (" << employees[i].getName() << "):" << endl
		     << setw(50) << "Hourly pay rate (USD/hour): " << setw(20) << employees[i].getHourlyRate() << endl
		     << setw(50) << "Total hours worked: " << setw(20) << employees[i].getHoursWorked() << endl
			 << setw(50) << "Gross pay (USD): " << setw(20) << setprecision(2) << employees[i].calculateGrossPay() << endl
			 << setw(50) << "Net pay (USD): " << setw(20) << setprecision(2) << employees[i].calculateNetPay() << endl;
	}
}

void summaryMetrics()
{
	if (employees.empty()) {
		cout << "No employee data! Please register employees." << endl;
		return;
	}
	cout << "\n\n---------- SUMMARY METRICS FOR " << companyName << " ----------" << endl;
	cout << setw(50) << "**** Total company expenditure: " << setw(20) << setprecision(2) << calculateTotalExpenditure() << "USD" << endl;
	cout << setw(50) << "**** Highest earning employee: " << setw(20) << findHighestEarningEmployee() << endl << endl;
}

int main()
{
	// Print a single introduction message
	cout << "********** WELCOME TO THE MONTHLY PAYROLL CALCULATOR PROGRAM **********" << endl;

	bool running = true;
	while (running) {
		cout << "\nPlease select an action from below:\n"
			<< "1. Register employee data\n2. Show company expenditure per employee\n"
			<< "3. Display summary metrics\n4. Exit\n"
			<< "\nYour choice (1 - 4): ";
		int choice;
		cin >> choice;

		switch (choice) {
			case 1: {
				registerEmployeeData();
				break;
			}
			case 2: {
				expenditurePerEmployee();
				break;
			}
			case 3: {
				summaryMetrics();
				break;
			}
			case 4: {
				cout << "Exiting program..." << endl;
				running = false;
				break;
			}
			default: {
				cout << "Invalid input! Try again..." << endl;
				cin.get();
				cin.ignore();
			}
		}
	}
	
	return 0;
}