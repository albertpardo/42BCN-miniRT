#include "miniRT.h"

t_vector3	ambient_light(int flag, t_vector3 new)
{
	static t_vector3	light = (t_vector3) {0, 0, 0};
	
	if (flag == 1)
		light = new;
	return (light);
}
