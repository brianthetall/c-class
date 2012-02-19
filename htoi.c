/*htoi.c
int htoi(const char *s)
const char *s is a null terminated string of HEX DIGITS
convert ascii string of hex-values into integer variable
Similar to 'atoi'.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int htoi(const char *s);
int main(int argc,char *argv[])
{
  printf("%X\r\n",htoi("6fb0"));
  printf("%X\r\n",htoi("4"));
  printf("%X\r\n",htoi("DEAD"));
  return 0;
}
int htoi(const char *s)
{
  int i,retval=0;
  char *t=(char *)calloc(strlen(s),sizeof(char));
  strcpy(t,s);//copy CONST char string into changable array
  for(i=0;i<strlen(t);i++)
    {
      if(isxdigit(t[i]))//is a hex-digit
	{
	  if(isalpha(t[i]))//is a-f
	    {
	      t[i]=tolower(t[i]);//make sure the character is lower-case.
	      retval+=(pow(16,strlen(t)-1-i)*(t[i]-87));//subtract ASCII offset
	    }
	  else if(isdigit(t[i]))//is 0-9
	    {
	      retval+=(pow(16,strlen(t)-1-i)*(t[i]-48));//subtract ASCII offset
	    }
	}
    }
  return retval;
}
