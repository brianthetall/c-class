//compile with gcc -lm interesting.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARGS 5
#define DEBUG 1

int main(int argc,char *argv[]){

  float pile,newPile,pileChange,fluxRate,minimum,total;//min. can be rate X% OR amount $X
  int compoundPeriod,iteration=1;

  if(argc!=ARGS){
    printf("interesting <pile> <fluxion-rate> <compound-period-months> <minimum-shovel-rate/amount>\r\n");
    return -1;
  }

  if(DEBUG){
    printf("%s\t%s\t%s\t%s\t%s\r\n",argv[0],argv[1],argv[2],argv[3],argv[4]);
  }

  pile=(float)atof(argv[1]);
  fluxRate=(float)atof(argv[2]);
  compoundPeriod=atoi(argv[3]);
  minimum=(float)atof(argv[4]);

  if(DEBUG){
    printf("%f\t%f\t%d\t%f\r\n",pile,fluxRate,compoundPeriod,minimum);
  }

  do{
    pileChange=pile-minimum;
    if(iteration % compoundPeriod == 0)//compound the interest
      {
	newPile = pileChange + pileChange*fluxRate;
	printf(".");
      }
    else
      {
	newPile=pileChange;
	printf(",");
      }

    printf("%d) Pile=%f\t",iteration++,pile);
    printf("NewPile=%f\tRxed:%f\r\n",pile=newPile,total+=minimum);

  }while(pile > 2);

  return 0;
}
