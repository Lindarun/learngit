#include <stdio.h>
#include <stdlib.h>
#include "头文件/stack.h"
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化链表
{
    s->elem = (ElemType *)malloc(sizes * sizeof(ElemType));//数组当栈桶
    if(s->elem == NULL)//申请失败返回error
        return ERROR;
    s->top = -1;//初始化栈顶指针为-1
    s->size = sizes;//保存栈的大小
    return OK;
}


Status isEmptyStack(SqStack *s)   //判断链表是否为空
{
    return (s->top == -1?OK : ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //得到链表头元素
{
    if(s == NULL || s->top == -1)//空栈或链表销毁则失败
        return ERROR;
    else *e = s->elem[s->top];
    return OK;
}


Status clearStack(SqStack *s)   //清空链表
{
    if(s == NULL)
        return ERROR;
    s->top = -1;//栈顶指针重设为-1
    return OK;
}


Status destoryStack(SqStack *s)  //销毁链表
{
    if(s == NULL)
        return ERROR;
    free(s->elem);
    free(s);
    s = NULL;
    return OK;
}


Status stackLength(SqStack *s,int *length)   //检测链表长度
{
    if(s == NULL)
        return ERROR;
    *length = s->top + 1;
    return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //入栈
{
    if(s == NULL || s->top == s->size-1)//无栈或栈满入栈失败
        return ERROR;
    s->top++;
    s->elem[s->top] = datas;
    return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //出栈
{
    if(s == NULL || s->top == -1)//无栈或栈空
        return ERROR;
    *datas = s->elem[s->top];//将弹出的值保存至e
    s->top--;
    return OK;
}

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
    //s = (LinkStack *)malloc(sizeof(LinkStack));错误
    if(s == NULL)//申请失败
        return ERROR;
    s->count = 0;//元素个数初始化为0
    s->top = NULL;//指针指向NULL
    return OK;
}

Status isEmptyLStack(LinkStack *s)  //判断链表是否为空
{
    return (s->top == NULL?OK:ERROR);
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到链表头元素
{
    if(isEmptyLStack(s) == OK || s == NULL)
        return ERROR;
    *e = s->top->data;
    return OK;
}

Status clearLStack(LinkStack *s)   //清空链表
{
    if(isEmptyLStack(s) == OK || s == NULL)
        return ERROR;
    LinkStackPtr p = s->top;
    s->top = s->top->next;
    while(s->top != NULL)
    {
        free(p);
        p = s->top;
        s->top = s->top->next;
    }
    free(p);
    p = NULL;
    return OK;
}

Status destoryLStack(LinkStack *s)   //销毁链表
{
    if(s == NULL)
        return ERROR;
    if(isEmptyLStack(s) == ERROR)
        clearLStack(s);
    free(s);
    s = NULL;
    return OK;
}

Status LStackLength(LinkStack *s,int *length)    //检测链表长度
{
    if(s == NULL)
        return ERROR;
    *length = s->count;
    return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //入栈
{
    if(s == NULL)
        return ERROR;
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = datas;
    p->next = NULL;
    if(s->top == NULL)
    {
        s->count++;
        s->top = p;
    }
    else
    {
        p->next = s->top;
        s->top = p;
        s->count++;
    }
    return OK;
}

Status popLStack(LinkStack *s,ElemType *datas)   //出栈
{
    if(s == NULL || s->count == 0)
        return ERROR;
    StackNode *p = s->top;
    s->top = s->top->next;
    *datas = p->data;
    free(p);
    p=NULL;
    s->count--;
    return OK;
}
