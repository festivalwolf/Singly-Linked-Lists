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


#define MAX_LL_SIZE 		10

typedef struct linked_list_t linked_list_t;

struct linked_list_t {
	int data;
	linked_list_t *next;
};

typedef struct {
	int size;
	linked_list_t *head;
	linked_list_t *tail;
}list_control_t;

// Linked List Functions
void init_list();
void add_head_node(int head_data);
void insert_node_next(int data_to_be_inserted);
void insert_node_random(int data_to_be_inserted, int pos);
void remove_last_node();
void remove_node_random(int data);
void print_list();
void delete_list();

linked_list_t *fetch_node(int data);
int max_list_size();
int current_list_size();

#endif /* LINKED_LISTS_INTERFACE_H_ */
