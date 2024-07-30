/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isrgb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:22:06 by apardo-m          #+#    #+#             */
/*   Updated: 2024/07/30 18:02:53 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isrbg(char *rgbstr)
{
	char	*argb;
	int		ncommas;
	int		i;	
	
	i = 0;
	if (countchar(rgbstr, ',') == 2)
	{
		argb = ft_stplit(rgbstr, ',');
		if (ft_astrlen(argb) == 3)
		{
			if (isstringvalueinpositiverange(argb[1], CHAR_MAX_RGB) && \
					isstringvalueinpositiverange(argb[1], CHAR_MAX_RGB) && \
					isstringvalueinpositiverange(argb[1], CHAR_MAX_RGB))
				ft_printf("[RBG] ALL RGB values in range [0,255]");
			else
				exiterr("[RGB] Some value is not in range [0,255]");
		}
		else
			exiterr("[RGB] No valid RGB components : No enought values");
	}
	else
		exiterr("[RGB] No valid RGB components (No 2 commas)");

}
