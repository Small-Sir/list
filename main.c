#include <stdio.h>
#include  <stdlib.h>
#include  "list.h"



///创建一个新节点
Node* creat_node()
{
    ///申请一个空间
    int num;
    Node* pnew = (Node*)malloc(sizeof(Node));
    if (pnew == NULL)
        exit(0);
    printf("input a number:");
    scanf_s("%d", &num);
    while (getchar() != '\n');
    pnew->num = num;
    pnew->pri = pnew->next = NULL;
    ///pnew->next=NULL;
    return pnew;
}


///增加
Node* add_list(Node* head, Node* pnew,Node** tail)
{
    if (head == NULL)
    {
        *tail = pnew;
    }
    pnew->next = head;
    if (head != NULL)
    {
        head->pri = pnew;
    }
    
    head = pnew;
    pnew->pri = NULL;
    return head;
}

Node* find_node(Node* head,int num)
{
    while (head != NULL)
    {
        if (head->num == num)
        {
            return head;
        }
        head = head->next;
    }
    printf("查不到，没有！！！\n");
    return NULL;
}

Node* take_off_node(Node** head, Node* node, Node** tail)
{
    if (node -> next == NULL && node->pri == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else if (node->pri != NULL && node == *tail)
    {
        *tail = node->pri;
        node->pri->next = NULL;
    }
    else if (node->next != NULL && node == *head)
    {
        *head = node->next;
        node->next->pri = NULL;
    }
    else if(node -> next != NULL && node->pri != NULL)
    {
        node->next->pri = node->pri;
        node->pri->next = node->next;
    }
    return node;
}

///删除
Node* del_list(Node* head,Node* tail)
{
    int num;
    printf("input you want to delete the number:");
    scanf_s("%d", &num);
    Node* node = find_node(head, num);
    Node* delete_node=take_off_node(&head, node, &tail);
    free(delete_node);
    printf("删除成功\n");
    return head;
}

///修改
void modify_node_list(Node* head)
{
    int num;
    printf("please input you want to find the number:");
    scanf_s("%d", &num);
    while (getchar() != '\n');
    while (head != NULL)
    {
        if (head->num == num)
        {
            printf("please input you want to modify the number:");
            scanf_s("%d", &num);
            head->num = num;
            return;
        }
        head = head->next;
    }
    printf("查不到，没有！！！\n");
    return;
}

///查找
void find_node_list(Node* head)
{
    int num;
    printf("please input you want to find the number:");
    scanf_s("%d", &num);
    while (getchar() != '\n');
    while (head != NULL)
    {
        if (head->num == num)
        {
            printf("找到了\n");
            printf("num:%d\n", head->num);
            return;
        }
        head = head->next;
    }
    printf("查不到，没有！！！\n");
    return;
}

///显示所有
void show_list_head(Node* head)
{
    while (head != NULL)
    {
        printf("num:%d\n", head->num);
        head = head->next;
    }
}

void show_list_tail(Node* tail)
{
    while (tail != NULL)
    {
        printf("num:%d\n", tail->num);
        tail = tail->pri;
    }
}
Node* find_min_node(Node* head)
{
    Node* min = head;
    while (head != NULL)
    {
        if (head->num <= min->num)
            min = head;
        head = head->next;
    }
    return min;
}



///排序
Node* sort_list(Node* head,Node** tail)
{
    Node* new_head = NULL;
    Node* new_tail = NULL;
    while (head != NULL)
    {
        Node* node = find_min_node(head);
        Node* temp = take_off_node(&head, node,tail);
        new_head = add_list(new_head, temp, &new_tail);
    }
    return new_head;
}

void menu()
{
    Node* head = NULL;
    Node* tail = NULL;
    Node* pnew = NULL;
    char sel;
    for (;;)
    {
        printf(LIST_H);
        scanf_s("%c", &sel,1);
        while (getchar() != '\n');
        switch (sel)
        {
        case '1':
            pnew = creat_node();
            head = add_list(head, pnew,&tail);///增加
            break;
        case '2':
            head = del_list(head,tail);///删除
            break;
        case '3':
            modify_node_list(head);///修改
            break;
        case '4':
            find_node_list(head);///查找
            break;
        case '5':
            show_list_head(head);///显示所有
            break;
        case '6':
            head = sort_list(head,&tail);///排序
            break;
        case '7':
            exit(0);
            return;
        default:
            printf("输入有误\n");
            break;

        }
    }
}

int main()
{
    menu();
    return 0;
}

