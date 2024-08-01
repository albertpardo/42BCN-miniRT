#include "minirt.h"

void	checkcy(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is cilinder\n");
		if (ft_astrlen(aelement) == 6)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Cylinder] Center is valid format\n");
			else
				ft_printf("[Cylinder] Center is NOT VALID format\n");
			if (isorientnormal(aelement[2]))
				ft_printf("[Cylinder] Normalized Vector is valid format\n");
			else
				ft_printf("[Cylinder] Normalized Vector is NOT VALID format\n");
// Change to only positive float
			if (isstrsgnfloat(aelement[3]))
				ft_printf("[Cylinder] Diameter is valid format\n");
			else
				exiterror("[Cylinder] Diameter is NOT VALID format\n");
// Change to only positive float
			if (isstrsgnfloat(aelement[4]))
				ft_printf("[Cylinder] Height is valid format\n");
			else
				exiterror("[Cylinder] Height is NOT VALID format\n");
			if (isrgbstr(aelement[5]))
				ft_printf("[Cylinder] RGB is valid format\n");
			else
				exiterror("[Cylinder] RGB is NOT VALID forimat\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_PLANE);
}
	
