#include <stdlib.h>
#include "linked-list.h"

struct ll_node
{
  char **item;
  struct ll_node *next;
};
/* typedef struct node *ll_node_ptr; */

/*
 * Returns a ll_node_ptr to the head of linked list
 * with item is added.
 *
 * Can be used to create a new linked list by passing NULL to head.
 * This way, the new linked list will have one element, item.
 */
ll_node_ptr
add_to_end(ll_node_ptr head, char *item[])
{
  ll_node_ptr ptr;
  /* Create a new list */
  if (head == NULL)
  {
    if ((ptr = (ll_node_ptr)malloc(sizeof(*ptr))) == NULL)
      return NULL;
    ptr->item = item;
    ptr->next = NULL;
    return ptr;
  }
  /* Add  new item to end of list */
  ptr = head;
  while (ptr->next != NULL)
    ptr = ptr->next;
  if ((ptr->next = (ll_node_ptr)malloc(sizeof(*ptr))) == NULL)
    return NULL;
  ptr = ptr->next;
  ptr->item = item;
  ptr->next = NULL;
  return head;
}

/*
 * Frees a linked list and all of the items in it.
 */
void
ll_free(ll_node_ptr head)
{
  ll_node_ptr delete;
  ll_node_ptr ptr = head;
  while (ptr != NULL)
  {
    delete = ptr;
    ptr = ptr->next;
    free(delete->item);
    free(delete);
  }
  return;
}
