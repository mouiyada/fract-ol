#include "fractol.h"

void put_pixel(t_fractol *f, int x, int y, int color)
{
	char *dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}

int mandelbrot(t_complex c)
{
	t_complex z = {0, 0};
	int i = 0;

	while (z.re * z.re +z.im * z.im <= 4 && i < MAX_ITER)
	{
		double tmp = z.re * z.re - z.im + c.re;
		z.im = 2 *z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return i;
}

void draw_mandelbrot(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);


for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			t_complex c = {
				(x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x,
				(y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom) + f->offset_y
			};
			int iter = mandelbrot(c);
			int color = iter == MAX_ITER ? 0x000000 : (iter * 255 / MAX_ITER) << 16;
			put_pixel(f, x, y, color);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
}
