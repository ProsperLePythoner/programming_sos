#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Student {
	private:
		string regNumber;
		string fullName;
		vector<float> marks;
	
	public:
		Student(string reg, string fullname, vector<float> scores):
			regNumber(reg), fullName(fullname), marks(scores) {}
		
		/* SETTER AND GETTER METHODS */
		const string getRegNumber() { return regNumber; }
		
		const string getFullName() { return fullName; }
		
		vector<float> getMarks() { return marks; }
		
		const float calculateTotal() {
			float total = 0;
			for (float m : marks)
				total += m;
			return total;
		}
		
		const float calculateAverage() {
			return calculateTotal() / 3.0;
		}
		
		const string calculateGrade() {
			float average = calculateAverage();
			
			if (average >= 80) {
				return "A";
			} else if (average >= 70) {
				return "B";
			} else if (average >= 60) {
				return "C";
			} else if (average >= 50) {
				return "D";
			} else {
				return "F";
			}
		}
		
		const void displayInfo() {
			cout << "> STUDENT DETAILS:" << endl;
			cout << setw(30) << "Registration number: " << setw(30) << getRegNumber() << endl
				 << setw(30) << "Full name:" << setw(30) << getFullName() << endl
				 << setw(30) << "Total marks: " << setw(30) << calculateTotal() << endl
				 << setw(30) << "Average marks: " << setw(30) << calculateAverage() << endl
				 << setw(30) << "Grade: " << setw(30) << calculateGrade() << endl << endl;
		}
};

vector<Student> createStudents(int n) {
	cout << showpoint;
	cout.precision(5);
	
	vector<Student> students;
	
	for (int i = 0; i < n; ++i) {
		cout << "\nEntering details for Student #" << i + 1 << "....." << endl;
		cout << "> Student's registration number: ";
		string reg;
		getline(cin, reg);
		cin.ignore();
		
		cout << "> Student's full name: ";
		string name;
		getline(cin, name);
		cin.ignore();
		
		cout << "> Enter " << name << "'s marks for three subjects\n";
		vector<float> marks;
		int s = 1;
		while (s <= 3) {
			cout << "\tSubject " << s << ": ";
			float m;
			cin >> m;
			cin.ignore();
			
			if (m >= 0 && m <= 100) {
				marks.push_back(m);
				s++;
			} else {
				cout << "Invalid input. Please enter a score in the range 0 - 100!" << endl;
			}
		}
		students.push_back(Student(reg, name, marks));
	}
	return students;
}

int main()
{
	// Allow the user to create three students
	cout << "********** WELCOME TO THE STUDENT MANAGEMENT SYSTEM **********" << endl;
	cout << "Before you proceed, you are required to enter details for three students.\n" << endl;
	vector<Student> students = createStudents(3);
	cout << endl << endl;
	
	// Display details for each student
	cout << "Details for all the above students..." << endl;
	for (Student s : students) {
		s.displayInfo();
	}
	
	return 0;
}