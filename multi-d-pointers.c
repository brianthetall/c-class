//6) Use multi-demensional pointers to store a list of names and numbers. 
//Write a function that accepts the multi-deminsional pointer and re-arranges the names in alphabetical order
//pass the program a name & number database contained within a text-file.
//your program will generate an output file to contain the results.
/*EXAMPLE DATABASE:
  bob dole 76
  tombraider 22
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG 1
#define LINE 512
int main(int argc,char* argv[])
{
  FILE *in,*out;
  int numberOfLines=1,i;
  char temp,*s;
  struct{//setup structure to hold each database element
    char *name;//human's name
    int number;//human's number
  }human;
  struct human *database;//pointer to the start of the d-base
  if(argc!=2)
    {
      printf("multi-d-pointers <database-file>\r\n");
      return -1;
    }
  if(NULL==(in=fopen(argv[1],"r")))//open input file
    {
      printf("Error opening file\r\n");
      return -2;
    }
  while((temp=fgetc(in))!=EOF)
    {//determine memory needs of the file
      if(temp=='\n')
	numberOfLines++;
    }
  fseek(in,0,0);//reset stream position within file
  if(DEBUG)printf("NumberOfLines=%d\r\n",numberOfLines);
  database=(struct human*)calloc(numberOfLines,sizeof(human));  //allocate memory for the contents of the file
  //start parsing the input file 
  s=(char*)calloc(LINE,sizeof(char));
  for(i=0;i<=numberOfLines;i++)
    {
      fgets(s,LINE,in);//read line
      if(DEBUG)printf("LINE %d:%s",i,s);
    }
  return 0;
}
