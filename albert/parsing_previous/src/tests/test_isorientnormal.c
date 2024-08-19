#include "minirt.h"

void	printest(char *str)
{
	ft_printf("\"%s\" is valid Coordenate type? ", str);
	if (isorientnormal(str))
		ft_printf("TRUE.\n");
	else
		ft_printf("FALSE.\n");
}

int	main(void)
{
	ft_printf("---- Valid ----\n");
	printest("0,0,0");
	printest("0.0,0.0,0.0");
	printest("1.0,+1.0,-1.0");
	ft_printf("\n---- NO Valid ----\n");
	printest("1.0,+1.0,-1.01");
	printest("1000000000000000000.0,+1.0,-1.01");
	ft_printf("\n---- Format Error ----\n");
	printest("");
	printest(",,");
	printest(",");
	printest("0.8");
	printest("0.8,");
	printest("0.8,0.0");
	printest("0.8,0,");
	printest("&,0,1");
	printest("-0.3*,0,1");
	return (0);
}
