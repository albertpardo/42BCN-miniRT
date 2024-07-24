#include "minirt.h"

void	exitifcheckfails(int val, char *msg)
{
	if (val == -1)
		exiterror(msg);
}
