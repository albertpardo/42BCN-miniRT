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

/*
void	checka(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is Ambient\n");
		if (ft_astrlen(aelement) == 3)
		{
			if (isstrfloatcerone(aelement[1]))
				ft_printf("[Ambient] Scale is valid format\n");
			else
				exiterror("[Ambient] Scale is NOT VALID format\n");
			if (isrgbstr(aelement[2]))
				ft_printf("[Ambient] RGB is valid format\n");
			else
				exiterror("[Ambient] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_AMBIENT);
}

void	checkc(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is Camara\n");
		if (ft_astrlen(aelement) == 4)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Camara] Viewport is valid format\n");
			else
				ft_printf("[Camara] Viewport is NOT VALID format\n");
			if (isorientnormal(aelement[2]))
				ft_printf("[Camara] Orientation is valid format\n");
			else
				ft_printf("[Camara] Orientation is NOT VALID format\n");
			if (isfov(aelement[3]))
				ft_printf("[Camara] FOV is valid format\n");
			else
				ft_printf("[Camara] FOV is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_CAMARA);
}

void	checkl(char **aelement)
{
		char	*id;
		int		l;

		id = aelement[0];
		ft_printf("Element is Light\n");
		l = ft_astrlen(aelement);
		if (l == 3)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Light] Lightpoint is valid format\n");
			else
				ft_printf("[Light] Lightpoint is NOT VALID format\n");
			if (isstrfloatcerone(aelement[2]))
				ft_printf("[Light] Bright Ratio is valid format\n");
			else
				exiterror("[Light] Bright Ratio is NOT VALID format\n");
		}
		else if (l == 4)
		{
			if (isrgbstr(aelement[3]))
				ft_printf("[Light] RGB is valid format\n");
			else
				exiterror("[Light] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_LIGHT);
}

void	checksp(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is sphere\n");
		if (ft_astrlen(aelement) == 4)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Sphere] Center is valid format\n");
			else
				ft_printf("[Sphere] Center is NOT VALID format\n");
// Change to only positive float
			if (isstrsgnfloat(aelement[2]))
				ft_printf("[Sphere] Diameter is valid format\n");
			else
				exiterror("[Sphere] Diameter is NOT VALID format\n");
			if (isrgbstr(aelement[3]))
				ft_printf("[Sphere] RGB is valid format\n");
			else
				exiterror("[Sphere] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_SPHERE);
}

void	checkcy(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is cilinder\n");
		if (ft_astrlen(aelement) == 6)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Cylinder] Center is valid format\n");
			else
				ft_printf("[Cylinder] Center is NOT VALID format\n");
			if (isorientnormal(aelement[2]))
				ft_printf("[Cylinder] Normalized Vector is valid format\n");
			else
				ft_printf("[Cylinder] Normalized Vector is NOT VALID format\n");
// Change to only positive float
			if (isstrsgnfloat(aelement[3]))
				ft_printf("[Cylinder] Diameter is valid format\n");
			else
				exiterror("[Cylinder] Diameter is NOT VALID format\n");
// Change to only positive float
			if (isstrsgnfloat(aelement[4]))
				ft_printf("[Cylinder] Height is valid format\n");
			else
				exiterror("[Cylinder] Height is NOT VALID format\n");
			if (isrgbstr(aelement[5]))
				ft_printf("[Cylinder] RGB is valid format\n");
			else
				exiterror("[Cylinder] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_PLANE);
}

void	checkpl(char **aelement)
{
		char	*id;

		id = aelement[0];
		ft_printf("Element is plane\n");
		if (ft_astrlen(aelement) == 4)
		{
			if (iscoordinatestr(aelement[1]))
				ft_printf("[Plane] Point in Plane is valid format\n");
			else
				ft_printf("[Plane] Point in Plane is NOT VALID format\n");
			if (isorientnormal(aelement[2]))
				ft_printf("[Plane] Normalized Normal is valid format\n");
			else
				ft_printf("[Plane] Normalized Normal is NOT VALID format\n");
			if (isrgbstr(aelement[3]))
				ft_printf("[Plane] RGB is valid format\n");
			else
				exiterror("[Plane] RGB is NOT VALID format\n");
		}
		else
			exiterror(ERR_NUM_TYPELEM_PLANE);
}

void	checkid(char **aelement)
{
	int	len;

	ft_printf("\t>> Check id :\n");
	len = ft_strlen(aelement[0]);
	if (len == 1 && ft_strncmp(aelement[0], "A", len) == 0)
		checka(aelement);
	else if (len == 1 && ft_strncmp(aelement[0], "C", len) == 0)
		checkc(aelement);
	else if (len == 1 && ft_strncmp(aelement[0], "L", len) == 0)
		checkl(aelement);
	else if (len == 2 && ft_strncmp(aelement[0], "sp", len) == 0)
		checksp(aelement);
	else if (len == 2 && ft_strncmp(aelement[0], "pl", len) == 0)
		checkpl(aelement);
	else if (len == 2 && ft_strncmp(aelement[0], "cy", len) == 0)
		checkcy(aelement);
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
//	else
//		exiterror(NO_ELEMENT);
}
*/


static void exitifemptyfileoronlyspaces(int i, int j)
{
	if (i == 0)
		exiterror(EMPTY_FILE);
	else if (j == 0)
		exiterror(SPACES_IN_FILE);
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
		exitifemptyfileoronlyspaces(i, j);
	}
	else
		exiterror(BAD_ARGUMENTS);
	return (0);
}
