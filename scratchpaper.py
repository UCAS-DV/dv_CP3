from tkinter import *

Facts = ["""A man can be arrested in
Italy for wearing a skirt in public.""",
"""Obama was the first black president."""]

root = Tk()

# specify size of window.
root.geometry("250x170")

# Create text widget and specify size.
T = Text(root, height = 5, width = 52)

# Create label
l = Label(root, text = "Fact of the Day")
l.config(font =("Courier", 14))

def change_fact():
    Facts[1]
    # Insert The Fact.
    T.insert(END, Facts[1])

# Create button for next text.
b1 = Button(root, text = "Next", command=change_fact)

# Create an Exit button.
b2 = Button(root, text = "Exit",
            command = root.destroy) 

l.pack()
T.pack()
b1.pack()
b2.pack()

# Insert The Fact.
T.insert(END, Facts[0])

mainloop()