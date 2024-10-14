#include "ft_printf.h"
#include <stdio.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main(){
   int printed = ft_printf("% .d%%\n", 0);
   int expected = printf("% .d%%\n", 0);

    printf("Expected: %d\n", expected);
    printf("Got: %d\n", printed);
  
}