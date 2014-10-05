#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer05.h"

void printPar(int * ans, int length)
{
  int ind;
  for (ind = 0; ind < length -1; ind++)
  {
    printf("%d + ", ans[ind]);
  }
  printf("%d\n", ans[length - 1]);
}

void partitionA(int * ans, int count, int value)
{
  int ind;
  if (value == 0)
  {
    printf("= ");
    printPar(ans, count);
  }
  for (ind = 1; ind <= value; ind++)
  {
    ans[count] = ind;
    count ++;
    partitionA(ans, count, value - ind);
    count --;
  }
}

//I didn't copy the code on book. However, after I fixing my code, it seems have the same strategy and format.
void partitionAll(int value)
{
  int count = 0;
  int * ans = malloc((value * 2) * sizeof(int));
  partitionA(ans, count, value);
  free(ans);
}


//Increasing
void partitionI(int * arr, int cnt, int value, int ind)
{
  int in;
  if (value == 0)
  {
    printf("= ");
    printPar(arr, cnt);
  }
  for (in = ind;in <= value; in++)
  {
    arr[cnt] = in;
    cnt ++;
    partitionI(arr, cnt, value - in, in + 1);
    cnt --;
  }
}

void partitionIncreasing(int value)
{
  int count = 0;
  int inde = 1;
  int * ans = malloc(value * sizeof(int));
  partitionI(ans, count, value, inde);
  free(ans);
}

//Decreasing
void partitionD(int * arr, int cnt, int value, int ind)
{
  int in;
  if (value == 0)
  {
    printf("= ");
    printPar(arr, cnt);
  }
  for (in = ind;in > 0; in--)
  {
    arr[cnt] = in;
    cnt ++;
    partitionD(arr, cnt, value - in, in - 1);
    cnt --;
  }
}

void partitionDecreasing(int value)
{
  int count = 0;
  int ind = value;
  int * ans = malloc(value * sizeof(int));
  partitionD(ans, count, value, ind);
  free (ans);
}


//Odd
void partitionO(int * arr, int cnt, int value)
{
  int ind;
  if (value == 0)
  {
    printf("= ");
    printPar(arr, cnt);
  }
  for (ind = 1; ind <= value; ind++)
  {
    if (ind % 2 != 0)
    {
      arr[cnt] = ind;
      partitionO(arr, cnt + 1, value - ind);
    }
  }
}

void partitionOdd(int value)
{
  int count = 0;
  int * ans = malloc(value * sizeof(int));
  partitionO(ans, count, value);
}


//Even
void partitionE(int * arr, int cnt, int value)
{
  int ind;
  if (value == 0)
  {
    printf("= ");
    printPar(arr, cnt);
  }
  for (ind = 1; ind <= value; ind++)
  {
    if (ind % 2 == 0)
    {
      arr[cnt] = ind;
      partitionE(arr, cnt + 1, value - ind);
    }
  }
}

void partitionEven(int value)
{
  int count = 0;
  int * ans = malloc(value * sizeof(int));
  partitionE(ans, count, value);
}


//Odd And Even
void partitionOE(int * arr, int cnt, int value, int dec)
{
  int ind;
  if (value == 0)
  {
    printf("= ");
    printPar(arr, cnt);
  }
  for (ind = 1; ind <= value; ind++)
  {
    if (dec != 0)
    {
      if (ind % 2 == 0)
      {
        arr[cnt] = ind;
        partitionOE(arr, cnt + 1, value - ind, 0);
      }
    }
    if (dec != 1)
    {  
      if (ind % 2 != 0)
      {
        arr[cnt] = ind;
        partitionOE(arr, cnt + 1, value - ind, 1);
      }
    }
  }
}

void partitionOddAndEven(int value)
{
  int count = 0;
  int dec = 2;
  int * ans = malloc(value * sizeof(int));
  partitionOE(ans, count, value, dec);
}


int main()
{
  partitionOddAndEven(6);
  return 0;
}
