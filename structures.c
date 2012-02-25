#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 1
struct timer
{
  int day,month,year,misc;
  void(*interrupt)(void);//set by the timer init function
};
struct coffeeMaker
{
  char *name;
  int cups;
  void(*toString)(const struct coffeeMaker*);//function pointer to toString function
  struct timer t;
  //  int numberTimers;
  int(*loadCoffee)(int);
  int(*loadWater)(int);
};


void initCoffeeMaker(struct coffeeMaker*,const char *name,const int cups,
		     void(*print)(const struct coffeeMaker*),
		     int(*waterload)(int),
		     int(*coffeeload)(int));
void makerToString(const struct coffeeMaker*);
int mrCoffee_coffeeload(int mass);
int mrCoffee_waterload(int volume);
int mrCoffee_power(int on);
void mrCoffee_ISR(void);
int mrCoffee_configtimer(struct coffeeMaker *cm,int day,int month,int year,void(*interrupt)(void));

int main(int argc,char* argv[])
{
  int i;
  struct coffeeMaker cm;//declare coffee maker
  cm.name=(char*)calloc(strlen("Captain Coffee"),sizeof(char));//alloc memory for the char* within coffeemaker
  initCoffeeMaker(&cm,"Captain Coffee",16,makerToString,mrCoffee_waterload,mrCoffee_coffeeload);//call coffeemaker init function
  //  printf("Addressof\"makerToString\"=%d\r\n",&makerToString);
  //  printf("Address@cm.toString=%d\r\n",cm.toString);
  cm.toString(&cm);
  cm.loadCoffee(10);
  cm.loadWater(10);
  mrCoffee_configtimer(&cm,3,19,2012,mrCoffee_ISR);//set date and function to run at that date
  cm.t.interrupt();
  return 0;
}
void initCoffeeMaker(struct coffeeMaker* cm,const char *name,const int cups,
		     void(*print)(const struct coffeeMaker*),
		     int(*waterload)(int),
		     int(*coffeeload)(int)
		     )
{
  cm->cups=cups;
  strcpy(cm->name,name);
  cm->toString=print;
  cm->loadCoffee=coffeeload;
  cm->loadWater=waterload;
}
void makerToString(const struct coffeeMaker *cm)
{
  if(cm==NULL)
    return;
  printf("CoffeeMakerName=%s\r\nVolumeCapacity=%d\r\n",
	 cm->name,cm->cups);
}
int mrCoffee_waterload(int volume)
{
  printf("MRCOFFEE WATERLOAD:%d\r\n",volume);
  return 0;
}
int mrCoffee_coffeeload(int mass)
{
  printf("MRCOFFEE COFFEELOAD:%d\r\n",mass);
  return 0;
}
void mrCoffee_ISR(void)
{
  printf("mrCoffee ISR\r\n");

}
int mrCoffee_configtimer(struct coffeeMaker *cm,int day,int month,int year,void(*interrupt)(void))
{
  cm->t.interrupt=interrupt;
  cm->t.day=day;
  cm->t.month=month;
  cm->t.year=year;
  return 0;
}
int mrCoffee_power(int on)
{
  if(on>0)
    {
      printf("PowerON\r\n");
    }
  else
    {
      //power off
      printf("PowerOFF\r\n");
    }
  return 0;
}
