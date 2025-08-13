
def select(*args):

    question = args[0]

    while True:
        print(question)
        for arg in args:
            if arg != question:
                print(arg)
        

        
