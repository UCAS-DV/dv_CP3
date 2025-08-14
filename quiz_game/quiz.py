import csv
import random

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
                print('Correct!')
                return 1
            else:
                print('Incorrect (for shame)!')
                return 0
        except:
            print('Invalid Input!')

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

def randomize_questions(all_questions):

    random.shuffle(all_questions)

    questions = []

    for i in range(0,10):
        questions.append(all_questions[i])

    return questions