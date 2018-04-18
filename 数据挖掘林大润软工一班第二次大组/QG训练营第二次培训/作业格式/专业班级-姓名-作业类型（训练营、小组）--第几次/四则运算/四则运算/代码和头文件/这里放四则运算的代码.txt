#include <stdio.h>
#include "代码和头文件\头文件\stack.h"
#define MAXN 30
#include <stdlib.h>
#include <string.h>
void transfer(char s[], char s_houzhui[])//转为后缀表达式
{
    SqStack *sq = (SqStack *)malloc(sizeof(SqStack));//创建数组栈
    initStack(sq,MAXN);//初始化
    int temp = 0;
    int *temp_ptr=&temp;//存放pop出的值
    int i;//原始char数组指针
    int j=0;//转化后char数组指针
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i] == ' ' || s[i] == '\n') continue;//滤过空格和回车
        else if(s[i]<='9' && s[i]>='0')//遇到数字放进后缀表达式
        {
            s_houzhui[j++] = s[i];
            if(s[i+1]>'9' || s[i+1]<'0')//多位数情形：将多位数最后一位放入一个空格标志
                s_houzhui[j++] = ' ';
        }
        else if(s[i] == '(') {pushStack(sq, s[i]);}//左括号直接pop进
        else if(s[i] == '+' || s[i] == '-')//若为加号或减号 则pop出栈顶所有优先级大于或等于加号或减号的
        {
            while(1)
            {
                int Result = getTopStack(sq,temp_ptr);
                if(temp == '(' || Result == 0)
                {
                    pushStack(sq,s[i]);
                    break;
                }
                else
                {
                    popStack(sq,temp_ptr);
                    s_houzhui[j++] = temp;
                }
            }
        }
        else if(s[i] == '*' || s[i] == '/') //乘号或除号 将所有栈顶为乘号或除号的pop出并将当前符号压入栈中
        {
            while(1)
            {
                int Result = getTopStack(sq,temp_ptr);
                if(temp == '(' || temp == '+' || temp == '-' || isEmptyStack(sq) == 1 || Result == 0)
                {
                    pushStack(sq,s[i]);
                    break;
                }
                else
                {
                    popStack(sq,temp_ptr);
                    s_houzhui[j++] = temp;
                }
            }
        }
        else if(s[i] == ')')//判断右括号
        {
            while(1)//弹出左右括号间的所有内容 遇到左括号停止弹出
            {
                popStack(sq,temp_ptr);
                if(temp == '(') break;
                else s_houzhui[j++] = (temp);
            }
        }
        else {printf("表达式有误\n"); break;}
    }
    while(isEmptyStack(sq) != 1)
    {
        popStack(sq,temp_ptr);
        s_houzhui[j++] = temp;
    }
    s_houzhui[j]='\0';
}
void calculate_s(char s_houzhui[])
{
    int j;//数组指针
    SqStack *sq = (SqStack *)malloc(sizeof(SqStack));//创建数组栈
    initStack(sq,MAXN);//初始化
    for(j=0;s_houzhui[j]!='\0';j++)//遍历数组
    {
        if( '0' <= s_houzhui[j] && '9' >= s_houzhui[j])//数字放入栈中
        {
            int data = 0, ans = 0;
            while(s_houzhui[j]!=' ')//多位数情形；根据空格转化为整型多位数
            {
                data = ans * 10;
                data += s_houzhui[j]-'0';
                ans = data;
                j++;
            }
            pushStack(sq,data);
        }
        else if(s_houzhui[j] == '+' || s_houzhui[j] == '-' || s_houzhui[j] == '*' || s_houzhui[j] == '/' )
        {
            int popdata1, popdata2;
            int *popdata1_ptr=&popdata1, *popdata2_ptr=&popdata2;
            if(isEmptyStack(sq) == OK)//检验栈是否为空，为空则表达式有误
                {printf("表达式有误，请重新输入\n"); break;}
            popStack(sq,popdata1_ptr);
            if(isEmptyStack(sq) == OK)//检验栈是否为空，为空则表达式有误
                {printf("表达式有误，请重新输入\n"); break;}
            popStack(sq,popdata2_ptr);
            switch(s_houzhui[j])//根据符号对pop出两值进行运算
            {
                case '+' :
                {
                  pushStack(sq, popdata1+popdata2);
                  break;
                }
                case '-' :
                {
                    pushStack(sq, popdata2-popdata1);
                    break;
                }
                case '*' :
                {
                    pushStack(sq, popdata2*popdata1);
                    break;
                }
                case '/' :
                {
                     pushStack(sq, popdata2/popdata1);//由于栈的数据类型为int型，无法计算浮点数
                }
            }
        }
        else continue;
    }
    int result = 0, *result_ptr = &result;//存放结果
    popStack(sq,result_ptr);//最后栈中的值即为表达式的值
    printf("表达式的值为：%d\n",result);
}

int main()
{
    char s[MAXN],s_houzhui[MAXN];
    printf("四则运算器（目前仅支持多位数的运算，并不支持浮点运算，负数运算;且并不支持中文输入法，不便之处，敬请原谅）\n");
    putchar('\n');
    printf("请输入一个四则运算表达式(按q结束)：");
    while(gets(s) && s[0] != 'q')
    {
        transfer(s,s_houzhui);//转化为后缀表达式
        calculate_s(s_houzhui);//计算后缀表达式;
        printf("请输入一个四则运算表达式(按q结束)：");
    }
    return 0;
}
