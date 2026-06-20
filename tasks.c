#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include"tasks.h"

/// Modify the following to hold your name and roll No.

char st_name[] = "Hamza Khan";         /// Modify with your name
char st_reg_num[] = "FA19-BCE-075";     /// Modify with your registration number


/** This function takes pointer to a node as argument
    and then prompts user to input the data for that
    employee. The function does not return anything.
*/
void inputNodeData(struct employee * emp)
{
    printf("\nEnter the name of the employee: ");
    fgets(emp->name, 50, stdin);

    printf("\nEnter the age of the employee: ");
    scanf("%d", &(emp->age));

    printf("\nEnter the basic salary of the employee: ");
    scanf("%f", &(emp->bs));

    printf("\nRecord entered !\n");
}

/** This function takes pointer to a node as argument
    and then prints the record on the screen (stdout).
    The function does not return anything.
*/
void printNodeData(struct employee * emp)
{
    printf("\nName:\t\t %s", emp->name);
    printf("Age:\t\t %d\n", emp->age);
    printf("Basic Salary:\t %.2f\n", emp->bs);
}

/** Function to display the list
*/
void printList(struct employee * emp)
{
   struct employee * ptr = emp;
   printf("\nStart of list: \n");

   //start from the beginning
   while(ptr != NULL)
   {
      printNodeData(ptr);
      ptr = ptr->next;
   }

   printf("\nEnd of list.\n");
}


/** Tests if the list is empty. ONLY the head of the list
    should be passed to this function.
*/
bool isListEmpty(struct employee * emp)
{
   return (emp == NULL);
}

/** Function to find the length (in number of nodes) of the list.
*/
int getListLength(struct employee * emp)
{
   int length = 0;
   struct employee * current;

   for(current = emp; current != NULL; current = current->next)
   {
      length++;
   }

   return length;
}

/** Insert a new node at the last location. i.e. after the current one.
    If the list is currently empty, a new node is created for the head.
    Note: This function takes an argument of type pointer to pointer.
*/
void  insertNodeAtEnd(struct employee ** first)
{
   struct employee * temp = *first;
   ///create a new node
   struct employee * new_node = (struct employee *) malloc(sizeof(struct employee));

   inputNodeData(new_node);  /// get data for the newly created node from the user.

   ///point its next pointer to NULL
   new_node->next = NULL;

   if(isListEmpty(*first))    /// if currently the list is empty
   {
    *first = new_node;
   }
   else
   {
    while((temp->next) != NULL)
        temp = temp->next;      /// scroll to the end of the list
    temp->next = new_node;
   }
}

/** This function searches the linked list pointed to by 'head', for
    the name given in 'name'. It returns the index of the node in
    the list or -1 if the name is not found.
*/
int searchNodeByName(struct employee * head, char * name)
{
    int index = -1;

    struct employee * temp = head;

    /*** Insert your code here **/

    for(int i=0;; i++)
    {
        if(strcmp(temp->name,name)==0)
        {
            return i;
        }
        temp=temp->next;
        if(temp==NULL)
        {
            break;
        }
    }

    return (index); /// name found at index
}

/** Insert a new node after the node specified by node index.

    It returns 0 (if node is successfully inserted) or -1 (if the index
    exceeds the length of the list).
*/
int  insertNodeAfter(struct employee * first, int idx)
{
   int index = 0;

   struct employee * temp = first;

   if(isListEmpty(first))    /// if currently the list is empty return -1
   {
    return(-1);
   }

   ///create a new node
   struct employee * new_node = (struct employee *) malloc(sizeof(struct employee));

   inputNodeData(new_node);  /// get data for the newly created node from the user.


   while((index != idx) && (temp->next) != NULL)
   {
      index ++;
      temp = temp->next;      /// scroll to the end of the list
   }
    if((temp->next == NULL) && (index != idx))      /// We reached the end of the list without
    {                                               /// reaching the required index
        free(new_node);
        printf("\nNode insertion not done. New data is discarded!!\n");
        return(-1);
    }

    new_node->next = temp->next;    /// Setting up the pointers for insertion
    temp->next = new_node;
    return(0);                  /// Successfully inserted node at idx
}

/** This function deletes the last node in the linked list */
void remove_last_node(struct employee * first)
{
    struct employee *point=first;
    struct employee *temp=NULL;
    for(int i=0;; i++)
    {   temp=point->next;
        if(temp->next==NULL)
        {
            free(temp);
            point->next=NULL;
            break;
        }
        point=point->next;

    }
}

/** This function prints the list to a file. The function takes as inputs
    a pointer to the start of the linked list and a file name. Your code
    should open a file with the specified file name and write all the
    data in the list in a user readable format.

    The function should return 0 if file writing is successful, and -1
    otherwise.
**/
int print_list_to_file(struct employee * first, char * filename)
{
    FILE *point= fopen(filename,"w");
    struct employee *temp=first;
    if(point==NULL)
    {
        return -1;
    }
    for(int i=0;;i++)
    {
        fprintf(point,"\nName: %s\nage: %d\nSalary: %.3f\n",temp->name,temp->age,temp->bs);
        temp=temp->next;
        if(temp==NULL)
        {
            break;
        }

    }
    fclose(point);
    return(0);
}
