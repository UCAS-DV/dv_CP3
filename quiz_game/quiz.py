import csv
import random

red = "\033[31m"
green = "\033[32m"
reset = "\033[0m"

# Asks a question
def ask_question(question, answer, options):

    while True:
        print(question)

        i = 0
        for option in options:
            i += 1
            print(f"{i}. {option}")

        user_answer = int(input('What is your answer (Enter Number)? '))

        try:
            if user_answer == int(answer):
                print(f'{green}Correct!{reset}')
                return 1
            else:
                print(f'{red}Incorrect (for shame)!{reset}')
                return 0
        except:
            print(f'{red}Invalid Input!{reset}')

# Gets the questions from the csv and converts them into a dictionaries
def get_questions(filepath):

    questions = []

    with open(filepath, 'r') as question_file:
        question_reader = csv.reader(question_file)

        for question in question_reader:

            # Checks if question is actually header
            if question != ['question','option1','option2','option3','option4','answer']:

                question_dict = {
                    'question': question[0],
                    'options': [question[1], question[2], question[3], question[4]],
                    'answer': question[5]
                }

                questions.append(question_dict)

    return questions

# Shuffles the questions
def randomize_questions(all_questions):

    random.shuffle(all_questions)

    questions = []

    for i in range(0,10):
        questions.append(all_questions[i])

    return questions