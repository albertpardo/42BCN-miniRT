#include "minirt.h"

void	printest(char *str)
{
	ft_printf("\"%s\" is valid FOV type? ", str);
	if (isfov(str))
		ft_printf("TRUE. INT format : %d\n", ft_atoi(str));
	else
		ft_printf("FALSE.\n");
}

int	main(void)
{
	ft_printf("---- Valid range ----\n");
	printest("0");
	printest("00");
	printest("000");
	printest("099");
	printest("180");
	ft_printf("\n---- NO Valid range ----\n");
	printest("-1");
	printest("181");
	ft_printf("\n---- Format Error ----\n");
	printest("+0");
	printest("+180");
	printest("0000");
	printest("0180");
	printest("-0");
	printest("a");
	return (0);
}
