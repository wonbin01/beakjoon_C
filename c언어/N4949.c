#include <stdio.h>
#include <string.h>

typedef struct
{
    char data[101];
    int top;
}Stack;

void check_balance(char str[]);
void init(Stack *stack);
void pop(Stack *stack);
void push1(Stack *stack);
void push2(Stack *stack);
int main(void)
{
    while(1)
    {
        char str[101];
        fgets(str,sizeof(str),stdin);
        if(strcmp(str, ".\n")==0)
        {
            break;
        }
        check_balance(str);
    }
    return 0;
}
void check_balance(char str[]) //������ �´��� Ȯ���ϴ� �Լ�
{
    Stack stack;
    init(&stack); // ( �Ǵ� [ ������ ��, stack�� push���� 
    for(int i=0;str[i]!='.';i++)
    {
        if(str[i]=='(')
        {
            push1(&stack);
        }
        else if(str[i]=='[')
        {
            push2(&stack);
        }
        else if(str[i]==')')
        {
            if(stack.data[stack.top]=='(')
            {
                pop(&stack);
            }
            else
            {
                stack.top++;
                stack.data[stack.top]=str[i];
            }
        }
        else if(str[i]==']')
        {
            if(stack.data[stack.top]=='[')
            {
                pop(&stack);
            }
            else
            {
                stack.top++;
                stack.data[stack.top]=str[i];
            }
        }
    }
    if(stack.top==-1) //stack�� ����ִ��� �ƴ���
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

}
void init(Stack *stack) //�����غ�(���ÿ� push����)
{
    (*stack).top=-1;
}
void pop(Stack *stack)
{
    (*stack).top--;
}
void push1(Stack *stack)
{
    (*stack).top++;
    (*stack).data[(*stack).top]='(';
}
void push2(Stack *stack)
{
    (*stack).top++;
    (*stack).data[(*stack).top]='[';
}