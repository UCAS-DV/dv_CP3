import csv

def get_questions():

    questions = []

    with open('quiz_game\questions.csv', 'r') as question_file:
        question_reader = csv.reader(question_file)

        for question in question_reader:

            # Checks if question is actually header
            if question != ['question','option1','option2','option3','option4','answer']:
                
                question_dict = {
                    'question': question[0],
                    'option1': question[1],
                    'option2': question[2],
                    'option3': question[3],
                    'option4': question[4],
                    'answer': question[5]
                }

                questions.append(question_dict)

    return questions 


def main():
    while True:

        print("-~-~-~-~-~-~- The Ultimate Quiz of Life -~-~-~-~-~-~-")

        print(get_questions())

        break

main()