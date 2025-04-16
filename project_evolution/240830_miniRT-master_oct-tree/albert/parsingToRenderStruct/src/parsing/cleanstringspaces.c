/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanstringspaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:15:12 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:25:57 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* 
 * 	avoidspaces(char *str, int i)
 *
 * 	Starting on str[i] looks for nex position where there are no ' '
 */

static int	avoidspaces(char *str, int i)
{
	while (str[i] != '\0' && ft_isspace(str[i]))
		i++;
	return (i);
}

/*
 * void 	delastnl(char * line)
 *
 * if '\n' exist at the end of line then it's subtituted by '\0'
 */

static void	delastnl(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len -1] = '\0';
}

/*
 * char	*cleanStringSpaces(char *str)
 *
 *	- flag : used to know if last get char is '.' or ','
 *
 *	Steps:
 *	1 - Avoid initial spaces in 'str'
 *	2 - until of 'str'
 *		- get no space chars
 *		- set 'flag' if last char is '.', ',', '+' or '-'.
 *		- avoid spaces
 *		- to put space check : 
 *			flag == 0 && char != ',' && char != '.' && isprint(char))
 *
 * Note:
 *  All the spaces after '.' or ',' are deleted. 
 *  	So '4.   5' is '4.5'
 *  	'4.  ,  5  .   6,  a' is '4.,5.6,a'
 *
 *  To define a decimal is better : '4.5' instead '4.'
 */

static char	*getstrmem(char *str)
{
	char	*tmpstr;

	tmpstr = ft_calloc(1, ft_strlen(str) + 1);
	if (tmpstr == NULL)
		exiterror(MALLOC_ERROR);
	return (tmpstr);
}

static int	iscommapointsgn(char c)
{
	return (c == ',' || c == '.' || c == '-' || c == '+');
}

char	*cleanstringspaces(char *str)
{
	int		i;
	int		j;
	int		flag;
	char	*tmpstr;

	flag = 0;
	i = 0;
	j = 0;
	tmpstr = getstrmem(str);
	i = avoidspaces(str, i);
	while (str[i] != '\0')
	{
		flag = 0;
		while (str[i] != '\0' && ! ft_isspace(str[i]))
			tmpstr[j++] = str[i++];
		if (iscommapointsgn(str[i - 1]))
			flag = 1;
		i = avoidspaces(str, i);
		if (str[i] != '\0' && flag == 0)
			if (str[i] != ',' && str[i] != '.' && ft_isprint(str[i]))
				tmpstr[j++] = ' ';
	}
	delastnl(tmpstr);
	return (tmpstr);
}
