#include <stdlib.h>
#include "answer03.h"
#include <stdio.h>
#include <string.h>

char * strcat_ex(char ** dest, int * n, const char * src)
{
  if (*dest == NULL || *n < (strlen(*dest) + strlen(src) + 1))
    {
      char * buffer;
      if (*dest == NULL)
        {
          *n = 1 + 2 * strlen(src);
          buffer = (char *)malloc( (*n) * sizeof(char));
          buffer[0] = '\0';
          strcpy(buffer, src);
          free(*dest);
          *dest = buffer;
        }
      else
        {
          *n = 1 + 2*(strlen(*dest) + strlen(src));
          buffer = (char *)malloc( (*n) * sizeof(char) );
          strcpy(buffer, *dest);
          free(*dest);
          *dest = buffer;
          strcat(*dest, src);
        }
    }
  else
    {
      strcat(*dest, src);
    }
  return (*dest);
}
char ** explode(const char * str, const char * delims, int * arrlen)
{
  int len = strlen(str);
  int i;
  char ** ans = NULL;
  *arrlen = 1;
  for (i = 0; i < len; ++i)
  {
    if (strchr(delims,str[i])!=NULL)
      {
        (*arrlen)++;
      }
  }
  ans = (char **) malloc( 2*(*arrlen) * sizeof(char*) );
  int pre=0 , cnt=0;
  for (i = 0; i < len; ++i)
  {
    if (strchr(delims,str[i])!=NULL)
      {
        ans[cnt]=(char *)malloc((2*(i-pre))*sizeof(char));
        memcpy(ans[cnt],str+pre,(i-pre)*sizeof(char));
        ans[cnt++][i-pre]='\0';
        pre=i+1;
      }
  }
  ans[cnt]=(char *)malloc((2*(len-pre))*sizeof(char));
  memcpy(ans[cnt],str+pre,(len-pre)*sizeof(char));
  ans[cnt++][len-pre]='\0';
  return ans;
}

char * implode(char ** strArr, int len, const char * glue)
{
  int ind_str;
  int n = 0;
  char * s = NULL;
  for (ind_str = 0; ind_str < len; ind_str++)
    {
      strArr[ind_str][strlen(strArr[ind_str])] = *glue;
      s = strcat_ex(&s, &n, strArr[ind_str]);
      
    }
  
  return s;

}
/*
void sortStringArray(char ** arrString, int len);
{
  int index_arr;
  int index_s;
  for (index_arr = 0; index_arr < (len - 1); index_arr++)
    {
      index_s = 0;
      while (arrString[index_arr][index_s] != '\0')
      {
        if (arrString[index_arr][index_s] == arrString[index_arr + 1][index_s])
          {
            index_s++;
          }
        if (arrString[index_arr][index_s] > arrString[index_arr + 1][index_s])
          {
            swapString(&arrString[index_arr], &arrString[index_arr + 1]);
            break;
          }
        else
          {
            break;
          }
      }
    }
    return 0;
}
*/
int compAsc(const void * a, const void * b)
{
  return(*(char *)a -*(char *)b);
}

void sortStringCharacters(char * str)
{
  int n = strlen(str);
  
  qsort(str, n, sizeof(str[0]), compAsc);
}



