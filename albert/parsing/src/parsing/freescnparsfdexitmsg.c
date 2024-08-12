#include "minirt.h"

/*
 * freescnparsfdexitmsg(char *msg, t_sceneinf *scn, t_pars *pars, int fd)
 *
 *	str is a duplicate of 'msg'
 *	
 * 	Go to the end of  'fd' file before close it
 *  Frees : 
 *		- pars.ln :  a file line 
 *		- pars.cln : line without spaces
 *		- pars.astr: pointer to string from pars.cln
 *  Put error message 'str' and exits
 */

void	freescnparsfdexitmsg(char *msg, t_sceneinf *scn, t_pars *pars, int fd)
{
	char *str;

	str = ft_strdup(msg);
	while (pars->ln != NULL)
	{
		free(pars->ln);
		pars->ln = get_next_line(fd);
	}
	close(fd);
	free(pars->cln);
	freearrstr(pars->astr);
	clearscene(scn);
	exiterrorfreemsg(str);
}
