#include<stdio.h>
#include<stdlib.h>

int main(int argc, char ** argv)
{
   int index;
   for (index = 1; index < argc; index++)
   {
     printf("%s ", argv[index]);
   }
   printf("\n");
   return EXIT_SUCCESS;

}
