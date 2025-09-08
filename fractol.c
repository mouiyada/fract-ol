#include "fractol.h"

int key_hook(int keycode, void *param)
{
	t_fractol *f = (t_fractol *)param;

	if (keycode == 65307)
		exit(0);
	else if (keycode == 65362)
		f->offset_y -= 1 / f->zoom;
	else if (keycode == 65364)
		f->offset_y += 1 / f->zoom;
	else if (keycode == 65361)
		f->offset_x -= 1 / f->zoom;
	else if (keycode == 65363)
		f->offset_x += 1 / f->zoom;
	draw_mandelbrot(f);
	return 0;
}

int mouse_hook(int button, int x, int y, void *param)
{
    t_fractol *f = (t_fractol *)param;
	(void)x;
	(void)y;

	if(button == 4)
		f->zoom *= 1.1;
	else if(button ==5)
		f->zoom /= 1.1;
    draw_mandelbrot(f);
    return 0;
}


int close_window(t_fractol*f)
{
	(void) f;

	exit(0);
	return 0;
}

int main(void)
{
	t_fractol f;
	f.zoom = 1.0;
	f.offset_x = 0.0;
	f.offset_y =0.0;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Mandelbrot");

	draw_mandelbrot(&f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_hook(f.win, 4, ButtonPressMask, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
	return 0;
}
