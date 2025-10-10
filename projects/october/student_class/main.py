class Student:

    """Student class with id, name, and grade
    Methods include __init__, getGrade, setGrade, and __str__"""

    def __init__(self, id = "000", name = "John Doe", grade = 100):
        """Intializes attributes"""
        self.id = id
        self.name = name
        self.grade = grade
    
    def getGrade(self):
        """Print grade"""
        print(f"{self.name}'s new grade: {self.grade}")
        return self.grade
    
    def setGrade(self, new_grade):
        """Set grade"""
        self.grade = new_grade

    def __str__(self):
        """Print student object"""
        return f"Student ID: {self.id}, Name: {self.name}, Grade: {self.grade}"
        
alice = Student("001", "Alice Smith", 95)
bob = Student("002", "Bob Johnson", 88)
charlie = Student("003", "Charlie Brown", 92)
diana = Student("004", "Diana Prince", 97)
john = Student()

print("Initial student infromation: ")

print(alice)
print(bob)
print(charlie)
print(diana)
print(john)

alice.setGrade(98)
charlie.setGrade(94)
john.setGrade(85)

print("\nUpdated grades: ")

alice.getGrade()
charlie.getGrade()
john.getGrade()