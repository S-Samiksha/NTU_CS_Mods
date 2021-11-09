# Introduction
import turtle
import time
wn = turtle.Screen()
wn.bgcolor("White")
wn.setup(width=500, height=500)
wn.title("Analog Clock SG time")
wn.tracer(0)



# Create our drawing pen
pen = turtle.Turtle()
pen.hideturtle()
pen.speed(0)
pen.pensize(3)


def draw_clock(h, m, s, pen):

# Draw clock face
    pen.up()
    pen.goto(0, 150)
    pen.setheading(180)
    pen.color("black")
    pen.pendown()
    pen.circle(150)

#Draw the hour lines
    pen.penup()
    pen.goto(0,0)
    pen.setheading(90)

    for _ in range(12):
        pen.fd(120)
        pen.pendown()
        pen.fd(30)
        pen.penup()
        pen.goto(0, 0)
        pen.rt(30)

# Drawing the minute lines
    pen.penup()
    pen.goto(0,0)
    pen.setheading(90)

    for _ in range(60):
        pen.fd(140)
        pen.pendown()
        pen.fd(10)
        pen.penup()
        pen.goto(0, 0)
        pen.rt(6)

# Draw the Hour hand
    pen.penup()
    pen.goto(0,0)
    pen.color("red")
    pen.setheading(90)
    angle = (h/12) * 360 + m/2
    pen.rt(angle)
    pen.pendown()
    pen.fd(80)

#Draw the minute hand
    pen.penup()
    pen.goto(0,0)
    pen.color("blue")
    pen.setheading(90)
    angle = (m/60) * 360
    pen.rt(angle)
    pen.pendown()
    pen.fd(110)

#Draw the second hand
    pen.penup()
    pen.goto(0,0)
    pen.color("gold")
    pen.setheading(90)
    angle = (s/60) * 360
    pen.rt(angle)
    pen.pendown()
    pen.fd(115)

while True:
    h = int(time.strftime("%I"))
    m = int(time.strftime("%M"))
    s = int(time.strftime("%S"))

    draw_clock(h,m,s,pen)
    wn.update()

    time.sleep(1)

    pen.clear()





wn.mainloop()
