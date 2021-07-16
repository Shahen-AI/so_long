#include "so_long.h"

int	so_close(void)
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

int	key_hook(void)
{
	if (key_mov.left)
	{
		printf("a is pressed!!!\n");
		key_mov.left = 0;
	}
	if (key_mov.right)
	{
		printf("d is pressed!!!\n");
		key_mov.right = 0;
	}
	if (key_mov.up)
	{
		printf("w is pressed!!!\n");
		key_mov.up = 0;
	}
	if (key_mov.down)
	{
		printf("s is pressed!!!\n");
		key_mov.down = 0;
	}
	return (0);
}

void	glob_init(void)
{
	g_globs.screenHeight = 720;
	g_globs.screenWidth = 1080;
}

int	frame()
{
	key_hook();
	mlx_clear_window(vars.mlx, vars.mlx_win);
	// printf("test\n");
	draw_image();
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, g_globs.data.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	vars.mlx = mlx_init();
	glob_init();
	vars.mlx_win = mlx_new_window(vars.mlx, g_globs.screenWidth, g_globs.screenHeight, "so_long");
	g_globs.data.img = mlx_new_image(vars.mlx, g_globs.screenWidth, g_globs.screenHeight);
	g_globs.data.addr = mlx_get_data_addr(g_globs.data.img, &g_globs.data.bits_per_pixel,
			&g_globs.data.line_length, &g_globs.data.endian);
	printf("tesdsadsadsat\n");
	mlx_hook(vars.mlx_win, 17, 1L << 17, so_close, 0);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_press, 0);
	mlx_loop_hook(vars.mlx, frame, 0);
	mlx_loop(vars.mlx);
	return (0);
}
