#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ELEM
{
    char name[80];
    int grade;
};
typedef struct ELEM elem;

struct node
{
    elem data;
    struct node *next;
};
typedef struct node list_node;
typedef struct node *list_ptr;

void init_ll(list_ptr *head);
int ll_insertStart(list_ptr *head,elem x);
int ll_insertAfter(list_ptr p,elem x);
int ll_deletestart(list_ptr *head,elem *x);
int deleteAfter(list_ptr prev,elem *x);
int ll_empty(list_ptr head);
void destroy_list(list_ptr *head);
void printlist(list_ptr head);

 main()
{
    elem student;
     list_ptr list;
     init_ll(&list);

     strcpy(student.name,"John");
     student.grade=7;
     ll_insertStart(&list,student);

     strcpy(student.name,"George");
     student.grade=9;
     ll_insertStart(&list,student);

     strcpy(student.name,"Padelis");
     student.grade=6;
     ll_insertStart(&list,student);

     printlist(list);
     destroy_list(&list);
}
int ll_insertStart(list_ptr *head,elem x)
{
    list_ptr newnode;
    newnode=(list_node*)malloc(sizeof(list_node));
    if(!newnode)
    {
        printf("Error");
        return 1;
    }
    newnode->data=x;
    newnode->next=*head;
    *head=newnode;
    return 0;
}
int ll_insertAfter(list_ptr p,elem x)
{
   list_ptr newnode;
   newnode=(list_node*)malloc(sizeof(list_node));
   if(!newnode)
   {
   printf("Error");
   return 1;
   }
   newnode->data=x;
   newnode->next=p->next;
   p->next=newnode;
   return 0;
}
int ll_deletestart(list_ptr *head,elem *x)
{
    list_ptr current;
    if(*head==NULL)
    return 1;
    current=*head;
    *x=current->data;
    *head=(*head)->next;
    free(current);
    return 0;
}
int deleteAfter(list_ptr prev,elem *x)
{
    list_ptr current;
    if(prev->next==NULL)
    return 1;
    current=prev->next;
    *x=current->data;
    prev->next=current->next;
    free(current);
    return 0;
}
void init_ll(list_ptr *head)
{
    *head=NULL;
}
int ll_empty(list_ptr head)
{
    return head==NULL;
}
void destroy_list(list_ptr *head)
{
    list_ptr ptr;
    while(*head!=NULL)
    {
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
}
void printlist(list_ptr head)
{
    list_ptr current;
    current=head;
    while(current!=NULL)
    {
        printf("(%s)(%d) ->",current->data.name,current->data.grade);
        current=current->next;
        printf(".");
    }
}