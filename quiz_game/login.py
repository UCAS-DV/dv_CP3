import csv

def read_file():

    profiles = []

    with open('quiz_game/profiles.csv', 'r') as profile_file:
        profile_reader = csv.reader(profile_file) 

        for profile in profile_reader:

            # Checks if question is actually header
            if profile != ['name','password','status']:

                profile_dict = {
                    'username': profile[0],
                    'password': profile[1],
                    'status': profile[2]
                }

                profiles.append(profile_dict)

    return profiles

def login():
    
    profiles = read_file()

    i = 0
    for profile in profiles:
        i += 1
        print(f'{i}. {profile['username']} - {profile['status']}')
    
    selection = input("Which profile would you like to access?")

    selection = int(selection)

login()

