/*
 * linked-list.h
 *
 * @author Mark Jarrell
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ll_node;
typedef struct ll_node *ll_node_ptr;

ll_node_ptr add_to_end(ll_node_ptr head, char *item[]);
void ll_free(ll_node_ptr head);

#endif /* LINKED_LIST_H */
