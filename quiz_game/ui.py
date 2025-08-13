
def select(*options):

    title = ''

    for option in options:

        # IF option is the first option, make option the title.
        if option == options[0]:
            title = option
            continue

        
