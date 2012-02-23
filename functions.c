/*
Several examples of using functions,parameters,return-types

In order to use the math library, must compile with "-lm" flag
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>//gcc -lm functions.c
#define DEBUG 1
#define LINE 256
#define ARGS 1
#define VECTOR 6
void printFunction(const char*);
int computeFloatingPointVector(long double*,const long double*,const long double*);//use powl
char* mirrorString(const char *);
int pointerLength(const void*);//return the number of bytes between the pointer & the '\0'
int main(int argc, char *argv[])
{
  char *s;
  int i;
  long double *bases,*exponents,*result;
  if(argc!=ARGS)
    {
      printf("functions");
      return -1;
    }
  bases=(long double*)calloc(VECTOR,sizeof(long double));
  exponents=(long double*)calloc(VECTOR,sizeof(long double));
  result=(long double*)calloc(VECTOR,sizeof(long double));
  for(i=0;i<5;i++)
    {
      bases[i]=i+9;
      exponents[i]=i+8*2;
    }
  bases[5]='\0';
  exponents[5]='\0';//function that finds size needs null-terminated pointers
  printf("basesLength=%d\r\n",pointerLength(bases));
  printf("computeFloatingPointVector=%d\r\n",computeFloatingPointVector(result,bases,exponents));
  for(i=0;i<VECTOR;i++)
    {
      printf("result[%d]=%f\r\n",i,(float)result[i]);
    }
  s=(char *)calloc(LINE,sizeof(char));
  s="this is a line.";
  printf("%s\r\n%s\r\n",s,mirrorString(s));
  printf("pointerLength(\"this is a line.\")=%d\r\n",pointerLength(s));

  //free(result);
  //free(exponents);
  //free(bases);
  return 0;
}
//-------MISC Function Examples-------------------------------------
void printFunction(const char* s)
{
  if(s!=NULL)
    {
      printf("%s",s);
    }
}
int computeFloatingPointVector(long double* retval,const long double* a,const long double* b)
{//use powl
  //  long double* retval;
  int i;
  printf("IN");
  if(a==NULL || b==NULL)
      return -1;
  if(pointerLength(a)!=pointerLength(b))  //make sure vectors are the same length
      return -2;
  printf("PointnerLengthA=%d\r\n",pointerLength(a));
  for(i=0;i<pointerLength(a);i++)
    {
      retval[i]=powl(a[i],b[i]);
      printf("%f^%f=%f\r\n",(double)a[i],(double)b[i],(double)retval[i]);
    }
  printf("leaving");

  return 0;
}
char* mirrorString(const char *in)
{
  char *s;
  int i,inLength=strlen(in);
  s=(char*)calloc(inLength,sizeof(char));
  for(i=0;i<inLength;i++)
    {
      s[i]=in[inLength-1-i];
    }
  return s;
}
int pointerLength(const void* v)//return the number of bytes between the pointer & the '\0'
{
  int i=0;
  while(((char*)v)[i++]!='\0')
  return i;
}
