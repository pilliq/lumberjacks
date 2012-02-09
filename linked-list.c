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
  return 0;
}
