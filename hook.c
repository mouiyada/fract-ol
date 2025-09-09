/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:58:27 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/09 13:18:15 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65362)
		f->offset_y -= 0.1 / f->zoom;
	else if (keycode == 65364)
		f->offset_y += 0.1 / f->zoom;
	else if (keycode == 65361)
		f->offset_x -= 0.1 / f->zoom;
	else if (keycode == 65363)
		f->offset_x += 0.1 / f->zoom;
	draw_fractal(f);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*f;

	(void)x;
	(void)y;
	f = (t_fractol *)param;
	if (button == 4)
		f->zoom *= 1.1;
	else if (button == 5)
		f->zoom /= 1.1;
	draw_fractal(f);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
