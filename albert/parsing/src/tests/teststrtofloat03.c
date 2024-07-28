/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teststrtofloat03.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 07:23:33 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/28 09:28:45 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	printest(char *s)
{
	printf("%s ? ", s);
	if (isstrsgnfloat(s))
		printf("TRUE\n");
	else
		printf("FALSE\n");
}

int	main(void)
{
	printf("------ Valid float (no check MAX / MIN limits) -------\n");
	printf("NO SIGNED:\n");
	printest("0");
	printest("1");
	printest("0.0");
	printest("1.0");
	printest("0.9");
	printest("1.1");
	printest("0.0500000000");
	printest("0.0932040");
	printf("\nSIGNED:\n");
	printest("-0");
	printest("+0");
	printest("-1");
	printest("+1");
	printest("-0.0");
	printest("+0.0");
	printest("-1.0");
	printest("+1.0");
	printest("+0.01");
	printest("-0.01");
	printest("-5");
	printf("\n------ No Valid (no check MAX / MIN limits) -------\n");
	printest(".1");
	printest("001.");
	printest("01.00");
	printest("001.0");
	printest("000000.0");
	printest("0.00");
	printest("0.0000000000");
	printest("1.0000000000");
	printest("-0.0a1");
	printest("-+1.0");
	printest("+++++++0.01");
	return (0);
}
