#include "minirt.h"

void	checksp(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is sphere\n");
		if (ft_astrlen(aelement) == 4)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Sphere] Center is valid format\n");
			else
				ft_printf("[Sphere] Center is NOT VALID format\n");
// Change to only positive float
			if (isstrsgnfloat(aelement[2]))
				ft_printf("[Sphere] Diameter is valid format\n");
			else
				exiterror("[Sphere] Diameter is NOT VALID format\n");
			if (isrgbstr(aelement[3]))
				ft_printf("[Sphere] RGB is valid format\n");
			else
				exiterror("[Sphere] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_SPHERE);
}
