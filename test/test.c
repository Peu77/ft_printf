#include <stdio.h>
#include "ft_printf.h"

int main(){
    const char* str = "% d\n";
    printf(str, 543);
    ft_printf(str, 0);
}