#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 1
struct timer
{
  int day,month,year,misc;
};
struct coffeeMaker
{
  char *name;
  int cups;
  struct timer t;
};
void initCoffeeMaker(struct coffeeMaker*,const char *name,const int cups);
void makerToString(const struct coffeeMaker*);
int main(int argc,char* argv[])
{
  struct coffeeMaker cm;
  cm.name=(char*)calloc(strlen("Captain Coffee"),sizeof(char));
  initCoffeeMaker(&cm,"Captain Coffee",16);
  makerToString(&cm);
  return 0;
}
void initCoffeeMaker(struct coffeeMaker* cm,const char *name,const int cups)
{
  cm->cups=cups;
  strcpy(cm->name,name);
}
void makerToString(const struct coffeeMaker *cm)
{
  if(cm==NULL)
    return;
  printf("CoffeeMakerName=%s\r\nVolumeCapacity=%d\r\n",
	 cm->name,cm->cups);
}
