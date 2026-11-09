""" Student Grading System """

class Student:
    '''A class representing an actual student'''
    # Create constructor for Student object
    def __init__(self, name: str) -> None:
        self._name = name
        self._marks = [] # a list of the student's marks
        self._total = 0
        self._grade = ''
        self._average = 0

    def calculate_average(self) -> float:
        '''Calculates student's average mark'''
        for m in self._marks: self._total += m
        self._average = self._total / len(self._marks)
        return self._average

    def grade(self) -> str:
        '''Grades the student's average mark'''
        if 80 <= self._average <= 100: return "A"
        elif self._average >= 60: return "B"
        elif self._average >= 40: return "C"
        else: return "F"

    def input_marks(self) -> None:
        '''Inputs student marks for five subjects'''
        print(f"\nYou are required to input {self._name}'s marks in five subjects....")
        iterations = 0
        while iterations < 5:
            try:
                marks = float(input(f"Marks for subject {iterations + 1}: "))

                # Validate input for marks
                if marks > 100 or marks < 0:
                    print("[ERROR] Marks must be between 0 - 100! Try again.\n")
                    continue

                # Append valid marks to list and update counter variable
                self._marks.append(marks)
                iterations += 1

            except ValueError:
                print(f"[ERROR] Invalid input! Marks must be a number between 0 and 100!Try again.\n")
                continue
        print(f"Input operation for 5 marks successful! 👍\n")

if __name__ == '__main__':
    print("----------📔 WELCOME TO THE STUDENT GRADING SYSTEM 📔---------")

    # Prompt user for student name and marks
    name = input("\nEnter the student's name: ").strip()
    student = Student(name=name)
    student.input_marks()

    # Compute average score and grade using the student objects methods
    average = student.calculate_average()
    grade = student.grade()

    # Print results
    print("\n..... RESULTS FOR STUDENT ..... ")
    print(f"Student name: {student._name}")
    print(f"Average score: {average:.2f}")
    print(f"Grade: {grade}\n")