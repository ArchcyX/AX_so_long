#include "../includes/so_long.h"

void    ft_error(int err_no)
{
    if (err_no == 1)
        write(1, "Map Error", 9);

}