//6) Use multi-demensional pointers to store a list of names and numbers. 
//Write a function that accepts the multi-deminsional pointer and re-arranges the names in alphabetical order
//pass the program a name & number database contained within a text-file.
//your program will generate an output file to contain the results.
/*EXAMPLE DATABASE:
  bob dole 76
  tombraider 22

Your method of storing the database in memory should only use enough to store contents of the name&number.
Find the size of the name before allocing memory in each structure.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG 0
#define LINE 512
#define NAMESIZE 32
struct human{//setup structure to hold each database element
  char *name;//human's name
  int number;//human's number
};
void printDatabase(struct human *,int size);
int main(int argc,char* argv[])
{
  FILE *in,*out;
  int numberOfLines=1,i;
  char temp,*s,*t,*tempName,lastChar;
  s=(char*)calloc(LINE,sizeof(char));//string buffer
  t=(char*)calloc(LINE,sizeof(char));//temp buffer
  tempName=(char*)calloc(NAMESIZE,sizeof(char));
  struct human *database;//pointer to the start of the d-base
  if(argc!=2)
    {
      printf("multi-d-pointers <database-file>\r\n");
      return -1;
    }
  strcat(s,"sort ");
  strcat(s,argv[1]);
  strcat(s,">.multi-d-file");
  system(s);  //system call to generate a sorted input file!
  s[0]='\0';
  //  if(NULL==(in=fopen(argv[1],"r")))//open input file
  if(NULL==(in=fopen(".multi-d-file","r")))//open SORTED input file
    {
      printf("Error opening file\r\n");
      return -2;
    }
  while((temp=fgetc(in))!=EOF)
    {//determine memory needs of the file
      if(temp=='\n')
	{
	  
	  numberOfLines++;//IS THIS WORKING CORRECTLY?
	}
    }
  fseek(in,0,0);//reset stream position within file
  if(DEBUG)printf("NumberOfLines=%d\r\n",numberOfLines);
  database=(struct human*)calloc(numberOfLines,sizeof(struct human));  //allocate memory for the contents of the file
  //start parsing the input file 

  for(i=0;i<numberOfLines;i++)
    {
      fgets(s,LINE,in);//read line
      if(DEBUG)printf("LINE %d:%s",i,s);
      t=strtok(s," ");
      strcpy(tempName,t);
      while(NULL!=(t=strtok(NULL," ")))
	{
	  if(isdigit(t[0]))
	    {
	      database[i].number=atoi(t);
	      database[i].name=(char*)calloc(strlen(tempName),sizeof(char));
	      strcpy(database[i].name,tempName);
	    }
	  else
	    {
	      strcat(tempName," ");
	      strcat(tempName,t);
	    }
	}
    }
  printDatabase(database,numberOfLines);
  printf("\r\n");
  return 0;
}
//=================================================================================
void printDatabase(struct human *dbase,int size)
{
  int i;
  if(dbase!=NULL)
    {
      printf("\r\nprintfDatabase:\r\n");
      for(i=0;i<size;i++)
	{
	  printf("%s\t%d\r\n",dbase[i].name,dbase[i].number);
	}
    }
}
