#include <stdio.h>
#include "../headfile/queue.h"
#include <stdlib.h>
#include <string.h>
extern int datasize;//����λ�ڴ����������� �����б���������
extern char temp;//����������ѡ����� �����б���������
//���������ݼ������
int IntinputTest()
{
    int i,index;
    printf("������һ���������ݣ�");
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
char CharinputTest()
{
    char i;
    int index;
    printf("������һ���ַ������ݣ�");
    index=scanf("%c",&i);
    getchar();
    while(!index)
    {
        printf("����������������룺");
        index=scanf("%c",&i);
        getchar();//���ջس�
    }
    return i;
}
float FloatinputTest()
{
    float i;
    int index;
    printf("������һ�������������ݣ�");
    index=scanf("%f",&i);
    getchar();
    while(!index)
    {
        printf("����������������룺");
        index=scanf("%f",&i);
        getchar();//���ջس�
    }
    return i;
}
double DoubleinputTest()
{
    double i;
    int index;
    printf("������һ��˫���������ݣ�");
    index=scanf("%lf",&i);
    getchar();
    while(!index)
    {
        printf("����������������룺");
        index=scanf("%lf",&i);
        getchar();//���ջس�
    }
    return i;
}
void Aq()
{
    AQueue *Q = (AQueue *)malloc(sizeof(AQueue));
    InitAQueue(Q);
    printf("���г�ʼ���ɹ�\n");
    printf("������ָ��ǰ���\n");
    printf("a.���г�ʼ��\tb.�ݻٶ���\n");
    printf("c.��ȡ����Ԫ��\td.���г���\n");
    printf("e.����\t        f.����\n");
    printf("g.������ӡ\th.��ն���\nq.quit\n");
    char section;
    printf("������ָ�");
    scanf("%c",&section);
    getchar();
    while(section != 'q')
    {
        if(section == 'a')
        {
            if(Q == NULL) Q = (AQueue *)malloc(sizeof(AQueue));
            InitAQueue(Q);
            printf("���г�ʼ���ɹ�\n");
        }
        else if(section == 'b')
        {
            DestoryAQueue(Q);
            printf("�ݻٳɹ�\n");
        }
        else if(section == 'c')
        {
            if(temp == '1')
            {
                int val;
                int *val_ptr = &val;
                if(TRUE == GetHeadAQueue(Q, val_ptr))
                {
                   printf("��ȡ�ɹ�������Ԫ��Ϊ");
                   APrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            }
            else if(temp == '2')
            {
                char val; char *val_ptr = &val;
                if(TRUE == GetHeadAQueue(Q, val_ptr))
                {
                   printf("��ȡ�ɹ�������Ԫ��Ϊ");
                   APrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            }
            else if(temp == '3')
            {
                float val; float *val_ptr = &val;
                if(TRUE == GetHeadAQueue(Q, val_ptr))
                {
                   printf("��ȡ�ɹ�������Ԫ��Ϊ");
                   APrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            }
            else if(temp == '4')
            {
                double val; double *val_ptr = &val;
                if(TRUE == GetHeadAQueue(Q, val_ptr))
                {
                   printf("��ȡ�ɹ�������Ԫ��Ϊ");
                   APrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            }
        }
        else if(section == 'd')
        {
            if(Q == NULL)
                printf("���в�����\n");
            else
                printf("���г���Ϊ��%d\n",LengthAQueue(Q));
        }
        else if(section == 'e')
        {
            if(temp == '1')
            {
                int val = IntinputTest();
                int *val_ptr = &val;
                if(TRUE == EnAQueue(Q, val_ptr))
                {
                   printf("��ӳɹ������Ԫ��Ϊ");
                   APrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�����л���в�����\n");
            }
            else if(temp == '2')
            {
                char val = CharinputTest(); char *val_ptr = &val;
                if(TRUE == EnAQueue(Q, val_ptr))
                {
                   printf("��ӳɹ������Ԫ��Ϊ");
                   APrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�����л���в�����\n");
            }
            else if(temp == '3')
            {
                float val = FloatinputTest(); float *val_ptr = &val;
                if(TRUE == EnAQueue(Q, val_ptr))
                {
                   printf("��ӳɹ������Ԫ��Ϊ");
                   APrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�����л���в�����\n");
            }
            else if(temp == '4')
            {
                double val = DoubleinputTest(); double *val_ptr = &val;
                if(TRUE == EnAQueue(Q, val_ptr))
                {
                   printf("��ӳɹ������Ԫ��Ϊ");
                   APrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�����л���в�����\n");
            }
        }
        else if(section == 'f')
        {
            if(DeAQueue(Q) == TRUE)
                printf("���ӳɹ�\n");
            else printf("����ʧ�ܣ�����Ϊ�ն��л���в�����\n");
        }
        else if(section == 'g')
        {
            if(TraverseAQueue(Q, APrint) == FLASE)
                printf("����ʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            else ;
        }
        else if(section == 'h')
        {
            ClearAQueue(Q);
            printf("��ճɹ�\n");
        }
        else printf("�����������������\n");
        printf("������ָ�");
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
    printf("���г�ʼ���ɹ�\n");
    printf("������ָ��ǰ���\n");
    printf("a.���г�ʼ��\tb.�ݻٶ���\n");
    printf("c.��ȡ����Ԫ��\td.���г���\n");
    printf("e.����\t        f.����\n");
    printf("g.������ӡ\th.��ն���\nq.quit\n");
    char section;
    printf("������ָ�");
    scanf("%c",&section);
    getchar();
    while(section != 'q')
    {
        if(section == 'a')
        {
            if(Q == NULL) Q = (LQueue *)malloc(sizeof(LQueue));
            InitLQueue(Q);
            printf("���г�ʼ���ɹ�\n");
        }
        else if(section == 'b')
        {
            DestoryLQueue(Q);
            printf("�ݻٳɹ�\n");
        }
        else if(section == 'c')
        {
            if(temp == '1')
            {
                int val;
                int *val_ptr = &val;
                if(TRUE == GetHeadLQueue(Q, val_ptr))
                {
                   printf("��ȡ�ɹ�������Ԫ��Ϊ");
                   LPrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            }
            else if(temp == '2')
            {
                char val; char *val_ptr = &val;
                if(TRUE == GetHeadLQueue(Q, val_ptr))
                {
                   printf("��ȡ�ɹ�������Ԫ��Ϊ");
                   LPrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            }
            else if(temp == '3')
            {
                float val; float *val_ptr = &val;
                if(TRUE == GetHeadLQueue(Q, val_ptr))
                {
                   printf("��ȡ�ɹ�������Ԫ��Ϊ");
                   LPrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            }
            else if(temp == '4')
            {
                double val; double *val_ptr = &val;
                if(TRUE == GetHeadLQueue(Q, val_ptr))
                {
                   printf("��ȡ�ɹ�������Ԫ��Ϊ");
                   LPrint(val_ptr);
                }
                else printf("��ȡʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            }
        }
        else if(section == 'd')
        {
            if(Q == NULL)
                printf("���в�����\n");
            else
                printf("���г���Ϊ��%d\n",LengthLQueue(Q));
        }
        else if(section == 'e')
        {
            if(temp == '1')
            {
                int val = IntinputTest();
                int *val_ptr = &val;
                if(TRUE == EnLQueue(Q, val_ptr))
                {
                   printf("��ӳɹ������Ԫ��Ϊ");
                   LPrint(val_ptr);
                }
                else printf("���ʧ�ܣ�ԭ�����Ϊ���в�����\n");
            }
            else if(temp == '2')
            {
                char val = CharinputTest(); char *val_ptr = &val;
                if(TRUE == EnLQueue(Q, val_ptr))
                {
                   printf("��ӳɹ������Ԫ��Ϊ");
                   LPrint(val_ptr);
                }
                else printf("���ʧ�ܣ�ԭ�����Ϊ���в�����\n");
            }
            else if(temp == '3')
            {
                float val = FloatinputTest(); float *val_ptr = &val;
                if(TRUE == EnLQueue(Q, val_ptr))
                {
                   printf("��ӳɹ������Ԫ��Ϊ");
                   LPrint(val_ptr);
                }
                else printf("���ʧ�ܣ�ԭ�����Ϊ���в�����\n");
            }
            else if(temp == '4')
            {
                double val = DoubleinputTest(); double *val_ptr = &val;
                if(TRUE == EnLQueue(Q, val_ptr))
                {
                   printf("��ӳɹ������Ԫ��Ϊ");
                   LPrint(val_ptr);
                }
                else printf("���ʧ�ܣ�ԭ�����Ϊ���в�����\n");
            }
        }
        else if(section == 'f')
        {
            if(DeLQueue(Q) == TRUE)
                printf("���ӳɹ�\n");
            else printf("����ʧ�ܣ�����Ϊ�ն��л���в�����\n");
        }
        else if(section == 'g')
        {
            if(TraverseLQueue(Q, LPrint) == FLASE)
                printf("����ʧ�ܣ�ԭ�����Ϊ�ն��л���в�����\n");
            else ;
        }
        else if(section == 'h')
        {
            ClearLQueue(Q);
            printf("��ճɹ�\n");
        }
        else printf("�����������������\n");
        printf("������ָ�");
        scanf("%c",&section);
        getchar();
    }
    free(Q);
    Q = NULL;
}
int main()
{
    //���ò˵�
    printf("�������������\n");
    printf("a.ѭ������\tb.����\n");
    printf("������:");
    char section;//ѡ��
    scanf("%c",&section);
    getchar();//���ջس�
    while(section)//����ȶ���
    {
        if(section == 'a') {Aq(); break;}
        else if(section == 'b') {Lq(); break;}
        else{printf("�����������������:\n"); }
        scanf("%c",&section);
        getchar();//���ջس�
    }
    return 0;
}
