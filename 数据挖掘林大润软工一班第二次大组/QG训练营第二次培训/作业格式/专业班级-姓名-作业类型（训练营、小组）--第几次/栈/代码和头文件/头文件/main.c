#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
//对输入是否为整数检查 加强稳定性
int inputTest()
{
    int i,index;
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
void printSqStack(SqStack *s)//打印数组栈
{
    if(s == NULL)
        printf("栈不存在\n");
    else if(isEmptyStack(s) == OK)
        printf("为空栈\n");
    else
    {
        printf("打印基于数组的栈如下\n");
        printf("栈的大小为：%d\n",s->size);
        printf("栈的元素个数为：%d\n",s->top+1);//栈顶指针标号加一即为栈里元素个数
        int cnt=0;
        for(;cnt<=s->top;cnt++)
        {
            printf("第%d个数据：%d",cnt+1,s->elem[cnt]);
            if(cnt == s->top)
                printf("\t<-栈顶位置");
            putchar('\n');
        }
    }
}
void Sq()
{
    printf("已进入数组栈的菜单\n");
    int sqtop, *sqtop_ptr=&sqtop;//存放被弹出栈顶值
    int sq_e, *sq_eptr=&sq_e;//存放查询栈顶值
    SqStack *sq = (SqStack *)malloc(sizeof(SqStack));
    printf("请输入数组栈大小:");
    int sizes = inputTest();
    initStack(sq, sizes);
    printf("请输入指令前序号\n");
    printf("a.初始化\tb.获取栈顶元素\n");
    printf("c.清空栈\td.摧毁栈\n");
    printf("e.push\t        f.pop\n");
    printf("g.打印\t        q.quit\n");
    char section;
    printf("请输入指令：");
    scanf("%c",&section);
    getchar();
    while(section != 'q')
    {
        if(section == 'a')
        {
            printf("请输入栈的大小：\n");
            int sizes = inputTest();
            if(OK == initStack(sq,sizes))
                printf("初始化成功\n");
            else printf("初始化失败\n");
        }
        else if(section == 'b')
        {
            if(getTopStack(sq,sq_eptr) == OK) printf("获取成功，栈顶值为%d\n",*sq_eptr);
            else printf("获取失败,原因可能为:为空栈或者栈不存在\n");
        }
        else if(section == 'c')
        {
            if(clearStack(sq) == OK) printf("清空成功\n");
            else printf("清空失败,原因为:栈不存在\n");
        }
        else if(section == 'd')
        {
            if(destoryStack(sq) == OK) {sq = NULL; printf("摧毁成功\n");}
            else printf("摧毁失败,原因为:栈不存在\n");
        }
        else if(section == 'e')
        {
            printf("请输入需推入栈的值：");
            int datas = inputTest();
            if(pushStack(sq,datas) == OK) printf("push成功\n");
            else printf("push失败,原因可能为:栈满或者栈不存在\n");
        }
        else if(section == 'f')
        {
            if(popStack(sq,sqtop_ptr) == OK) printf("弹出成功，弹出值为%d\n",*sqtop_ptr);
            else printf("弹出失败,原因可能为:空栈或者栈不存在\n");
        }
        else if(section == 'g')
        {
            printSqStack(sq);
        }
        else printf("输入错误，请重新输入\n");
        printf("请输入指令：");
        scanf("%c",&section);
        getchar();
    }
}
void printLStack(LinkStack *s)
{
    if(s == NULL)
        printf("栈不存在\n");
    else if(isEmptyLStack(s) == OK)
        printf("为空栈\n");
    else
    {
        printf("打印基于链表的栈如下\n");
        printf("栈的元素个数为：%d\n",s->count);
        int cnt = 1;
        LinkStackPtr p = s->top;//遍历用的指针
        while(p != NULL)
        {
            printf("第%d个元素：%d",cnt,p->data);
            if(cnt == 1) printf("\t<-栈顶位置");
            putchar('\n');
            cnt++;
            p = p->next;
        }
    }
}
void Link()
{
    printf("已进入链表栈的菜单\n");
    int ltop, *ltop_ptr=&ltop;//存放被弹出栈顶值
    int l_e, *l_eptr=&l_e;//存放查询栈顶值
    LinkStack *lq = (LinkStack *)malloc(sizeof(LinkStack));
    if(initLStack(lq) == OK) printf("建立链表栈成功\n");
    printf("请输入指令前序号\n");
    printf("a.初始化\tb.获取栈顶元素\n");
    printf("c.清空栈\td.摧毁栈\n");
    printf("e.push\t        f.pop\n");
    printf("g.打印\t        q.quit\n");
    char section;
    printf("请输入指令：");
    scanf("%c",&section);
    getchar();
    while(section != 'q')
    {
        if(section == 'a')
        {
            if(OK == initLStack(lq)) printf("初始化成功\n");
            else printf("初始化失败\n");
        }
        else if(section == 'b')
        {
            if(getTopLStack(lq,l_eptr) == OK) printf("获取成功，栈顶值为：%d\n",*l_eptr);
            else printf("获取失败,原因可能为:为空栈或者栈不存在\n");
        }
        else if(section == 'c')
        {
            if(clearLStack(lq) == OK) printf("清空成功\n");
            else printf("清空失败,原因为:栈不存在\n");;
        }
        else if(section == 'd')
        {
            if(destoryLStack(lq) == OK) {lq = NULL;printf("摧毁成功\n");}//函数无法改变lq的值，需手动改变
            else printf("摧毁失败,原因为:栈不存在\n");;
        }
        else if(section == 'e')
        {
            printf("请输入需推入栈的值：");
            int datas = inputTest();
            if(pushLStack(lq,datas) == OK) printf("push成功\n");
            else printf("push失败,原因可能为:栈满或者栈不存在\n");;
        }
        else if(section == 'f')
        {
            if(popLStack(lq,ltop_ptr) == OK) printf("弹出成功，弹出值为%d\n",*ltop_ptr);
            else printf("弹出失败,原因可能为:空栈或者栈不存在\n");;
        }
        else if(section == 'g')
        {
            printLStack(lq);
        }
        else printf("输入错误，请重新输入\n");
        printf("请输入指令：");
        scanf("%c",&section);
        getchar();
    }
}
int main()
{
    printf("请输入栈的类型\n");
    printf("a.数组\tb.链表\n");
    printf("请输入：");
    char temp;//选项
    scanf("%c",&temp);
    getchar();//吸收空格
    while(temp)//提高稳定性
    {
        if(temp == 'a') {Sq(); break;}
        else if(temp == 'b') {Link(); break;}
        else{printf("输入错误 请重新输入\n"); }
        scanf("%c",&temp);
        getchar();//吸收空格
    }
    return 0;
}
