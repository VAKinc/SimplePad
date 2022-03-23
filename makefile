# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
 
app: app.o
    $(CC) $(CFLAGS) -o app app.o gamepad.o
 
# The app.o target can be written more simply
 
app.o: app.cpp gamepad.h
    $(CC) $(CFLAGS) -c app.cpp
 
gamepad.o: gamepad.h
