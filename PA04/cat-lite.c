#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char ** argv)
{
  int index1;
  int index2;
  char c;
  FILE* fp;
  for (index1 = 1; index1 < argc; index1++)
  {
    if (strcmp(argv[index1], "--help") == 0)
    {
      printf("Usage: cat-lite [--help] [FILE]...\n"
             " With no FILE, or when FILE is -, read standard input.\n\n"
              "Examples:\n"
                "cat-lite README   Print the file README to standard output.\n"
                "cat-lite f - g    Print f's contents, then standard input,\n" 
                                  "then g's contents.\n"
                "cat-lite          Copy standard input to standard output.\n");
      return EXIT_SUCCESS;
    }
  }
  char string[256];
  if (argc == 1)
  {
    while (fgets(string, 256, stdin) != NULL)
    {
    printf("%s", string);
    }
    return EXIT_SUCCESS;
  }
  else
  {
  for (index2 = 1; index2 < argc; index2++)
  {
    if (strcmp(argv[index2], "-") == 0)
    {
      while (fgets(string, 256, stdin))
      {
      printf("%s", string);
      }
    }
    else
    {
      fp = fopen(argv[index2],"r");
      if (fp == NULL)
      {
        printf("cat cannot open %s\n", argv[index2]);
        return EXIT_FAILURE;
      }
      while (1)
      {
         c = fgetc(fp);
         if (c == EOF)
         {
           break;
         }
         printf("%c", c);
      }
    fclose(fp);
    }
  }
  }


  return EXIT_SUCCESS;
}
