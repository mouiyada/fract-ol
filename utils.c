/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:49:26 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/12 22:10:35 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_calc(t_complex z, t_complex c)
{
	int		i;
	double	tmp;

	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	frac;
	double	div;

	result = 0;
	sign = 1;
	frac = 0;
	div = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			frac = frac * 10 + (*str++ - '0');
			div *= 10;
		}
	}
	return (sign * (result + frac / div));
}

int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000);
	return (0xF00000 * iter / MAX_ITER);
}
