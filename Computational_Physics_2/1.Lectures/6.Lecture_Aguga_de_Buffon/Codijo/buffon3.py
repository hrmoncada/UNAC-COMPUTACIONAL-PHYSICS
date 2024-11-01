#Estimating Pi using Buffon's Needle - www.101computing.net/estimating-pi-using-buffons-needle
# https://www.101computing.net/estimating-pi-using-buffons-needle/
import turtle
import random

boardWidth = 40
needleLength = 30
numberOfNeedles = 50
    
myPen = turtle.Turtle()
myPen.hideturtle()
myPen.speed(0)

y=180
#Draw floor boards
for i in range(0,10):
   myPen.penup()
   myPen.goto(-200,y)
   myPen.pendown()
   myPen.goto(200,y)
   y-=boardWidth

#Draw Needles
myPen.color("#f442d1")
for needle in range(0,numberOfNeedles):
   x=random.randint(-180,180)
   y=random.randint(-180,180)
   angle=random.randint(0,360)
   myPen.penup()
   myPen.goto(x,y)
   myPen.setheading(angle)
   myPen.pendown()
   myPen.forward(needleLength)
  
print("L = " + str(needleLength))
print("N = " + str(numberOfNeedles))
print("W = " + str(boardWidth))
print("C = ???")
