/*
lower_to_Upper_FILE

convert a text file to ALL upper case. 
Generates a new file in the process.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LINE 256

int main(int argc,char *argv[])
{
  FILE *in,*out;//file pointers declared
  char temp;
  if(argc!=2)//check for correct number of arguments
    {
      printf("lower_to_Upper_FILE <input-file>\r\n");
      return -1;
    }
  if(NULL==(in=fopen(argv[1],"r")))//open the input file
    {
      printf("Error opening file %s\r\n",argv[1]);
      return -2;
    }
  if(NULL==(out=fopen(strcat(argv[1],".new"),"w")))//create the output file
    {
      printf("Error opening output file %s\r\n",strcat(argv[1],".new"));//use strcat to append ".new" to the output file
      return -3;
    }
  while(EOF != (temp=fgetc(in)))//loop while the EndOfFile has not been reached
    {
      if(isalpha(temp))//if the current character is a letter; lower | upper
	{
	  temp=toupper(temp);//convert to UPPER CASE
	}
      fputc(temp,out);//store temp in output file
    }
  fclose(out);//close Files.
  fclose(in);
  return 0;
}
