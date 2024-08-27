#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *A;
};

void Create(struct Stack *);
void Display(struct Stack);
void Push(struct Stack *);
int Pop(struct Stack *);
int Peek(struct Stack);
int stackTop(struct Stack);
int isFull(struct Stack *);
int isEmpty(struct Stack *);

void Create(struct Stack *st)
{
    printf("Enter the size of a stack: ");
    scanf("%d", &st->size);
    st->A=(int *)malloc(st->size*sizeof(int));
    st->top=-1;
}

void Display(struct Stack st)
{
    printf("The elements inside the stack is: ");
    for(int i=st.top; i>=0; i--)
    {
        printf("%d ", st.A[i]);
    }
    printf("\n");
}

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
        st->top++;
        st->A[st->top]=x;
    }
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
        x=st->A[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct Stack st)
{
    int position;
    printf("Enter the position for which you want to get the value: ");
    scanf("%d", &position);
    if(st.top-position+1<0 || st.top-position+1>=st.size)
    {
        return 0;
    }
    else
    {
        return st.A[st.top-position+1];
    }
}

int stackTop(struct Stack st)
{
    if(isEmpty(&st))
    {
        return 0;
    }
    else
    {
        return st.A[st.top];
    }
}

int isFull(struct Stack *st)
{
    if(st->top==st->size-1)
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
    if(st->top==-1)
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
    Create(&st);
    Push(&st);
    Push(&st);
    Display(st);
    int x=Pop(&st);
    if(x==0)
    {
        printf("Stack is underflow or empty.\n");
    }
    else
    {
        printf("The popped-out element from the stack is: %d.\n", x);
    }
    if(!isEmpty(&st))
    {
        Display(st);
    }
    int y=Peek(st);
    if(y==0)
    {
        printf("Position is Invalid.\n");
    }
    else
    {
        printf("The element present at the given position is: %d\n", y);
    }
    int z=stackTop(st);
    if(z)
    {
        printf("The top most element in the stack is: %d.\n", z);
    }
    else
    {
        printf("Stack is Empty.\n");
    }
}
