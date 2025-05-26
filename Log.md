# Logs
## First day of log - 23-05-2025
### Program progress
This is my first day of logging my progress. It has already been some time since i started this project, and i've only gotten better at C since.
The goal of this project is to learn different elements of C, and to gain better knowledge about programming. So far, i have made a select screen and the excel ark in the terminal.


Today i started on the intepreter, which is the part of the program that reads a given equation and calculates it.
A interpreter is made of of several parts. One of them is a lexer, which is a system which translate the given equation into tokens, small chunks of information, that makes it possible for the calculator to understand.
For example: If i write '=123 + 456' the actual equation would look something like this: {61,49,50,32,43,32,52,53,54}.
This is due to the equation being an array made of characters. All numbers and signs, like 1, 2, 3... spaces and operators(+, -, /, *) are stored as their ASCII value. ASCII values are represented as numbers between 0 and 255.
The number 1 in ASCII is 49, the operator + is 43, the letter A is 65 and so on.

Our lexer needs to make our string, {61,49,50,32,43,32,52,53,54}, readable for our calculator. This is done in my function lexer, in my equation file.
### Random thoughts on C
Many people states that C is a hard and not a beginner friendly programmning language, due to it being "low level".
I've been told the same story, but i don't think this is a problem. C is just fair and annoying.
It might be really annoying actually. You always know it's you fault when your program isen't working, it's always your fault you have a memory leak. Uhh I don't wanna write more. Goodbye.

## Withdrawal symptoms hitting - 26-05-2025
### Program progress
I forgot to back up my latest version of my program to github, and i dont have acces to the disk with the program untill thursday. I can't make any progress.
WAIT. NEVERMIND, i can continue on the UI part! I'm saved :D I should proberly make my UI code prettier and more featureful.
I still don't know know if my program should be CLI, only terminal, or if i should make a GUI...
