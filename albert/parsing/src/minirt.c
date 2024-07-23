#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

#define	BAD_ARGUMENTS "BAD ARGUMETS. Use : ./minirt NAME.rt"
#define NO_OPEN "open() failed"
#define NO_CLOSE "\nclose() failed" 
#define MALLOC_ERROR "Memory assignament ERROR"

void	exiterror(char *msg)
{
	perror(msg);
	exit (EXIT_FAILURE);
}

void	exitifcheckfails(int val, char *msg)
{
	if (val == -1)
		exiterror(msg);
}

int		ft_isspace(const char c)
{
	return ( c == ' ' || c == '\t');
}

/*
 * char	*cleanStringSpaces(char *str)
 *
 *	- flag : used to know if last get char is '.' or ','
 *
 *	Steps:
 *	1 - Avoid initial spaces in 'str'
 *	2 - until of 'str'
 *		- get no space chars
 *		- set 'flag' if las char is '.' or ','
 *		- avoid spaces
 *		- to put space check : flag == 0 && (isdigit(char) || char == '+' || char == '-')
 *
 */

char	*cleanStringSpaces(char *str)
{
	int		i;
	int		j;
	int		flag;
	char	*tmpstr;

	flag = 0;
	i = 0;
	j = 0;
	tmpstr = ft_calloc(1, ft_strlen(str));
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
			if (str[i] != '\0' && flag == 0 && (ft_isdigit(str[i]) || str[i] == '+'))
				tmpstr[j++] = ' ';
		}
	}
	else
		exiterror(MALLOC_ERROR);
	return (tmpstr);
}

void	putArrayStr(char ** arrstr)
{
	ft_printf("\nArray de string de la linea sin spaces: \n");
	while (arrstr && *arrstr)
	{
		ft_printf("%s\n", *arrstr);
		arrstr++;
	}
}


int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	char	*cleanline;
	char 	**splitline;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		exitifcheckfails(fd, NO_OPEN);
		line = get_next_line(fd);
  		while (line)
		{
			cleanline = cleanStringSpaces(line);
			ft_printf("Linea Original  >%s", line);
			ft_printf("Linea sin spaces>%s", cleanline);
			splitline = ft_split(cleanline, ' ');
			putArrayStr(splitline);
			free(cleanline);
			free(line);
			line = get_next_line(fd);
		}
		exitifcheckfails(close(fd), NO_CLOSE);
	}
	else
		exiterror(BAD_ARGUMENTS);
	return (0);
}
