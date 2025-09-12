/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:48:30 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/12 20:45:26 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 200

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			mode;
	t_complex	julia_c;
	int			redraw_countdown;
}	t_fractol;

void	init_fractol(t_fractol *f, int argc, char **argv);
void	print_usage(void);
int		mandelbrot(t_complex c);
int		julia_calc(t_complex z, t_complex c);
void	draw_fractal(t_fractol *f);
void	put_pixel(t_fractol *f, int x, int y, int color);
int		key_hook(int keycode, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		close_window(void *param);
int		get_color(int iter);
double	ft_atof(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
