#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void displaySortedArray(const int* const arr, const int size);
void sortArray(int* const arr, const int size);
double calculateAverage(const int* const arr, const int size);
string gradeScore(double average);

int main()
{
    int size;
    int marks[100] = {};

    cout << "How many students do you wanna input marks for? ";
    cin >> size;

    // Input validation
    if (size <= 0 || size > 100) {
        cout << "Error: Number of students must be between 1 and 100.\n";
        return 1;
    }

    cout << "\nRequired: Enter marks for " << size << " students......" << endl;

    for (int i = 0; i < size; ++i) {
        cout << "Marks for student " << i + 1 << ": ";
        cin >> marks[i];
        
        // Optional: Validate mark range (e.g., 0-100)
        while (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid mark! Please enter a value between 0 and 100: ";
            cin >> marks[i];
        }
    }

    // Sort the scores
    sortArray(marks, size);

    // Calculate average score
    double averageScore = calculateAverage(marks, size);

    // Find the average grade
    string grade = gradeScore(averageScore);

    cout << "\n----- RESULTS -----\n";
    displaySortedArray(marks, size);
    cout << "\nAverage score: " << averageScore << endl;
    cout << "Average grade: " << grade << endl;

    return 0;
}

// ====================== FUNCTION DEFINITIONS ======================

void displaySortedArray(const int* const arr, const int size)
{
    cout << "\nSORTED ARRAY.....\n";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void sortArray(int* const arr, const int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int smallestIndex = i;  // Fix 1: Store index, not value

        for (int index = i + 1; index < size; ++index)
        {
            if (arr[index] < arr[smallestIndex])
            {
                smallestIndex = index;
            }
        }

        // Swap only once after finding the smallest
        if (smallestIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[smallestIndex];
            arr[smallestIndex] = temp;
        }
    }
}

double calculateAverage(const int* const arr, const int size)
{
    int total = 0;
    for (int i = 0; i < size; ++i)
        total += arr[i];        // Fixed: was using undefined 'marks'

    return total / static_cast<double>(size);
}

string gradeScore(double average)
{
    if (average >= 80) return "A";
    else if (average >= 70) return "B";
    else if (average >= 60) return "C";
    else if (average >= 50) return "D";
    else return "F";
}