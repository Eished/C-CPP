#include <stdlib.h>
const int Maxsize = 20;
typedef struct node
{
  DataType key;
  struct node *next;
} Node, *LinkList;
LinkList InitiateLinkList()
{
  LinkList head;
  head = malloc(sizeof(Node));
  head->next = NULL;
  return head;
}