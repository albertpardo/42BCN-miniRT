#include "miniRT.h"

void	putintersection(t_intersection *intersec)
{
	printf("\n-- putintersection(t_intersection *intersec)-- \n");
	printf("hit = %d\n", intersec->hit);
	printf("objindex = %d\n", intersec->objindex);
	printf("distance = %f\n", intersec->distance);
	printf("point = (%f, %f, %f)\n", intersec->point.x, intersec->point.y, intersec->point.z);
	printf("normal = (%f, %f, %f)\n", intersec->normal.x, intersec->normal.y, intersec->normal.z);
	printf("rawnormal = (%f, %f, %f)\n", intersec->rawnormal.x, intersec->rawnormal.y, intersec->rawnormal.z);
	printf("tnear = %f\n", intersec->tnear);

}
