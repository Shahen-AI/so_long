#include "../so_long.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char    *dst;

	dst = g_globs.data.addr + (y * g_globs.data.line_length + x * (g_globs.data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_pixel(int x, int y)
{
	char	*dst;
	int		color;

	dst = g_globs.data.addr + (y * g_globs.data.line_length + x * (g_globs.data.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void	draw_square(int i, int j, int color)
{
	int x;
	int y;

	x = 0;
	while (x < g_globs.side)
	{
		y = 0;
		while (y < g_globs.side)
		{
			my_mlx_pixel_put(i * g_globs.side + y, j * g_globs.side + x, color);
			++y;
		}
		++x;
	}
}

void	draw_image()
{
	int i = 0, j;

	while (i < g_globs.mapHeight)
	{
		j = 0;
		while (j < g_globs.mapWidth)
		{
			if (g_globs.map[i][j] == '1')
			{
				draw_square(j, i, 0x00FF5733);
			}
			if (g_globs.map[i][j] == '0')
			{
				draw_square(j, i, 0x00726457);
			}
			if (g_globs.map[i][j] == 'E')
			{
				draw_square(j, i, 0x009ACD32);
			}
			if (i == g_globs.posY && j == g_globs.posX)
			{
				draw_square(j, i, 0x00E7DBD0);
			}
			if (g_globs.map[i][j] == 'C')
			{
				draw_square(j, i, 0x00F2C136);
			}
			++j;
		}
		++i;
	}
}
