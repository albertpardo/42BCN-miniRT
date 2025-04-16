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
#define MAX_ITERATION 100

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
		
/*		MinRe = -2.0;
		MaxRe = 1.0;
		MinIm = -1.5;
		MaxIm = 1.5;*/

		MinRe = 0.2;
		MaxRe = 0.4;
		MinIm = -0.3;
		MaxIm = 0.3;


		k = 1 +1/img->zoom;

		MinRe *= k;
		MaxRe *= k;
		MinIm *= k;
		MaxIm *= k;

		printf("MinRe=%f, MaxRe=%f, MinIm = %f, MaxIm = %f\n", MinRe, MaxRe, MinIm, MaxRe);

		Re_factor = (MaxRe - MinRe) / (img->width - 1);
		Im_factor = (MaxIm - MinIm) / (img->height - 1);
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
	int	exit_x(t_mlxdata *win)
	{
		mlx_destroy_window (win->mlx_ptr, win->win_ptr);
		exit (0);  // Close Windows and finish the program`
	}

	int deal_key(int key, void *win)
	{
		if (key == 53) // ESC Key = 53
			exit_x(win);
		return (0);
	} 

	int mouse_event(int button, int x, int y, t_structs *winimg)
	{
		double	*zoom;

		zoom = &winimg->img->zoom;
		printf("Antes> Button = %d,(x = %d, y = %d), zoom=%f\n", button, x, y, *zoom);
	if (button == 5)
		*zoom -= 0.01;
	else if (button == 4)
		*zoom += 0.1;
	if (*zoom < 0.0)
		*zoom = 0.0;
	printf("Despues>Button = %d,(x = %d, y = %d), zoom=%f\n", button, x, y, *zoom);
	basic_mandel( MAX_ITERATION, winimg->img, 0xFF000000);
	mlx_clear_window(winimg->win->mlx_ptr, 	winimg->win->win_ptr);
	mlx_put_image_to_window(winimg->win->mlx_ptr, \
			winimg->win->win_ptr, winimg->img->img, 0, 0);
	printf("-------\n");
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
	return((t_data) {img.img, img.addr, img.height, img.width, img.bits_per_pixel, \
			img.line_length, img.endian, img.fondo_color, img.zoom});
}

/*
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


	MinRe *= k;
	MaxRe *= k;
	MinIm *= k;
	MaxIm *= k;

	printf("MinRe=%f\n", MinRe);

	Re_factor = (MaxRe - MinRe) / (img->width - 1);
	Im_factor = (MaxIm - MinIm) / (img->height - 1);
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

*/

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
		basic_mandel( MAX_ITERATION, &img, 0xFF000000);
		mlx_key_hook(win.win_ptr, deal_key, &img);
		mlx_mouse_hook(win.win_ptr, &mouse_event, &winimg);
//		mlx_hook(win.win_ptr, 6, 0 , mouse_pos, &win);
		mlx_hook(win.win_ptr, 17, 1L<<0, &exit_x, &win);
		mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, img.img, 0, 0);
		mlx_loop(win.mlx_ptr);
	}
	else
		return (1);
	return (0);
}
