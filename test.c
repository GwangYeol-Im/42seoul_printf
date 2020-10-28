#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int len = ft_printf("%s1\n", "str");
    printf("%d\n", len);
    return (0);
}
