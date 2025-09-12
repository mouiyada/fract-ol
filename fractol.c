/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:55:43 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/12 20:10:11 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	write(1, "Please write as follows:\n", 26);
	write(1, "./fractol mandelbrot\n", 22);
	write(1, "./fractol julia <re> <im>\n", 27);
}

static void	set_mode(t_fractol *f, int argc, char **argv)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		f->mode = 0;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		f->mode = 1;
		f->julia_c.re = ft_atof(argv[2]);
		f->julia_c.im = ft_atof(argv[3]);
	}
	else
	{
		print_usage();
		exit(1);
	}
}

void	init_fractol(t_fractol *f, int argc, char **argv)
{
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(1);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
		exit(1);
	set_mode(f, argc, argv);
}

int	main_loop_hook(t_fractol *f)
{
	if (f->redraw_countdown > 0)
		f->redraw_countdown--;
	if (f->redraw_countdown == 0)
	{
		draw_fractal(f);
		f->redraw_countdown = -1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc != 2 && argc != 4)
	{
		print_usage();
		return (1);
	}
	init_fractol(&f, argc, argv);
	f.redraw_countdown = 0;
	mlx_key_hook(f.win, key_hook, &f);
	mlx_hook(f.win, 4, (1L << 2), mouse_hook, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop_hook(f.mlx, main_loop_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
