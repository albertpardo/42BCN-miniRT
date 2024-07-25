#include "minirt.h"

void	putarraystr(char ** arrstr)
{
	ft_printf("\nArray de strings de la linea sin extra spaces: \n");
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
		exitifnotvalidfiletype(argv[1], EXT, BAD_FILETYPE);
		fd = open(argv[1], O_RDONLY);
		exitifcheckfails(fd, NO_OPEN);
		line = get_next_line(fd);
  		while (line)
		{
			cleanline = cleanstringspaces(line);
			ft_printf("--------------------------------------------\n");
			ft_printf("Linea Original  >%s", line);
			ft_printf("Del extra spaces>%s", cleanline);
			splitline = ft_split(cleanline, ' ');
			putarraystr(splitline);
			freearrstr(splitline);
			free(cleanline);
			free(line);
			line = get_next_line(fd);
		}
		exitifcheckfails(close(fd), NO_CLOSE);
		printf("\nCheck float : %f\n", ft_atof("11.234")); 
	}
	else
		exiterror(BAD_ARGUMENTS);
	return (0);
}
