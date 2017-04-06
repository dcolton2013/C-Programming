/*************************************
 Program Name: ParenthesisChecker.c
 Programmer: Donovan Colton
 Class: CS 3335 A
 Date: 10/13/16
 *************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top =0;

void stack_overflow();
void stack_underflow();

void make_empty(){
    top = 0;
}
bool is_empty(){
    return top == 0;
}
bool is_full(){
    return top == STACK_SIZE;
}
void push(char i){
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}
int pop(){
    if (is_empty())
        stack_underflow();
    return contents[--top];
}

void stack_overflow(){
    printf("Stack Overflow\n");
    exit(0);
}

void stack_underflow(){
    printf("Stack Underflow\n");
    exit(0);
}

int main(int argc, char** argv) {
    //prompt user
    printf("Enter a series of (), {}, []: ");
    char c = getchar();
    if (c == '\n'){
        printf("No chars pushed to stack.\n");
        return 0;
    }

    while (c != '\n'){
        switch(c){
            //push opening chars to stack
            case '(':
            case '{':
            case '[':   push(c);
                        break;
            //search for matching opening chars for closing chars
            //if no match, stop execution
            case ')':   if (pop() != '('){
                            printf("Incorrect formatting\n");
                            return 0;
                        }
                        break;

            case '}':   if (pop() != '{'){
                            printf("Incorrect formatting\n");
                            return 0;
                        }
                        break;

            case ']':   if (pop() != '['){
                            printf("Incorrect formatting\n");
                            return 0;
                        }
                        break;
            //default case handles chars other than
            // {} () []
            default:    printf("unsupported char: %c\n", c);
        }
        //get next char from user input
        c = getchar();
    }

    //leftover chars in stack
    if (!is_empty())
        printf("Incorrect formatting\n");
    //empty stack all opening chars matched with closing
    else
        printf("Correct formatting\n");

    return (EXIT_SUCCESS);
}
