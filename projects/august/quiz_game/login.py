import csv
from quiz import red
from quiz import reset

# Reads profile file
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

def select_profile(prompt):
    while True:

        profiles = read_file()

        i = 0
        for profile in profiles:
            i += 1
            print(f'{i}. {profile['username']} - {profile['status']}')
            
        try:
            selection = input(prompt)
            selected_profile = profiles[int(selection) - 1]
        except:
            print(f'{red}Invalid Input{reset}')
            continue

        return selected_profile

def delete_profile():

    profiles = []

    while True:

        profiles = read_file()

        i = 0
        for profile in profiles:
            i += 1
            print(f'{i}. {profile['username']} - {profile['status']}')
            
        try:
            selection = int(input('Choose a profile to delete (Enter Number)'))
            break
        except:
            print(f'{red}Invalid Input{reset}')
            continue

    match input(f"1. No \n2. Yes \nAre you sure that you wish to delete {profiles[selection - 1]['username']} (Enter Number? "):
        case '1':
            return None
        case '2':
            pass

    profiles.pop(selection - 1)

    with open('quiz_game/profiles.csv', 'w', newline='') as profile_file:
        profile_writer = csv.writer(profile_file)

        profile_writer.writerow(['name', 'password', 'status'])

        for profile in profiles:
            profile_writer.writerow([profile['username'],
                                     profile['password'],
                                     profile['status']])

    


# Creates questions
def create_profile(is_admin):

    profile = [
        input('Enter new username: '),
        input('Enter new password: '),
    ]

    if is_admin:
        profile.append("Admin")
    else:
        profile.append("User")
    
    # Adds header and new profile
    with open('quiz_game/profiles.csv', 'a', newline='') as profile_file:
        question_writer = csv.writer(profile_file)
        question_writer.writerow(profile)

# User login menu
def login():

    while True:

        profiles = read_file()

        if profiles:
            selected_profile = select_profile("Choose a profile (Enter Number): ")

            if input(f"What is the password for {selected_profile['username']}: ") == selected_profile['password']:
                if selected_profile['status'] == 'Admin':
                    return True
                else:
                    return False
            else:
                print(f'{red}Incorrect Password{reset}')
        else:
            create_profile(True)