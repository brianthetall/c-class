//compile with gcc -lm interesting.c
#include <stdio.h>
#include <math.h>

#define ARGS 4
#define DEBUG 1

int main(int argc,char *argv[]){
  if(argc!=ARGS){
    printf("interesting <pile> <fluxion-rate> <compound-period-months> <minimum-shovel-rate/amount>\r\n");
  }
  return 0;
}
