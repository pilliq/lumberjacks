#include "linked-list.h"

struct node
{
  char **item;
  struct node *next;
};
/* typedef struct node *node_ptr; */

/**
 * Returns a node_ptr to the head of linked list
 * with item is added.
 *
 * Can be used to create a new linked list by passing NULL to head.
 * This way, the new linked list will have one element, item.
 */
node_ptr
add_to_end(node_ptr head, char *item[])
{
  node_ptr head;
  /* Create a new list */
  if (head == NULL)
  {
    if ((head = (node_ptr)malloc(sizeof(*node_ptr))) == NULL)
      return NULL;
    head->item = item;
    head->next = NULL;
    return head;
  }
  /* Add  new item to end of list */
  ptr = head;
  while (ptr->next != NULL)
    ptr = ptr->next;
  if ((ptr->next = (node_ptr)malloc(sizeof(*node_ptr))) == NULL)
    return NULL;
  ptr = ptr->next;
  ptr->item = item;
  ptr->next = NULL;
  return head;
}
