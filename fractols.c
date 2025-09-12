/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:49:04 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/12 17:58:52 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int	mandelbrot(t_complex c)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.re = 0;
	z.im = 0;
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

static void	set_complex(t_fractol *f, t_complex *c, int x, int y)
{
	c->re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x;
	c->im = -(y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom) - f->offset_y;
}

static void	draw_pixel(t_fractol *f, int x, int y)
{
	t_complex	c;
	int			iter;
	int			color;

	set_complex(f, &c, x, y);
	if (f->mode == 0)
		iter = mandelbrot(c);
	else
		iter = julia_calc(c, f->julia_c);
	color = get_color(iter);
	put_pixel(f, x, y, color);
}

void	draw_fractal(t_fractol *f)
{
	int	x;
	int	y;

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
}
