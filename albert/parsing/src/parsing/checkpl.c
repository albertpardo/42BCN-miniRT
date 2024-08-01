#include "minirt.h"

void	checkpl(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is plane\n");
		if (ft_astrlen(aelement) == 4)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Plane] Point in Plane is valid format\n");
			else
				ft_printf("[Plane] Point in Plane is NOT VALID format\n");
			if (isorientnormal(aelement[2]))
				ft_printf("[Plane] Normalized Normal is valid format\n");
			else
				ft_printf("[Plane] Normalized Normal is NOT VALID format\n");
			if (isrgbstr(aelement[3]))
				ft_printf("[Plane] RGB is valid format\n");
			else
				exiterror("[Plane] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_PLANE);
}
