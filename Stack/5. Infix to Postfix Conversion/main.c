#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int size;
    int top;
    char *A;
};

char *Conversion(char *);
void Push(struct Stack *, char);
char Pop(struct Stack *);
int isFull(struct Stack *);
int isEmpty(struct Stack *);
char stackTop(struct Stack *);
int isOperand(char);
int precedence(char);

void Push(struct Stack *st, char i)
{
    if(!isFull(st))
    {
        st->top++;
        st->A[st->top]=i;
    }
}

char Pop(struct Stack *st)
{
    if(!isEmpty(st))
    {
        return st->A[st->top--];
    }
    return -1;
}

int isFull(struct Stack *st)
{
    if(st->top==st->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    return 0;
}

char stackTop(struct Stack *st)
{
    if(!isEmpty(st))
    {
        return st->A[st->top];
    }
    return -1;
}

int isOperand(char i)
{
    if(i=='+' || i=='-' || i=='*' || i=='/')
    {
        return 0;
    }
    return 1;
}

int precedence(char i)
{
    if(i=='+' || i=='-')
    {
        return 1;
    }
    if(i=='*' || i=='/')
    {
        return 2;
    }
    return 0;
}

char *Conversion(char *expression)
{
    struct Stack st;
    st.size=strlen(expression);
    st.top=-1;
    st.A=(char *)malloc(sizeof(char)*st.size);
    char *postfix=(char *)malloc(sizeof(char)*(st.size+1));
    int i=0, j=0;
    while(expression[i]!='\0')
    {
        if(isOperand(expression[i]))
        {
            postfix[j++]=expression[i++];
        }
        else
        {
            if(precedence(expression[i])>precedence(stackTop(&st)))
            {
                Push(&st, expression[i++]);
            }
            else
            {
                postfix[j++]=Pop(&st);
            }
        }
    }
    while(!isEmpty(&st))
    {
        postfix[j++]=Pop(&st);
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char expression[100], *postfix;
    printf("Enter the expression containing only '+', '-', '*', and '/': ");
    scanf("%s", expression);
    postfix=Conversion(expression);
    printf("The postfix expression of the expression %s is : %s", expression, postfix);
}
