#include "../so_long.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char    *dst;

	dst = g_globs.data.addr + (y * g_globs.data.line_length + x * (g_globs.data.bits_per_pixel / 8));
			// printf("test\n");
	*(unsigned int*)dst = color;
}

void	draw_image()
{
	int x;
	int y;

	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
			my_mlx_pixel_put(x, y, 0x00FF5733);
			++y;
		}
		++x;
	}
}
