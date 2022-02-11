import random
import turtle
import math
import time

# Window Settings
wn = turtle.Screen()
wn.title("Bulls and Cows")
wn.bgcolor("white")
wn.setup(width=700, height=500)
wn.tracer(0)

#Writing the title on the screen
pen = turtle.Turtle()
pen.speed(0)
pen.color("black")
pen.penup()
pen.hideturtle()
pen.goto(-190,210)
pen.write("Welcome to the Bulls and Cows Game!", font = ("Arial", 16, "normal"))

#Function to write the number of trials and track previous trials
def pen(guess,number, bull, cow):
    guess = guess_list
    number = count
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.penup()
    pen.hideturtle()
    pen.goto(-290,190-number*10)
    pen.write("Try", font = ("Arial", 12, "normal"))
    pen.goto(-267, 190 - number * 10)
    pen.write(number, font = ("Arial", 12, "normal"))
    pen.goto(-260, 190 - number * 10)
    pen.write(":", font = ("Arial", 12, "normal"))
    pen.goto(-253, 190 - number * 10)
    pen.write(guess, font = ("Arial", 12, "normal"))
    pen.goto(90,190 - number * 10)
    pen.write(bull, font = ("Arial", 12, "normal"))
    pen.goto(105, 190 - number * 10)
    pen.write("Bulls", font = ("Arial", 12, "normal"))
    pen.goto(145, 190 - number * 10)
    pen.write(cow, font = ("Arial", 12, "normal"))
    pen.goto(158, 190 - number * 10)
    pen.write("Cows", font = ("Arial", 12, "normal"))


# Make sure the input is correct
def getinput():
    count2 = 0
    guess = turtle.textinput("Get Value ", "Please input a four digit value separated by a space: ")
    guess_list = guess.split()
    while count2 < 5:
        if len(guess) != 7 and len(guess_list) !=4:
            guess = turtle.textinput("Error!", "Please input a FOUR digit value SEPARATED by a space: ")
            guess_list = guess.split()
            time.sleep(1)
            count2 += 1
        else:
          break
    else:
        print("You have reached maximum trial limit")
    return guess_list

# Defining variables
count = 0
fourDigitRandom = [random.randint(0,9), random.randint(0,9), random.randint(0,9), random.randint(0,9)]
A_Bull = 0
B_Cow_raw = 0
B_Cow_net = 0

while A_Bull < 4 and count < 5:
        # Change the input value into list
        A_Bull = 0
        B_Cow_raw = 0
        B_Cow_net = 0
        count += 1
        guess_list = getinput()
        for i in range(len(fourDigitRandom)):
            if fourDigitRandom[i] == int(guess_list[i]):
                A_Bull += 1
            else:
                A_Bull += 0
        for i in range(len(fourDigitRandom)):
            if fourDigitRandom in guess_list:
                B_Cow_raw += 1
            else:
                B_Cow_raw += 0
        B_Cow_net = B_Cow_raw
        pen(guess_list, count, A_Bull, B_Cow_net)
        time.sleep(2)
else:
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.penup()
    pen.hideturtle()
    pen.write("You have lost the game! The actual answer was: ", align = "center", font = ("Arial", 16, "normal"))
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.penup()
    pen.hideturtle()
    pen.goto(-50, -20)
    pen.write(fourDigitRandom, font = ("Arial", 16, "normal"))
    time.sleep(5)
    wn.clearscreen()
    turtle.bye()

wn.mainloop()
