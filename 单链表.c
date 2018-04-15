#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(Node)
#define MAXN 100
int a[MAXN];
typedef struct Node
{ int data;
  struct Node *next;
}Node, *ptr_Node;

typedef enum Status
{
	SUCCESS,
	ERROR
}Status;

//������������һ�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL
ptr_Node create(int *arr, int n)
{
    ptr_Node head,p1,p2;
    head=(ptr_Node)malloc(LEN);
    if(head==NULL) return NULL;//�����ڴ�ʧ�� ����NULL
    head->data=n;//ͷ���������Ϊ������Ч���ݳ���
    p1=head;
    int l=n;//���泤��
    while(n--)
    {
        p2=(ptr_Node)malloc(LEN);
        p2->data=a[l-n-1];
        p1->next=p2;
        p1=p2;
    }
    p1->next=NULL;
    return head;
}
//���ٸ���������
void destroy(ptr_Node head)
{
    ptr_Node p=head;
    if(p->next==NULL) printf("����Ϊ�գ�");
    while(p)
    {
        p=p->next;
        free(head);
        head=p;
    }
    head=NULL;
    p=NULL;
}

//�ڵ� index λ������� node ���
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR
Status insert(ptr_Node *head, ptr_Node node, int index)
{
    ptr_Node p=*head;
    if(index<0 || index>(p->data) || p->next==NULL)//������Ϊ�� ��ų����䳤�Ȼ�С����ʱ�޸�ʧ��
        return ERROR;
    ptr_Node p1=p->next,p2=node;
    p->data++;
    if(index==0)
    {
        p2->next=p1;
        p->next=p2;
        return SUCCESS;
    }
    while(--index)
    {
        p1=p1->next;
    }
    p2->next=p1->next;//������ʹ��ֵ������ʧ��
    p1->next=p2;
    return SUCCESS;
}

//ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data����
//ɾ���ɹ����� SUCCESS������������� ERROR
Status delete(ptr_Node *head, int index, int *data)
{
    ptr_Node p=*head;
    if(index<0 || index>=(p->data) || p->next==NULL)//������Ϊ�� ��ų����䳤�Ȼ�С����ʱ�޸�ʧ��
        return ERROR;
    p->data--;
    ptr_Node p1=p,p2;
    while(index--)
    {
        p1=p1->next;
    }
    p2=p1->next;
    *data=p2->data;
    p1->next=p2->next;
    free(p2);
    p2=NULL;
    return SUCCESS;
}


//�������в��ҽڵ�ֵ�� data ��ȵĽڵ㣬�������ҵ��ĵ�һ���ڵ��ǰһ���ڵ��λ��
//������ͷ�ڵ���ȣ����� 0����û�ҵ����������������-1
int search(ptr_Node head, int data)
{
    if(head->next==NULL) return -1;//����Ϊ�� ����-1
    ptr_Node p=head->next;
    int index=0;
    while(p)
    {
        if(data==p->data) return index;//������Ӧλ�õ�ǰһ��
        index++;
        p=p->next;
    }
    p=NULL;
    return -1;//ѭ������  �Ҳ�����ֵ ����-1
}


//�������� index λ�����Ľ���ֵ�޸�Ϊ(*data)����ԭֵ���浽(*data)
//�޸ĳɹ����� SUCCESS������������� ERROR
Status edit(ptr_Node head, int index, int *data)
{
    if(index<0 || index>=(head->data) || head->next==NULL)//������Ϊ�� ��ų����䳤�Ȼ�С����ʱ�޸�ʧ��
        return ERROR;
    ptr_Node p1=head;
    while(index--)
    {
        p1=p1->next;
    }
    p1=p1->next;
    //������ֵ
    *data^=p1->data;
    p1->data^=*data;
    *data^=p1->data;
    p1=NULL;
    return SUCCESS;
}

//����ѡ��,ʵ�ֵ������սڵ�ֵ��С��������
ptr_Node mer(ptr_Node head1,ptr_Node head2)
{
    if(head1 == NULL)return head2;//ǰ�벿��Ϊ�� �򷵻غ�벿��
    if(head2 == NULL)return head1;//����벿��Ϊ�� �򷵻�ǰ�벿��
    ptr_Node res=NULL,p=NULL;//����resָ��Ϊ������ͷָ��
    if(head1->data < head2->data)//�Ƚ���������ͷ��Ѱ������ͷ
        {res = head1; head1 = head1->next;}
    else{res = head2; head2 = head2->next;}
    p = res;
    //����С��Ԫ������ǰ��
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            p->next = head1;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            head2 = head2->next;
        }
        p = p->next;
    }
    //��δ����Ԫ�ؽ������
    if(head1 != NULL) p->next = head1;
    else if(head2 != NULL) p->next = head2;
    return res;
}
ptr_Node Mergesort(ptr_Node head)
{
    if(head->next==NULL) return head;
    //Ѱ���м�ڵ�
    ptr_Node fast_left=head,slow_right=head;//����ָ��ͬʱ�䵱���Ҳ��ֵ�ָ��
    while(fast_left->next!=NULL && fast_left->next->next!= NULL)
    {
        fast_left=fast_left->next->next;
        slow_right=slow_right->next;
    }
    fast_left=slow_right;
    slow_right=slow_right->next;
    fast_left->next=NULL;//������
    fast_left=Mergesort(head);//ǰ�벿������
    slow_right=Mergesort(slow_right);//��벿������
    return mer(fast_left,slow_right);//���غϲ��������ָ��
}
Status sort(ptr_Node *head)//�鲢����
{
    ptr_Node p=*head;
    if(p->next==NULL) return ERROR;
    p=p->next;//ָ����Ч���ݵ�����ͷ
    (*head)->next=Mergesort(p);//����Ч���ݽ��й鲢����
    return SUCCESS;
}
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
//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
void print(ptr_Node head)
{
    ptr_Node p=head;
    if(p->next==NULL)
        printf("�б�Ϊ�գ�\n");
    int cnt=1;
    printf("����%d������\n",p->data);
    p=p->next;
    while(p)
    {
        printf("��%d�����ݣ�%d\n",cnt++,p->data);
        p=p->next;
    }
}
//ͨ���û�����ֵ��������
ptr_Node arrTransfer()
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
    ptr_Node p=create(a,cnt);
    printf("��������\n");
    print(p);
    return p;
}
int main()
{
    ptr_Node head=arrTransfer();
    if(head==NULL) {printf("����ʧ��\n");return 0;}
    char temp;//ѡ�����
    printf("ָ������£�\n");
    printf("a.destroy\tb.print\n");
    printf("c.insert\td.delete\n");
    printf("e.search\tf.edit\n");
    printf("g.sort(permanent)\tq.quit\n");
    printf("h.create\n");
    printf("������ָ��ǰ����ţ�");
    scanf("%c",&temp);
    while(temp!='q')
    {
        if(temp=='a') destroy(head);
        else if(temp=='b') print(head);
        else if(temp=='c')
        {
            printf("���������λ�ã���λ�ú�һλ���룩��");
            int pos=inputTest();
            printf("������������ݣ�");
            int data=inputTest();
            ptr_Node p=(Node* )malloc(LEN);//�����ṹ��ָ��洢����ֵ
            if(insert(&head,p,pos)==SUCCESS)
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
            if(delete(&head,pos,p)==SUCCESS)
            {
                printf("ɾ���ɹ���ɾ����ֵΪ%d\n",*p);
                print(head);
            }
            else printf("ɾ��ʧ�ܣ�\n");
        }
        else if(temp=='e')
        {
            printf("��������ҵ�ֵ��");
            int data=inputTest();
            if(-1==search(head,data))
                printf("�Ҳ�����ֵ\n");
            else printf("��ֵΪ%d���ڵ�%dλ��",data,search(head,data)+1);
        }
        else if(temp=='f')
        {
            printf("�������޸�λ�ã���λ�ú�һλ�޸ģ���");
            int pos=inputTest();
            printf("�������޸�ֵ��");
            int editData=inputTest();
            int *p=&editData;
            if(edit(head,pos,p)==SUCCESS)
            {
                printf("�޸ĳɹ���\n");
                printf("���޸ĵ�ֵΪ%d\n",*p);
            }
            else printf("�޸�ʧ�ܣ�\n");
        }
        else if(temp=='g')
        {
            if(sort(&head)==SUCCESS)
            {
                printf("����ɹ���\n");
                print(head);
            }
            else printf("����ʧ�ܣ�\n");
        }
        else if(temp=='h')
        {
            if(head->next==NULL) head=arrTransfer();
            else printf("�����Ѵ��ڣ����ȴݻ�\n");
        }
        else printf("�����������������\n");
        printf("������ָ��ǰ����ţ�");
        scanf("%c",&temp);
    }
	return 0;
}
