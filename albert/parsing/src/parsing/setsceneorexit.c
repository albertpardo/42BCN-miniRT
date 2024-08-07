/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsceneorexit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:58:55 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/07 11:53:08 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "testaux.h"

static void	exitifemptyfileoronlyspaces(int i, int j)
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
			if (cleanstr[0] != '\0' && cleanstr[0] != '\n')
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
				}
				else
				{
					freearrstr(splitline);
					free(cleanstr);
					//free(line);
					clearscene(scene);
					//exiterror("KO! Element error");
					exiterrorfreemsg(line);
				}
				freearrstr(splitline);
				free(cleanstr);
				free(line);
				line = get_next_line(fd);
			}
			else
			{
				free(cleanstr);
				free(line);
				printf("TODO : free scene en exit with error?");
			}
		}
		else
		{
			free(line);
			printf("TODO : free scene en exit with error");
		}
	}
	exitifcheckfails(close(fd), NO_CLOSE);
	exitifemptyfileoronlyspaces(i, j);
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
