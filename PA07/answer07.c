#include "answer07.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>

#define ImageHeader_magic 0x21343632

#define FALSE 0
#define TRUE 1

Image * Image_load(const char * filename)
{
  FILE * fp = fopen(filename, "rb");
  if(fp == NULL)
  {
    return NULL;
  }
  ImageHeader header;
  int read;
  read = fread(&header, sizeof(ImageHeader), 1, fp);
  if (read != 1)
  {
    fclose(fp);
    return NULL;
  }
  
  if ((header.magic_number) != ImageHeader_magic)
  {
    fclose(fp);
    return NULL;
  }

  if (header.width <= 0 || header.height <= 0)
  {
    fclose(fp);
    return NULL;
  }

  Image * im;
  im = malloc(sizeof(Image));
  if (im == NULL)
  {
    free(im -> data);
    free(im -> comment);
    free(im);
    fclose(fp);
    return NULL;
  }

  im -> width = header.width;
  im -> height = header.height;
  im -> comment = malloc(sizeof(char) * (header.comment_len));
  im -> data = malloc(sizeof(uint8_t) * (header.width*header.height));

  if (im -> data == NULL)
  {
    free(im -> data);
    free(im -> comment);
    free(im);
    fclose(fp);
    return NULL;
  }

  read = fread(im -> comment, sizeof(char), header.comment_len, fp);
  if (read != header.comment_len)
  {
    free(im -> data);
    free(im -> comment);
    free(im);
    fclose(fp);
    return NULL;
  }
  
  if (im -> comment[header.comment_len - 1] != '\0')
  {
    free(im -> data);
    free(im -> comment);
    free(im);
    fclose(fp);
    return NULL;
  }

  if (im -> data == NULL)
  {
    free(im -> data);
    free(im -> comment);
    free(im);
    fclose(fp);
    return NULL;
  }
  
  read = fread(im -> data, sizeof(uint8_t), header.width * header.height, fp);
  if (read != (header.width * header.height))
  {
    free(im -> data);
    free(im -> comment);
    free(im);
    fclose(fp);
    return NULL;
  }
  
  uint8_t check;
  read = fread(&check, sizeof(uint8_t), 1, fp);
  if (read != 0)
  {
    free(im -> data);
    free(im -> comment);
    free(im);
    fclose(fp);
    return NULL;
  }
  fclose(fp);
  
  return im;
}


int Image_save(const char* filename, Image* image)
{
  FILE * fp;
  int written;

  fp = fopen(filename, "wb");
  if (fp == NULL)
  {
    return FALSE;
  }
  
  ImageHeader  header;
  header.magic_number = ImageHeader_magic;
  header.width = image -> width;
  header.height = image -> height;
  header.comment_len = strlen(image -> comment);

  written = fwrite(&header, sizeof(ImageHeader), 1, fp);
  if (written != 1)
  {
    return FALSE;
  }

  size_t bytes_com = sizeof(char) * (header.comment_len + 1);
  fwrite(image -> comment, bytes_com, 1, fp); 

  size_t bytes_data = sizeof(uint8_t) * (image -> height * image -> width);

  fwrite(image -> data, bytes_data, 1, fp);

  if(fp)
  {
    fclose(fp);
  }
  return TRUE;
}

void Image_free(Image* image)
{
  if(image != NULL)
  {
    free(image->comment);
    free(image->data);
  }
  free(image);
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
  int max = intensity[0];
  int min = intensity[0];
  int ind;
  int tot = height * width;
  for (ind = 0; ind < tot; ind++)
  {
    if (intensity[ind] < min)
    {
      min = intensity[ind];
    }
    if (intensity[ind] > max)
    {
      max = intensity[ind];
    }
  }
  
  for(ind = 0; ind < tot; ind++)
  {
    intensity[ind] = (intensity[ind] - min)*255.0 / (max - min);
  }
}
