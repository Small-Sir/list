#ifndef _LISH_H_
#define _LISH_H_

#define LIST_H  "\t\t\t1.增加\n"\
                                             "\t\t\t2.删除\n"\
                                              "\t\t\t3.修改\n"\
                                               "\t\t\t4.查找\n"\
                                                "\t\t\t5.显示所有的\n"\
                                                 "\t\t\t6.排序\n"\
                                                  "\t\t\t7.退出\n"\
                                                   "\t\t\t请输入你的选项："

typedef struct node
{
    struct node* pri;///
    int num;
    struct node* next;
}Node;

///增加
Node* add_list(Node* head, Node* pnew, Node** tail);

///删除
Node* del_list(Node* head, Node* tail);

///修改
void modify_node_list(Node* head);

///查找
void find_node_list(Node* head);

///显示所有
void show_list_head(Node* head);
void show_list_tail(Node* tail);

///排序
Node* sort_list(Node* head, Node** tail);



#endif // _DOUBLE_LIST_H_

