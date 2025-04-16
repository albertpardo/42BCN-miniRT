FLAGS = -Wall -Wextra #-Werror
MLX_LINUX = minilibx-linux/
MLX = ${MLX_LINUX}

.PHONY: all

all:
	@echo "call the rigth test"

window:
	cd ${MLX} && ./configure
	cc -v ${FLAGS} -lXext -lX11 -lm ./minilibx-linux/libmlx_Linux.a  01_test_open_only_window.c
	
	#gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 01_test_open_only_window.c

pixel: 
	make -C $(MLX)
	cc -v -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -lbsd -lXext -lX11 -lm 02_test_pixel.c
	#gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 02_test_pixel.c

pixels: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 02_test_pixels.c

key: 
	make -C $(MLX)
	gcc -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 02_test_pixel_key.c

line: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 03_test_draw_line.c

mouse: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 04_test_mouse.c

mouse_exit: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 04_test_mouse_exitX.c

mousescape_exit: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 04_test_mouseX_esc_exit.c

useparam: 
	make -C $(MLX)$
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 05_test_use_param.c

image: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 06_test_image.c

image_struct: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 07_test_image_struct.c

line1: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 07_01_test_square.c

image_color:
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 07_02_mlx_pixel_put_color.c

image_colors:
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 07_02_mlx_pixel_put_colors.c

event2: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 08_test_events_mouse_inout.c

event3: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 08_test_events_mouse_move.c

read_xpm_img: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 09_read_image.c

put_xpm_img: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 09_put_image.c

text: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 10_text.c

key_colors: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 11_changue_colors_whith_keys_qweasdol.c

basic_mandel: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 20_basic_mandelbrot.c

mandel_colors: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 20_basic_mandelbrot_colors.c

mandel_mouse: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 20_basic_mandelbrot_colors_zoom1.c

mandel_zoom: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 20_basic_mandelbrot_colors_zoom2.c

mandel_move: 
	make -C $(MLX)
	gcc -Wall -Wextra -Werror -I $(MLX) -L $(MLX) -l mlx -framework OpenGL -framework AppKit 21_basic_mandelbrot_zoom_move.c

color_print:
	cc -g -Wall -Wextra -Werror test_color_01.c

clean:

fclean:
	rm -f *.out

re: fclean all
