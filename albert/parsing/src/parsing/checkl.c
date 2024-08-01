#include "minirt.h"

void	checkl(char **aelement)
{
		char	*id;
		int		l;

		id = aelement[0];
		ft_printf("Element is Light\n");
		l = ft_astrlen(aelement);
		if (l == 3)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Light] Lightpoint is valid format\n");
			else
				ft_printf("[Light] Lightpoint is NOT VALID format\n");
			if (isstrfloatcerone(aelement[2]))
				ft_printf("[Light] Bright Ratio is valid format\n");
			else
				exiterror("[Light] Bright Ratio is NOT VALID format\n");
		}
		else if (l == 4)
		{
			if (isrgbstr(aelement[3]))
				ft_printf("[Light] RGB is valid format\n");
			else
				exiterror("[Light] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_LIGHT);
}
