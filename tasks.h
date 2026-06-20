/** This file will contains the definition of one element/node (structure) of the linked list
    and the functions associated with the list.
    */

struct employee
{
   char name[50];
   int age;
   float bs;

   struct employee * next;
};

void inputNodeData(struct employee * emp);
void printNodeData(struct employee * emp);
void printList(struct employee * head);
void  insertNodeAtEnd(struct employee ** head);
bool isListEmpty(struct employee * head);
int getListLength(struct employee * head);
int searchNodeByName(struct employee * head, char * name);
int  insertNodeAfter(struct employee * head, int idx);
void remove_last_node(struct employee * first);
int print_list_to_file(struct employee * first, char * filename);

