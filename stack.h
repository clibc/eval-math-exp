typedef struct
{
    int *first_item;
    int *top;
    int itemCount;
    int maxSize;
} Stack;

Stack *Create_Stack(int maxItemSize);
void Push_Stack(Stack *stack, int value);
int Pop_Stack(Stack *stack);
int Top_Stack(Stack *stack);
