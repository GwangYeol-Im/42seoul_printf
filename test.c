#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int n;

    printf("%%%c%szz%dzz%i%uzz!!\n", 'a', "str", 1, 2, -123);
    ft_printf("%%%c%szz%dzz%i%uzz!!\n", 'a', "str", 1, 2, -123);
    return (0);
}
