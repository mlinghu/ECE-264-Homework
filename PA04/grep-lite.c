#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char ** argv)
{
  int index0;
  for (index0 = 1; index0 < argc; index0++)
    {
      if (strcmp(argv[index0], "--help") == 0)
      {
        printf("Usage: grep-lite [OPTION]... PATTERN\n"
               "Search for PATTERN in standard input. PATTERN is a\n"
               "string. grep-lite will search standard input line by\n"
               "line, and (by default) print out those lines which\n"
               "contain pattern as a substring.\n\n"
                 "-v, --invert-match     print non-matching lines\n"
                 "-n, --line-number      print line numbers with output\n"
                 "-q, --quiet            suppress all output\n\n"
               "Exit status is 0 if any line is selected, 1 otherwise;\n"
               "if any error occurs, then the exit status is 2.);\n");
        return EXIT_SUCCESS;
      }
    }
  int index1;
  for (index1 = 1; index1 < (argc - 1); index1++)
  {
    if ((strcmp(argv[index1], "-v") != 0) && (strcmp(argv[index1], "-n") != 0) && (strcmp(argv[index1], "-q") != 0) && (strcmp(argv[index1], "--invert-match") != 0) && (strcmp(argv[index1], "--line-number") != 0) && (strcmp(argv[index1], "--quiet") != 0))

    {
      fputs("There is an invalid command-line argument!\n", stderr);
      return (2);
    }
  }
  
  if (argv[argc - 1][0] == '-')
  {
    fputs("The PATTERN cannot start with a '-'", stderr);
    return (2);
  }
  
  int index2;
  int c_v = 0;
  int c_n = 0;
  int c_q = 0;
  for (index2 = 1; index2 < argc; index2++)
  {
    if (strcmp(argv[index2], "-v") == 0 || strcmp(argv[index2], "--invert-match") == 0)
    {
      c_v++;
    }
    if (strcmp(argv[index2], "-n") == 0 || strcmp(argv[index2], "--line-number") == 0)
    {
      c_n++;
    }
    if (strcmp(argv[index2], "-q") == 0 || strcmp(argv[index2], "--quiet") == 0)
    {
      c_q++;
    }
  }
  char string[2000];
  char *decide;
  int count = 0;
  int line= 1;
  char *pat = argv[argc - 1];
  while(fgets(string, 2000, stdin) != NULL)
  {
   decide = strstr(string, pat);
   int exist = 0;
   if (decide != NULL)
   {
     count++;
     if (c_n != 0 && c_q == 0 && c_v == 0)
     {
       printf("%d:", line);
     }
     if (c_q == 0 && c_v ==0)
     {
       printf("%s\n", string);
     }
     exist++;
   }
   if (exist == 0 && c_q == 0 && c_v != 0)
   {
     if (c_n != 0)
     {
       printf("%d:",line);
     }
     printf("%s\n",string);
   }
   line++;
  }
  if (count != 0)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
