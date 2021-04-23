#include "stack.h"
#include <stdlib.h>
#include <string.h>

Stack *Create_Stack(int maxItemSize)
{
    Stack *retval = (Stack *)malloc(sizeof(Stack));
    int *ptr = (int *)malloc(sizeof(int) * maxItemSize);

    retval->first_item = ptr;
    retval->top = NULL;
    retval->itemCount = 0;
    retval->maxSize = maxItemSize;
    return retval;
}

void Push_Stack(Stack *stack, int value)
{
    if (stack->top == NULL)
    {
        *stack->first_item = value;
        stack->top = stack->first_item;
    }
    else
    {
        if (stack->maxSize <= stack->itemCount)
        {
            stack->maxSize = stack->maxSize * 2;
            int *ptr = (int *)malloc(sizeof(int) * stack->maxSize);
            memcpy(ptr, stack->first_item, sizeof(int) * stack->itemCount);
            free(stack->first_item);
            stack->first_item = ptr;
            stack->top = stack->first_item + stack->itemCount;

            *stack->top = value;
        }
        else
        {
            stack->top++;
            *stack->top = value;
        }
    }
    stack->itemCount++;
}

int Pop_Stack(Stack *stack)
{
    if (stack->top != NULL)
    {
        int retval = *stack->top;
        stack->top -= 1;
        stack->itemCount--;
        return retval;
    }
    return *(int *)NULL;
}

int Top_Stack(Stack *stack)
{
    if (stack->top != NULL)
    {
        int retval = *stack->top;
        return retval;
    }
    return *(int *)NULL;
}

Stack_Char *Create_StackChar(int maxItemSize)
{
    Stack_Char *retval = (Stack_Char *)malloc(sizeof(Stack));
    char *ptr = (char *)malloc(sizeof(char) * maxItemSize);

    retval->first_item = ptr;
    retval->top = NULL;
    retval->itemCount = 0;
    retval->maxSize = maxItemSize;
    return retval;
}

void Push_StackChar(Stack_Char *stack, char value)
{
    if (stack->top == NULL)
    {
        *stack->first_item = value;
        stack->top = stack->first_item;
    }
    else
    {
        if (stack->maxSize <= stack->itemCount)
        {
            stack->maxSize = stack->maxSize * 2;
            char *ptr = (char *)malloc(sizeof(char) * stack->maxSize);
            memcpy(ptr, stack->first_item, sizeof(char) * stack->itemCount);
            free(stack->first_item);
            stack->first_item = ptr;
            stack->top = stack->first_item + stack->itemCount;

            *stack->top = value;
        }
        else
        {
            stack->top++;
            *stack->top = value;
        }
    }
    stack->itemCount++;
}

char Pop_StackChar(Stack_Char *stack)
{
    if (stack->top != NULL)
    {
        char retval = *stack->top;
        stack->top -= 1;
        stack->itemCount--;
        return retval;
    }
    return *(char *)NULL;
}

char Top_StackChar(Stack_Char *stack)
{
    if (stack->top != NULL)
    {
        char retval = *stack->top;
        return retval;
    }
    return *(char *)NULL;
}
