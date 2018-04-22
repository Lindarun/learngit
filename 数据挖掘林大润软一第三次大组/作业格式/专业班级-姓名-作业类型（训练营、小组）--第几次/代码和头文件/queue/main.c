#include <stdio.h>
#include "../headfile/queue.h"
#include <stdlib.h>
#include <string.h>
extern int datasize;//将单位内存容量传进来 用于判别数据类型
extern char temp;//将数据类型选项传进来 用于判别数据类型
//各类型数据检查输入
int IntinputTest()
{
    int i,index;
    printf("请输入一个整型数据：");
    index=scanf("%d",&i);
    getchar();
    while(!index)
    {
        printf("输入错误，请重新输入：");
        index=scanf("%d",&i);
        getchar();//吸收回车
    }
    return i;
}
char CharinputTest()
{
    char i;
    int index;
    printf("请输入一个字符型数据：");
    index=scanf("%c",&i);
    getchar();
    while(!index)
    {
        printf("输入错误，请重新输入：");
        index=scanf("%c",&i);
        getchar();//吸收回车
    }
    return i;
}
float FloatinputTest()
{
    float i;
    int index;
    printf("请输入一个单精度型数据：");
    index=scanf("%f",&i);
    getchar();
    while(!index)
    {
        printf("输入错误，请重新输入：");
        index=scanf("%f",&i);
        getchar();//吸收回车
    }
    return i;
}
double DoubleinputTest()
{
    double i;
    int index;
    printf("请输入一个双精度型数据：");
    index=scanf("%lf",&i);
    getchar();
    while(!index)
    {
        printf("输入错误，请重新输入：");
        index=scanf("%lf",&i);
        getchar();//吸收回车
    }
    return i;
}
void Aq()
{
    AQueue *Q = (AQueue *)malloc(sizeof(AQueue));
    InitAQueue(Q);
    printf("队列初始化成功\n");
    printf("请输入指令前序号\n");
    printf("a.队列初始化\tb.摧毁队列\n");
    printf("c.获取队首元素\td.队列长度\n");
    printf("e.进队\t        f.出队\n");
    printf("g.遍历打印\th.清空队列\nq.quit\n");
    char section;
    printf("请输入指令：");
    scanf("%c",&section);
    getchar();
    while(section != 'q')
    {
        if(section == 'a')
        {
            if(Q == NULL) Q = (AQueue *)malloc(sizeof(AQueue));
            InitAQueue(Q);
            printf("队列初始化成功\n");
        }
        else if(section == 'b')
        {
            DestoryAQueue(Q);
            printf("摧毁成功\n");
        }
        else if(section == 'c')
        {
            if(temp == '1')
            {
                int val;
                int *val_ptr = &val;
                if(TRUE == GetHeadAQueue(Q, val_ptr))
                {
                   printf("获取成功，队首元素为");
                   APrint(val_ptr);
                }
                else printf("获取失败！原因可能为空队列或队列不存在\n");
            }
            else if(temp == '2')
            {
                char val; char *val_ptr = &val;
                if(TRUE == GetHeadAQueue(Q, val_ptr))
                {
                   printf("获取成功，队首元素为");
                   APrint(val_ptr);
                }
                else printf("获取失败！原因可能为空队列或队列不存在\n");
            }
            else if(temp == '3')
            {
                float val; float *val_ptr = &val;
                if(TRUE == GetHeadAQueue(Q, val_ptr))
                {
                   printf("获取成功，队首元素为");
                   APrint(val_ptr);
                }
                else printf("获取失败！原因可能为空队列或队列不存在\n");
            }
            else if(temp == '4')
            {
                double val; double *val_ptr = &val;
                if(TRUE == GetHeadAQueue(Q, val_ptr))
                {
                   printf("获取成功，队首元素为");
                   APrint(val_ptr);
                }
                else printf("获取失败！原因可能为空队列或队列不存在\n");
            }
        }
        else if(section == 'd')
        {
            if(Q == NULL)
                printf("队列不存在\n");
            else
                printf("队列长度为：%d\n",LengthAQueue(Q));
        }
        else if(section == 'e')
        {
            if(temp == '1')
            {
                int val = IntinputTest();
                int *val_ptr = &val;
                if(TRUE == EnAQueue(Q, val_ptr))
                {
                   printf("入队成功，入队元素为");
                   APrint(val_ptr);
                }
                else printf("获取失败！原因可能为满队列或队列不存在\n");
            }
            else if(temp == '2')
            {
                char val = CharinputTest(); char *val_ptr = &val;
                if(TRUE == EnAQueue(Q, val_ptr))
                {
                   printf("入队成功，入队元素为");
                   APrint(val_ptr);
                }
                else printf("获取失败！原因可能为满队列或队列不存在\n");
            }
            else if(temp == '3')
            {
                float val = FloatinputTest(); float *val_ptr = &val;
                if(TRUE == EnAQueue(Q, val_ptr))
                {
                   printf("入队成功，入队元素为");
                   APrint(val_ptr);
                }
                else printf("获取失败！原因可能为满队列或队列不存在\n");
            }
            else if(temp == '4')
            {
                double val = DoubleinputTest(); double *val_ptr = &val;
                if(TRUE == EnAQueue(Q, val_ptr))
                {
                   printf("入队成功，入队元素为");
                   APrint(val_ptr);
                }
                else printf("获取失败！原因可能为满队列或队列不存在\n");
            }
        }
        else if(section == 'f')
        {
            if(DeAQueue(Q) == TRUE)
                printf("出队成功\n");
            else printf("出队失败，可能为空队列或队列不存在\n");
        }
        else if(section == 'g')
        {
            if(TraverseAQueue(Q, APrint) == FLASE)
                printf("遍历失败，原因可能为空队列或队列不存在\n");
            else ;
        }
        else if(section == 'h')
        {
            ClearAQueue(Q);
            printf("清空成功\n");
        }
        else printf("输入错误，请重新输入\n");
        printf("请输入指令：");
        scanf("%c",&section);
        getchar();
    }
    free(Q);
    Q = NULL;
}
void Lq()
{
    LQueue *Q = (LQueue *)malloc(sizeof(LQueue));
    InitLQueue(Q);
    printf("队列初始化成功\n");
    printf("请输入指令前序号\n");
    printf("a.队列初始化\tb.摧毁队列\n");
    printf("c.获取队首元素\td.队列长度\n");
    printf("e.进队\t        f.出队\n");
    printf("g.遍历打印\th.清空队列\nq.quit\n");
    char section;
    printf("请输入指令：");
    scanf("%c",&section);
    getchar();
    while(section != 'q')
    {
        if(section == 'a')
        {
            if(Q == NULL) Q = (LQueue *)malloc(sizeof(LQueue));
            InitLQueue(Q);
            printf("队列初始化成功\n");
        }
        else if(section == 'b')
        {
            DestoryLQueue(Q);
            printf("摧毁成功\n");
        }
        else if(section == 'c')
        {
            if(temp == '1')
            {
                int val;
                int *val_ptr = &val;
                if(TRUE == GetHeadLQueue(Q, val_ptr))
                {
                   printf("获取成功，队首元素为");
                   LPrint(val_ptr);
                }
                else printf("获取失败！原因可能为空队列或队列不存在\n");
            }
            else if(temp == '2')
            {
                char val; char *val_ptr = &val;
                if(TRUE == GetHeadLQueue(Q, val_ptr))
                {
                   printf("获取成功，队首元素为");
                   LPrint(val_ptr);
                }
                else printf("获取失败！原因可能为空队列或队列不存在\n");
            }
            else if(temp == '3')
            {
                float val; float *val_ptr = &val;
                if(TRUE == GetHeadLQueue(Q, val_ptr))
                {
                   printf("获取成功，队首元素为");
                   LPrint(val_ptr);
                }
                else printf("获取失败！原因可能为空队列或队列不存在\n");
            }
            else if(temp == '4')
            {
                double val; double *val_ptr = &val;
                if(TRUE == GetHeadLQueue(Q, val_ptr))
                {
                   printf("获取成功，队首元素为");
                   LPrint(val_ptr);
                }
                else printf("获取失败！原因可能为空队列或队列不存在\n");
            }
        }
        else if(section == 'd')
        {
            if(Q == NULL)
                printf("队列不存在\n");
            else
                printf("队列长度为：%d\n",LengthLQueue(Q));
        }
        else if(section == 'e')
        {
            if(temp == '1')
            {
                int val = IntinputTest();
                int *val_ptr = &val;
                if(TRUE == EnLQueue(Q, val_ptr))
                {
                   printf("入队成功，入队元素为");
                   LPrint(val_ptr);
                }
                else printf("入队失败！原因可能为队列不存在\n");
            }
            else if(temp == '2')
            {
                char val = CharinputTest(); char *val_ptr = &val;
                if(TRUE == EnLQueue(Q, val_ptr))
                {
                   printf("入队成功，入队元素为");
                   LPrint(val_ptr);
                }
                else printf("入队失败！原因可能为队列不存在\n");
            }
            else if(temp == '3')
            {
                float val = FloatinputTest(); float *val_ptr = &val;
                if(TRUE == EnLQueue(Q, val_ptr))
                {
                   printf("入队成功，入队元素为");
                   LPrint(val_ptr);
                }
                else printf("入队失败！原因可能为队列不存在\n");
            }
            else if(temp == '4')
            {
                double val = DoubleinputTest(); double *val_ptr = &val;
                if(TRUE == EnLQueue(Q, val_ptr))
                {
                   printf("入队成功，入队元素为");
                   LPrint(val_ptr);
                }
                else printf("入队失败！原因可能为队列不存在\n");
            }
        }
        else if(section == 'f')
        {
            if(DeLQueue(Q) == TRUE)
                printf("出队成功\n");
            else printf("出队失败，可能为空队列或队列不存在\n");
        }
        else if(section == 'g')
        {
            if(TraverseLQueue(Q, LPrint) == FLASE)
                printf("遍历失败，原因可能为空队列或队列不存在\n");
            else ;
        }
        else if(section == 'h')
        {
            ClearLQueue(Q);
            printf("清空成功\n");
        }
        else printf("输入错误，请重新输入\n");
        printf("请输入指令：");
        scanf("%c",&section);
        getchar();
    }
    free(Q);
    Q = NULL;
}
int main()
{
    //设置菜单
    printf("请输入队列类型\n");
    printf("a.循环数组\tb.链表\n");
    printf("请输入:");
    char section;//选项
    scanf("%c",&section);
    getchar();//吸收回车
    while(section)//提高稳定性
    {
        if(section == 'a') {Aq(); break;}
        else if(section == 'b') {Lq(); break;}
        else{printf("输入错误，请重新输入:\n"); }
        scanf("%c",&section);
        getchar();//吸收回车
    }
    return 0;
}
