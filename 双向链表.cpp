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
//返回尾指针
ptr_TNode ptr_tail=NULL; 
//对输入检查 加强稳定性
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
//根据数组生成一条双向链表，成功则返回头节点，失败返回 NULL 
ptr_TNode create(int *arr, int n)//生成一个不具有头结点的双向链表 
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

//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
Status delete_T(ptr_TNode *head, int index, int *data)
{
	if(index<0 || head==NULL) return  ERROR;
	ptr_TNode p=*head,p1;
	while(index--)
	{
		p=p->next;
		if(p==NULL) return ERROR; //长度不够 返回error 
	}
	if(p->pre==NULL) {*data=p->data;*head=p->next;free(p);(*head)->pre=NULL;}//若为头节点 将头指针指向下一节点 并将其pre指向NULL 
	else if(p->next==NULL) {*data=p->data;ptr_tail=p->pre;free(p);ptr_tail->next=NULL;}//若为尾节点 将尾指针指向上一节点 并将其next指向NULL  
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
//双向链表,在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
	if(index<0 || head==NULL) return  ERROR;//位置为负数 空链表 返回error 
	ptr_TNode p=*head,p1;
	if(index==0) {node->next=p;p->pre=node;(*head)=node;node->pre=NULL;return SUCCESS;}//若插入处为头部 
	while(--index)
	{
		p=p->next;
		if(p==NULL) return ERROR;
	}
	if(p->next==NULL){p->next=node;node->next=NULL;node->pre=p;ptr_tail=node;}//若插入处为尾部 
	else//其他位置 
	{
		p1=p->next;	
		p->next=node;
		node->next=p1;
		p1->pre=node;
		node->pre=p;
    }
    return SUCCESS;
}
//销毁给定的链表 
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
//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print(ptr_TNode head)
{
	if(head->next==NULL)
	 {printf("链表为空!\n"); return;}
	ptr_TNode p=head;
	int cnt=1;
	do
	{
		printf("第%d个数据：%d\n",cnt++,p->data);
		p=p->next;
	}while(p);
}
//从尾端输出
void printtail(ptr_TNode tail)
{
	if(tail->pre==NULL)
	 {printf("链表为空!\n"); return;}
	ptr_TNode p=tail;
	int cnt=1;
	do
	{
		printf("第%d个数据：%d\n",cnt++,p->data);
		p=p->pre;
	}while(p);
} 
ptr_TNode arrTransfer()
{
    int i,data,cnt=0;//设置cnt为数据个数计数
    printf("请输入数据个数：");
    cnt=inputTest();
    printf("请逐个输入链表数据\n");
    for(i=0;i<cnt;i++)
    {
        printf("请输入第%d个数据：",i+1);
        a[i]=inputTest();
    }
    ptr_TNode p=create(a,cnt);
    printf("链表如下\n");
    print(p);
    return p;
}
int main()
{
	ptr_TNode head=arrTransfer();
	if(head==NULL) {printf("创建失败\n");return 0;}
	char temp;//选项变量
	printf("指令表如下：\n");
	printf("a.正序输出链表\tb.倒序输出链表\n");
	printf("c.插入\td.删除");
	printf ("e.摧毁链表\tf.生成链表\n");
	printf("q.退出\n");
	printf("请输入指令前的序号：");
    scanf("%c",&temp);
    while(temp!='q')
    {
    	if(temp=='a') print(head);
    	else if(temp=='b') printtail(ptr_tail);
    	else if(temp=='e') destory(head);
    	else if(temp=='f')
    	{
    		if(head->next==NULL) head=arrTransfer();
            else printf("链表已存在，请先摧毁\n");
    	}
    	else if(temp=='c')
    	{
    		printf("请输入插入位置（该位置后一位插入）：");
            int pos=inputTest();
            printf("请输入插入数据：");
            int data=inputTest();
            ptr_TNode p=(TNode* )malloc(LEN);//创建结构体指针存储插入值
            if(insert_T(&head,p,pos)==SUCCESS)
            {
                printf("插入成功！\n");
                print(head);
            }
            else printf("插入失败!\n");
    	}
    	else if(temp=='d')
    	{
    		printf("请输入删除位置（该位置后一位删除）：");
            int pos=inputTest();
            int deleteData,*p=&deleteData;
            if(delete_T(&head,pos,p)==SUCCESS)
            {
                printf("删除成功！删除的值为%d\n",*p);
                print(head);
            }
            else printf("删除失败！\n");
    	}
    	else printf("输出错误！请重新输入\n");
        printf("请输入指令前的序号：");
        scanf("%c",&temp);
    }
	return 0;
}
