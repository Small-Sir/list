#include <stdio.h>
#include  <stdlib.h>
#include  "list.h"



///����һ���½ڵ�
Node* creat_node()
{
    ///����һ���ռ�
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


///����
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
    printf("�鲻����û�У�����\n");
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

///ɾ��
Node* del_list(Node* head,Node* tail)
{
    int num;
    printf("input you want to delete the number:");
    scanf_s("%d", &num);
    Node* node = find_node(head, num);
    Node* delete_node=take_off_node(&head, node, &tail);
    free(delete_node);
    printf("ɾ���ɹ�\n");
    return head;
}

///�޸�
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
    printf("�鲻����û�У�����\n");
    return;
}

///����
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
            printf("�ҵ���\n");
            printf("num:%d\n", head->num);
            return;
        }
        head = head->next;
    }
    printf("�鲻����û�У�����\n");
    return;
}

///��ʾ����
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



///����
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
            head = add_list(head, pnew,&tail);///����
            break;
        case '2':
            head = del_list(head,tail);///ɾ��
            break;
        case '3':
            modify_node_list(head);///�޸�
            break;
        case '4':
            find_node_list(head);///����
            break;
        case '5':
            show_list_head(head);///��ʾ����
            break;
        case '6':
            head = sort_list(head,&tail);///����
            break;
        case '7':
            exit(0);
            return;
        default:
            printf("��������\n");
            break;

        }
    }
}

int main()
{
    menu();
    return 0;
}

