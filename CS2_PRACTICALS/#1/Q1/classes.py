class Student:
    def __init__(self, reg, name, marks: list) -> None:
        self.reg_number = reg
        self.name = name
        self.marks = marks # A list containing marks in computer science, mathematics and physics

    def total_marks(self) -> float:
        return sum(self.marks)

    def average_marks(self) -> float:
        return sum(self.marks) / len(self.marks)

    def grade(self) -> str:
        if self.average_marks() >= 80: return 'A'
        elif self.average_marks() >= 70: return 'B'
        elif self.average_marks() >= 60: return 'C'
        elif self.average_marks() >= 50: return 'D'
        elif self.average_marks() >= 40: return 'E'
        else: return 'F'

    def details(self) -> None:
        '''Custom method for student details'''
        print(f"Student registration number: {self.reg_number}")
        print(f"Student name: {self.name}")
        print(f"Total marks: {self.total_marks()} (out of 300)")
        print(f"Average mark: {self.average_marks()}")
        print(f"Grade: {self.grade()}\n")

class ScienceStudent(Student):
    def __init__(self, reg, name, marks: list) -> None:
        super().__init__(reg, name, marks)

    def grade(self) -> str:
        'Overrides method grade() from base class Student'
        if self.average_marks() >= 50: return 'PASS'
        else: return 'NEEDS IMPROVEMENT'

if __name__ == '__main__':
    student1 = Student('1001', 'Brendan Snow', [80, 90, 75])
    student2 = ScienceStudent('1002', 'Jonathan Basil', [65, 80, 79])

    print("Demonstrating polymorphism via overriden method grade().....")
    print(f"Calling grade() on student 1: {student1.grade()}")
    print(f"Calling grade() on student 2: {student2.grade()}\n")