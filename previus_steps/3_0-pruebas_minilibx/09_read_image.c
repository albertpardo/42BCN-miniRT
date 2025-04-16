#include <mlx.h>
#include <stdio.h>

#define MAX_X 1920
#define MAX_Y 1080

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./png-2702691_640_425.xpm";
	int		img_width = 645;
	int		img_height = 425;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	if (img == NULL)
		printf("Read error");
	else
		printf("Read OK");
}	
