from quiz import ask_question
from quiz import get_questions
from quiz import randomize_questions
from quiz import red
from quiz import reset
from quiz_create import create_quiz_menu
from quiz_create import display_quizzes
from quiz_create import get_quizzes

# Gives user the question and grades them
def give_quiz(questions):

    total_points = len(questions)
    points = 0

    for question in questions:
        # If answer is correct, add 1 point, if not, add no points
        points += ask_question(question['question'], question['answer'], question['options'])

    return f'{points}/{total_points}'



# Runs the main menu and enters the quiz
def main():
    while True:
        print("-~-~-~-~- THE QUIZ GAME -~-~-~-~-")

        print("1. Take Quiz \n2. Create Quiz \n3. Exit")
        
        selection = input("What would you like to do? (Enter Number) ")

        if selection == "3":
            print('Exiting')
            break
        elif selection == '2':
            create_quiz_menu()
        elif selection == '1':

            display_quizzes(False)

            try:
                questions = randomize_questions(get_questions(get_quizzes(False)[int(input('What quiz would you like to take? (Enter Number) ')) - 1]))
                print(give_quiz(questions))
            except:
                print(f'{red}Invalid Input{reset}')

main()