#include "stack.h"
#include <stdio.h>

int main()
{
    Stack *stck = Create_Stack(15);
    Stack_Char *stck2 = Create_StackChar(3);

    Push_Stack(stck, 5);
    Push_Stack(stck, 6);
    Push_Stack(stck, 7);
    Push_Stack(stck, 16);
    Push_Stack(stck, 91);

    Push_StackChar(stck2, 'a');
    Push_StackChar(stck2, 'd');
    Push_StackChar(stck2, 'b');
    Push_StackChar(stck2, '`');

    Pop_Stack(stck);
    Pop_Stack(stck);
    Pop_Stack(stck);

    Push_Stack(stck, 100);
    Push_Stack(stck, 20);
    Push_Stack(stck, 480);

    Pop_StackChar(stck2);
    Pop_StackChar(stck2);

    return 0;
}
