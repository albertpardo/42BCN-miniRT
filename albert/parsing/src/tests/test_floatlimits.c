#include "minirt.h"
#include "float.h"

//i					 1         2         3
//            12345678901234567890123456789012345678 
// FLT_MAX : 340282346638528859811704183484516925440.000000

int		main(void)
{
		
	printf("----Extrated from -> https://en.cppreference.com/w/c/types/limits\n");
    printf("DECIMAL_DIG     = %d\n", DECIMAL_DIG);
    printf("FLT_DECIMAL_DIG = %d\n", FLT_DECIMAL_DIG);
    printf("FLT_RADIX       = %d\n", FLT_RADIX);
    printf("FLT_MIN         = %e\n", FLT_MIN);
    printf("FLT_MAX         = %e\n", FLT_MAX);
    printf("FLT_EPSILON     = %e\n", FLT_EPSILON);
    printf("FLT_DIG         = %d\n", FLT_DIG);
    printf("FLT_MANT_DIG    = %d\n", FLT_MANT_DIG);
    printf("FLT_MIN_EXP     = %d\n", FLT_MIN_EXP);
    printf("FLT_MIN_10_EXP  = %d\n", FLT_MIN_10_EXP);
    printf("FLT_MAX_EXP     = %d\n", FLT_MAX_EXP);
    printf("FLT_MAX_10_EXP  = %d\n", FLT_MAX_10_EXP);
    printf("FLT_ROUNDS      = %d\n", FLT_ROUNDS);
    printf("FLT_EVAL_METHOD = %d\n", FLT_EVAL_METHOD);
    printf("FLT_HAS_SUBNORM = %d\n", FLT_HAS_SUBNORM);
	
	printf("\n----- My evaluation ---\n");
	printf("FLT_MAX                    :  %f\n", FLT_MAX); 
	printf("FLT_MIN                    :  %f\n", FLT_MIN); 
	printf("FLT_NEG                    : %f\n", -FLT_MAX); 

	printf("ft_atof(string(FLT_MAX)    :  %f\n", ft_atof("340282346638528859811704183484516925440")); 
	printf("ft_atof(string(-FLT_MAX)   : %f\n", ft_atof("-340282346638528859811704183484516925440.0"));
	printf("\nusando 'ft_atof' para un string > FLTMAX\n");
	printf("ft_atof(string(>FLT_MAX)   :  %f\n", ft_atof("340282429999999999999999999999999999999")); 
	printf("ft_atof(string(<-FLT_MAX)  : %f\n", ft_atof("-340282429999999999999999999999999999999")); 
	printf("\nObtengo 'inf' para 3.4028243e+38 al usar printf\n");
	printf("ft_atof(string(>FLT_MAX)   :  %f\n", ft_atof("340282430000000000000000000000000000000")); 
	printf("ft_atof(string(<-FLT_MAX)  : %f\n", ft_atof("-340282430000000000000000000000000000000")); 
}
