#include <stdio.h>
#include "ft_printf.h"

int main(){
    const char* str = "% #09.4d\n";
    printf(str, 543);
    ft_printf(str, 543);
}