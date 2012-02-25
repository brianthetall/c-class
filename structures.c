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
  void(*toString)(const struct coffeeMaker*);//function pointer to toString function
};
void initCoffeeMaker(struct coffeeMaker*,const char *name,const int cups,void(*print)(const struct coffeeMaker*));
void makerToString(const struct coffeeMaker*);
int main(int argc,char* argv[])
{
  int i;
  struct coffeeMaker cm;//declare coffee maker
  cm.name=(char*)calloc(strlen("Captain Coffee"),sizeof(char));//alloc memory for the char* within coffeemaker
  initCoffeeMaker(&cm,"Captain Coffee",16,makerToString);//call coffeemaker init function
  printf("Addressof\"makerToString\"=%d\r\n",&makerToString);
  printf("Address@cm.toString=%d\r\n",cm.toString);
  cm.toString(&cm);
  return 0;
}
void initCoffeeMaker(struct coffeeMaker* cm,const char *name,const int cups,void(*print)(const struct coffeeMaker*))
{
  cm->cups=cups;
  strcpy(cm->name,name);
  cm->toString=print;
}
void makerToString(const struct coffeeMaker *cm)
{
  if(cm==NULL)
    return;
  printf("CoffeeMakerName=%s\r\nVolumeCapacity=%d\r\nAddressOfToString=%d",
	 cm->name,cm->cups,cm->toString);
}
