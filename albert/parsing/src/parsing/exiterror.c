#include "minirt.h"

void	exiterror(char *msg)
{
	perror(msg);
	exit (EXIT_FAILURE);
}
