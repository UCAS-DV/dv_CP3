class Animal():
    def __init__(self, age, color):
        self.age = age
        self.color = color

    def growOlder(self):
        self.age += 1

    def __str__(self):
        return f"Age: {self.age}\nColor: {self.color}"

class Dog(Animal):
    def __init__(self, age, color):
        super().__init__(age, color)
        