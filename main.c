#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int handle_operators(char opr, int o1, int o2);
int precedence(char op);

int main()
{
    char *tokens = "2/1*5";

    Stack *value_stack = Create_Stack(15);
    Stack_Char *operator_stack = Create_StackChar(15);

    for (int i = 0; i < (int)strlen(tokens); ++i)
    {
        if (isdigit(tokens[i]))
        {
            Push_Stack(value_stack, atoi(&tokens[i]));
        }
        else
        {
            switch (tokens[i])
            {
            case '(':
                Push_StackChar(operator_stack, '(');
                break;

            case ')':
                while (operator_stack->itemCount > 0 && Top_StackChar(operator_stack) != '(')
                {
                    char opr = Pop_StackChar(operator_stack);
                    int op1 = Pop_Stack(value_stack);
                    int op2 = Pop_Stack(value_stack);
                    int result = handle_operators(opr, op2, op1);
                    Push_Stack(value_stack, result);
                }
                if (operator_stack->itemCount > 0)
                    Pop_StackChar(operator_stack);
                break;

            case '*':
            case '/':
            case '+':
            case '-':
                while (operator_stack->itemCount > 0 && precedence(Top_StackChar(operator_stack)) >= precedence(tokens[i]))
                {
                    char opr = Pop_StackChar(operator_stack);
                    int op1 = Pop_Stack(value_stack);
                    int op2 = Pop_Stack(value_stack);
                    int result = handle_operators(opr, op2, op1);
                    Push_Stack(value_stack, result);
                }
                Push_StackChar(operator_stack, tokens[i]);
                break;

            default:
                printf("Undefined token '%c'\n", tokens[i]);
                exit(-1);
            }
        }
    }

    while (operator_stack->itemCount > 0)
    {
        char opr = Pop_StackChar(operator_stack);
        int op1 = Pop_Stack(value_stack);
        int op2 = Pop_Stack(value_stack);
        int result = handle_operators(opr, op2, op1);
        Push_Stack(value_stack, result);
    }

    printf("result  = %i\n", Top_Stack(value_stack));
    return 0;
}

int handle_operators(char opr, int o1, int o2)
{
    switch (opr)
    {
    case '*':
        return o1 * o2;
    case '/':
        return o1 / o2;
    case '+':
        return o1 + o2;
    case '-':
        return o1 - o2;

    default:
        return *(int *)NULL;
    }
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
