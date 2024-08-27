#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
}*top=NULL;

void Push(struct Stack *);
void Display(struct Stack);
int Pop(struct Stack *);
int Peek(struct Stack);
void stackTop(struct Stack);
int isFull(struct Stack *);
int isEmpty(struct Stack *);

void Push(struct Stack *st)
{
    if(isFull(st))
    {
        printf("Stack is overflow or full.\n");
        return;
    }
    else
    {
        int x;
        printf("Enter the element which you want to push inside the stack: ");
        scanf("%d", &x);
        struct Stack *t;
        t=(struct Stack *)malloc(sizeof(struct Stack));
        t->data=x;
        t->next=top;
        top=t;
    }
}

void Display(struct Stack st)
{
    struct Stack *p=top;
    printf("The elements in the stack is: ");
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int Pop(struct Stack *st)
{
    int x;
    if(isEmpty(st))
    {
        return 0;
    }
    else
    {
        struct Stack *p;
        p=top;
        x=p->data;
        top=p->next;
        free(p);
    }
    return x;
}

int Peek(struct Stack st)
{
    int position;
    printf("Enter the position for which you want to get the value: ");
    scanf("%d", &position);
    struct Stack *p=top;
    for(int i=0; i<position-1 && p!=NULL; i++)
    {
        p=p->next;
    }
    if(p!=NULL)
    {
        return p->data;
    }
    else
    {
        return 0;
    }
}

void stackTop(struct Stack st)
{
    if(isEmpty(&st))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("The top most element in the stack is: %d.\n", top->data);
    }
}

int isFull(struct Stack *st)
{
    struct Stack *t;
    t=(struct Stack *)malloc(sizeof(struct Stack));
    if(t==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *st)
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Stack st;
    Push(&st);
    Push(&st);
    Display(st);
    int x=Pop(&st);
    if(x)
    {
        printf("The popped-out element is: %d.\n", x);
    }
    else
    {
        printf("Stack is underflow or empty.\n");
    }
    if(!isEmpty(&st))
    {
        Display(st);
    }
    int y=Peek(st);
    if(y==0)
    {
        printf("Invalid Position.\n");
    }
    else
    {
        printf("The element present at the given position is: %d.\n", y);
    }
    stackTop(st);
}
