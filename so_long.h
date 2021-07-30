#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"

struct s_long
{
	void	*mlx;
	void	*mlx_win;
	void	*mlxend;
	void	*mlx_winend;
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
	t_data	exitTEX;
	t_data	collTEX;
	t_data	wallTEX;
	t_data	end;
	int		screenHeight;
	int		screenWidth;
	int		mapHeight;
	int		mapWidth;
	char	**map;
	int		side;
	int		posX;
	int		posY;
	int		steps;
	int		Pcount;
	int		Ccount;
	int		Ecount;
}			g_globs;

void	parser(int argc, char **argv);
void	my_mlx_pixel_put(int x, int y, int color, t_data *data);
int		get_pixel(int x, int y, t_data *data);
void	draw_image();

void	ft_error(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);

#endif