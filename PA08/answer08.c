#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "answer08.h"

List * List_createNode(const char * str)
{
  List * node = malloc(sizeof(List));
  node -> str = strdup(str);
  node -> next = NULL;
  
  return node;
}

void List_destroy(List * list)
{
   if(list != NULL)
   {
     free(list -> str);
     List_destroy(list -> next);
   }
   free(list);
}

int List_length(List * list)
{
  if (list == NULL)
  {
    return 0;
  }
  int count = 0;
  while (list != NULL)
  {
    count++;
    list = list -> next;
  }
  return count;
}


List * List_merge(List * lhs, List * rhs, int(*compar)(const char *, const char *))
{
  List * ans = NULL;
  List ** tail = &ans;
  
  while (lhs && rhs)
  {
    if (compar((const char *)lhs -> str, (const char *)rhs -> str) < 0)
    {
      *tail = lhs;
      lhs = lhs -> next;
    }
    else
    {
      *tail = rhs;
      rhs = rhs -> next;
    }
    tail = & ((*tail) -> next);
  }
  *tail = lhs ? lhs : rhs;

  return ans;
}

List * List_sort(List * list, int(*compar)(const char *, const char *))
{
  int length = List_length(list);
  if (length <= 1)
  {
    return list;
  }
  int ind;
  List * lhs = list;
  for (ind = 1; ind < (length / 2); ind++)
  {
    list = list -> next;
  }
  List * rhs = list -> next;
  list -> next = NULL;
  
  lhs = List_sort(lhs, compar);
  rhs = List_sort(rhs, compar);
  
  list = List_merge(lhs, rhs, compar);

  return list;
}





