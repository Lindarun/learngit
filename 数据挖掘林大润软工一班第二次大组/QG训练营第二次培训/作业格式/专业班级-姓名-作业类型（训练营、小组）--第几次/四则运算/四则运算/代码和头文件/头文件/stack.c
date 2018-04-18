#include <stdio.h>
#include <stdlib.h>
#include "ͷ�ļ�/stack.h"
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ������
{
    s->elem = (ElemType *)malloc(sizes * sizeof(ElemType));//���鵱ջͰ
    if(s->elem == NULL)//����ʧ�ܷ���error
        return ERROR;
    s->top = -1;//��ʼ��ջ��ָ��Ϊ-1
    s->size = sizes;//����ջ�Ĵ�С
    return OK;
}


Status isEmptyStack(SqStack *s)   //�ж������Ƿ�Ϊ��
{
    return (s->top == -1?OK : ERROR);
}


Status getTopStack(SqStack *s,ElemType *e)   //�õ�����ͷԪ��
{
    if(s == NULL || s->top == -1)//��ջ������������ʧ��
        return ERROR;
    else *e = s->elem[s->top];
    return OK;
}


Status clearStack(SqStack *s)   //�������
{
    if(s == NULL)
        return ERROR;
    s->top = -1;//ջ��ָ������Ϊ-1
    return OK;
}


Status destoryStack(SqStack *s)  //��������
{
    if(s == NULL)
        return ERROR;
    free(s->elem);
    free(s);
    s = NULL;
    return OK;
}


Status stackLength(SqStack *s,int *length)   //���������
{
    if(s == NULL)
        return ERROR;
    *length = s->top + 1;
    return OK;
}

Status pushStack(SqStack *s,ElemType datas)  //��ջ
{
    if(s == NULL || s->top == s->size-1)//��ջ��ջ����ջʧ��
        return ERROR;
    s->top++;
    s->elem[s->top] = datas;
    return OK;
}

Status popStack(SqStack *s,ElemType *datas)   //��ջ
{
    if(s == NULL || s->top == -1)//��ջ��ջ��
        return ERROR;
    *datas = s->elem[s->top];//��������ֵ������e
    s->top--;
    return OK;
}

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
    //s = (LinkStack *)malloc(sizeof(LinkStack));����
    if(s == NULL)//����ʧ��
        return ERROR;
    s->count = 0;//Ԫ�ظ�����ʼ��Ϊ0
    s->top = NULL;//ָ��ָ��NULL
    return OK;
}

Status isEmptyLStack(LinkStack *s)  //�ж������Ƿ�Ϊ��
{
    return (s->top == NULL?OK:ERROR);
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�����ͷԪ��
{
    if(isEmptyLStack(s) == OK || s == NULL)
        return ERROR;
    *e = s->top->data;
    return OK;
}

Status clearLStack(LinkStack *s)   //�������
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

Status destoryLStack(LinkStack *s)   //��������
{
    if(s == NULL)
        return ERROR;
    if(isEmptyLStack(s) == ERROR)
        clearLStack(s);
    free(s);
    s = NULL;
    return OK;
}

Status LStackLength(LinkStack *s,int *length)    //���������
{
    if(s == NULL)
        return ERROR;
    *length = s->count;
    return OK;
}

Status pushLStack(LinkStack *s,ElemType datas)   //��ջ
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

Status popLStack(LinkStack *s,ElemType *datas)   //��ջ
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
