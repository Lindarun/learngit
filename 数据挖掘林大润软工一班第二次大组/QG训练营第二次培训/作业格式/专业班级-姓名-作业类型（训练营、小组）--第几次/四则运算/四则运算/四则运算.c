#include <stdio.h>
#include "�����ͷ�ļ�\ͷ�ļ�\stack.h"
#define MAXN 30
#include <stdlib.h>
#include <string.h>
void transfer(char s[], char s_houzhui[])//תΪ��׺���ʽ
{
    SqStack *sq = (SqStack *)malloc(sizeof(SqStack));//��������ջ
    initStack(sq,MAXN);//��ʼ��
    int temp = 0;
    int *temp_ptr=&temp;//���pop����ֵ
    int i;//ԭʼchar����ָ��
    int j=0;//ת����char����ָ��
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i] == ' ' || s[i] == '\n') continue;//�˹��ո�ͻس�
        else if(s[i]<='9' && s[i]>='0')//�������ַŽ���׺���ʽ
        {
            s_houzhui[j++] = s[i];
            if(s[i+1]>'9' || s[i+1]<'0')//��λ�����Σ�����λ�����һλ����һ���ո��־
                s_houzhui[j++] = ' ';
        }
        else if(s[i] == '(') {pushStack(sq, s[i]);}//������ֱ��pop��
        else if(s[i] == '+' || s[i] == '-')//��Ϊ�ӺŻ���� ��pop��ջ���������ȼ����ڻ���ڼӺŻ���ŵ�
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
        else if(s[i] == '*' || s[i] == '/') //�˺Ż���� ������ջ��Ϊ�˺Ż���ŵ�pop��������ǰ����ѹ��ջ��
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
        else if(s[i] == ')')//�ж�������
        {
            while(1)//�����������ż���������� ����������ֹͣ����
            {
                popStack(sq,temp_ptr);
                if(temp == '(') break;
                else s_houzhui[j++] = (temp);
            }
        }
        else {printf("���ʽ����\n"); break;}
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
    int j;//����ָ��
    SqStack *sq = (SqStack *)malloc(sizeof(SqStack));//��������ջ
    initStack(sq,MAXN);//��ʼ��
    for(j=0;s_houzhui[j]!='\0';j++)//��������
    {
        if( '0' <= s_houzhui[j] && '9' >= s_houzhui[j])//���ַ���ջ��
        {
            int data = 0, ans = 0;
            while(s_houzhui[j]!=' ')//��λ�����Σ����ݿո�ת��Ϊ���Ͷ�λ��
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
            if(isEmptyStack(sq) == OK)//����ջ�Ƿ�Ϊ�գ�Ϊ������ʽ����
                {printf("���ʽ��������������\n"); break;}
            popStack(sq,popdata1_ptr);
            if(isEmptyStack(sq) == OK)//����ջ�Ƿ�Ϊ�գ�Ϊ������ʽ����
                {printf("���ʽ��������������\n"); break;}
            popStack(sq,popdata2_ptr);
            switch(s_houzhui[j])//���ݷ��Ŷ�pop����ֵ��������
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
                     pushStack(sq, popdata2/popdata1);//����ջ����������Ϊint�ͣ��޷����㸡����
                }
            }
        }
        else continue;
    }
    int result = 0, *result_ptr = &result;//��Ž��
    popStack(sq,result_ptr);//���ջ�е�ֵ��Ϊ���ʽ��ֵ
    printf("���ʽ��ֵΪ��%d\n",result);
}

int main()
{
    char s[MAXN],s_houzhui[MAXN];
    printf("������������Ŀǰ��֧�ֶ�λ�������㣬����֧�ָ������㣬��������;�Ҳ���֧���������뷨������֮��������ԭ�£�\n");
    putchar('\n');
    printf("������һ������������ʽ(��q����)��");
    while(gets(s) && s[0] != 'q')
    {
        transfer(s,s_houzhui);//ת��Ϊ��׺���ʽ
        calculate_s(s_houzhui);//�����׺���ʽ;
        printf("������һ������������ʽ(��q����)��");
    }
    return 0;
}
