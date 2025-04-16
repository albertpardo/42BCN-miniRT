/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freecleanlineandgetnl.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:36:50 by apardo-m          #+#    #+#             */
/*   Updated: 2024/08/19 17:28:14 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*freecleanlineandgetnl(char *cleanstr, char *line, int fd)
{
	free(cleanstr);
	free(line);
	return (get_next_line(fd));
}
