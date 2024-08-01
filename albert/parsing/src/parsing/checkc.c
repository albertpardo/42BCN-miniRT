#include "minirt.h"

void	checkc(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is Camara\n");
		if (ft_astrlen(aelement) == 4)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Camara] Viewport is valid format\n");
			else
				ft_printf("[Camara] Viewport is NOT VALID format\n");
			if (isorientnormal(aelement[2]))
				ft_printf("[Camara] Orientation is valid format\n");
			else
				ft_printf("[Camara] Orientation is NOT VALID format\n");
			if (isfov(aelement[3]))
				ft_printf("[Camara] FOV is valid format\n");
			else
				ft_printf("[Camara] FOV is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_CAMARA);
}
