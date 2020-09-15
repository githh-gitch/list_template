#include "stdio.h"
#include "stdlib.h"

//数据
typedef struct DATA
{
    char name[20];
    int score;
} Data;
//结点
typedef struct node
{
    Data data;
    struct node *pnext;
}Node;

//链表
typedef struct List
{
    Node* pfornt;//指向头结点
    Node* prear;//指向尾结点
    int count;//计数
}list;


/*
函数名：ListInit(list **pplist)
参数：指向链表指针的指针
功能：链表初始化
返回值：成功返回1 失败返回0
*/
int ListInit(list **pplist)//二级指针操作地址
{
    *pplist = (list*)malloc(sizeof(list));
    if(NULL == *pplist)
    {
        return 0;
    }
    else//初始化链表
    {
        (*pplist) -> pfornt = NULL;
        (*pplist) -> prear = NULL;
        (*pplist) -> count = 0;
    }
    return 1;
    
    
}
/*
函数名：IsEmpty(list *plist)
参数：要判断链表
功能：判断链表是否为空
返回值：成功返回1 失败返回0
*/
int IsEmpty(list *plist)
{
    if(plist -> count == 0)//链表内结点数为0
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
/*
函数名：InserList(list *plist,Node *pnode)
参数：链表，要插入的节点
功能：在plist这个链表中插入pnode的节点
返回值：无
*/
void InserList(list *plist,Node *pnode)
{
    //尾插法
    if(IsEmpty(plist))
    {
        plist -> pfornt = pnode;
    }
    else
    {
        plist->prear->pnext = pnode;
    }
    plist -> prear = pnode;
    plist -> count++;  
    
}
/*
函数名：TraverList(list *plist,void(*Traver)(Node* pnode))
参数：plist ：要遍历的链表，Traver ：函数指针，指向函数的指针，返回值为void，参数为Node*
功能:遍历plist链表，进行Traver函数操作
返回值：无
*/
void TraverList(list *plist,void(*Traver)(Node* pnode))
{
    Node *ptemp = plist -> pfornt;//ptemp指向第一个节点
    int listsize = plist -> count; //有几个节点
    while(listsize)
    {
        Traver(ptemp);
        ptemp = ptemp -> pnext;
        listsize --;
    }
}
void ShowData(Node *pnode)
{
    int i;
    for (i = 0;i < 20; i++)
    {
        if(pnode->data.name[i] != '\0')
        {
            printf("%c\n",pnode -> data.name[i]);
        }
        else
        {
            break;
        }
        
     }
}
int main()
{
    list *pList;//指针变量
    ListInit(&pList);//创建链表
    int i;

    while(1)
    {
        //创建节点
        Node *pnode = (Node*)malloc(sizeof(Node));
        int n = rand() % 10 + 5;
        for(i = 0; i < n; i++)
        {
            pnode->data.name[i] = rand() % 26 + 65;//26个大写字母

        }
        pnode -> data.name[n] = '\0';
        pnode -> pnext = NULL;



        //添加节点
        InserList(pList,pnode);
        
        //显示链表
        TraverList(pList,ShowData);



        Sleep(100);

    }
}
