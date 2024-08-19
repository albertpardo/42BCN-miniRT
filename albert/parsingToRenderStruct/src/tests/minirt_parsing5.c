#include "minirt.h"
#include "testaux.h"

int		main(int argc, char *argv[])
{
	t_sceneinf	scene;

	setsceneorexit(argc, argv[1], &scene);
	printf("\n ==== Scene Width valid Values ====");
	//putsceneinfo(&scene);
	putsceneinfoinline(&scene);
	clearscene(&scene);
	return (0);
}
