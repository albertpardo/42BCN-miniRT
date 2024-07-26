#include "minirt.h"

#define CHAR_MAX_RGB "255"
#define CHAR_MAX_FOV "180"
#define INT_NUMDIGITS 3
#define MIN_INT_VALUE 0

static int alldigits(char *str)
{
	char *tmp;

	tmp = str;
	while (tmp != NULL && *tmp != '\0' && ft_isdigit(*tmp))
		tmp++;
	if (tmp != str  && *tmp == '\0')
	   return (1);
	return (0);	
}

/*
 * True if str is a integer >= 0 and <= 'maxintval'
 *
 */

int	isstringvalueinpositiverange(char *str, char *maxintval)
{
	int	len_str;
	int	len_max;

	len_str = ft_strlen(str);
	len_max = ft_strlen(maxintval);
	if (len_str <= len_max && alldigits(str)) 
		if (len_str == len_max && ft_strncmp(str, maxintval, len_max) <= 0)
			return (1);
	return (0);
}


void	printest(char *str)
{
	printf("-----------------------\n");
	printf("alldigits(%s) = %d\n", str, alldigits(str));
	printf("isstrintvalueinpositiverange(%s, %s) = %d\n", str, CHAR_MAX_RGB, isstringvalueinpositiverange(str, CHAR_MAX_RGB));
	printf("isstrintvalueinpositiverange(%s, %s) = %d\n", str, CHAR_MAX_FOV, isstringvalueinpositiverange(str, CHAR_MAX_FOV));
}

int	main(void)
{

	printest("0");
	printest("123");
	printest("180");
	printest("181");
	printest("255");
	printest("256");
	printest("256");
	printest("+200");
	printest("2.56");
	printest("");
	printest("a");

	
	return (0);
}
