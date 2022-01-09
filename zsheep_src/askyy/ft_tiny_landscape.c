/*
 *		ft_tiny_landscape.c
 */

#include "askyy.h"

void	ft_make_road(char **world, int y)
{
	ft_fill_str_wchar(world[y - 3], '=');
	ft_fill_str_wchar_mod(world[y - 2], '-', 3);
	ft_fill_str_wchar(world[y - 1], '=');
}

void	ft_make_grass(char **world, int y)
{
	char	grass[4] = {34, 39, 96, 0};

	ft_fill_str_wstr(world[y - 4], grass);
}

void	ft_make_car(char **world, int y, int x)
{
	char	obj_car_01[15] = "__,__o_\\_____ ";
	char	obj_car_02[15] = "'-o--------o-'";
	int		i;
	char	grass[4] = {34, 39, 96, 0};

	i = 0;
	while (i < 14)
	{
		world[y - 1][x / 2 - 7 + i] = obj_car_01[i];
		world[y][x / 2 - 7 + i] = obj_car_02[i];
		i++;
	}
	ft_fill_char_wstr(&(world[y - 1][x / 2 - 8]), grass);
	world[y][x / 2 - 8] = '=';
}
