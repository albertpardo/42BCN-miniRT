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
	int		i;
	int		j;

	if (argc == 2)
	{
		i = 0;
		j = 0;
		exitifnotvalidfiletype(argv[1], EXT, BAD_FILETYPE);
		fd = open(argv[1], O_RDONLY);
		exitifcheckfails(fd, NO_OPEN);
		line = get_next_line(fd);
  		while (line)
		{
			i++;
			cleanline = cleanstringspaces(line);
			if (cleanline[0] != '\0' && cleanline[0] != '\n')
				j++;
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
		if (i == 0)
			printf("Empty file\n");
		else if (j == 0)
			printf("File only with 'spaces' and/or '\\t' and '\\n'");
		printf("\nCheck float : %f\n", ft_atof("11.234")); 
	}
	else
		exiterror(BAD_ARGUMENTS);
	return (0);
}
