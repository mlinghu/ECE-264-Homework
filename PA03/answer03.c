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
  ans = (char **) malloc( (2*(*arrlen) + 1) * sizeof(char*) );
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
  *arrlen = cnt;
  return ans;
}

char * implode(char ** strArr, int len, const char * glue)
{
  int ind_str;
  int n = 0;
  char * s = NULL;
  if (*strArr == NULL)
  {
    return s;
  }
  if (len <= 1)
  {
    strcat_ex(&s, &len, strArr[0]);
    return s;
  }
  for (ind_str = 0; ind_str < len; ind_str++)
  {
      s = strcat_ex(&s, &n, strArr[ind_str]);
      if (ind_str == len -1)
      {
        break;
      }
      s = strcat_ex(&s, &n, glue);
  }
  
  return s;
}



int compStr(const void *a, const void  *b)
{
  int ans = strcmp(*(char **)a,*(char **)b);
  return(ans);
}
void sortStringArray(char ** arrString, int len)
{
  qsort(arrString, len, sizeof(char *), compStr);
  return;
}




int compAsc(const void * a, const void * b)
{
  return(*(char *)a -*(char *)b);
}

void sortStringCharacters(char * str)
{
  int n = strlen(str);
  
  qsort(str, n, sizeof(str[0]), compAsc);
  return;
}


void destroyStringArray(char ** strArr, int len)
{  
  int index_str;
  if (strArr == NULL)
  {
    return;
  }
  for (index_str = 0; index_str < len; index_str++)
  {
    free(strArr[index_str]);
  }
  free(strArr);
return;
}
