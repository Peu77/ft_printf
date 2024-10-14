#include "ft_printf.h"
#include <stdio.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main(){
    printf("printf: %423,\n", 5);
    ft_printf("my: %423\n", 5);
  
}