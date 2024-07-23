#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

#define	BAD_ARGUMENTS "BAD ARGUMETS. Use : ./minirt NAME.rt"
#define NO_OPEN "open() failed"
#define NO_CLOSE "\nclose() failed" 

void	exitifcheckfails(int val, char *msg)
{
	if (val == -1)
	{
		perror(msg);
		exit (EXIT_FAILURE);
	}
}

int		ft_isspace(const char c)
{
	return ( c == ' ' || c == '\t');
}

/*
 *   void	putWithOneSpace(char *str)
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

void	putWithOneSpace(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	while (str[i] != '\0')
	{
		flag = 0;
		while (str[i] != '\0' && ! ft_isspace(str[i]))
			ft_putchar(str[i++]);
		if (str[i -1 ] == ',' || str[i - 1] == '.')
			flag = 1;
		while (str[i] != '\0' && ft_isspace(str[i]))
			i++;
		if (str[i] != '\0' && flag == 0 && (ft_isdigit(str[i]) || str[i] == '+'))
			ft_putchar(' ');
	}
}

int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		exitifcheckfails(fd, NO_OPEN);
		line = get_next_line(fd);
  		while (line)
		{
			ft_printf("Linea Original  >%s",line);
			ft_putstr("Linea sin spaces>");
			putWithOneSpace(line);
			free(line);
			line = get_next_line(fd);
		}
		exitifcheckfails(close(fd), NO_CLOSE);
	}
	else
	{
		perror(BAD_ARGUMENTS);
		return (1);
	}
	return (0);
}
