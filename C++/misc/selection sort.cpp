#include <iostream>
#include <string>
using namespace std;

void displaySortedArray(int * const arr, const int size)
{
	cout << "\nSORTED ARRAY.....\n";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void sortArray(int * const arr, const int size) {
	int smallest;
	
	for (int i = 0; i < size - 1; ++i)
	{
		smallest = i;
		
		for (int index = i + 1; index < size; ++index)
		{
			if (arr[index] < arr[smallest]) {
				smallest = index;
				
				int temp = arr[i];
				arr[i] = arr[smallest];
				arr[smallest] = temp;
			}
		}
	}
}

double calculateAverage(int * const arr, const int size) {
	int total = 0;
	for (int i = 0; i < size; ++i)
		total += arr[i];
	return total / static_cast<double>(size);
}

string gradeScore(int average) {
	if (average >= 80) return "A";
	else if (average >= 70) return "B";
	else if (average >= 60) return "C";
	else if (average >= 50) return "D";
	else return "F";
}

int main()
{
	int size;
	int marks[100] = {};
	double averageScore;
	string grade;
	
	cout << "How many students do you wanna input marks for? ";
	cin >> size;
	cout << "\nRequired: Enter marks for " << size << " students......" << endl;
	
	for (int i = 0; i < size; ++i) {
		cout << "Marks for student " << i + 1 << ": ";
		cin >> marks[i];
	}
	
	// Sort the scores
	sortArray(marks, size);
	
	// Calculate average score
	averageScore = calculateAverage(marks, size);
	
	// Find the average grade
	grade = gradeScore(averageScore);
	
	cout << "----- RESULTS -----\n";
	displaySortedArray(marks, size);
	cout << "Average score: " << averageScore << "\n" << "Average grade: "
	     << grade << endl;
}