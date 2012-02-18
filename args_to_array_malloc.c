/*
this program accepts numbers via the command line.
it dynamically creates an array to store the arguments using: malloc
*/

#include <stdio.h>//standard i/o library
#include <stdlib.h>//memory allocation function
int main(int argc,char *argv[])
{
  int i,number_of_elements;
  int *array;//declare pointer
  if (argc<2)//no numbers were passed
    {
      printf("Try adding arguments\r\n");
      return -1;
    }
  number_of_elements = argc-1;
  array = (int *)calloc(number_of_elements,sizeof(int));//point array to a section of memory
  for(i=0;i<number_of_elements;i++)
    {
      array[i] = atoi(argv[i+1]);//convert argument into an integer & store in array
      printf("array[%d]=%d\r\n",i,array[i]);
    }
  printf("\r\n");
  free(array);//let the memory go...
  return 0;
}
