#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

struct s_long
{
	void	*mlx;
	void	*mlx_win;
}			vars;

struct s_mov
{
	int	up;
	int	down;
	int	left;
	int	right;
}		key_mov;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

struct s_parsing
{
	t_data	data;
	t_data	playerTEX;
	int		screenHeight;
	int		screenWidth;
}			g_globs;

int		parser(void);
void	my_mlx_pixel_put(int x, int y, int color);
void	draw_image();

#endif