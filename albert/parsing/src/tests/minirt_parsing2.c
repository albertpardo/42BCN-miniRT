#include "minirt.h"

void	putarraystr(char **arrstr)
{
	ft_printf("\nArray de strings de la linea sin extra spaces: \n");
	while (arrstr && *arrstr)
	{
		ft_printf("%s\n", *arrstr);
		arrstr++;
	}
}

void	checka(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is Ambient\n");
		if (ft_astrlen(aelement) == 3)
			ft_printf("TODO check each type element Ambient\n");
		else
			exiterror(ERR_NUM_TYPELEM_AMBIENT);
}

void	checkid(char **aelement)
{
	int	len;

	ft_printf("\t>> Check id :\n");
	len = ft_strlen(aelement[0]);
	if (len == 1 && ft_strncmp(aelement[0], "A", len) == 0)
//		ft_printf("Element is Ambient\n");
		checka(aelement);
	else
		ft_printf("TODO evaluate this element\n");
}

void	checkidvalid(char **elem)
{
	printf("\n>> checkidvalid(...) :\n");
	if (elem != NULL && *elem != NULL)
	{
		if (ft_isstralpha(elem[0]))
			checkid(elem);
		else
			exiterror(ID_ERROR_NOALPHA);
	}
	else
		exiterror(NO_ELEMENT);
}

/*
 *
 * - i : counter for total file lines
 * - j : counter for no lines equal to "\0" or "\n"
 */

int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	char	*cleanstr;
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
			cleanstr = cleanstringspaces(line);
			if (cleanstr[0] != '\0' && cleanstr[0] != '\n')
				j++;
			ft_printf("--------------------------------------------\n");
			ft_printf("Linea Original  >%s", line);
			ft_printf("Del extra spaces>%s", cleanstr);
			splitline = ft_split(cleanstr, ' ');
			putarraystr(splitline);
			checkidvalid(splitline);
			freearrstr(splitline);
			free(cleanstr);
			free(line);
			line = get_next_line(fd);
		}
		exitifcheckfails(close(fd), NO_CLOSE);
		if (i == 0)
			exiterror(EMPTY_FILE);
		else if (j == 0)
			exiterror(SPACES_IN_FILE);
	}
	else
		exiterror(BAD_ARGUMENTS);
	return (0);
}
