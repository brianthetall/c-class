/*
print_args.c
Print to the terminal, all the arguments that were passed
*/
#include <stdio.h>
int main(int argc,char *argv[])
{
  int i;
  for(i=0;i<argc;i++)
    printf("%s\r\n",argv[i]);
  return 0;
}
