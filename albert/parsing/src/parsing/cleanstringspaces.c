#include "minirt.h"

/*
 * char	*cleanStringSpaces(char *str)
 *
 *	- flag : used to know if last get char is '.' or ','
 *
 *	Steps:
 *	1 - Avoid initial spaces in 'str'
 *	2 - until of 'str'
 *		- get no space chars
 *		- set 'flag' if last char is '.' or ','
 *		- avoid spaces
 *		- to put space check : flag == 0 && char != ',' && char != '.' && isprint(char))
 *
 */

char	*cleanstringspaces(char *str)
{
	int		i;
	int		j;
	int		flag;
	char	*tmpstr;

	flag = 0;
	i = 0;
	j = 0;
	tmpstr = ft_calloc(1, ft_strlen(str) + 1);
	if (tmpstr)
	{
		while (str[i] != '\0' && ft_isspace(str[i]))
			i++;
		while (str[i] != '\0')
		{
			flag = 0;
			while (str[i] != '\0' && ! ft_isspace(str[i]))
			tmpstr[j++] = str[i++];
			if (str[i -1 ] == ',' || str[i - 1] == '.')
				flag = 1;
			while (str[i] != '\0' && ft_isspace(str[i]))
				i++;
			//if (str[i] != '\0' && flag == 0 && (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')   )
			if (str[i] != '\0' && flag == 0 && str[i] != ',' && str[i] != '.' && ft_isprint(str[i]))
				tmpstr[j++] = ' ';
		}
	}
	else
		exiterror(MALLOC_ERROR);
	return (tmpstr);
}
