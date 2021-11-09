#Importing the modules -------------------------------------------------------------------------------------------------
import turtle
import time

#Getting the screen from turtle ----------------------------------------------------------------------------------------
wn = turtle.Screen()
wn.title("Tic Tac Toe")
wn.bgcolor("white")
wn.setup(width=700, height=500)
wn.tracer(0)

# Writing the title on the screen---------------------------------------------------------------------------------------
pen = turtle.Turtle()
pen.speed(0)
pen.color("black")
pen.penup()
pen.hideturtle()
pen.penup()
pen.goto(-190,210)
pen.write("Welcome to The Game of Tic Tac Toe!", font = ("Arial", 16, "normal"))

#Drawing the tic tac toe board------------------------------------------------------------------------------------------
#Draw the horizontal lines
def draw_hline(x,y):
    pen.speed(0)
    pen.color("black")
    pen.pensize(2)
    pen.penup()
    pen.goto(x,y)
    pen.pendown()
    pen.forward(300)

draw_hline(-150,50)
draw_hline(-150,-50)

#Draw the vertical lines
def draw_vline(x,y):
    pen.speed(0)
    pen.color("black")
    pen.pensize(2)
    pen.penup()
    pen.goto(x,y)
    pen.setheading(270)
    pen.pendown()
    pen.forward(300)

draw_vline(-50,150)
draw_vline(50,150)
wn.update()

#Defining the positions on the board------------------------------------------------------------------------------------
position_dict ={
    "C":"",
    "CT":"",
    "CB":"",
    "TR":"",
    "TL":"",
    "BR":"",
    "BL":"",
    "CR":"",
    "CL":""
}

#Defining the player function-------------------------------------------------------------------------------------------
def current_player(position, symbol):
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.hideturtle()
    pen.penup()
    if position_dict[position] != "":
        position = str(turtle.textinput("Current Player {}".format(symbol), "Do not override the other player's Position. Enter a valid position: "))
        current_player(position,symbol)
    elif position == "C":
        position_dict["C"]= symbol
        pen.goto(0,0)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    elif position == "CT":
        position_dict["CT"] = symbol
        pen.goto(0,50)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    elif position == "CB":
        position_dict["CB"] = symbol
        pen.goto(0,-150)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    elif position == "TR":
        position_dict["TR"] = symbol
        pen.goto(75,50)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    elif position == "CR":
        position_dict["CR"] = symbol
        pen.goto(75,0)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    elif position == "BR":
        position_dict["BR"] = symbol
        pen.goto(75,-150)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    elif position == "TL":
        position_dict["TL"] = symbol
        pen.goto(-75,50)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    elif position == "CL":
        position_dict["CL"] = symbol
        pen.goto(-75,0)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    elif position == "BL":
        position_dict["BL"] = symbol
        pen.goto(-100,-100)
        pen.write(symbol, font = ("Arial", 20, "normal"))
    else:
        position = str(turtle.textinput("Current Player {}".format(symbol), "Please enter a VALID position: "))
        current_player(position,symbol)

#Conditions to Win------------------------------------------------------------------------------------------------------
cond = True
def conditions(current_symbol):
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.hideturtle()
    pen.penup()
    pen.goto(-100, 0)
    global cond
    global position_dict
    if position_dict["CL"] == position_dict["C"] == position_dict["CR"] == current_symbol:
        time.sleep(1)
        wn.clear()
        pen.write("Player {} wins!".format(current_symbol), font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["CT"] == position_dict["TR"] == current_symbol:
        time.sleep(1)
        wn.clear()
        pen.write("Player {} wins!".format(current_symbol), font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["BL"] == position_dict["CB"] == position_dict["BR"] == current_symbol:
        time.sleep(1)
        wn.clear()
        pen.write("Player {} wins!".format(current_symbol), font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["C"] == position_dict["BR"] == current_symbol:
        time.sleep(1)
        wn.clear()
        pen.write("Player {} wins!".format(current_symbol), font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TR"] == position_dict["C"] == position_dict["BL"] == current_symbol:
        time.sleep(1)
        wn.clear()
        pen.write("Player {} wins!".format(current_symbol), font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TR"] == position_dict["CR"] == position_dict["BR"] == current_symbol:
        time.sleep(1)
        wn.clear()
        pen.write("Player {} wins!".format(current_symbol), font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["CL"] == position_dict["BL"] == current_symbol:
        time.sleep(1)
        wn.clear()
        pen.write("Player {} wins!".format(current_symbol), font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["CT"] == position_dict["C"] == position_dict["CB"] == current_symbol:
        time.sleep(1)
        wn.clear()
        pen.write("Player {} wins!".format(current_symbol), font=("Arial", 20, "normal"))
        cond = False

#The Game Loop----------------------------------------------------------------------------------------------------------
#While the game is still going and no draw has occurred-----------------------------------------------------------------
count = 0
while count < 10 and cond == True:
    current_symbol = "X"
    position = str(turtle.textinput("Player {}".format(current_symbol), "Please enter the position that you want to put X: "))
    current_player(position, current_symbol)
    conditions(current_symbol)
    count += 1
    if count == 9 or cond == False:
        time.sleep(1)
        break
    time.sleep(1)
    current_symbol = "O"
    position = str(turtle.textinput("Player {}".format(current_symbol), "Please enter the position that you want to put O: "))
    current_player(position, current_symbol)
    conditions(current_symbol)
    count += 1
    if count == 9 or cond == False:
        time.sleep(1)
        break
    wn.update()

#once a draw has happened-----------------------------------------------------------------------------------------------
if count == 9 and cond==True:
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.hideturtle()
    pen.penup()
    pen.goto(-50, 0)
    wn.clear()
    pen.write("DRAW!", font=("Arial", 20, "normal"))

wn.update()
wn.mainloop()
#End!!------------------------------------------------------------------------------------------------------------------
