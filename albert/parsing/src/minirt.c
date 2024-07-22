#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

#define	BAD_ARGUMENTS "BAD ARGUMETS. Use : ./minirt NAME.rt"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_printf(argv[1]);
		ft_printf("\n");
	}
	else
	{
		perror(BAD_ARGUMENTS);
		return (1);
	}
	return (0);
}
