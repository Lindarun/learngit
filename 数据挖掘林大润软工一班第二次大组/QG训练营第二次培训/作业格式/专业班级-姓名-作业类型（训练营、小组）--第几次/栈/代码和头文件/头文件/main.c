#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
//�������Ƿ�Ϊ������� ��ǿ�ȶ���
int inputTest()
{
    int i,index;
    index=scanf("%d",&i);
    getchar();
    while(!index)
    {
        printf("����������������룺");
        index=scanf("%d",&i);
        getchar();//���ջس�
    }
    return i;
}
void printSqStack(SqStack *s)//��ӡ����ջ
{
    if(s == NULL)
        printf("ջ������\n");
    else if(isEmptyStack(s) == OK)
        printf("Ϊ��ջ\n");
    else
    {
        printf("��ӡ���������ջ����\n");
        printf("ջ�Ĵ�СΪ��%d\n",s->size);
        printf("ջ��Ԫ�ظ���Ϊ��%d\n",s->top+1);//ջ��ָ���ż�һ��Ϊջ��Ԫ�ظ���
        int cnt=0;
        for(;cnt<=s->top;cnt++)
        {
            printf("��%d�����ݣ�%d",cnt+1,s->elem[cnt]);
            if(cnt == s->top)
                printf("\t<-ջ��λ��");
            putchar('\n');
        }
    }
}
void Sq()
{
    printf("�ѽ�������ջ�Ĳ˵�\n");
    int sqtop, *sqtop_ptr=&sqtop;//��ű�����ջ��ֵ
    int sq_e, *sq_eptr=&sq_e;//��Ų�ѯջ��ֵ
    SqStack *sq = (SqStack *)malloc(sizeof(SqStack));
    printf("����������ջ��С:");
    int sizes = inputTest();
    initStack(sq, sizes);
    printf("������ָ��ǰ���\n");
    printf("a.��ʼ��\tb.��ȡջ��Ԫ��\n");
    printf("c.���ջ\td.�ݻ�ջ\n");
    printf("e.push\t        f.pop\n");
    printf("g.��ӡ\t        q.quit\n");
    char section;
    printf("������ָ�");
    scanf("%c",&section);
    getchar();
    while(section != 'q')
    {
        if(section == 'a')
        {
            printf("������ջ�Ĵ�С��\n");
            int sizes = inputTest();
            if(OK == initStack(sq,sizes))
                printf("��ʼ���ɹ�\n");
            else printf("��ʼ��ʧ��\n");
        }
        else if(section == 'b')
        {
            if(getTopStack(sq,sq_eptr) == OK) printf("��ȡ�ɹ���ջ��ֵΪ%d\n",*sq_eptr);
            else printf("��ȡʧ��,ԭ�����Ϊ:Ϊ��ջ����ջ������\n");
        }
        else if(section == 'c')
        {
            if(clearStack(sq) == OK) printf("��ճɹ�\n");
            else printf("���ʧ��,ԭ��Ϊ:ջ������\n");
        }
        else if(section == 'd')
        {
            if(destoryStack(sq) == OK) {sq = NULL; printf("�ݻٳɹ�\n");}
            else printf("�ݻ�ʧ��,ԭ��Ϊ:ջ������\n");
        }
        else if(section == 'e')
        {
            printf("������������ջ��ֵ��");
            int datas = inputTest();
            if(pushStack(sq,datas) == OK) printf("push�ɹ�\n");
            else printf("pushʧ��,ԭ�����Ϊ:ջ������ջ������\n");
        }
        else if(section == 'f')
        {
            if(popStack(sq,sqtop_ptr) == OK) printf("�����ɹ�������ֵΪ%d\n",*sqtop_ptr);
            else printf("����ʧ��,ԭ�����Ϊ:��ջ����ջ������\n");
        }
        else if(section == 'g')
        {
            printSqStack(sq);
        }
        else printf("�����������������\n");
        printf("������ָ�");
        scanf("%c",&section);
        getchar();
    }
}
void printLStack(LinkStack *s)
{
    if(s == NULL)
        printf("ջ������\n");
    else if(isEmptyLStack(s) == OK)
        printf("Ϊ��ջ\n");
    else
    {
        printf("��ӡ���������ջ����\n");
        printf("ջ��Ԫ�ظ���Ϊ��%d\n",s->count);
        int cnt = 1;
        LinkStackPtr p = s->top;//�����õ�ָ��
        while(p != NULL)
        {
            printf("��%d��Ԫ�أ�%d",cnt,p->data);
            if(cnt == 1) printf("\t<-ջ��λ��");
            putchar('\n');
            cnt++;
            p = p->next;
        }
    }
}
void Link()
{
    printf("�ѽ�������ջ�Ĳ˵�\n");
    int ltop, *ltop_ptr=&ltop;//��ű�����ջ��ֵ
    int l_e, *l_eptr=&l_e;//��Ų�ѯջ��ֵ
    LinkStack *lq = (LinkStack *)malloc(sizeof(LinkStack));
    if(initLStack(lq) == OK) printf("��������ջ�ɹ�\n");
    printf("������ָ��ǰ���\n");
    printf("a.��ʼ��\tb.��ȡջ��Ԫ��\n");
    printf("c.���ջ\td.�ݻ�ջ\n");
    printf("e.push\t        f.pop\n");
    printf("g.��ӡ\t        q.quit\n");
    char section;
    printf("������ָ�");
    scanf("%c",&section);
    getchar();
    while(section != 'q')
    {
        if(section == 'a')
        {
            if(OK == initLStack(lq)) printf("��ʼ���ɹ�\n");
            else printf("��ʼ��ʧ��\n");
        }
        else if(section == 'b')
        {
            if(getTopLStack(lq,l_eptr) == OK) printf("��ȡ�ɹ���ջ��ֵΪ��%d\n",*l_eptr);
            else printf("��ȡʧ��,ԭ�����Ϊ:Ϊ��ջ����ջ������\n");
        }
        else if(section == 'c')
        {
            if(clearLStack(lq) == OK) printf("��ճɹ�\n");
            else printf("���ʧ��,ԭ��Ϊ:ջ������\n");;
        }
        else if(section == 'd')
        {
            if(destoryLStack(lq) == OK) {lq = NULL;printf("�ݻٳɹ�\n");}//�����޷��ı�lq��ֵ�����ֶ��ı�
            else printf("�ݻ�ʧ��,ԭ��Ϊ:ջ������\n");;
        }
        else if(section == 'e')
        {
            printf("������������ջ��ֵ��");
            int datas = inputTest();
            if(pushLStack(lq,datas) == OK) printf("push�ɹ�\n");
            else printf("pushʧ��,ԭ�����Ϊ:ջ������ջ������\n");;
        }
        else if(section == 'f')
        {
            if(popLStack(lq,ltop_ptr) == OK) printf("�����ɹ�������ֵΪ%d\n",*ltop_ptr);
            else printf("����ʧ��,ԭ�����Ϊ:��ջ����ջ������\n");;
        }
        else if(section == 'g')
        {
            printLStack(lq);
        }
        else printf("�����������������\n");
        printf("������ָ�");
        scanf("%c",&section);
        getchar();
    }
}
int main()
{
    printf("������ջ������\n");
    printf("a.����\tb.����\n");
    printf("�����룺");
    char temp;//ѡ��
    scanf("%c",&temp);
    getchar();//���տո�
    while(temp)//����ȶ���
    {
        if(temp == 'a') {Sq(); break;}
        else if(temp == 'b') {Link(); break;}
        else{printf("������� ����������\n"); }
        scanf("%c",&temp);
        getchar();//���տո�
    }
    return 0;
}
