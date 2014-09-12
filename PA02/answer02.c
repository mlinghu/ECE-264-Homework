#include "answer02.h"
#include "stdio.h" 

size_t my_strlen(const char * str)
{
  int length = 0;
  while (str[length] != '\0') 
    {
      length++;
    }
    return length;
}

int my_countchar(const char * str, char ch)
{
  int length = 0;
  int count = 0;
  while (str[length] != '\0')
    {
      if (str[length] == ch)
        {
          count++;
        }
      length++;
    }
  return count;
}
 
char * my_strchr(const char * str, int ch)
{
  int length = my_strlen(str) + 1;
  char * s = NULL;
  int a = 0;
  while (a <= length)
  {  
    if (str[a] == ch)
      {
        s =(char *) &str[a];
        break;
      }
    a++;
  }
  return (s);
}
char * my_strrchr(const char * str, int ch)
{
  int length = my_strlen(str);
  char * s = NULL;
  while (length >= 0)
  {
    if (str[length] == ch)
      {
         s = (char *)&str[length];
         break;
      }
    length--;
  }
  return (s);
}

char * my_strstr(const char * haystack, const char * needle)
{
  int hay_ind, needle_ind;
  if(needle[0] == '\0')
    return (char *) haystack;

  for(hay_ind = 0; haystack[hay_ind] != '\0'; hay_ind++) 
    {
      for(needle_ind = 0; needle[needle_ind] == haystack[hay_ind + needle_ind]; needle_ind++)
        {
          if (needle[needle_ind + 1] == '\0')
            {
              return (char *)&haystack[hay_ind];
            }
        }
    }
  return NULL;
}
            
char * my_strcpy(char * dest, const char * src)
{
  int index = 0;
  while(1)
    {
      dest[index] = src[index];
      if (dest[index] == '\0')
        {
          return(dest);
        }
      index++;
    }
}
/*
int main()
{
  const char * str = "Hello";
  char buffer[50];
  my_strcpy(buffer, "Hello ");
  printf("length: %d", my_strlen((const char *)buffer));
  printf("answeris : %s\n", my_strcat(buffer,"world!"));
  return 0;
}
*/

char * my_strcat(char * dest, const char * src)
{
  int length = 0;
  int i = my_strlen((const char *)dest);
    while(1)
    {
      dest[i + length] = src[length];
      if (src[length] == '\0')
        {
          return(dest);
        }
      length++;
    }
}

int my_isspace(int ch)
{
  return (ch == ' '||ch =='\f'||ch =='\n'||ch == '\r'||ch == '\t'||ch == '\v');
}

int my_atoi(const char * str)
{ 
  int ret = 0; 
  int sign = 1; 
  
  while((str[0] == ' ')|| (str[0] =='\f') || (str[0] =='\n' )|| (str[0] == '\r') || (str[0] == '\t') || (str[0] == '\v'))
    {
       str++;
    }
  if (str[0]=='-')
    { 
      sign = -1; 
      str++;
    }
  if ('0' <= *str && *str <= '9')
        {
          while ('0'<= *str && *str <= '9')
            {
              ret = ret*10 + (*str++ - '0');
            }
        }
  if (sign != 1)
    {
      return (-ret);
    }
  return ret;
}
