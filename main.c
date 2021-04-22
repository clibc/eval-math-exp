#include "stack.h"
#include <stdio.h>

int main()
{
    Stack *stck = Create_Stack(15);

    Push_Stack(stck, 5);
    Push_Stack(stck, 6);
    Push_Stack(stck, 7);
    Push_Stack(stck, 16);
    Push_Stack(stck, 91);

    int a = Pop_Stack(stck);
    int b = Pop_Stack(stck);
    int c = Pop_Stack(stck);

    Push_Stack(stck, 100);
    Push_Stack(stck, 20);
    Push_Stack(stck, 480);

    return 0;
}
