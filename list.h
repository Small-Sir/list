#ifndef _LISH_H_
#define _LISH_H_

#define LIST_H  "\t\t\t1.����\n"\
                                             "\t\t\t2.ɾ��\n"\
                                              "\t\t\t3.�޸�\n"\
                                               "\t\t\t4.����\n"\
                                                "\t\t\t5.��ʾ���е�\n"\
                                                 "\t\t\t6.����\n"\
                                                  "\t\t\t7.�˳�\n"\
                                                   "\t\t\t���������ѡ�"

typedef struct node
{
    struct node* pri;///
    int num;
    struct node* next;
}Node;

///����
Node* add_list(Node* head, Node* pnew, Node** tail);

///ɾ��
Node* del_list(Node* head, Node* tail);

///�޸�
void modify_node_list(Node* head);

///����
void find_node_list(Node* head);

///��ʾ����
void show_list_head(Node* head);
void show_list_tail(Node* tail);

///����
Node* sort_list(Node* head, Node** tail);



#endif // _DOUBLE_LIST_H_

