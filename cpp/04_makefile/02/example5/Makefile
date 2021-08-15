# Demonstration of including another makefile

all : test

test : main.o test1.o test2.o
	g++ main.o test1.o test2.o -o test

main.o : main.cpp
	g++ -c main.cpp
	
include test1.mk 

include test2.mk

include clean.mk