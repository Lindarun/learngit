#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headfile/queue.h"
//循环队列结构
int datasize;//全局保存数据内存大小，用于打印
char temp;//全局保存选项，用于打印
void InitAQueue(AQueue *Q)//初始化队列
{
    Q->front = 0;
    Q->rear = 0;
    printf("数据类型如下\n");//用户定义数据类型
    printf("1.int\t2.char\n");
    printf("3.float\t4.double\n");
    printf("请输入数据类型的序号：");
    scanf("%c",&temp);
    getchar();
    while(1)
    {
        if(temp == '1') {Q->data_size = sizeof(int); break;}
        else if(temp == '2') {Q->data_size = sizeof(char); break;}
        else if(temp == '3') {Q->data_size = sizeof(float); break;}
        else if(temp == '4') {Q->data_size = sizeof(double); break;}
        else {printf("输入错误，请重新输入：\n");scanf("%c",&temp);getchar();}
    }
    int i;
    datasize = Q->data_size;
    for(i=0;i<MAXQUEUE;i++)
    {
        Q->data[i] = malloc(Q->data_size);
    }
}
void DestoryAQueue(AQueue *Q)//销毁队列
{
    free(Q->data);//先清空队列数据
    free(Q);//再销毁头结构体
    Q = NULL;
}
Status IsFullAQueue(const AQueue *Q)
{
    return (Q->rear + 1) % MAXQUEUE == Q->front?TRUE:FLASE;
}
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(IsFullAQueue(Q) == TRUE || Q == NULL)
        return FLASE;
    memcpy(e, Q->data[Q->front], Q->data_size);//将指针指向的值赋值到e中
    return TRUE;
}
Status IsEmptyAQueue(const AQueue *Q)
{
    return Q->rear == Q->front?TRUE:FLASE;
}
int LengthAQueue(AQueue *Q)
{
    return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}
Status EnAQueue(AQueue *Q, void *data)
{
    if(IsFullAQueue(Q) == TRUE || Q == NULL)
        return FLASE;
    memcpy(Q->data[Q->rear], data, Q->data_size);
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    return TRUE;
}
Status DeAQueue(AQueue *Q)
{
    if(IsEmptyAQueue(Q) == TRUE || Q == NULL)
        return FLASE;
    Q->front = (Q->front + 1) % MAXQUEUE;
    return TRUE;
}
void ClearAQueue(AQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    int i;
    for(i=0;i<MAXQUEUE;i++)
    {
        Q->data[i] = NULL;
    }
}
void APrint(void *q)
{
    if(datasize == 1) {char *p = q; printf("%c\n",*p);}
    else if(datasize == 4)
    {
       if(temp == '1') {int *p = q; printf("%d\n",*p);}
       else if(temp == '3') {float *p = q; printf("%f\n",*p);}
    }
    else if(datasize == 8) {double *p = q; printf("%f\n",*p);}
}
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(Q == NULL || IsEmptyAQueue(Q) == TRUE)
        return FLASE;
    int i = Q->front;
    printf("打印队列如下:\n");
    while(i != Q->rear)
    {
        foo(Q->data[i]);
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}
//链式队列结构
void InitLQueue(LQueue *Q)
{
    Q->front = NULL;
    Q->rear = NULL;
    printf("数据类型如下\n");
    printf("1.int\t2.char\n");
    printf("3.float\t4.double\n");
    printf("请输入数据类型的序号：");
    scanf("%c",&temp);
    getchar();
    while(1)
    {
        if(temp == '1') {Q->data_size = sizeof(int); break;}
        else if(temp == '2') {Q->data_size = sizeof(char); break;}
        else if(temp == '3') {Q->data_size = sizeof(float); break;}
        else if(temp == '4') {Q->data_size = sizeof(double); break;}
        else {printf("输入错误，请重新输入：\n");
        scanf("%c",&temp);
        getchar();}
    }
    datasize = Q->data_size;
}
void ClearLQueue(LQueue *Q)
{
    Q->rear = Q->front;
    while(Q->front != NULL)
    {
        Q->front = Q->front->next;
        free(Q->rear);
        Q->rear = Q->front;
    }
}
void DestoryLQueue(LQueue *Q)
{
    ClearLQueue(Q);
    free(Q);
    Q = NULL;
}
Status IsEmptyLQueue(const LQueue *Q)
{
    return Q->front == NULL ? TRUE : FLASE;
}
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(Q == NULL || IsEmptyLQueue(Q) == TRUE)
    {
        return FLASE;
    }
    memcpy(e, Q->front->data, Q->data_size);
    return TRUE;
}
int LengthLQueue(LQueue *Q)
{
    if(IsEmptyLQueue(Q) == TRUE || Q == NULL)
        return 0;
    int cnt = 1;
    Node *p = Q->front;
    while(p->next != NULL)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}
Status EnLQueue(LQueue *Q, void *data)
{
    if(Q == NULL)
        return FLASE;
    Node *p = (Node *)malloc(sizeof(Node));
    if(p == NULL)
        return FLASE;
    printf("bilibili\n");
    p->data = malloc(Q->data_size);//为空指针设定空间容量
    memcpy(p->data, data, Q->data_size);
    printf("bilibili\n");
    p->next = NULL;
    if(Q->front == NULL)
    {
        Q->front = p;
        Q->rear = p;
        return TRUE;
    }
    printf("sbsbsb\n");
    Q->rear->next = p;
    printf("hahaha\n");
    Q->rear = p;
    return TRUE;
}
Status DeLQueue(LQueue *Q)
{
    if(Q == NULL || IsEmptyLQueue(Q) == TRUE)
        return FLASE;
    Node *p = Q->front;
    Q->front = Q->front->next;
    free(p);
    p = NULL;
    return TRUE;
}
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    if(Q == NULL || IsEmptyLQueue(Q) == TRUE || Q->front == NULL)
        return FLASE;
    printf("打印队列如下：\n");
    Node *p = Q->front;
    while(p != NULL)
    {
        foo(p->data);
        p = p->next;
    }
    return TRUE;
}
void LPrint(void *q)
{
    if(datasize == 1) {char *p = q; printf("%c\n",*p);}
    else if(datasize == 4)
    {
       if(temp == '1') {int *p = q; printf("%d\n",*p);}
       else if(temp == '3') {float *p = q; printf("%f\n",*p);}
    }
    else if(datasize == 8) {double *p = q; printf("%f\n",*p);}
}
