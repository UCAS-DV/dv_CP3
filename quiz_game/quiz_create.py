import csv
from quiz import red
from quiz import reset
from quiz import get_questions
import os
from pathlib import Path

def get_quizzes():\

    quiz_filepaths = []
    for file in os.listdir("quiz_game/quizzes"):
        if str(file) != 'general_questions.csv':
            quiz_filepaths.append(f'quiz_game/quizzes/{str(file)}')

    return quiz_filepaths

# Creates questions
def create_question(filepath):

    question = [
        input('What is your question? '),
        input('What is your first answer? '),
        input('What is your second answer? '),
        input('What is your third answer? '),
        input('What is your fourth answer? ')
    ]

    # Gets correct answer from user
    while True:

        correct_answer = input(f"1. {question[1]} \n2. {question[2]} \n3. {question[3]} \n4. {question[4]} \nWhich answer is correct? (Enter Number) ")
        if correct_answer not in ['1', '2', '3', '4']:
            print(f'{red}Invalid Input{reset}')
        else:
            question.append(correct_answer)
            break
    
    # Adds question to quiz_file
    with open(filepath, 'a', newline='') as quiz_file:
        question_writer = csv.writer(quiz_file)

        question_writer.writerow(question)

# Menu for creating, deleting, and reading questions
def modify_quiz(filepath):
    
    while True:
        match input('1. Create Question \n2. Delete Question \n3. Read Questions \n4. Exit \nWhat would you like to do? (Enter Number) '):
            case '1':
                create_question(filepath)
            case '3':
                i = 0
                for question in get_questions():
                    i += 1
                    print(f'{i}. {question['question']}')

                    j = 0
                    for option in question['options']:
                        j += 1
                        print(f'    {j}. {option}')

                    print(f'    {question['answer']}')

                input("If you're done looking, enter anything: ")

            case '4':
                # Checks if quiz is long enough to be saved. If it doesn't, the quiz will be deleted
                if len(get_questions(filepath)) < 11:
                    if input('Warning: You do not have the required 10 questions to save your quiz. If you exit now, your quiz will be deleted. Do you wish to exit? (Y/N) ').lower() != 'y':
                        continue
                    else:
                        os.remove(filepath)

                print("Exiting...")
                break
            case _:
                print(f'{red}Invalid Input{reset}')

# Menu for creating, modifying, and deleting quizzes.
def create_quiz_menu():
    while True:
        match input('1. Create New Quiz \n2. Modify Quiz \n3. Delete Quiz \n4. Exit \nWhat would you like to do? (Enter Number) '):
            case '1':

                quiz_name = f'quiz_game/quizzes/{input("What will you be naming this quiz? ")}.csv'

                # Creates new quiz
                open(quiz_name, 'x')

                # Adds header
                with open(quiz_name, 'w', newline='') as quiz_file:
                    header_writer = csv.writer(quiz_file)

                    header_writer.writerow(['question', 'option1', 'option2', 'option3', 'option4', 'answer'])

                modify_quiz(quiz_name)
            case '2':
                i = 0
                # Lists out quizzes
                for quiz in get_quizzes():
                    i += 1
                    print(f'{i}. {quiz}')

                try:
                    modify_quiz(get_quizzes()[int(input('What quiz would you like to modify? (Enter Number) ')) - 1])
                except:
                    print(f'{red}Invalid Input{reset}')
            case '3':

                i = 0
                # Lists out quizzes
                for quiz in get_quizzes():
                    i += 1
                    print(f'{i}. {quiz}')

                try:
                    os.remove(get_quizzes()[int(input('What quiz would you like to delete? (Enter Number) ')) - 1])
                except:
                    print(f'{red}Invalid Input{reset}')

            case '4':
                print("Exiting...")
                break
            case _:
                print(f'{red}Invalid Input{reset}')