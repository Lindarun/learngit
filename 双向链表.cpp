#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(TNode) 
typedef struct TNode 
{
	int data; 
	struct TNode *next;
	struct TNode *pre;
}TNode, *ptr_TNode;
typedef enum Status 
{
	SUCCESS,
	ERROR 
}Status;
int a[100]={0} ;
//����βָ��
ptr_TNode ptr_tail=NULL; 
//�������� ��ǿ�ȶ���
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
//������������һ��˫�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL 
ptr_TNode create(int *arr, int n)//����һ��������ͷ����˫������ 
{
	int cnt=0;
	ptr_TNode head,tail,p1,p2;
	head=(TNode *)malloc(LEN);
	head->data=a[cnt++];
	head->pre=NULL;
	p1=head;
	while(cnt<n)
	{
		p2=(TNode *)malloc(LEN);
		p2->data=a[cnt++];
		p1->next=p2;
		p2->pre=p1;
		p1=p2;
	}
	p1->next=NULL;
	tail=p1;
	ptr_tail=tail;
	return head;
}

//˫������,ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
Status delete_T(ptr_TNode *head, int index, int *data)
{
	if(index<0 || head==NULL) return  ERROR;
	ptr_TNode p=*head,p1;
	while(index--)
	{
		p=p->next;
		if(p==NULL) return ERROR; //���Ȳ��� ����error 
	}
	if(p->pre==NULL) {*data=p->data;*head=p->next;free(p);(*head)->pre=NULL;}//��Ϊͷ�ڵ� ��ͷָ��ָ����һ�ڵ� ������preָ��NULL 
	else if(p->next==NULL) {*data=p->data;ptr_tail=p->pre;free(p);ptr_tail->next=NULL;}//��Ϊβ�ڵ� ��βָ��ָ����һ�ڵ� ������nextָ��NULL  
	else
	{
		*data=p->data;
		p1=p->pre;
		p1->next=p->next;
		p1=p->next;
		p1->pre=p->pre;
		free(p);
	} 
	p=NULL;
	return SUCCESS;
}
//˫������,�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
	if(index<0 || head==NULL) return  ERROR;//λ��Ϊ���� ������ ����error 
	ptr_TNode p=*head,p1;
	if(index==0) {node->next=p;p->pre=node;(*head)=node;node->pre=NULL;return SUCCESS;}//�����봦Ϊͷ�� 
	while(--index)
	{
		p=p->next;
		if(p==NULL) return ERROR;
	}
	if(p->next==NULL){p->next=node;node->next=NULL;node->pre=p;ptr_tail=node;}//�����봦Ϊβ�� 
	else//����λ�� 
	{
		p1=p->next;	
		p->next=node;
		node->next=p1;
		p1->pre=node;
		node->pre=p;
    }
    return SUCCESS;
}
//���ٸ��������� 
void destory(ptr_TNode head)
{
	ptr_TNode p=head;
	while(head)
	{
		p=p->next;
		free(head);
		head=p;
	}
	head=NULL;
	p=NULL;
}
//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
void print(ptr_TNode head)
{
	if(head->next==NULL)
	 {printf("����Ϊ��!\n"); return;}
	ptr_TNode p=head;
	int cnt=1;
	do
	{
		printf("��%d�����ݣ�%d\n",cnt++,p->data);
		p=p->next;
	}while(p);
}
//��β�����
void printtail(ptr_TNode tail)
{
	if(tail->pre==NULL)
	 {printf("����Ϊ��!\n"); return;}
	ptr_TNode p=tail;
	int cnt=1;
	do
	{
		printf("��%d�����ݣ�%d\n",cnt++,p->data);
		p=p->pre;
	}while(p);
} 
ptr_TNode arrTransfer()
{
    int i,data,cnt=0;//����cntΪ���ݸ�������
    printf("���������ݸ�����");
    cnt=inputTest();
    printf("�����������������\n");
    for(i=0;i<cnt;i++)
    {
        printf("�������%d�����ݣ�",i+1);
        a[i]=inputTest();
    }
    ptr_TNode p=create(a,cnt);
    printf("��������\n");
    print(p);
    return p;
}
int main()
{
	ptr_TNode head=arrTransfer();
	if(head==NULL) {printf("����ʧ��\n");return 0;}
	char temp;//ѡ�����
	printf("ָ������£�\n");
	printf("a.�����������\tb.�����������\n");
	printf("c.����\td.ɾ��");
	printf ("e.�ݻ�����\tf.��������\n");
	printf("q.�˳�\n");
	printf("������ָ��ǰ����ţ�");
    scanf("%c",&temp);
    while(temp!='q')
    {
    	if(temp=='a') print(head);
    	else if(temp=='b') printtail(ptr_tail);
    	else if(temp=='e') destory(head);
    	else if(temp=='f')
    	{
    		if(head->next==NULL) head=arrTransfer();
            else printf("�����Ѵ��ڣ����ȴݻ�\n");
    	}
    	else if(temp=='c')
    	{
    		printf("���������λ�ã���λ�ú�һλ���룩��");
            int pos=inputTest();
            printf("������������ݣ�");
            int data=inputTest();
            ptr_TNode p=(TNode* )malloc(LEN);//�����ṹ��ָ��洢����ֵ
            if(insert_T(&head,p,pos)==SUCCESS)
            {
                printf("����ɹ���\n");
                print(head);
            }
            else printf("����ʧ��!\n");
    	}
    	else if(temp=='d')
    	{
    		printf("������ɾ��λ�ã���λ�ú�һλɾ������");
            int pos=inputTest();
            int deleteData,*p=&deleteData;
            if(delete_T(&head,pos,p)==SUCCESS)
            {
                printf("ɾ���ɹ���ɾ����ֵΪ%d\n",*p);
                print(head);
            }
            else printf("ɾ��ʧ�ܣ�\n");
    	}
    	else printf("�����������������\n");
        printf("������ָ��ǰ����ţ�");
        scanf("%c",&temp);
    }
	return 0;
}
