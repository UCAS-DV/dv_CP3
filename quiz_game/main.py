import quiz
from quiz_create import create_quiz_menu

# Gives user the question and grades them
def give_quiz(questions):

    total_points = len(questions)
    points = 0

    for question in questions:
        points += quiz.ask_question(question['question'], question['answer'], question['options'])

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
            questions = quiz.randomize_questions(quiz.get_questions("quiz_game/general_questions.csv"))

            print(give_quiz(questions))

main()