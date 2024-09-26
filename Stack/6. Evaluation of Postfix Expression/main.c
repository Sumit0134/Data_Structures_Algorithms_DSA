#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int size;
    int top;
    int *A;
};

void Push(struct Stack *, int);
int Pop(struct Stack *);
int stackTop(struct Stack *);
int isFull(struct Stack *);
int isEmpty(struct Stack *);
int isOperand(char);
int Evaluation(char *);

void Push(struct Stack *st, int i)
{
    if(!isFull(st))
    {
        st->top++;
        st->A[st->top]=i;
    }
}

int Pop(struct Stack *st)
{
    if(!isEmpty(st))
    {
        return st->A[st->top--];
    }
    return -1;
}

int stackTop(struct Stack *st)
{
    if(!isFull(st))
    {
        return st->A[st->top];
    }
    return -1;
}

int isFull(struct Stack *st)
{
    if(st->top==st->size-1)
    return 1;
    return 0;
}

int isEmpty(struct Stack *st)
{
    if(st->top==-1)
    return 1;
    return 0;
}

int isOperand(char i)
{
    if(i=='+' || i=='-' || i=='*' || i=='/')
    return 0;
    return 1;
}

int Evaluation(char *expression)
{
    struct Stack st;
    st.size=strlen(expression);
    st.top=-1;
    st.A=(int *)malloc(sizeof(int)*st.size);
    for(int i=0; expression[i]!='\0'; i++)
    {
        if(isOperand(expression[i]))
        {
            Push(&st, expression[i]-'0');
        }
        else
        {
            int x1, x2, result;
            x2=Pop(&st);
            x1=Pop(&st);
            switch(expression[i])
            {
                case '+': result=x1+x2; break;
                case '-': result=x1-x2; break;
                case '*': result=x1*x2; break;
                case '/': result=x1/x2; break;
            }
            Push(&st, result);
        }
    }
    return stackTop(&st);
}

int main()
{
    char expression[100];
    printf("Enter a postfix expression containing only '+', '-', '*', '/': ");
    scanf("%s", &expression);
    int result=Evaluation(expression);
    printf("The answer of the given postfix expression is: %d", result);
}
