/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isrgbstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:30:00 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/31 16:48:58 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void printest(char *str)
{
	ft_printf("\"%s\" is valid RGB type? ", str);
	if (isrgbstr(str))
		ft_printf("TRUE.\n");
	else
		ft_printf("FALSE.\n");
}

int	main(void)
{
	ft_printf("---- Valid range ----\n");
	printest("0,0,0");
 	printest("255,255,255");
	ft_printf("\n---- NO Valid range ----\n");
	printest("-1,0,0");
	printest("0,-1,0");
	printest("0,0,-1");
	printest("-1,-1,0");
	printest("-1,0,-1");
	printest("-1,-1,-1");
	printest("256,0,0");
	printest("0,256,0");
	printest("0,0,256");
	printest("256,256,0");
	printest("256,0,256");
	printest("256,256,256");
	ft_printf("\n---- Format Error ----\n");
	printest(",,");
	printest(",");
	printest("8");
	printest("8,");
	printest("8,0");
	printest("8,0,");
	printest("&,0,1");
	return (0);
}
