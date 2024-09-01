/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:06:25 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/29 11:13:47 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Returns
 * 	The index of the first occurrence of "(char) c" in "*s".
 * 		 c can be '\0'
 * 	-1 for no ocurrence
 */

#include <stddef.h>

int	ft_strichr(const char *s, int c)
{
	unsigned char	un_c;
	int				i;

	i = 0;
	if (s == NULL)
		return (-1);
	un_c = (unsigned char) c;
	while (s[i] != '\0' && s[i] != un_c)
		i++;
	if (s[i] == '\0' && s[i] != un_c)
		return (-1);
	return (i);
}
