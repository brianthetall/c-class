/*******************************************************************************
 * print varible sizes
 * compile with: gcc -g -Wall -std=c99 -o printVarSizes printVarSizes.c
 */
#include <stdio.h>
#include <stdint.h>

int main() {
    
  printf("sizes:\r\n");
  printf("char: %ld bytes\r\n", sizeof(char));
  printf("int: %ld bytes\r\n", sizeof(int));
  printf("short: %ld bytes\r\n", sizeof(short));
  printf("long: %ld bytes\r\n", sizeof(long));
  printf("float: %ld bytes\r\n", sizeof(float));
  printf("double: %ld bytes\r\n", sizeof(double));

  printf("uint8_t: %ld bytes\r\n", sizeof(uint8_t));
  printf("int8_t: %ld bytes\r\n", sizeof(int8_t));
  printf("uint16_t: %ld bytes\r\n", sizeof(uint16_t));
  printf("int16_t: %ld bytes\r\n", sizeof(int16_t));
  printf("uint32_t: %ld bytes\r\n", sizeof(uint32_t));
  printf("int32_t: %ld bytes\r\n", sizeof(int32_t));

  return 0;
}
