from classes import Student

def validate_reg_no(reg_no: str) -> float:
    if not reg_no:
        print("Registration number cannot be empty! Try again\n\n")
        return False
    return True

def validate_mark(mark: float) -> bool:
    if mark < 0 or mark > 100:
        print(f"Input {mark} not allowed! Marks must be between 0 and 100. Try again\n\n")
        return False
    return True

def input_student_details() -> dict:
    while True:
        reg_no = input("Student registration number: ").strip()
        if validate_reg_no(reg_no):
            break
        else: continue
    
    name = input("Student name: ").strip()
    marks = []

    for subject in ('Computer Science', 'Mathematics', 'Physics'):
        while True:
            score = float(input(f"{name}'s marks in {subject}: "))
            if validate_mark(score):
                marks.append(score)
                break
            else: continue
    return {
        'reg_no': reg_no, 'name': name, 'marks': marks
    }

def main() -> None:
    print("------ WELCOME TO THE STUDENT EXAMINATION RESULTS MANAGEMENT PROGRAM ------")
    print("You are required to input details for at least three students...")
    students = [] # A list to hold student objects

    for i in range(3):
        print(f"\nINFORMATION FOR STUDENT #{i + 1}")
        details = input_student_details()

        # Create instances of class Student
        student = Student(details['reg_no'], details['name'], details['marks'])
        students.append(student) # Append student to students list

    print("\nINPUT SUCCESSFUL! The following is the data for the three students you have registered...")

    for student in students:
        student.details()