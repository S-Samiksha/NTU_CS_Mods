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

#Player X
def player_X(position):
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.hideturtle()
    pen.penup()
    if position_dict[position] != "":
        position = str(turtle.textinput("Player X", "Do not override Player O's Position. Enter a valid position: "))
        player_X(position)
    elif position == "C":
        position_dict["C"]= "X"
        pen.goto(0,0)
        pen.write("X", font = ("Arial", 20, "normal"))
    elif position == "CT":
        position_dict["CT"] = "X"
        pen.goto(0,50)
        pen.write("X", font = ("Arial", 20, "normal"))
    elif position == "CB":
        position_dict["CB"] = "X"
        pen.goto(0,-150)
        pen.write("X", font = ("Arial", 20, "normal"))
    elif position == "TR":
        position_dict["TR"] = "X"
        pen.goto(75,50)
        pen.write("X", font = ("Arial", 20, "normal"))
    elif position == "CR":
        position_dict["CR"] = "X"
        pen.goto(75,0)
        pen.write("X", font = ("Arial", 20, "normal"))
    elif position == "BR":
        position_dict["BR"] = "X"
        pen.goto(75,-150)
        pen.write("X", font = ("Arial", 20, "normal"))
    elif position == "TL":
        position_dict["TL"] = "X"
        pen.goto(-75,50)
        pen.write("X", font = ("Arial", 20, "normal"))
    elif position == "CL":
        position_dict["CL"] = "X"
        pen.goto(-75,0)
        pen.write("X", font = ("Arial", 20, "normal"))
    elif position == "BL":
        position_dict["BL"] = "X"
        pen.goto(-100,-100)
        pen.write("X", font = ("Arial", 20, "normal"))
    else:
        position = str(turtle.textinput("Player X", "Please enter a VALID position: "))
        player_X(position)

#Player O
def player_O(position):
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.hideturtle()
    pen.penup()
    if position_dict[position] != "":
        position = str(turtle.textinput("Player O", "Do not override Player X's Position. Enter a valid position: "))
        player_O(position)
    elif position == "C":
        position_dict["C"] = "O"
        pen.goto(0,0)
        pen.write("O", font = ("Arial", 20, "normal"))
    elif position == "CT":
        position_dict["CT"] = "O"
        pen.goto(0,50)
        pen.write("O", font = ("Arial", 20, "normal"))
        pen.write("O", font = ("Arial", 20, "normal"))
    elif position == "CB":
        position_dict["CB"] = "O"
        pen.goto(0,-150)
        pen.write("O", font = ("Arial", 20, "normal"))
    elif position == "TR":
        position_dict["TR"] = "O"
        pen.goto(75,50)
        pen.write("O", font = ("Arial", 20, "normal"))
    elif position == "CR":
        position_dict["CR"] = "O"
        pen.goto(75,0)
        pen.write("O", font = ("Arial", 20, "normal"))
    elif position == "BR":
        position_dict["BR"] = "O"
        pen.goto(75,-150)
        pen.write("O", font = ("Arial", 20, "normal"))
    elif position == "TL":
        position_dict["TL"] = "O"
        pen.goto(-75,50)
        pen.write("O", font = ("Arial", 20, "normal"))
    elif position == "CL":
        position_dict["CL"] = "O"
        pen.goto(-75,0)
        pen.write("O", font = ("Arial", 20, "normal"))
    elif position == "BL":
        position_dict["BL"] = "O"
        pen.goto(-100,-100)
        pen.write("O", font = ("Arial", 20, "normal"))
    else:
        position = str(turtle.textinput("Player O", "Please enter a VALID position: "))
        player_O(position)


#Conditions to Win------------------------------------------------------------------------------------------------------

cond = True

def conditions():
    pen = turtle.Turtle()
    pen.speed(0)
    pen.color("black")
    pen.hideturtle()
    pen.penup()
    pen.goto(-100, 0)
    global cond
    global position_dict
    if position_dict["CL"] == position_dict["C"] == position_dict["CR"] == "X":
        time.sleep(1)
        wn.clear()
        pen.write("Player X wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["CL"] == position_dict["C"] == position_dict["CR"] == "O":
        time.sleep(1)
        wn.clear()
        pen.write("Player O wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["CT"] == position_dict["TR"] == "O":
        time.sleep(1)
        wn.clear()
        pen.write("Player O wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["CT"] == position_dict["TR"] == "X":
        time.sleep(1)
        wn.clear()
        pen.write("Player X wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["BL"] == position_dict["CB"] == position_dict["BR"] == "X":
        time.sleep(1)
        wn.clear()
        pen.write("Player X wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["BL"] == position_dict["CB"] == position_dict["BR"] == "O":
        time.sleep(1)
        wn.clear()
        pen.write("Player O wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["C"] == position_dict["BR"] == "O":
        time.sleep(1)
        wn.clear()
        pen.write("Player O wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["C"] == position_dict["BR"] == "X":
        time.sleep(1)
        wn.clear()
        pen.write("Player X wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TR"] == position_dict["C"] == position_dict["BL"] == "O":
        time.sleep(1)
        wn.clear()
        pen.write("Player O wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TR"] == position_dict["C"] == position_dict["BL"] == "X":
        time.sleep(1)
        wn.clear()
        pen.write("Player X wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TR"] == position_dict["CR"] == position_dict["BR"] == "O":
        time.sleep(1)
        wn.clear()
        pen.write("Player O wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TR"] == position_dict["CR"] == position_dict["BR"] == "X":
        time.sleep(1)
        wn.clear()
        pen.write("Player X wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["CL"] == position_dict["BL"] == "O":
        time.sleep(1)
        wn.clear()
        pen.write("Player O wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["TL"] == position_dict["CL"] == position_dict["BL"]== "X":
        time.sleep(1)
        wn.clear()
        pen.write("Player X wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["CT"] == position_dict["C"] == position_dict["CB"] == "X":
        time.sleep(1)
        wn.clear()
        pen.write("Player X wins!", font=("Arial", 20, "normal"))
        cond = False
    elif position_dict["CT"] == position_dict["C"] == position_dict["CB"] == "O":
        time.sleep(1)
        wn.clear()
        pen.write("Player O wins!", font=("Arial", 20, "normal"))
        cond = False



#The Game Loop----------------------------------------------------------------------------------------------------------
count = 0

#While the game is still going and no draw has occurred-----------------------------------------------------------------
while count < 10 and cond == True:
    position = str(turtle.textinput("Player X", "Please enter the position that you want to put X: "))
    player_X(position)
    conditions()
    count += 1
    if count == 9 or cond == False:
        time.sleep(1)
        break
    time.sleep(1)
    position = str(turtle.textinput("Player O", "Please enter the position that you want to put O: "))
    player_O(position)
    conditions()
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
