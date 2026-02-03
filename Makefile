# ==========================================
# Name: Anurag Prashant Umale              =   
# Student Id: 1887255                      =
# E-mail: aumale@ucsc.edu                  =
# File: Makefile						   =
# Class: CSE 101 Spring 2023               =
# ==========================================

CC = gcc
CFLAGS = -std=c17 -Wall

all: Lex ListTest

Lex: Lex.o List.o
	$(CC) -o $@ $^

ListTest: ListTest.o List.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f Lex ListTest List *.o

checkTest:
	valgrind --leak-check=full ./ListTest

checkLex:
	valgrind --leak-check=full ./Lex infile outfile
