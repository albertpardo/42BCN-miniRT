/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:58:08 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/23 15:29:23 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

/*
 * Create a new string as result of concat "s1" and "s2"
 *
 * Returns:
 * 	- A new string as result of concat "s1" and "s2" 
 * 	- NULL if there is  memory problems
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		p_size;
	char	*p;

	p_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(sizeof(char) * p_size);
	if (p)
		*p = '\0';
	if (p && s1)
		ft_strlcpy(p, s1, p_size);
	if (p && s2)
		ft_strlcat(p, s2, p_size);
	return (p);
}
