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
#define VECTOR 3
void printFunction(const char*);//TESTED
int computeFloatingPointVector(double*,const double*,const double*);//TESTED
char* mirrorString(const char *,char*);//TESTED
int pointerLength(const void*);//return the number of bytes between the pointer & the '\0'. Good for char strings.
int main(int argc, char *argv[])
{
  char *s,*t;
  int i;
  double *bases,*exponents,*result;
  if(argc!=ARGS)
    {
      printf("functions");
      return -1;
    }
  printFunction("Output from testing the printFunction\r\n");//testing the printFunction()
  bases=(double*)calloc(VECTOR,sizeof(double));//declaring memory for the vectors
  exponents=(double*)calloc(VECTOR,sizeof(double));//exponent vector
  result=(double*)calloc(VECTOR,sizeof(double));//result vector
  bases[0]=16.3;exponents[0]=4.3;//initalize some date
  bases[1]=136.3;exponents[1]=44.3;//initalize some date
  printf("computeFloatingPointVector=%d\r\n",computeFloatingPointVector(result,bases,exponents));//TEST FloatingVector function
  for(i=0;i<VECTOR;i++)
    {
      printf("result[%d]=%f\r\n",i,(float)result[i]);
    }
  s=(char *)calloc(LINE,sizeof(char));
  t=(char *)calloc(LINE,sizeof(char));
  s="this is a line.";
  printf("%s\r\n%s\r\n",s,mirrorString(s,t));
  printf("pointerLength(\"this is a line.\")=%d\r\n",pointerLength(s));

  return 0;
}
//-------MISC Function Examples-------------------------------------
void printFunction(const char* s)
{
  if(s!=NULL)
      printf("%s",s);
}
int computeFloatingPointVector(double* retval,const double* a,const double* b)
{//use powl
  int i;
  if(a==NULL || b==NULL)
      return -1;
  for(i=0;i<VECTOR;i++)
    {
      retval[i]=powl(a[i],b[i]);//compute the operation a^b
      printf("%.2f^%.2f=%.2f\r\n",(double)a[i],(double)b[i],(double)retval[i]);//print all involved
    }
  return 0;
}
char* mirrorString(const char *in,char *out)
{//mirror *in. store results in *out
  int i,inLength=strlen(in);
  for(i=0;i<inLength;i++)
    out[i]=in[inLength-1-i];
  return out;
}
int pointerLength(const void* v)//return the number of bytes between the pointer & the '\0'
{
  int i=0;
  while(((char*)v)[i++]!='\0'){printf(".");}
  return i;
}
