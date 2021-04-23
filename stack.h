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

typedef struct
{
    char *first_item;
    char *top;
    int itemCount;
    int maxSize;
} Stack_Char;

Stack_Char *Create_StackChar(int maxItemSize);
void Push_StackChar(Stack_Char *stack, char value);
char Pop_StackChar(Stack_Char *stack);
char Top_StackChar(Stack_Char *stack);
