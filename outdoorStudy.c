#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

/* Struktur ADT Stack */

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

/* Function prototype */

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

/* Function definition below */

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) 
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main()
{
    Stack stack;

    stack_init(&stack);

    int n, i;
    int number[100];
    scanf("%d", &n); 
    for (i = 0; i < n; i++){
        scanf("%d", &number[i]);
    }
    int x;
    scanf("%d", &x);
    int num = 1;
    int check = 1;
    for (i = 0; i < n; i++)
    {
        while (!stack_isEmpty(&stack) && stack_top(&stack) == num){
            num++;
            stack_pop(&stack);
        }
        if (number[i] == num){
            num++;
        }
        else if (!stack_isEmpty(&stack) && number[i] > stack_top(&stack)){
            check = 0;
            break;
        }
        else{
            stack_push(&stack, number[i]);
        }        
    }

    if (check == 1){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
// Buat objek Stack
//    Stack myStack;
//
//    // PENTING! Jangan lupa diinisialisasi
//    stack_init(&myStack);
//
//    // Operasi pada stack
//    stack_push(&myStack, 1);
//    stack_push(&myStack, 2);
//    stack_push(&myStack, 3);
//
//    // cetak isi stack
//    while (!stack_isEmpty(&myStack)) {
//        printf("%d ", stack_top(&myStack));
//        stack_pop(&myStack);
//    }
//    puts("");
//    return 0;
}