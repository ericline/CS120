/******************************************************************************
filename    list.c
author      Eric Lin
DP email    eric.lin@digipen.edu
course      CS120
lab         12
due date    12/5/2021
Brief Description:
    This file contains several functions to manipulate and print results from
    a linked list. Functions include: add_front, add_back, free_list,
    print_list, remove_item, size_list, sum_list. 
  
******************************************************************************/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
   Function: add_front

Description: Adds a node to the front of a linked list.

     Inputs: list  - A pointer at a pointer at a struct.
             value - A number (integer) that is being added to the list.

    Outputs: void.
*******************************************************************************/
void add_front(struct Node **list, int value)
{
    /* Create new node for the front of the list */
    struct Node *front_node = (struct Node*)malloc(sizeof(struct Node));

    /* Intialize node number value */
    front_node->number = value;

    /* If list is empty, add node as first node */
    if(!(*list))
    {

        /* Mark front node as also the end of list */
        front_node->next = NULL;

        /* Assign list pointer to front node */
        *list = front_node;

    }
    else
    {    
        /* Assign next to the front of the pointer */
        front_node->next = *list;

        /* Move the list pointer to the new front node */
        *list = front_node;
    }
}

/*******************************************************************************
   Function: add_back

Description: Adds a node to the back of a linked list.

     Inputs: list  - A pointer at a pointer at a struct.
             value - A number (integer) that is being added to the list.

    Outputs: void.
*******************************************************************************/
void add_back(struct Node **list, int value)
{
    /* Create new node for the back of the list */
    struct Node *back_node = (struct Node*)malloc(sizeof(struct Node));

    /* Pointer to walk through the list */
    struct Node *ptr = *list;

    /* Initialize next and number of back_node so it acts as end of list */
    back_node->next = NULL;
    back_node->number = value;

    /* If list is empty, assign back_node value as the head */
    if(!(*list))
    {
        *list = back_node;
    }
    else
    {   
        /* Walk through linked list until pointer at the end */
        while(ptr->next)
        {
            ptr = ptr->next;
        }

        /* Insert back_node at pointer pointing at the end of list */
        ptr->next = back_node;
    }
}

/*******************************************************************************
   Function: free_list

Description: Frees all nodes a given linked list.

     Inputs: list - A pointer at a struct.

    Outputs: void.
*******************************************************************************/
void free_list(struct Node *list)
{   
    /* while list pointer is not null */
    while(list)
    {
        /* temp pointer for next node in the list */
        struct Node *temp = list->next;

        /* free current node */
        free(list);

        /* move pointer to the next node */
        list = temp;
    }
}

/*******************************************************************************
   Function: print_list

Description: Prints the all the numbers of a linked list.

     Inputs: list - A pointer at a struct.

    Outputs: Void, but prints a linked list.
*******************************************************************************/
void print_list(const struct Node *list)
{
    /* while list pointer is not null */
    while(list)
    {
        /* print value in each node */
        printf("%3i", list->number);

        /* move pointer to next node */
        list = list->next;
    }

    /* new line for each list */
    printf("\n");

}

/*******************************************************************************
   Function: remove_item

Description: Removes a node containing the given value from a linked list.

     Inputs: list  - A pointer at a pointer at a struct.
             value - A number (integer) to find in the linked list.

    Outputs: void
*******************************************************************************/
void remove_item(struct Node **list, int value)
{
    struct Node *temp = *list;           /* pointer to move through list */
    struct Node *previous_node = *list; /* pointer at previous node */
    
    /* if pointer is not null */
    if(temp) 
    {
        /* while pointer is not null */
        while(temp)
        {   
            /* if number is found */
            if(temp->number == value)
            {
                /* assign new next value */
                previous_node->next = temp->next;

                /* move pointer up if first node is removed
                sets pointer to new beginning */
                if(temp == *list && previous_node == *list)
                {
                    *list = previous_node->next;
                }

                /* free current node */
                free(temp);

                /* break once number is found and removed */
                break;
            }

            /* move pointers through the list */
            previous_node = temp;
            temp = temp->next;

        }
    } 
}

/*******************************************************************************
   Function: size_list

Description: Calculates the size of a given linked list

     Inputs: list - A pointer at a struct.

    Outputs: Returns the total size (integer) of a linked list.
*******************************************************************************/
int size_list(const struct Node *list)
{
    int size = 0;  /* size of list */
  
    /* if list pointer is not null */
    if(list)
    {
        /* move through list until end */
        while(list)
        {
            /* increment size each node */
            size++;

            /* move onto to next node */
            list = list->next;
        }
    }

    /* return size of list */
    return size;
}

/*******************************************************************************
   Function: sum_list

Description: Calculates the sum of all nodes in a given linked list

     Inputs: list - A pointer at a struct.

    Outputs: Returns the total sum (integer) of a linked list.
*******************************************************************************/
int sum_list(const struct Node *list)
{
    int sum = 0;    /* sum of list */
  
    /* if list pointer is not null */
    if(list)
    {
        /* move through list */
        while(list)
        {
            /* add the value of each node to sum */
            sum += list->number;
            
            /* move onto to next node */
            list = list->next;
        } 
    }
  
    /* return sum of list */
    return sum;
}
