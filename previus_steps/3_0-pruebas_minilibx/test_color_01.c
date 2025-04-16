/*
 *https://harm-smits.github.io/42docs/libs/minilibx/colors.html
 */


#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int component_in_range(int comp)
{
	if (comp > 0xFF)
		comp %= 0xFF;
	return (comp);
}

int inc_componet(int comp, int inc)
{
	comp += inc;
	return (component_in_range(comp));
}

int inc_t(int trgb, int inc)
{
	return (create_trgb(inc_componet(get_t(trgb), inc), get_r(trgb), \
		   	get_g(trgb), get_b(trgb)));
}

int inc_r(int trgb, int inc)
{
	return (create_trgb(get_t(trgb), inc_componet(get_r(trgb), inc), \
			   	get_g(trgb), get_b(trgb)));
}

int inc_g(int trgb, int inc)
{
	return (create_trgb(get_t(trgb), get_r(trgb), inc_componet(get_g(trgb), inc), \
			   get_b(trgb)));
}

int inc_b(int trgb, int inc)
{
	return (create_trgb(get_t(trgb), get_r(trgb), get_g(trgb), \
			   inc_componet(get_b(trgb), inc)));
}

int get_opposite_component(int comp)
{
	comp = component_in_range(comp);
	return ( 0xFF - comp);
}

int get_opposite(int trgb)
{
	return (0xFFFFFFFF - trgb);
}

int get_opposite_rgb(int trgb)
{
	int t;
	int rgb;

	t = 0xFF000000 & trgb;
	rgb = 0x00FFFFFF & trgb;
	rgb = 0x00FFFFFF - rgb;
	rgb = t | rgb;
	return (rgb);
}
	
int main(void)
{
	printf("create_trgb -> %X\n", create_trgb( 0x0, 0x0, 0xFF, 0x00));
	printf("%d\n", 0x0000FF00);
	printf("%X\n", 0xFFFFFFFF);
	printf("T -> Original %#08X , Incremetado %#08X\n", 0x01010101, inc_t(0x01010101, 5));
	printf("R -> Original %#08X , Incremetado %#08X\n", 0x01010101, inc_r(0x01010101, 5));
	printf("G -> Original %#08X , Incremetado %#08X\n", 0x01010101, inc_g(0x01010101, 5));
	printf("B -> Original %#08X , Incremetado %#08X\n", 0x01010101, inc_b(0x01010101, 5));
	printf("Original %#08X , Oposite %#08X\n", 0x00000000, get_opposite(0x00000000));
	printf("Original %#08X , Oposite %#08X\n", 0x01010101, get_opposite(0x01010101));
	printf("Original %#08X , Oposite %#08X\n", 0x0000FF01, get_opposite(0x0000FF01));
	printf("Original %#08X , RGB Opo %#08X\n", 0x05000000, get_opposite_rgb(0x05000000));
}
