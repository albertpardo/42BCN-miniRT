#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

#define	BAD_ARGUMENTS "BAD ARGUMETS. Use : ./minirt NAME.rt"
#define NO_OPEN "open() failed"
#define NO_CLOSE "\nclose() failed" 

void exitifcheckfails(int val, char *msg)
{
	if (val == -1)
	{
		perror(msg);
		exit (EXIT_FAILURE);
	}
}

int main(int argc, char *argv[])
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
			ft_printf("%s",line);
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
