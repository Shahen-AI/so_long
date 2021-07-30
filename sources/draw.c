#include "../so_long.h"

void	my_mlx_pixel_put(int x, int y, int color, t_data *data)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_pixel(int x, int y, t_data *data)
{
	char	*dst;
	int		color;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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
			my_mlx_pixel_put(i * g_globs.side + y, j * g_globs.side + x, color, &g_globs.data);
			++y;
		}
		++x;
	}
}

void	draw_tex(int i, int j, t_data *data)
{
	int x;
	int y;
	unsigned int color;

	x = 0;
	while (x < g_globs.side)
	{
		y = 0;
		while (y < g_globs.side)
		{
			color = get_pixel(y, x, data);
			if (color == 0xFF000000)
				color = 0x00d3d3d3;
			my_mlx_pixel_put(i * g_globs.side + y, j * g_globs.side + x, color, &g_globs.data);
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
				draw_tex(j, i, &g_globs.wallTEX); // 0x00C39B77
			if (g_globs.map[i][j] == '0')
				draw_square(j, i, 0x00d3d3d3);
			if (g_globs.map[i][j] == 'E')
				draw_tex(j, i, &g_globs.exitTEX);
			if (i == g_globs.posY && j == g_globs.posX)
				draw_tex(j, i, &g_globs.playerTEX);
			if (g_globs.map[i][j] == 'C')
				draw_tex(j, i, &g_globs.collTEX);
			++j;
		}
		++i;
	}
}
