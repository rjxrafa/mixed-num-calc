# The Mixed Number Calculator

- You may work with ONE partner only! (Talking to ANYONE other than your partner will be considered working with more than ONE partner. Hence, comparing work, copying work, etc, is FORBIDDEN!)
- You must document all of your work.
- You cannot ask ANYONE other than your partner on how to do this Final Project, nor use ANY CODE off of the web. All code must be of your own making!
- The tutors and I will help explain how C++ functions, or the Qt GUI works, but WILL NOT ASSIST IN ANY MANNER OR FORM ON COMPLETING THE FINAL! No questions on clarification will be answered during lab or via email!)
- You must have a print out in hand when you arrive. If you print out in class, your score will be deducted by 30%!
- If you work on the project during the Final Exam period, your score will be ZERO!!! (Your project must be "ready to go" when you walk in the door)
- Both partners must submit to Canvas by 2 pm on the day of the Final. If you have not submitted by then, your score will be ZERO!!!
- READ THE SYLLABUS!!!

# Introduction:

The goal of this final project is for you to develop a terminal-based mixed number calculator that will accept an arbitrary length algebraic expression that contains the standard operations (+,-,/, and *) and parentheses. Once the user presses the return key, the calculator will display the RPN translation of the algebraic expression, a space, an equal sign, and then the mixed number result.

When the program starts, a prompt such as INPUT: or EXPRESSION: must be printed. After each successful calculation, this prompt will re-appear asking for the next algebraic expression to enter. Naturally, if the user enters just the return key, then the program will terminate.

When the program starts, an appropriate message should appear that describes the functionality of the program.

## What is RPN?

Reverse Polish Notation is a way of expressing arithmetic expressions that avoids the use of brackets to define priorities for evaluation of operators. In ordinary notation, one might write

> (3 + 5) * (7 - 2)

and the brackets tell us that we have to add 3 to 5, and then subtract 2 from 7, and multiply the two results together. In RPN, the numbers and operators are listed one after another, and an operator always acts on the most recent numbers in the list. The numbers can be thought of as forming a stack, like a pile of plates. The most recent number goes on the top of the stack. An operator takes the appropriate number of arguments from the top of the stack and replaces them by the result of the operation.


In this notation the above expression would be

> 3 5 + 7 2 - *

Reading from left to right, this is interpreted as follows:

- Push 3 onto the stack.
- Push 5 onto the stack. The stack now contains (3, 5).
- Apply the + operation: take the top two numbers off the stack, add them together, and put the result back on the stack. The stack now contains just the number 8.
- Push 7 onto the stack.
- Push 2 onto the stack. It now contains (8, 7, and 2).
- Apply the - operation: take the top two numbers off the stack, subtract the top one from the one below, and put the result back on the stack. The stack now contains (8, 5).
- Apply the * operation: take the top two numbers off the stack, multiply them together, and put the result back on the stack. The stack now contains just the number 40

Polish Notation was devised by the Polish philosopher and mathematician Jan Lucasiewicz (1878-1956) for use in symbolic logic. In his notation, the operators preceded their arguments, so that the expression above would be written as

> \* + 3 5 - 7 2

The 'reversed' form has however been found more convenient from a computational point of view. Hewlett-Packard championed reverse Polish Notation for years, though it is rumored that their most recent calculators do not support it anymore, which is a pity. RPN is one of those things that can be difficult to learn, but wonderful to use once it is understood.

 

## Algorithm to Convert Algebraic to RPN:

Edsger Dijkstra, one of the pilars of Computer Science, invented the Shunting-yard algorithm (Links to an external site.)Links to an external site. to convert infix expressions to postfix (RPN), so named because its operation resembles that of a railroad shunting yard. The link above is crucial to solving this problem.

In order to implement the Shunting-yard algorithm, you will be needing a stack. For the purposes of this exercise, the Standard Template Library (STL) stack (Links to an external site.)Links to an external site. may be used. (In CS 2 the STL vector was used to develop a single dimension array that could grow or shrink as necessary)

## The Assignment Particulars:

Design a C++ program that will implement the following specifications for our terminal-based calculator. You may use any resource that you wish to complete this assignment, excepting seeking help from any other individual who is not on your programming team.

Clarification of the requirements may be asked during lab or via Canvas.


# Specifications:

- The calculator must read a complete algebraic expression that can consist of integers, decimal numbers, fractions, or mixed numbers and present the result in proper form (fractions reduced, integer results must have just the integer and no 0/1, purely fractional results must not have a leading integer 0, negative signs must be in the proper places within mixed numbers, and so forth)

- Your program must have the following classes:
  - Mixed, which will inherit from the class Fraction
  - Fraction, because you will be reading fractions on their own.
  - Parser, a class that "figures out" what the user entered and prepares a string which is the translation from algebraic to RPN.
  - Calculate, a class that takes in an RPN expression and returns a single "number" as the result. The RPN expression is obtained from the Parser class. This class shall contain an operand stack and an operator stack.
- You must use the STL stack, which is a class in its own right, within the Parser class as well as your class that does the actual computations.
- The calculator should provide error messages for "algebraically incorrect" entries (such as a missing closing parenthese, fractions that have a negative sign in the denominator, and so forth)
- For ease of parsing, the following rules shall be followed:
  - All operators must have at least one space on either side of them
  - Mixed numbers can have only one space between the integer and the fraction
  - Unary minus signs must appear directly beside the value that they are making negative
- Visual display of the calculator should be aesthetically pleasing.
- You may use any resource you wish, as long as it can be FULLY DOCUMENTED within your code.
- You may work in teams of two people ONLY (but you can do it by yourself if you so desire) and submit one test for the team.
- You must be prepared to answer any question about your program when you demonstrate its functionality during lab.
 

## Hints:

- Read the input character by character.
If the character is a "(" or ")" this will dictate what to do with the input according to the Shunting-yard algorithm
- If the input is a number, start building a new string with that number. Appended spaces, uninary minus, fraction indicator, and other numbers until an operator is hit. Then "read" what is in that temporary string into the appropriate type (mixed or fraction). Purely integer input should be stored as a mixed number, with the fractional part being 0/1.
- Do not wait to start on this program. This is a standard problem for this level of a course at the four-year universities. At this level, this program should take approximately 15 hours to complete (since we've already developed the inherited MixedNumber and Fraction classes).
- All input must be stored as a mixed number!!!!!!
- The tutors and other faculty cannot be consulted on "how" to do the program.
 

## Extra Credit:

- Using the Qt graphics libraries, develop a windowing application that "looks like" a calculator. "Looks like" means that there will be keys for digits, operators, the fraction symbol, and an equal sign (which will signify end of input). As each key is pressed, the user should see their expression being built on the calculator (as in real life). Once the equal sign is pressed, the converted expression will appear on another display with the answer. (Note: calculators have a CLEAR and CLEAR ENTRY key, and they shall be required too). 150 points)

- Have the GUI as an interface only, and all calculations calculated upon a "server." This means that one program, on the server, will be handling multiple requests from multiple clients simultaneously (150 points)

- Allow the user NOT to have spaces around operators and parenthesis and still compute the correct answer (100 points)

 