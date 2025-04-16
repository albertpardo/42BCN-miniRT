
#include "cub3d.h"
#include "window.h"

int	ft_errors2(int n)
{
	if (n == 4)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid route in map!\n", 22);
		exit(1);
	}
	else if (n == 5)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to initialize the program!\n", 47);
		exit(1);
	}
	else
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	return (1);
}

/*Funcion que muestra mensajes de error*/
int	ft_errors(int n)
{
	if (n == 1)
	{
		write (2, "Error\n", 6);
		write (2, "Use: ./so_long <map.ber>\n", 25);
		exit(1);
	}
	else if (n == 2)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to open the file\n", 37);
		exit(1);
	}
	else if (n == 3)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid map file!\n", 18);
		exit(1);
	}
	else
		ft_errors2(n);
	return (1);
}
