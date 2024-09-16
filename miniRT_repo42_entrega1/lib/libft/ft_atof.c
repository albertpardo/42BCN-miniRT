/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:41:03 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/23 17:51:31 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Number in string to float
 * The fist sign found is the float' sign
 * Avoid ' ' , and other print chars in the range 9 to 13
 *
 * No check to avoid Double Limits Values 
 * No check no well formated floats numbers in string 
 */

static float	avoid_spaces_getsign(const char **p)
{
	float	sign;

	sign = 1.0;
	while (**p == ' ' || (**p > '\b' && **p <= '\r'))
		(*p)++;
	if (**p == '-')
		sign = -1.0f;
	if (**p == '+' || **p == '-')
		(*p)++;
	return (sign);
}

static float	mypow(float base, int exp)
{
	float	result;

	result = 1.0f;
	while (exp-- > 0)
		result *= base;
	return (result);
}

float	ft_atof(const char *str)
{
	float	result;
	float	decimal;
	float	sign;
	int		i;

	result = 0.0f;
	decimal = 0.0f;
	i = 0;
	sign = avoid_spaces_getsign(&str);
	while (*str != '.' && (*str >= '0' && *str <= '9'))
	{
		result = result * 10.0f + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (*str != '.' && (*str >= '0' && *str <= '9'))
	{
		decimal = decimal * 10.0f + (*str - '0');
		str++;
		i++;
	}
	decimal /= mypow(10.0f, i);
	result = sign * (result + decimal);
	return (result);
}
