/*
 * linked-lists-interface.h
 *
 *  Created on: Feb 4, 2021
 *      Author: Nikhil Bhat
 */

#ifndef LINKED_LISTS_INTERFACE_H_
#define LINKED_LISTS_INTERFACE_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ENABLE_PRINT		0
#define MAX_LL_SIZE 		10

typedef struct llist_t llist_t;


// Linked List Functions
void init_list();
void add_head_node(int head_data);
void insert_node_next(int data_to_be_inserted);
void insert_node_random(int data_to_be_inserted, int pos);
void remove_last_node();
void remove_node_random(int data);
void delete_list();

llist_t *fetch_node(int data);
int max_list_size();
int current_list_size();

#if ENABLE_PRINT
void print_list();
#endif


#endif /* LINKED_LISTS_INTERFACE_H_ */
