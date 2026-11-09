#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

const float TAX_RATE = 0.1;

class Employee {
	private:
		string name;
		int employeeID;
		float basicSalary;
		float allowance;
	
	public:
		Employee(string employeeName, int id, float salary, float employeeAllowance) : 
		name(employeeName), employeeID(id), basicSalary(salary), allowance(employeeAllowance) {}
		
		const float calculateNetSalary() {
			return (1 - TAX_RATE) * (getBasicSalary() + getAllowance());
		}
		
		void displayDetails() {
			cout << "Employee ID: " << setw(50) << getEmployeeID() << endl
				<< "Employee Name: " << setw(50) << getName() << endl
				<< "Basic salary: " << setw(50) << setprecision(10) << getBasicSalary() << endl
				<< "Allowance: " << setw(50) << setprecision(10) << getAllowance() << endl
				<< "Net salary: " << setw(50) << setprecision(10) << calculateNetSalary() << endl;
		}
		
		// Create appropriate setter and getter functions to enforce encapsulation
		int getEmployeeID() { return employeeID; }
		
		string getName() { return name; }
		
		float getBasicSalary() { return basicSalary; }
		
		float getAllowance() { return allowance; }
};

class Manager: public Employee {
	private:
		float bonus;
	
	public:
		Manager(string managerName, int id, float managerSalary, float managerAllowance, float bonusAmount) : 
		Employee(managerName, id, managerSalary, managerAllowance), bonus(bonusAmount) {}

		const float calculateNetSalary() {
			return (1 - TAX_RATE) * (getBasicSalary() + getAllowance() + getBonus());
		}
		
		float getBonus() { return bonus; }
		
		void displayDetails()
		{
			cout << "Employee ID: " << setw(50) << getEmployeeID() << endl
				<< "Employee Name: " << setw(50) << getName() << endl
				<< "Basic salary: " << setw(50) << setprecision(10) << getBasicSalary() << endl
				<< "Allowance: " << setw(50) << setprecision(10) << getAllowance() << endl
				<< "Net salary: " << setw(50) << setprecision(10) << calculateNetSalary() << endl
				<< "Bonus: " << setw(50) << setprecision(10) << getBonus() << endl;
		}
};

int main()
{
	// Create 3 objects of the Employee class using an array
	vector<Employee> employees;
	cout << showpoint;
	
	// Accept input from the user for each employee
	cout << "------------------ Welcome to BRIGHT WORKS LTD!!! ------------------" << endl;
	cout << "\nYou are required to input data for three(3) employees.........." << endl;
	string name;
	int employeeID;
	float basicSalary, allowance;
	
	for (int i = 0; i < 3; ++i) {
		cout << "\nEMPLOYEE #" << i + 1 << endl;
		cout << "Name of the employee: ";
		cin >> name;
		cout << "Employee ID: ";
		cin >> employeeID;
		cout << "Basic salary for '" << name << "'(TZS): ";
		cin >> basicSalary;
		cout << "Allowance for '" << name << "'(TZS): ";
		cin >> allowance;
		
		employees.push_back(Employee(name, employeeID, basicSalary, allowance));
	}

	// Output data for each employee
	cout << "\n\nOUTPUT DATA FOR EACH EMPLOYEE....." << endl;
	for (int i = 0; i < 3; ++i)
	{
		employees[i].displayDetails();
		cout << endl;
	}

	// Create one Manager object
	Manager manager("Festo Brendan", 1, 10000000.00, 2000000.00, 500000.00);
	cout << "\n\nDISPLAYING THE MANAGER'S DETAILS......" << endl;
	manager.displayDetails();
}
