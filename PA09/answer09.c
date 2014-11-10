#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer09.h"

char ** explode(const char * str, const char * delims)
{
  int len = strlen(str);
  int i;
  char ** ans = NULL;
  int arrlen = 1;
  for (i = 0; i < len; ++i)
  {
    if (strchr(delims,str[i])!=NULL)
    {
      arrlen++;
    }
  }
  ans = (char **) malloc( (2*(arrlen) + 1) * sizeof(char*) );
  int pre=0 , cnt=0;
  for (i = 0; i < len; ++i)
  {
    if (strchr(delims,str[i])!=NULL)
    {
      int slen = (2*(i-pre) + 1) * sizeof(char);
      ans[cnt]=(char *)malloc(slen);
      memcpy(ans[cnt],str+pre,(i-pre + 1)*sizeof(char));
      ans[cnt++][i-pre]='\0';
      pre=i+1;
    }
  }
  ans[cnt]=(char *)malloc((2*(len-pre) + 1)*sizeof(char));
  memcpy(ans[cnt],str+pre,(len-pre + 1)*sizeof(char));
  ans[cnt++][len-pre]='\0';
  arrlen = cnt;
  return ans;
}

BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode * root;
  root = malloc(sizeof(BusinessNode));
  root -> name = name;
  root -> stars = stars;
  root -> address = address;
  root -> left = NULL;
  root -> right = NULL;
  return root;
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  if (root == NULL)
  {
    return node;
  }
  if (strcmp(node -> name, root -> name) <= 0)
  {
    root -> left = tree_insert(node, root -> left);
  }
  else
  {
    root -> right = tree_insert(node, root -> right);
  }
  return root;
}

BusinessNode * load_tree_from_file(char * filename)
{
  FILE *fp = fopen(filename, "r");
  char ** value;
  if (fp == NULL)
  {
    return NULL;
  }
  BusinessNode * root = NULL;
  BusinessNode * node = NULL;
  char line[500];
  while(fgets(line, 500, fp) != NULL)
  {
    value = explode(line, "\t");
    node = create_node(value[0], value[1], value[2]);
    root = tree_insert(node, root);
    free(value);
  }
  fclose(fp);
  return root;
}

BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (strcmp(name, root -> name) == 0)
  {
    return root;
  }

  if (strcmp(name, root -> name) > 0)
  {
    return tree_search_name(name, root -> right);
  }
  if (strcmp(name, root -> name) < 0)
  {
    return tree_search_name(name, root -> left);
  }
  return NULL;
}

void print_node(BusinessNode * node)
{
  if (node == NULL)
  {
    return;
  }
  printf("%s\n", node -> name);
  printf("============\n");
  printf("Stars:\n");
  printf("   %s\n", node -> stars);
  printf("Address:\n");
  printf("   %s\n", node -> address);
}


void print_tree(BusinessNode * tree)
{
  print_node(tree);
  print_tree(tree -> left);
  print_tree(tree -> right);
}


void destroy_tree(BusinessNode * root)
{
  if (root != NULL)
  {
    free(root -> stars);
    free(root -> name);
    free(root -> address);
    destroy_tree(root -> left);
    destroy_tree(root -> right);
  }
  free(root);
}
