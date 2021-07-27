#include "so_long.h"

int	so_close()
{
	exit(0);
	return (0);
}

int	key_press(int keycode)
{
	if (keycode == 0)
		key_mov.left = 1;
	if (keycode == 1)
		key_mov.down = 1;
	if (keycode == 2)
		key_mov.right = 1;
	if (keycode == 13)
		key_mov.up = 1;
	if (keycode == 53)
	{
		mlx_destroy_window(vars.mlx, vars.mlx_win);
		so_close();
	}
	return (0);
}

int	key_hook()
{
	if (key_mov.left)
	{
		if (g_globs.map[g_globs.posY][g_globs.posX - 1] != '1')
		{
			if (g_globs.map[g_globs.posY][g_globs.posX - 1] == 'C')
				g_globs.map[g_globs.posY][g_globs.posX - 1] = '0';
			if (g_globs.map[g_globs.posY][g_globs.posX - 1] == 'E')
				so_close(); 
			--g_globs.posX;
			++g_globs.steps;
			ft_putstr("Steps count : ");
			ft_putnbr(g_globs.steps);
			ft_putchar('\n');
		}
		key_mov.left = 0;
	}
	if (key_mov.right)
	{
		if (g_globs.map[g_globs.posY][g_globs.posX + 1] != '1')
		{
			if (g_globs.map[g_globs.posY][g_globs.posX + 1] == 'C')
				g_globs.map[g_globs.posY][g_globs.posX + 1] = '0';
			if (g_globs.map[g_globs.posY][g_globs.posX + 1] == 'E')
				so_close();
			++g_globs.posX;
			++g_globs.steps;
			ft_putstr("Steps count : ");
			ft_putnbr(g_globs.steps);
			ft_putchar('\n');
		}
		key_mov.right = 0;
	}
	if (key_mov.up)
	{
		if (g_globs.map[g_globs.posY - 1][g_globs.posX] != '1')
		{
			if (g_globs.map[g_globs.posY - 1][g_globs.posX] == 'C')
				g_globs.map[g_globs.posY - 1][g_globs.posX] = '0';
			if (g_globs.map[g_globs.posY - 1][g_globs.posX] == 'E')
				so_close();
			--g_globs.posY;
			++g_globs.steps;
			ft_putstr("Steps count : ");
			ft_putnbr(g_globs.steps);
			ft_putchar('\n');
		}
		key_mov.up = 0;
	}
	if (key_mov.down)
	{
		if (g_globs.map[g_globs.posY + 1][g_globs.posX] != '1')
		{
			if (g_globs.map[g_globs.posY + 1][g_globs.posX] == 'C')
				g_globs.map[g_globs.posY + 1][g_globs.posX] = '0';
			if (g_globs.map[g_globs.posY + 1][g_globs.posX] == 'E')
				so_close();
			++g_globs.posY;
			++g_globs.steps;
			ft_putstr("Steps count : ");
			ft_putnbr(g_globs.steps);
			ft_putchar('\n');
		}
		key_mov.down = 0;
	}
	return (0);
}

void	glob_init()
{
	int i = 0, j;

	g_globs.steps = 0;
	g_globs.side = 50;
	g_globs.screenHeight = g_globs.side * g_globs.mapHeight;
	g_globs.screenWidth = g_globs.side * g_globs.mapWidth;
	while (i < g_globs.mapHeight)
	{
		j = 0;
		while (j < g_globs.mapWidth)
		{
			if (g_globs.map[i][j] == 'P')
				break ;
			++j;
		}
		if (g_globs.map[i][j] == 'P')
				break ;
		++i;
	}
	g_globs.map[i][j] = '0';
	g_globs.posX = j;
	g_globs.posY = i;
}

int	frame()
{
	key_hook();
	mlx_clear_window(vars.mlx, vars.mlx_win);
	draw_image();
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, g_globs.data.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	parser(argc, argv);
	glob_init();
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, g_globs.screenWidth, g_globs.screenHeight, "so_long");
	g_globs.data.img = mlx_new_image(vars.mlx, g_globs.screenWidth, g_globs.screenHeight);
	g_globs.data.addr = mlx_get_data_addr(g_globs.data.img, &g_globs.data.bits_per_pixel,
			&g_globs.data.line_length, &g_globs.data.endian);
	mlx_hook(vars.mlx_win, 17, 1L << 17, so_close, 0);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_press, 0);
	mlx_loop_hook(vars.mlx, frame, 0);
	mlx_loop(vars.mlx);
	return (0);
}
