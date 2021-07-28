#include "../so_long.h"

int ones_check(char *line, int a)
{
	int i = 0;
	
	if (!ft_strlen(line))
		return (0);
	if (g_globs.mapHeight == 0 || a == 0)
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

void	map_alloc()
{
	int i;

	i = 0;
	if (!(g_globs.map = (char **)malloc((g_globs.mapHeight + 1) * sizeof(char *))))
		ft_error("Error : allocation error.\n");
	while (i < g_globs.mapHeight)
	{
		if (!(g_globs.map[i] = (char *)malloc((g_globs.mapWidth + 1) * sizeof(char *))))
			ft_error("Error : allocation error.\n");
		++i;
	}
	g_globs.map[i] = NULL;
}

void	map_fill(int fd)
{
	map_alloc();
	int a = 1, i, j = 0;
	char *line;

	while(a)
	{
		i = 0;
		a = get_next_line(fd, &line);
		while (i < g_globs.mapWidth)
		{
			if (line[i] == 'P')
				++g_globs.Pcount;
			if (line[i] == 'E')
				++g_globs.Ecount;
			if (line[i] == 'C')
				++g_globs.Ccount;
			g_globs.map[j][i] = line[i];
			++i;
		}
		g_globs.map[j][i] = '\0';
		++j;
	}
}

void	parser(int argc, char **argv)
{
	if (argc == 1)
		ft_error("Please enter the map file!\n");
	else if (argc > 2)
		ft_error("Error : Too many arguments.\n");
	int fd = open(argv[1], 0666);
	if (fd < 3)
		ft_error("Error : Can't open the file.\n");
	int a = 1;
	char *line = NULL;
	g_globs.mapWidth = 0;
	while (a > 0)
	{
		if (!line)
			g_globs.mapWidth = 0;
		else
			g_globs.mapWidth = ft_strlen(line);
		a = get_next_line(fd, &line);
		if (g_globs.mapWidth > 0 && a)
			sym_check(line);
		if (g_globs.mapWidth > 0 && g_globs.mapWidth != ft_strlen(line))
			ft_error("Error : Map isn't a rectangle.\n");
		if (!ones_check(line, a))
			ft_error("Error : Map isn't surrounded by walls.\n");
		++g_globs.mapHeight;
	}
	close(fd);
	fd = open(argv[1], 0666);
	map_fill(fd);
	close(fd);
	if (g_globs.Pcount == 0)
		ft_error("You don't set players position!\n");
	if (g_globs.Ecount == 0)
		ft_error("You don't have an exit!\n");
	if (g_globs.Ccount == 0)
		ft_error("You don't have collectibles!\n");
	if (g_globs.Pcount > 1)
		ft_error("Error : Too many player positions!\n");
	if (g_globs.Ecount > 1)
		ft_error("Error : Too many exit positions!\n");
}
