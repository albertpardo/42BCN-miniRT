/* 
 * Code from: 
 * https://gontjarow.github.io/MiniLibX/mlx-tutorial-draw-line.html
 */

#include <mlx.h>
#include <math.h>
#include <stdio.h>

void draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	double pixelX = beginX;
	double pixelY = beginY;

	printf("Pixels %d\n", pixels);
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	while (pixels)
	{
		printf("(%f,%f)\n", pixelX, pixelY);
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

int main(void)
{
	void *mlx;
	void *win;
  
	mlx = mlx_init();
	win = mlx_new_window(mlx,  640, 360, "Tutorial Window - Draw Line");
	draw_line(mlx, win, 640, 360, 0, 0, 0xFFFFFF);
    mlx_loop(mlx);
	return (0);
}
