#include "../so_long.h"

int ones_check(char *line, int a)
{
	int i = 0;
	
	if (!ft_strlen(line))
		return (0);
	if (g_globs.mapWidth == 0 || a == 0)
	{
		while (i < ft_strlen(line))
		{
			if (line[i] != '1')
				return (0);
			++i;
		}
	}
	else
	{
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		return (0);
	}
	return (1);
}

void sym_check(char *line)
{
	int i = 0;

	while (++i < ft_strlen(line) - 1)
	{
		if (line[i] != '1' && line[i] != '0' &&
			line[i] != 'P' && line[i] != 'C' && line[i] != 'E')
			{
				ft_putstr("Shit detected - ");
				ft_putchar(line[i]);
				ft_error("\n");
			}
	}
	
}

int	parser(int argc, char **argv)
{
	if (argc == 1)
		ft_error("You have forgotten the map file, BITCH!!!\n");
	else if (argc > 2)
		ft_error("Too many arguments.\n");
	int fd = open(argv[1], 0666);
	int a = 1;
	char *line = NULL;
	g_globs.mapWidth = 0;
	while (a > 0)
	{
		if (!line)
			g_globs.mapHeight = 0;
		else
			g_globs.mapHeight = ft_strlen(line);
		a = get_next_line(fd, &line);
		if (g_globs.mapHeight > 0 && a)
			sym_check(line);
		if (g_globs.mapHeight > 0 && g_globs.mapHeight != ft_strlen(line))
			ft_error("Map isn't a rectangle.\n");
		if (!ones_check(line, a))
			ft_error("Map isn't surrounded by walls.\n");
		++g_globs.mapWidth;
	}
	return (0);
}
