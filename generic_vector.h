#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include "status.h"

typedef void* G_VECTOR;

//init
G_VECTOR g_vector_init_default(Status(*item_assign)(Item_ptr, ITEM),
	void (*item_destroy)(Item_ptr));
//use vector
int g_vector_get_capacity(G_VECTOR hG_Vector);
int g_vector_get_size(G_VECTOR hG_Vector);
Status g_vector_push_back(G_VECTOR hG_Vector, ITEM item);  //insert new item
Status g_vector_pop_back(G_VECTOR hG_Vector);
ITEM g_vector_at(G_VECTOR hG_Vector, int index);
//destroy
void g_vector_destroy(G_VECTOR* ph_G_Vector);

Status int_assign(Item_ptr, ITEM);
void int_destroy(Item_ptr);

#endif
