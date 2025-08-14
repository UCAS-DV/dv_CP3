import csv
import quiz
import random

def give_quiz(questions):

    total_points = len(questions)
    points = 0

    for question in questions:
        points += quiz.ask_question(question['question'], question['answer'], question['options'])

    return f'{points}/{total_points}'

def main():
    while True:

        questions = quiz.randomize_questions(quiz.get_questions("quiz_game\general_questions.csv"))

        print(give_quiz(questions))

main()