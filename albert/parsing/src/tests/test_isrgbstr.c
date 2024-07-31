/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isrgbstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:30:00 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/31 14:51:59 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void putisrgb(char *str)
{
	ft_printf("%\"%s\" is valid RGB type? ", str);
	if (isrgbstr(str))
		ft_printf("TRUE.\n");
	else
		ft_printf("FALSE.\n");
}

int	main(void)
{
	ft_printf("---- Valid range ----\n");
	putisrgb("0,0,0");
 	putisrgb("255,255,255");
	ft_printf("\n---- NO Valid range ----\n");
	putisrgb("-1,0,0");
	putisrgb("0,-1,0");
	putisrgb("0,0,-1");
	putisrgb("-1,-1,0");
	putisrgb("-1,0,-1");
	putisrgb("-1,-1,-1");
	putisrgb("256,0,0");
	putisrgb("0,256,0");
	putisrgb("0,0,256");
	putisrgb("256,256,0");
	putisrgb("256,0,256");
	putisrgb("256,256,256");
	ft_printf("\n---- Format Error ----\n");
	putisrgb(",,");
	putisrgb(",");
	putisrgb("8");
	putisrgb("8,");
	putisrgb("8,0");
	putisrgb("8,0,");
	putisrgb("&,0,1");
	return (0);
}
