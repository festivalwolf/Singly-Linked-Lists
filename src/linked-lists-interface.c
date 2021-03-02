/*
 * linked-lists-interface.c
 *
 *  Created on: Feb 4, 2021
 *      Author: Nikhil
 */
#include "linked-lists-interface.h"

struct linked_list_t {
	int data;
	linked_list_t *next;
};

typedef struct {
	int size;
	linked_list_t *head;
	linked_list_t *tail;
}list_control_t;


static list_control_t list_control;

void init_list()
{
	list_control.size = 0;
	list_control.head = NULL;
	list_control.tail = NULL;
}


void add_head_node(int head_data)
{
	// Allocate memory for start/first node
	linked_list_t *ll_ptr = (linked_list_t *)malloc(sizeof(linked_list_t));

	// Init values
	ll_ptr->data = head_data;
	ll_ptr->next = NULL;
	list_control.size++;
	list_control.head = ll_ptr;
	list_control.tail = ll_ptr;
}


void insert_node_next(int data_to_be_inserted)
{
	if(list_control.head == NULL)
	{
#if ENABLE_PRINT
		printf("\nHead node not added !! call add_head_node()");
#endif
		return;
	}
    if(list_control.size >= MAX_LL_SIZE)
    {
#if ENABLE_PRINT
    	printf("\nList limit reached !! Cannot add more nodes !");
#endif
    	return;
    }
    else
    {
		linked_list_t *ll_ptr = (linked_list_t *)malloc(sizeof(linked_list_t));

		list_control.size++;
		ll_ptr->data = data_to_be_inserted;
		ll_ptr->next = NULL;
		list_control.tail = ll_ptr;
#if ENABLE_PRINT
		printf("\nNode added to list successfully!");
#endif
    }
}

void insert_node_random(int data_to_be_inserted, int pos)
{
	int pos_tmp = 0;
	linked_list_t *ll_temp2;
	linked_list_t *ll_temp1 = list_control.head;

	if(list_control.head == NULL)
	{
#if ENABLE_PRINT
		printf("\nHead node not added !! call add_head_node()");
#endif
		return;
	}
	if(list_control.size >= MAX_LL_SIZE)
	{
#if ENABLE_PRINT
		printf("\nList limit reached !! Cannot add more nodes !");
#endif
		return;
	}
	else
	{
		linked_list_t *ll_ptr = (linked_list_t *)malloc(sizeof(linked_list_t));

		ll_ptr->data = data_to_be_inserted;

		//if node inserted at the start of the list
		if(pos == 1)
		{
			ll_ptr->next = list_control.head;
			list_control.head = ll_ptr;
		}
		else
		{
			// If node inserted in the middle
			while(pos_tmp++ != (pos - 1))
			{
				ll_temp1 = ll_temp1->next;
				if(pos_tmp == pos - 2)
				{
					ll_temp2 = ll_temp1->next;
					ll_temp1->next = ll_ptr;
				}
			}
			ll_ptr->next = ll_temp2;

		}

		list_control.size++;
		list_control.tail = ll_ptr;
#if ENABLE_PRINT
		printf("\nNode added to list successfully!");
#endif

	}

}
void remove_last_node()
{
	linked_list_t *ll_remove = list_control.head;
	linked_list_t *ll_remove_aux = list_control.head;

	if(list_control.head == NULL)
	{
#if ENABLE_PRINT
		printf("\nHead node not added !! call add_head_node()");
#endif
		return;
	}
	if(list_control.size == 0)
	{
#if ENABLE_PRINT
		printf("\nList empty !!");
#endif
		return;
	}
	else
	{
		while(ll_remove->next != NULL)
		{
			ll_remove = ll_remove->next;
			if(ll_remove->next == NULL)
			{
				continue;
			}
			ll_remove_aux = ll_remove_aux->next;
		}
		ll_remove_aux->next = NULL;
	    list_control.size--;
		free(ll_remove);
	}

}

void remove_node_random(int data)
{
	int list_counter = 0;
	linked_list_t *ll_remove = list_control.head;
	linked_list_t *ll_remove_aux2 = list_control.head;
	linked_list_t *ll_remove_aux1;


	if(list_control.head == NULL)
	{
#if ENABLE_PRINT
		printf("\nHead node not added !! call add_head_node()");
#endif
		return;
	}
	else
	{
		//If node removed from the start of list
		if(ll_remove->data == data)
		{
			list_control.head = ll_remove->next;
			list_control.size--;
			free(ll_remove);
		}
		else
		{
			while(list_counter++ != MAX_LL_SIZE || ll_remove->data != data)
			{
				ll_remove = ll_remove->next;
				if(ll_remove->data == data)
				{
					ll_remove_aux1 = ll_remove->next;
					continue;
				}
				ll_remove_aux2 = ll_remove_aux2->next;
			}
			ll_remove_aux2->next = ll_remove_aux1;
			list_control.size--;
			free(ll_remove);
		}

	}

}

linked_list_t *fetch_node(int data)
{
	int list_counter = 0;
	linked_list_t *ll_fetch = list_control.head;

	if(list_control.head == NULL)
	{
#if ENABLE_PRINT
		printf("\nHead node not added !! call add_head_node()");
#endif
		return NULL;
	}
	else
	{
		while(list_counter++ != MAX_LL_SIZE || ll_fetch->data != data)
		{
			ll_fetch = ll_fetch->next;
			if(ll_fetch->data == data)
			{
				break;
			}
		}

	}
	return ll_fetch;
}

#if ENABLE_PRINT
void print_list()
{
	linked_list_t *ll_print;
	int node_number_counter = 0;

	for(ll_print = list_control.head; ll_print != NULL; ll_print = ll_print->next)
	{
		++node_number_counter;
		printf("\nNode %d value : %d", node_number_counter, ll_print->data);
	}
}
#endif

void delete_list()
{
	int list_counter = 0;

	while(list_counter++ != MAX_LL_SIZE)
	{
		remove_last_node();
	}
}

int max_list_size()
{
 return MAX_LL_SIZE;
}

int current_list_size()
{
  return MAX_LL_SIZE - list_control.size;
}
