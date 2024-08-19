#include "minirt.h"

void	printest(char *str)
{
	ft_printf("\"%s\" is valid Coordenate type? ", str);
	if (iscoordinatestr(str))
		ft_printf("TRUE.\n");
	else
		ft_printf("FALSE.\n");
}

int	main(void)
{
	ft_printf("---- Valid ----\n");
	printest("0,0,0");
	printest("0.0,0.0,0.0");
	printest("0,0,340282346638528859811704183484516925440");
	printest("0,0,+340282346638528859811704183484516925440");
	printest("0,0,-340282346638528859811704183484516925440");
	printest("0,0,340282346638528859811704183484516925440.0001");
	ft_printf("\n---- NO Valid ----\n");
	printest("0,0,340282346638528859811704183484516925441");
	printest("0,0,+340282346638528859811704183484516925441");
	printest("0,0,-340282346638528859811704183484516925441");
	ft_printf("\n---- Format Error ----\n");
	printest("");
	printest(",,");
	printest(",");
	printest("8");
	printest("8,");
	printest("8,0");
	printest("8,0,");
	printest("&,0,1");
	printest("-0.3*,0,1");
	return (0);
}
