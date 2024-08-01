#include "minirt.h"

void	checka(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is Ambient\n");
		if (ft_astrlen(aelement) == 3)
		{
			if (isstrfloatcerone(aelement[1]))
				ft_printf("[Ambient] Scale is valid format\n");
			else
				exiterror("[Ambient] Scale is NOT VALID format\n");
			if (isrgbstr(aelement[2]))
				ft_printf("[Ambient] RGB is valid format\n");
			else
				exiterror("[Ambient] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_AMBIENT);
}
