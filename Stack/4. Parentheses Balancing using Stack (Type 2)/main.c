#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int size;
    int top;
    char *A;
};

void push(struct Stack *, char);
char pop(struct Stack *);
int isMatching(char, char);
int isBalanced(char *);
int isFull(struct Stack *);
int isEmpty(struct Stack *);

void push(struct Stack *st, char i)
{
    if(isFull(st))
    return;
    else
    st->A[++st->top]=i;
}

char pop(struct Stack *st)
{
    if(isEmpty(st))
    return 0;
    else
    return st->A[st->top--];
}

int isMatching(char left, char right)
{
    if(left=='(' && right==')')
    return 1;
    else if(left=='{' && right=='}')
    return 1;
    else if(left=='[' && right==']')
    return 1;
    else
    return 0;
}

int isBalanced(char *expression)
{
    struct Stack st;
    st.size=strlen(expression);
    st.A=(char *)malloc(st.size*sizeof(char));
    st.top=-1;
    for(int i=0; expression[i]!='\0'; i++)
    {
        if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
        push(&st, expression[i]);
        else if(expression[i]==')' || expression[i]=='}' || expression[i]==']')
        {
            if(isEmpty(&st))
            return 0;
            char x=pop(&st);
            if(!isMatching(x, expression[i]))
            return 0;
        }
    }
    if(isEmpty(&st))
    return 1;
    else
    return 0;
}

int isFull(struct Stack *st)
{
    if(st->top==st->size-1)
    return 1;
    else
    return 0;
}

int isEmpty(struct Stack *st)
{
    if(st->top==-1)
    return 1;
    else
    return 0;
}

int main()
{
    char expression[100];
    printf("Enter the expression: ");
    scanf("%s", expression);
    int result=isBalanced(expression);
    if(result==1)
    printf("Yes, it is balanced.\n");
    else
    printf("No, it is not balanced.\n");
}
