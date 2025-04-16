/*
 * https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#pushing-images-to-a-window
 *
 * Mandelbrot : http://warp.povusers.org/Mandelbrot/
 * 
 */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_X 1000
#define MAX_Y 1000
#define ESC_KEY 53
#define UP_KEY	126
#define DOWN_KEY 125
#define RIGHT_KEY 124
#define LEFT_KEY 123
#define MAX_ITERATION 100

#define CT_ZOOM 0.1

typedef struct mlxdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}				t_mlxdata;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fondo_color;
	double	zoom;
	double	incRe;
	double	incIm;
}				t_data;

typedef struct s_structs
{
	t_mlxdata	*win;
	t_data		*img;
}				t_structs;

typedef struct	complexnum
{
	double	re;
	double	im;
}				t_complexnum;
			
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst; // Acces to pixel postion in *data

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;  //Change the pixel color
}

// Color functions
int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int setcolor(const int n, const int maxiter)
{
	int component;

	component = n * 0xFF * 2 / maxiter;
	if ( n < (maxiter / 2) - 1)
		return (create_trgb(0x00, component, 0x0, 0x0));
	return (create_trgb(0x00, 0xFF, component, component));
}

// End color function

// Mandel....
void basic_mandel(int MaxIteration, t_data *img, int color)
{
	double			MinRe;
	double			MaxRe;
	double			MinIm;
	double			MaxIm;
	double			Re_factor;
	double			Im_factor;
	int				x;
	int				y;
	int				n;
	int				isInside;
	t_complexnum	c;
	t_complexnum	Z;
	t_complexnum	Z2;
	double 			k;
		
	MinRe = -2.0;
	MaxRe = 1.0;
	MinIm = -1.5;
	MaxIm = 1.5;
	k = 1/img->zoom;

	Re_factor = (MaxRe - MinRe) / (img->width - 1);
	Im_factor = (MaxIm - MinIm) / (img->height - 1);

	printf("---------------\n");
	printf("w = %d , h = %d\n", img->width, img->height);
	printf("Antes -> MinRe=%f,  MaxRe=%f, incRe =  %f, Re_factor = %f, Re_factor * img->incRe = %f \n", MinRe, MaxRe, img->incRe,  Re_factor,  Re_factor * img->incRe);

	MinRe = MinRe + Re_factor * img->incRe;
	MaxRe = MaxRe + Re_factor * img->incRe;
	MinIm = MinIm + Im_factor * img->incIm;
	MaxIm = MaxIm + Im_factor * img->incIm;	

	MinRe = MinRe * k;
	MaxRe = MaxRe * k;
	MinIm = MinIm * k;
	MaxIm = MaxIm * k;	

	printf("Despues -> MinRe=%f,  MaxRe=%f, incRe =  %f, Re_factor = %f, Re_factor * img->incRe = %f \n", MinRe, MaxRe, img->incRe,  Re_factor,  Re_factor * img->incRe);
	y = 0;
	while(y < img->height)
	{
		c.im = MaxIm - y * Im_factor;
		x = 0;
		while(x < img->width)
		{
			c.re = MinRe + x * Re_factor;
			Z.re = c.re;
			Z.im = c.im;
			isInside = 1;
			n = 0;
			while(n < MaxIteration)
			{
				Z2.re = Z.re * Z.re;
				Z2.im = Z.im * Z.im;
				if(Z2.re + Z2.im > 4)
				{
					isInside = 0;
					break;
				}
				Z.im = 2 * Z.re * Z.im + c.im;
				Z.re = Z2.re - Z2.im + c.re;
				n++;
			}
			if(isInside) 
				my_mlx_pixel_put(img, x, y, color);
			else
// 				Determinar color (x,y, n)
// 				n to a color so that from 0 to MaxIterations/2-1 the color goes from black (0x0) to red(0x00FF0000) and from MaxIterations/2 to MaxIterations-1 the color goes from red(0x00FF0000) to white(0x00FFFFFF)
				my_mlx_pixel_put(img, x, y, setcolor(n, MaxIteration));
			x++;
		}
		y++;
	}
}
// end Mandel

// Events
int exit_x(t_structs *winimg)
{
	mlx_destroy_image(winimg->win->mlx_ptr, winimg->img->img);
	mlx_destroy_window(winimg->win->mlx_ptr, winimg->win->win_ptr);
	exit (0);  // Close Windows and finish the program`
	return (0);
}

int deal_key(int key, t_structs *winimg)
{
	printf(" deal w = %d, h = %d\n", winimg->img->width, winimg->img->height);
	if (key == ESC_KEY)
		exit_x(winimg);
	else if (key == RIGHT_KEY)
		winimg->img->incRe += 2.0;
	else if (key == LEFT_KEY)
		winimg->img->incRe -= 2.0;
	else if (key == UP_KEY)
		winimg->img->incIm += 2.0;
	else if (key == DOWN_KEY)
		winimg->img->incIm -= 2.0;
	printf("incRe = %f\n",winimg->img->incRe);
	basic_mandel( MAX_ITERATION, winimg->img, 0xFF000000);
	mlx_clear_window(winimg->win->mlx_ptr, 	winimg->win->win_ptr);
	mlx_put_image_to_window(winimg->win->mlx_ptr, \
			winimg->win->win_ptr, winimg->img->img, 0, 0);
	return (0);
} 

int mouse_event(int button, int x, int y, t_structs *winimg)
{
	double	*zoom;
	
	x = 0;
	y = 0;
	zoom = &winimg->img->zoom;
	if (button == 5)
		*zoom -= CT_ZOOM;
	else if (button == 4)
		*zoom += CT_ZOOM;
	if (*zoom < 0.0)
		*zoom = 0.0;
	basic_mandel( MAX_ITERATION, winimg->img, 0xFF000000);
	mlx_clear_window(winimg->win->mlx_ptr, 	winimg->win->win_ptr);
	mlx_put_image_to_window(winimg->win->mlx_ptr, \
			winimg->win->win_ptr, winimg->img->img, 0, 0);
	return (0);
}

/*
int	mouse_pos(int x, int y, t_mlxdata *win)
{
	if ( x >= 0 && x <= win->width && y >= 0 && y <= win->height)
		printf("(%d, %d)\n", x, y);
	return (0);
}
*/
// End events

t_mlxdata start_newindow(int w, int h, char *str)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, w, h, str);
	return ((t_mlxdata) {mlx_ptr, win_ptr, w, h});
}

t_data start_newimage(t_mlxdata	win, int color)
{
	t_data	img;

	img.img = mlx_new_image(win.mlx_ptr, win.width, win.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.height = win.height;
	img.width = win.width;
	img.fondo_color = color;
	img.zoom = 1.0;
	img.incRe = 0;
	img.incIm = 0;
	return((t_data) {img.img, img.addr, img.height, img.width, img.bits_per_pixel, \
			img.line_length, img.endian, img.fondo_color, img.zoom, img.incRe, img.incIm});
}

int	main(void)
{
	t_data		img;
	t_mlxdata	win;
	t_structs	winimg;

	win = start_newindow(MAX_X, MAX_Y, "Basic Mandelbrot");
	if (win.mlx_ptr != NULL && win.win_ptr != NULL)
	{
		img = start_newimage(win, 0x007F7F7F);
		winimg.win = &win;
		winimg.img = &img;
		mlx_key_hook(win.win_ptr, deal_key, &winimg);
		mlx_mouse_hook(win.win_ptr, mouse_event, &winimg);
	//	mlx_hook(win.win_ptr, 6, 0 , mouse_pos, &win);
		mlx_hook(win.win_ptr, 17, 1L<<0, &exit_x, &winimg);
		basic_mandel( MAX_ITERATION, winimg.img, 0xFF000000);
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img.img, 0, 0);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
