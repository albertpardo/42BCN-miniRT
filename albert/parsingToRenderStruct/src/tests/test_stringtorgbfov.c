#include "minirt.h"

void	printest(char *str)
{
	printf("-----------------------\n");
	printf("isstrintvalueinpositiverange(%s, %s) = %d\n", str, CHAR_MAX_RGB, isstringvalueinpositiverange(str, CHAR_MAX_RGB));
	printf("isstrintvalueinpositiverange(%s, %s) = %d\n", str, CHAR_MAX_FOV, isstringvalueinpositiverange(str, CHAR_MAX_FOV));
}

int	main(void)
{
// Valid (depens max range)
	printest("0");
	printest("00");
	printest("000");
	printest("123");
	printest("180");
	printest("181");
	printest("255");
	printest("256");
	printest("256");
// No valid
	printest("+20");
	printest("2.56");
	printest("");
	printest("a");
	printest("424242");
	printest("-1002");
	
	return (0);
}
