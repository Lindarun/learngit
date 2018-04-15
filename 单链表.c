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

//根据数组生成一条链表，成功则返回头节点，失败返回 NULL
ptr_Node create(int *arr, int n)
{
    ptr_Node head,p1,p2;
    head=(ptr_Node)malloc(LEN);
    if(head==NULL) return NULL;//申请内存失败 返回NULL
    head->data=n;//头结点数据域为链表有效数据长度
    p1=head;
    int l=n;//保存长度
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
//销毁给定的链表
void destroy(ptr_Node head)
{
    ptr_Node p=head;
    if(p->next==NULL) printf("链表为空！");
    while(p)
    {
        p=p->next;
        free(head);
        head=p;
    }
    head=NULL;
    p=NULL;
}

//在第 index 位后面插入 node 结点
//插入成功返回 SUCCESS，失败返回 ERROR
Status insert(ptr_Node *head, ptr_Node node, int index)
{
    ptr_Node p=*head;
    if(index<0 || index>(p->data) || p->next==NULL)//当链表为空 序号超过其长度或小于零时修改失败
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
    p2->next=p1->next;//曾尝试使用值拷贝但失败
    p1->next=p2;
    return SUCCESS;
}

//删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中
//删除成功返回 SUCCESS，其他情况返回 ERROR
Status delete(ptr_Node *head, int index, int *data)
{
    ptr_Node p=*head;
    if(index<0 || index>=(p->data) || p->next==NULL)//当链表为空 序号超过其长度或小于零时修改失败
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


//在链表中查找节点值与 data 相等的节点，并返回找到的第一个节点的前一个节点的位置
//（例：头节点相等，返回 0），没找到或者其他情况返回-1
int search(ptr_Node head, int data)
{
    if(head->next==NULL) return -1;//链表为空 返回-1
    ptr_Node p=head->next;
    int index=0;
    while(p)
    {
        if(data==p->data) return index;//返回相应位置的前一个
        index++;
        p=p->next;
    }
    p=NULL;
    return -1;//循环结束  找不到该值 返回-1
}


//将链表中 index 位点后面的结点的值修改为(*data)，将原值保存到(*data)
//修改成功返回 SUCCESS，其他情况返回 ERROR
Status edit(ptr_Node head, int index, int *data)
{
    if(index<0 || index>=(head->data) || head->next==NULL)//当链表为空 序号超过其长度或小于零时修改失败
        return ERROR;
    ptr_Node p1=head;
    while(index--)
    {
        p1=p1->next;
    }
    p1=p1->next;
    //交换两值
    *data^=p1->data;
    p1->data^=*data;
    *data^=p1->data;
    p1=NULL;
    return SUCCESS;
}

//此题选做,实现单链表按照节点值大小升序排序
ptr_Node mer(ptr_Node head1,ptr_Node head2)
{
    if(head1 == NULL)return head2;//前半部分为空 则返回后半部分
    if(head2 == NULL)return head1;//若后半部分为空 则返回前半部分
    ptr_Node res=NULL,p=NULL;//定义res指针为新链表头指针
    if(head1->data < head2->data)//比较两条子链头来寻找新链头
        {res = head1; head1 = head1->next;}
    else{res = head2; head2 = head2->next;}
    p = res;
    //将较小的元素排在前面
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
    //将未排序元素接在其后
    if(head1 != NULL) p->next = head1;
    else if(head2 != NULL) p->next = head2;
    return res;
}
ptr_Node Mergesort(ptr_Node head)
{
    if(head->next==NULL) return head;
    //寻找中间节点
    ptr_Node fast_left=head,slow_right=head;//快慢指针同时充当左右部分的指针
    while(fast_left->next!=NULL && fast_left->next->next!= NULL)
    {
        fast_left=fast_left->next->next;
        slow_right=slow_right->next;
    }
    fast_left=slow_right;
    slow_right=slow_right->next;
    fast_left->next=NULL;//断链表
    fast_left=Mergesort(head);//前半部分排序
    slow_right=Mergesort(slow_right);//后半部分排序
    return mer(fast_left,slow_right);//返回合并后的链表指针
}
Status sort(ptr_Node *head)//归并排序
{
    ptr_Node p=*head;
    if(p->next==NULL) return ERROR;
    p=p->next;//指向有效数据的链表头
    (*head)->next=Mergesort(p);//将有效数据进行归并排序
    return SUCCESS;
}
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
//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print(ptr_Node head)
{
    ptr_Node p=head;
    if(p->next==NULL)
        printf("列表为空！\n");
    int cnt=1;
    printf("共有%d个数据\n",p->data);
    p=p->next;
    while(p)
    {
        printf("第%d个数据：%d\n",cnt++,p->data);
        p=p->next;
    }
}
//通过用户输入值创建链表
ptr_Node arrTransfer()
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
    ptr_Node p=create(a,cnt);
    printf("链表如下\n");
    print(p);
    return p;
}
int main()
{
    ptr_Node head=arrTransfer();
    if(head==NULL) {printf("创建失败\n");return 0;}
    char temp;//选项变量
    printf("指令表如下：\n");
    printf("a.destroy\tb.print\n");
    printf("c.insert\td.delete\n");
    printf("e.search\tf.edit\n");
    printf("g.sort(permanent)\tq.quit\n");
    printf("h.create\n");
    printf("请输入指令前的序号：");
    scanf("%c",&temp);
    while(temp!='q')
    {
        if(temp=='a') destroy(head);
        else if(temp=='b') print(head);
        else if(temp=='c')
        {
            printf("请输入插入位置（该位置后一位插入）：");
            int pos=inputTest();
            printf("请输入插入数据：");
            int data=inputTest();
            ptr_Node p=(Node* )malloc(LEN);//创建结构体指针存储插入值
            if(insert(&head,p,pos)==SUCCESS)
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
            if(delete(&head,pos,p)==SUCCESS)
            {
                printf("删除成功！删除的值为%d\n",*p);
                print(head);
            }
            else printf("删除失败！\n");
        }
        else if(temp=='e')
        {
            printf("请输入查找的值：");
            int data=inputTest();
            if(-1==search(head,data))
                printf("找不到该值\n");
            else printf("该值为%d，在第%d位上",data,search(head,data)+1);
        }
        else if(temp=='f')
        {
            printf("请输入修改位置（该位置后一位修改）：");
            int pos=inputTest();
            printf("请输入修改值：");
            int editData=inputTest();
            int *p=&editData;
            if(edit(head,pos,p)==SUCCESS)
            {
                printf("修改成功！\n");
                printf("被修改的值为%d\n",*p);
            }
            else printf("修改失败！\n");
        }
        else if(temp=='g')
        {
            if(sort(&head)==SUCCESS)
            {
                printf("排序成功！\n");
                print(head);
            }
            else printf("排序失败！\n");
        }
        else if(temp=='h')
        {
            if(head->next==NULL) head=arrTransfer();
            else printf("链表已存在，请先摧毁\n");
        }
        else printf("输出错误！请重新输入\n");
        printf("请输入指令前的序号：");
        scanf("%c",&temp);
    }
	return 0;
}
