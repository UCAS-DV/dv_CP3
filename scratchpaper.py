import keyboard

x_cord = 0
y_cord = 0

true_x_cord = 0
true_y_cord = 0

speed = 5
true_speed = speed * 0.0001

def main():
    while True:
        if keyboard.is_pressed("w"):
            true_y_cord += true_speed
        if keyboard.is_pressed("s"):
            true_y_cord -= true_speed
        if keyboard.is_pressed("a"):
            true_x_cord -= true_speed