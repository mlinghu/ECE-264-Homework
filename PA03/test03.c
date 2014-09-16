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
  printf("string[1] is: %s\n", strArr2[1]);
  
  //Test of implode
  printf("Test of implode\n");
  int len3 = 2;
  char ** strArr3 = malloc(len3 * sizeof(char *));
  strArr3[0] = strdup("The");
  strArr3[1] = strdup("Turing test");
  const char * glue = "{newline}";
  char * str3 = implode(strArr3, len3, glue);
  printf("string is (%s)\n", str3);

  //Test of sortString
  int len4;
  char ** strArr = explode("lady beatle brew", " ", &len4);
  sortStringArray(strArr, len4);
  char * str4 = implode(strArr, len4, " ");
  printf("%s\n", str4);
  
  //Test of sortStringCharacter
  char * s5 = strdup("How did it get so late so soon?");
  sortStringCharacters(s5);
  printf("after sorting: %s\n", s5);
  
  //Test of destroyString
  int len6;
  const char * abe = "Give me six hours to chop down a tree and I will spend\n"
                     "the first four sharpening the axe.";
  char ** strArr6 = explode(abe, "\n",&len6);
  destroyStringArray(strArr6, len6);
  printf("after free: %s\n", strArr6[1]);
  destroyStringArray(NULL, 0);


  return 0;
}

