/*
 * linked-lists-interface.c
 *
 *  Created on: Feb 4, 2021
 *      Author: Nikhil
 */
#include "linked-lists-interface.h"

struct llist_t {
	int data;
	llist_t *next;
};

typedef struct {
	int size;
	llist_t *head;
	llist_t *tail;
}llist_ctrl_t;


static llist_ctrl_t llist_ctrl;

void init_list()
{
	llist_ctrl.size = 0;
	llist_ctrl.head = NULL;
	llist_ctrl.tail = NULL;
}


void add_head_node(int head_data)
{
	// Allocate memory for start/first node
	llist_t *ll_ptr = (llist_t *)malloc(sizeof(llist_t));

	// Init values
	ll_ptr->data = head_data;
	ll_ptr->next = NULL;
	llist_ctrl.size++;
	llist_ctrl.head = ll_ptr;
	llist_ctrl.tail = ll_ptr;
}


void insert_node_next(int data_to_be_inserted)
{
	if(llist_ctrl.head == NULL)
	{
#if ENABLE_PRINT
		printf("\nHead node not added !! call add_head_node()");
#endif
		return;
	}
    if(llist_ctrl.size >= MAX_LL_SIZE)
    {
#if ENABLE_PRINT
    	printf("\nList limit reached !! Cannot add more nodes !");
#endif
    	return;
    }
    else
    {
    	llist_t *ll_ptr = (llist_t *)malloc(sizeof(llist_t));

		llist_ctrl.size++;
		ll_ptr->data = data_to_be_inserted;
		ll_ptr->next = NULL;
		llist_ctrl.tail = ll_ptr;
#if ENABLE_PRINT
		printf("\nNode added to list successfully!");
#endif
    }
}

void insert_node_random(int data_to_be_inserted, int pos)
{
	int pos_tmp = 0;
	llist_t *ll_temp2;
	llist_t *ll_temp1 = llist_ctrl.head;

	if(llist_ctrl.head == NULL)
	{
#if ENABLE_PRINT
		printf("\nHead node not added !! call add_head_node()");
#endif
		return;
	}
	if(llist_ctrl.size >= MAX_LL_SIZE)
	{
#if ENABLE_PRINT
		printf("\nList limit reached !! Cannot add more nodes !");
#endif
		return;
	}
	else
	{
		llist_t *ll_ptr = (llist_t *)malloc(sizeof(llist_t));

		ll_ptr->data = data_to_be_inserted;

		//if node inserted at the start of the list
		if(pos == 1)
		{
			ll_ptr->next = llist_ctrl.head;
			llist_ctrl.head = ll_ptr;
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

		llist_ctrl.size++;
		llist_ctrl.tail = ll_ptr;
#if ENABLE_PRINT
		printf("\nNode added to list successfully!");
#endif

	}

}
void remove_last_node()
{
	llist_t *ll_remove = llist_ctrl.head;
	llist_t *ll_remove_aux = llist_ctrl.head;

	if(llist_ctrl.head == NULL)
	{
#if ENABLE_PRINT
		printf("\nHead node not added !! call add_head_node()");
#endif
		return;
	}
	if(llist_ctrl.size == 0)
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
	    llist_ctrl.size--;
		free(ll_remove);
	}

}

void remove_node_random(int data)
{
	int list_counter = 0;
	llist_t *ll_remove = llist_ctrl.head;
	llist_t *ll_remove_aux2 = llist_ctrl.head;
	llist_t *ll_remove_aux1;


	if(llist_ctrl.head == NULL)
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
			llist_ctrl.head = ll_remove->next;
			llist_ctrl.size--;
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
			llist_ctrl.size--;
			free(ll_remove);
		}

	}

}

llist_t *fetch_node(int data)
{
	int list_counter = 0;
	llist_t *ll_fetch = llist_ctrl.head;

	if(llist_ctrl.head == NULL)
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
	list_t *ll_print;
	int node_number_counter = 0;

	for(ll_print = llist_ctrl.head; ll_print != NULL; ll_print = ll_print->next)
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
  return MAX_LL_SIZE - llist_ctrl.size;
}
