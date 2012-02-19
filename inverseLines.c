/*
Inverse the lines of a text file
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 256
int main(int argc,char *argv[])
{
  FILE *in,*out;
  char *s=(char*)calloc(LINE,sizeof(char));
  int lineCount=0,index=0,i;
  fpos_t position,*positions;
  if(argc!=2)
    {
      printf("inverseLines <input-file>\r\n");
      return -1;
    }
  if(NULL==(in=fopen(argv[1],"r")))
    {
      printf("Error opening file:%s\r\n",argv[1]);
      return -2;
    }
  if(NULL==(out=fopen(strcat(argv[1],".inversed"),"w")))
    {
      printf("Error creating output file:%s\r\n",strcat(argv[1],".inversed"));
      return -3;
    }
  //start @ the end of inputfile and write lines to the outputfile
  while(NULL!=fgets(s,LINE,in))//determine line count
    {
      lineCount++;
    }
  positions=(fpos_t *)calloc(lineCount,sizeof(fpos_t));//for storing line positions
  fseek(in,0,SEEK_SET);//reset file pointer
  //  positions[index++]=(fpos_t)0;//first line starts @ offset 0
  while(NULL!=fgets(s,LINE,in))
    {
      if(-1==fgetpos(in,&positions[index++]))
	{
	  printf("Error fgetpos\r\n");
	  return -4;
	}
    }
  for(i=lineCount-2;i>=0;i--)
    {
      fsetpos(in,&positions[i]);
      printf("%s",fgets(s,LINE,in));
      fputs(s,out);
    }
  fseek(in,0,SEEK_SET);//get the first line
  printf("%s",fgets(s,LINE,in));
  fputs(s,out);
  fclose(out);
  fclose(in);
  free(positions);
  free(s);
  return 0;
}
