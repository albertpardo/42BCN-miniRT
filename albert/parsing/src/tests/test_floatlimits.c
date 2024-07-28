#include "minirt.h"
#include "float.h"
//3.402823466e+38F
//i						 1         2         3
//             12345678901234567890123456789012345678 
// CFLT_MAX : 340282346638528859811704183484516925440.000000

int		main(void)
{
	float	fl;
	float	f2;
	float	f3;
	int 	i;
	i = 0;
	fl = FLT_MAX;
	printf("\nCheck float : %f\n", ft_atof("11.234")); 
	printf("\n  CFLT_MAX : %f\n", fl); 
	fl = fl - 1.0f;
	printf("\n--CFLT_MAX : %f\n", fl); 
	f2 = 1.01f;
	printf("\n%i, f2 : %f\n", ++i, f2); 
	f2 += .0000005f;
	printf("\n%i, f2 : %f\n", ++i, f2); 
	f2 += .0000005f;
	printf("\n%i, f2 : %f\n", ++i, f2); 
	f2 = 340282346638528859811704183484516925430.0f;
	printf("\n%i, f2 : %f\n", ++i, f2);
	printf("---\n");
	f3 = 3.402823466e+38f;	
	printf("\n%i, f3 : %f\n", ++i, f3); 
	f3 = 3.40282346e+38f;	
	printf("\n%i, f3 : %f\n", ++i, f3); 
	f3 = 3.4028234e+38f;	
	printf("\n%i, f3 : %f\n", ++i, f3); 
	f2 = 3.402823e+38f;	
	printf("\n%i,   f2 : %f\n", ++i, f2); 
	f3 = 3.4e+38f;	
	printf("\n%i,   f3 : %f\n", ++i, f3);
	printf("Diff f2-f3 : %f\n", f2 -f3);
	printf("---\n");
	f2 = 340000000000000000000000000000000000000.f;
	printf("\n%i, f2 : %f\n", ++i, f2); 
	f2 = 330000000000000000000000000000000000000.f;
	printf("\n%i, f2 : %f\n", ++i, f2); 
}
