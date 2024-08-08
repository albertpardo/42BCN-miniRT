/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsceneorexit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:58:55 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/08 16:27:06 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "testaux.h"

static void	exitifemptyfileoronlyspaces(int i, int j, t_sceneinf *scene)
{
	if (i == 0 || j == 0)
		clearscene(scene);
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

//  TODO Error when a file Has A > 1 , or C > 1 or L > 1 

/*
static void	setscenefromfd(int fd, t_sceneinf *scene)
{
	char	*line;
	char	*cleanstr;
	char	**splitline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		cleanstr = cleanstringspaces(line);
		if (cleanstr)
		{
			//if (cleanstr[0] != '\0' && cleanstr[0] != '\n')
			if (cleanstr[0] != '\0')
			{
				j++;
				ft_printf("--------------------------------------------\n");
				ft_printf("Linea Original  >%s", line);
				ft_printf("Del extra spaces>%s", cleanstr);
				splitline = ft_split(cleanstr, ' ');
				if (splitline)
				{
					putarraystr(splitline);
					if (iselement(splitline))
					{
						printf("\nElement is OK!\n");
						setelementinscene(splitline, scene);
						freearrstr(splitline);
						free(cleanstr);
						free(line);
						line = get_next_line(fd);
					}
					else
					{
						freearrstr(splitline);
						free(cleanstr);
						clearscene(scene);
						close(fd);
						exiterrorfreemsg(line);
					}
				}
				else
				{
					free(cleanstr);
					free(line);
					clearscene(scene);
					close(fd);
					exiterror(MALLOC_ERROR);
				}
			}
			else
			{
				free(cleanstr);
				free(line);
				line = get_next_line(fd);
			}
		}
		else
		{
			free(line);
			clearscene(scene);
			close(fd);
			exiterror(MALLOC_ERROR);
		}
		freelinscenfdexitbymalloc(line, scene, fd);

	}
	exitifcheckfails(close(fd), NO_CLOSE);
	exitifemptyfileoronlyspaces(i, j, scene);
}
*/

/*
static void	setscenefromfd(int fd, t_sceneinf *scene)
{
	char	*line;
	char	*cleanstr;
	char	**splitline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		cleanstr = cleanstringspaces(line);
		if (cleanstr)
		{
			if (cleanstr[0] != '\0')
			{
				j++;
				splitline = ft_split(cleanstr, ' ');
				if (splitline)
				{
					putarraystr(splitline);
					if (iselement(splitline))
					{
						setelementinscene(splitline, scene);
						freearrstr(splitline);
						free(cleanstr);
						free(line);
						line = get_next_line(fd);
					}
					else
					{
						freearrstr(splitline);
						free(cleanstr);
						clearscene(scene);
						close(fd);
						exiterrorfreemsg(line);
					}
				}
				else
				{
					free(cleanstr);
					freelinscenfdexitbymalloc(line, scene, fd);
				}
			}
			else
			{
				free(cleanstr);
				free(line);
				line = get_next_line(fd);
			}
		}
		else
			freelinscenfdexitbymalloc(line, scene, fd);
	}
	exitifcheckfails(close(fd), NO_CLOSE);
	exitifemptyfileoronlyspaces(i, j, scene);
}
*/

/*
 *
 * TODO Muchos argumentos
 *
 * EXIT if Ambient, Camara or Light is duplicated.
 *
 */

static void	nodupsorexit(char **aelem, t_sceneinf *scn, char *ln, char *clnstr, int fd)
{
	if (ft_strlen(aelem[0]) == 1)
	{
		if (aelem[0][0] == 'A' && scn->amb.isset)
		{
			free(ln);
			freesplitcleanscenefd(aelem, clnstr, scn, fd);
			exiterror(ERR_DUP_AMB);
		}
		if (aelem[0][0] == 'C' && scn->cam.isset)
		{
			free(ln);
			freesplitcleanscenefd(aelem, clnstr, scn, fd);
			exiterror(ERR_DUP_CAM);
		}
		if (aelem[0][0] == 'L' && scn->light.isset)
		{
			free(ln);
			freesplitcleanscenefd(aelem, clnstr, scn, fd);
			exiterror(ERR_DUP_LIG);
		}
	}
}

static void	setsceneandgnl(char *cleanstr, t_sceneinf *scn, char **line, int fd)
{
	char	**aelem;

	aelem = ft_split(cleanstr, ' ');
	if (aelem)
	{
		putarraystr(aelem);
		if (iselement(aelem))
		{
			nodupsorexit(aelem, scn, *line, cleanstr, fd);
			setelementinscene(aelem, scn);
			freearrstr(aelem);
			*line = freecleanlineandgetnl(cleanstr, *line, fd);
		}
		else
		{
			freesplitcleanscenefd(aelem, cleanstr, scn, fd);
			exiterrorfreemsg(*line);
		}
	}
	else
	{
		free(cleanstr);
		freelinscenfdexitbymalloc(*line, scn, fd);
	}
}

static void	setscenefromfd(int fd, t_sceneinf *scene)
{
	char	*line;
	char	*cleanstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		cleanstr = cleanstringspaces(line);
		if (cleanstr == NULL)
			freelinscenfdexitbymalloc(line, scene, fd);
		if (cleanstr[0] != '\0')
		{
			j++;
			setsceneandgnl(cleanstr, scene, &line, fd);
		}
		else
			line = freecleanlineandgetnl(cleanstr, line, fd);
	}
	exitifcheckfails(close(fd), NO_CLOSE);
	exitifemptyfileoronlyspaces(i, j, scene);
}

/*
 * void	setsceneorexit(int argc, char *scfile, t_sceneinf *scene)
 * If file is right sceneinfo is created
 *
 * else put error and exit
 */

void	setsceneorexit(int argc, char *scfile, t_sceneinf *scene)
{
	int	fd;

	if (argc == 2)
	{
		exitifnotvalidfiletype(scfile, EXT, BAD_FILETYPE);
		fd = open(scfile, O_RDONLY);
		exitifcheckfails(fd, NO_OPEN);
		printf("==== Initiaize empty scene ====");
		ft_memset(scene, 0, sizeof(t_sceneinf));
		putsceneinfoinline(scene);
		setscenefromfd(fd, scene);
	}
	else
		exiterror(BAD_ARGUMENTS);
}
