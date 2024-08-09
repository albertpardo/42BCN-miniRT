/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsceneorexit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:58:55 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/09 14:07:39 by apardo-m         ###   ########.fr       */
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
 * nodupsorexit(t_pars *pars, t_sceneinf *scn, int fd)
 *
 * If A, C or L appear more than onces EXIT
 *
 */

static void	nodupsorexit(t_pars *pars, t_sceneinf *scn, int fd)
{
	if (ft_strlen(pars->astr[0]) == 1)
	{
		if (pars->astr[0][0] == 'A' && scn->amb.isset)
		{
			while (pars->ln != NULL)
			{
				free(pars->ln);
				pars->ln = get_next_line(fd);
			}
			freesplitcleanscenefd(pars->astr, pars->cln, scn, fd);
			exiterror(ERR_DUP_AMB);
		}
		if (pars->astr[0][0] == 'C' && scn->cam.isset)
		{
			while (pars->ln != NULL)
			{
				free(pars->ln);
				pars->ln = get_next_line(fd);
			}
			free(pars->ln);
			freesplitcleanscenefd(pars->astr, pars->cln, scn, fd);
			exiterror(ERR_DUP_CAM);
		}
		if (pars->astr[0][0] == 'L' && scn->light.isset)
		{
			while (pars->ln != NULL)
			{
				free(pars->ln);
				pars->ln = get_next_line(fd);
			}
			free(pars->ln);
			freesplitcleanscenefd(pars->astr, pars->cln, scn, fd);
			exiterror(ERR_DUP_LIG);
		}
	}
}

/*
 * setsceneandgnl(int fd, t_sceneinf *scn, t_pars *pars)
 * 
 * set scene and new line in 't_pars pars'
 *
 * Exit for any error.
 *
 */

static void	setsceneandgnl(int fd, t_sceneinf *scn, t_pars *pars)
{
	char	*str;

	pars->astr = ft_split(pars->cln, ' ');
	if (pars->astr)
	{
		putarraystr(pars->astr);
		if (iselement(pars->astr))
		{
			nodupsorexit(pars, scn, fd);
			setelementinscene(pars->astr, scn);
			freearrstr(pars->astr);
			pars->ln = freecleanlineandgetnl(pars->cln, pars->ln, fd);
		}
		else
		{
			str = ft_strdup(pars->ln);
			while (pars->ln != NULL)
			{
				free(pars->ln);
				pars->ln = get_next_line(fd);
			}
			freesplitcleanscenefd(pars->astr, pars->cln, scn, fd);
			exiterrorfreemsg(str);
		}
	}
	else
	{
		free(pars->astr);
		freelinscenfdexitbymalloc(pars->ln, scn, fd);
	}
}

/*
 * setscenefromfd(int fd, t_sceneinf *scene)
 *
 * - i : counter for total file lines
 * - j : countier for no lines equal to "\0" or "\n"
 *
 * Set scene or Exit for empty file or file with only spaces  
 */

static void	setscenefromfd(int fd, t_sceneinf *scene)
{
	t_pars	pars;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_memset(&pars, 0, sizeof(t_pars));
	pars.ln = get_next_line(fd);
	while (pars.ln)
	{
		i++;
		pars.cln = cleanstringspaces(pars.ln);
		if (pars.cln == NULL)
			freelinscenfdexitbymalloc(pars.ln, scene, fd);
		if (pars.cln[0] != '\0')
		{
			j++;
			setsceneandgnl(fd, scene, &pars);
		}
		else
			pars.ln = freecleanlineandgetnl(pars.cln, pars.ln, fd);
	}
	exitifcheckfails(close(fd), NO_CLOSE);
	exitifemptyfileoronlyspaces(i, j, scene);
}

/*
 * void	setsceneorexit(int argc, char *scfile, t_sceneinf *scene)
 *
 * scfile : scene file with extension 'rt'
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
