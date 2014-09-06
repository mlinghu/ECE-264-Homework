#include "answer02.h"
#include "stdio.h"
int main()
{
  const char * s1 = "Hello World!"; 
  const char * s2 = ""; 
  const char * s3 = "foo";
  printf("my_strchr = %s\n", my_strchr(s1, 'l'));
  return 0;
}
 
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
  int length = 0;
  int count = 0;
  int i = 0;
  char* s;
  while (str[length] != '\0')
  {  
    if (str[length] == ch)
      {
        while (str[length] != '\0')
          {
            s[i] = str[length];
            i++;
            length++;
          }
        break;
      }
    length++;
  } 
  return s;
}
 
