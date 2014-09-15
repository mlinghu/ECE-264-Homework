#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer03.h"

int main()
{
  //Test of strcat_ex
  char * s1;
  int n1 = 0;
  s1 = NULL;
  printf("test answer is: %s\n", strcat_ex(&s1, &n1, "world!"));

  //Test of explode
  int len2;
  char ** strArr2 = explode("The\nTuring test", " \t\v\n\r\f", &len2);
  printf("len = %d\n", len2);
  printf("string[0] is: %s\n", strArr2[0]);
  
  //Test of implode
  int len3;
  char ** strArr3 = explode("100 224 147 80", " ", &len3);
  char * str3 = implode(strArr3, len3, ", ");
  printf("string is (%s)\n", str3);
  
  //Test of sortStringCharacter
  char * s5 = strdup("How did it get so late so soon?");
  sortStringCharacters(s5);
  printf("after sorting: %s\n", s5);
  
  return 0;
}
