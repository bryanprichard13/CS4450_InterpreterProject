# CS4450_InterpreterProject
CS4450 Interpreter Project 2020

Group Name: THE INTERPRETERS

Members: 
Bryan Prichard (The All C-ing Eye),   
Christian Caldwell (The REACTor),   
Micah Tamerius (Python, Pythoff),   
Ben Frailey (R ya ready, kids?),  

Language Selection: C++

Description:
This is a simple Python interpreter written in C++. It is meant as a simplified replacement for python's built in interpreter in order for us to increase our understanding on how interpreters work. It is able to handle conditionals, variable definitions, while and for loops, arithmetic operators, assignment operators, conditional statements, comments, and print. 


How to Run:
run the make command within the local repository on your computer.
use the interpreter on a program using ./python_interpreter $PROGRAM_NAME

Requirements:
    if/else blocks: 53-66 in statement.cpp
    variable definitions: symbolTable.cpp/symbolTable.h
    while and for Loops: 73-84 in statement.cpp 
    airthmetic operators: number.h/number.cpp, classes are defined in arithmetic.h and .cpp
    assignment operators: number.h/number.cpp
    conditional statements: number.h/number.cpp, classes are defined in conditional.h and .cpp
    comments: lex.l (replaced with white space until a line break occurs)
    Support Output Operation: 86-90 in statement.cpp
    
    
Based on: https://github.com/cullum/piethon
