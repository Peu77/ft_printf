#include <stdio.h>
#include "ft_printf.h"

int main(){
    const char* str = "% +05.10d";
    printf(str, 423);
    ft_printf(str, 423);
}