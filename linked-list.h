/*
 * linked-list.h
 *
 * @author Mark Jarrell
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node;
typedef struct node *node_ptr;

node_ptr add_to_end(node_ptr head, char *item[]);

#endif /* LINKED_LIST_H */
