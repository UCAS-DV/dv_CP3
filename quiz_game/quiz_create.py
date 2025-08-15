import csv
from quiz import red
from quiz import reset

def create_question(filepath):

    question = [
        input('What is your question? '),
        input('What is your first answer? ')
        input('What is your second answer? ')
        input('What is your third answer? ')
        input('What is your fourth answer? ')
    ]

    while True:

        correct_answer = 
        if input(f"1. {question[1]} \n2. {question[2]} \n3. {question[3]} \n4. {question[4]} \nWhich answer is correct? (Enter Number) ") not in ['1', '2', '3', '4']:
            print("")


    with open(filepath, 'a', newline='') as quiz_file:
        question_writer = csv.writer(quiz_file)

        


def create_quiz():

    quiz_name = input("What will you be naming this quiz? ")

    open(f"quiz_game/{quiz_name}.csv", 'x')

    while True:
        match input('1. Create Question \n2. Delete Question \n3. Read Questions \n4. Exit \nWhat would you like to do? (Enter Number) '):
            case '1':
                create_question(f"quiz_game/{quiz_name}.csv")
            case '4':
                print("Exiting...")
                break
            case _:
                print(f'{red}Invalid Input{reset}')

def create_quiz_menu():
    while True:
        match input('1. Create New Quiz \n2. Modify Quiz \n3. Delete Quiz \n4. Exit \nWhat would you like to do? (Enter Number) '):
            case '1':
                create_quiz()
            case '4':
                print("Exiting...")
                break
            case _:
                print(f'{red}Invalid Input{reset}')