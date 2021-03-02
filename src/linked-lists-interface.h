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
void llist_init();
void llist_add_head(int head_data);
void llist_insert_node_next(int data_to_be_inserted);
void llist_insert_node_rand(int data_to_be_inserted, int pos);
void llist_remove_node_next();
void llist_remove_node_random(int data);
void llist_delete();

llist_t *llist_fetch_node(int data);
int llist_max_size();
int llist_current_size();

#if ENABLE_PRINT
void print_list();
#endif


#endif /* LINKED_LISTS_INTERFACE_H_ */
