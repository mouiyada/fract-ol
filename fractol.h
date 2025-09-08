#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100
#define ButtonPressMask (1L<<2)

typedef struct s_complex {
	double re;
	double im;
} t_complex;

typedef struct s_fractol {
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int line_len;
	int endian;

	double zoom;
	double offset_x;
	double offset_y;
} t_fractol;

// 関数プロトタイプ
void draw_mandelbrot(t_fractol *f);
int key_hook(int keycode, void *param);
int mouse_hook(int button, int x, int y, void *param);
int close_window(t_fractol *f);
void put_pixel(t_fractol *f, int x, int y, int color);

#endif
