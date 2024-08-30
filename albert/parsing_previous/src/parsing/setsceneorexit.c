/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setsceneorexit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:58:55 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/13 10:22:24 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "testaux.h"

/*
 * - i : counter for total lines in file
 * - j : counter for lines NO equal to "\0" or "\n"
 *
 *	EXIT if:
 *	- Empty file
 *	- File with only spaces and/or tabs
 */

/*
static void	exitifemptyspaces(int i, int j, t_sceneinf *scene)
{
	if (i == 0 || j == 0)
		clearscene(scene);
	if (i == 0)
		exiterror(EMPTY_FILE);
	else if (j == 0)
		exiterror(SPACES_IN_FILE);
}
*/

/*
 * - i : counter for total lines in file
 * - j : counter for lines NO equal to "\0" or "\n"
 *
 *	EXIT if:
 *	- Empty file
 *	- File with only spaces and/or tabs
 *  - If Ambient, Camara or Ligth is not defined in the file.
 */

static void	exitifemptyspacesnoacl(int i, int j, t_sceneinf *scn)
{
	if (i == 0 || j == 0 || !scn->amb.isset || !scn->cam.isset || \
			!scn->light.isset)
	{
		clearscene(scn);
		if (i == 0)
			exiterror(EMPTY_FILE);
		else if (j == 0)
			exiterror(SPACES_IN_FILE);
		else if (!scn->amb.isset)
			exiterror(ERR_NO_AMB);
		else if (!scn->cam.isset)
			exiterror(ERR_NO_CAM);
		else if (!scn->light.isset)
			exiterror(ERR_NO_LIG);
	}
}

/*
 * nodupsorexit(t_pars *pars, t_sceneinf *scn, int fd)
 *
 * If A, C or L appear more than once then EXIT
 *
 */

static void	nodupsorexit(t_pars *pars, t_sceneinf *scn, int fd)
{
	if (ft_strlen(pars->astr[0]) == 1)
	{
		if (pars->astr[0][0] == 'A' && scn->amb.isset)
			freescnparsfdexitmsg(ERR_DUP_AMB, scn, pars, fd);
		if (pars->astr[0][0] == 'C' && scn->cam.isset)
			freescnparsfdexitmsg(ERR_DUP_CAM, scn, pars, fd);
		if (pars->astr[0][0] == 'L' && scn->light.isset)
			freescnparsfdexitmsg(ERR_DUP_LIG, scn, pars, fd);
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

/*
static void	setsceneandgnl(int fd, t_sceneinf *scn, t_pars *pars)
{
	pars->astr = ft_split(pars->cln, ' ');
	if (pars->astr)
	{
	// 	putarraystr(pars->astr);
		if (iselement(pars->astr))
		{
			nodupsorexit(pars, scn, fd);
			setelementinscene(pars->astr, scn);
			freearrstr(pars->astr);
			pars->ln = freecleanlineandgetnl(pars->cln, pars->ln, fd);
		}
		else
			freescnparsfdexitmsg(pars->ln, scn, pars, fd);
	}
	else
	{
		free(pars->astr);
		freelinscenfdexitbymalloc(pars->ln, scn, fd);
	}
}
*/


/*
*  error :
*    0  no error
* 	 1  Format Error
*	 2  All normal vector components are 0
*
*  Change name iselement for other and must return 0,1 or 2
*
*/
static void	setsceneandgnl(int fd, t_sceneinf *scn, t_pars *pars)
{
	int	error;

	pars->astr = ft_split(pars->cln, ' ');
	error = iselement(pars->astr);
	if (pars->astr && error == 1)   // here for error == 0
	{
		nodupsorexit(pars, scn, fd);
		setelementinscene(pars->astr, scn);
		freearrstr(pars->astr);
		pars->ln = freecleanlineandgetnl(pars->cln, pars->ln, fd);
	}
	else if (pars->astr && error == 0)   // error == 1
			freescnparsfdexitmsg(pars->ln, scn, pars, fd);
	//else if (pars->astr && error == 2)   // error == 2 TODO
	else
	{
		free(pars->astr);
		freelinscenfdexitbymalloc(pars->ln, scn, fd);
	}
}

/*
 * setscenefromfd(int fd, t_sceneinf *scene)
 *
 * - i : counter for total lines in file
 * - j : counter for lines NO equal to "\0" or "\n"
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
	exitifemptyspacesnoacl(i, j, scene);
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
//		ft_printf("==== Initiaize empty scene ====");
		ft_memset(scene, 0, sizeof(t_sceneinf));
//		putsceneinfoinline(scene);
		setscenefromfd(fd, scene);
	}
	else
		exiterror(BAD_ARGUMENTS);
}
