// header

#include "fractol.h"

void	mouse_zoom(t_dim *dim, int x, int y, double zoom)
{
	double	scaled_x;
	double	scaled_y;
	double	add_real;
	double	add_imag;
	
/* 	(void)zoom;
 */	/* (void)dim;
	(void)x;
	(void)y; */
	/* f->center_r = f->min_r - f->max_r;
	f->center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (f->center_r - zoom * f->center_r) / 2;
	f->min_r = f->max_r + zoom * f->center_r;
	f->min_i = f->min_i + (f->center_i - zoom * f->center_i) / 2;
	f->max_i = f->min_i + zoom * f->center_i;
 */
	/*dim->center_r = dim->right_f - dim->left_f;
	dim->center_i = dim->bottom_f - dim->top_f;
	dim->right_f = dim->right_f + (dim->center_r - zoom * dim->center_r) / 2;
	dim->left_f = dim->right_f + zoom * dim->center_r;
	dim->top_f = dim->top_f + (dim->center_i - zoom * dim->center_i) / 2;
	dim->bottom_f = dim->top_f + zoom * dim->center_i;*/
	
	printf("x: %d\n", x);
	printf("y: %d\n", y);
	printf("left_f: %f\n", dim->left_f);
	printf("right_f: %f\n", dim->right_f);
	printf("top_f: %f\n", dim->top_f);
	printf("bottom_f: %f\n", dim->bottom_f);
	dim->center_r = (dim->right_f - dim->left_f) / 2 + dim->left_f;
	dim->center_i = (dim->bottom_f - dim->top_f) / 2 + dim->top_f;
	printf("center_r: %f\n", dim->center_r);
	printf("center_i: %f\n", dim->center_i);
	scaled_x = (dim->center_r - x * dim->scale_r + (dim->right_f - dim->left_f) / 2) / 2;
	scaled_y = (dim->center_i - y * dim->scale_i + (dim->bottom_f - dim->top_f) / 2) / 2;
	printf("scaled_x: %f\n", scaled_x);
	printf("scaled_x: %f\n", scaled_y);

	/* dim->left_f *= zoom;
	dim->top_f *= zoom;
	dim->right_f *= zoom;
	dim->bottom_f *= zoom; */

	add_real = scaled_x * (zoom - 1);
	add_imag = scaled_y * (zoom - 1);
	printf("add_real: %f\n", add_real);
	printf("add_imag: %f\n", add_imag);

	dim->right_f += add_real;
	dim->left_f += add_real;
	dim->top_f += add_imag;
	dim->bottom_f += add_imag;

	/* dim->right_f = dim->right_f + (dim->center_r - (x * dim->scale_r - dim->left_f - dim->scale_r));
	dim->left_f = dim->left_f + (dim->center_r - (x * dim->scale_r - dim->left_f - dim->scale_r));
	dim->top_f = dim->top_f + (dim->center_i - (y * dim->scale_i - dim->bottom_f - dim->scale_i));
	dim->bottom_f = dim->bottom_f + (dim->center_i - (y * dim->scale_i - dim->bottom_f - dim->scale_i)); */

	return ;
}

void	shift_fract(t_dim *dim, double shiftx, double shifty)
{
	dim->left_f += shiftx;
	dim->right_f += shiftx;
	dim->top_f += shifty;
	dim->bottom_f += shifty;
}