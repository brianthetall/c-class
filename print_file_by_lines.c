#include <stdio.h>
#include <stdlib.h>//calloc
#define LINESIZE 256//easy to change line size definition
int main(int argc,char *argv[])
{
  FILE *in;//input file pointer
  char *s;//character buffer pointer
  if(argc != 2)
    {
      printf("print_file_by_lines <file>\r\n");//operator error message
      return -1;
    }
  if(NULL==(in=fopen(argv[1],"r")))//open the file with read permissions
    {
      printf("Error opening file.\r\n");
      return -2;
    }
    s=(char *)calloc(LINESIZE,sizeof(char));//assign memory to the character buffer
    while(NULL!=fgets(s,LINESIZE,in))//loop while not @ end-of-file
      {
	printf("%s",s);//print current line of the input file
      }
    free(s);//free memory
    fclose(in);//close file
    return 0;//return success
}
