/*
 *		ft_sky.c
 */

#include "askyy.h"

int	ft_check_square(char **world, char c, int xpos, int ypos, int size)
{
	int	i;
	int	j;

	if (size % 2 == 0)
		size++;
	ypos -= size / 2;
	xpos -= size / 2;
	if (ypos < 0 || xpos < 0)
		return (0);
	j = ypos;
	while (world[j] && j < ypos + size) 	
	{
		i = xpos;
		while (world[j][i] && i < xpos + size) 	
		{
			if (world[j][i] != c)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_sky_init(char **world)
{
	int	y;
	int	x;

	y = 0;
	while (world[y])
	{
		x = 0;
		while (world[y][x])
		{
			if (rand() % 100 == 0 && ft_check_square(world, ' ', x, y, 5))
				world[y][x] = '*';
			x++;	
		}
		y++;
	}
}

void	ft_clean_around_star(char **world, int y, int x)
{
	if (world[y][x - 1])
		world[y][x - 1] = ' ';
	if (world[y][x + 1])
		world[y][x + 1] = ' ';
	if (world[y - 1][x])
		world[y - 1][x] = ' ';
	if (world[y + 1][x])
		world[y + 1][x] = ' ';
}

void	ft_improve_star(char **world, int y, int x)
{
	ft_clean_around_star(world, y, x);
	if (world[y][x] == '0' || world[y][x] == 'O') 
		if (world[y][x - 1] && world[y][x + 1])
		{
			world[y][x - 1] = '-';
			world[y][x + 1] = '-';
		}
	if (world[y][x] == 'O') 
		if (world[y - 1][x] && world[y + 1][x])
		{
			world[y - 1][x] = '|';
			world[y + 1][x] = '|';
		}
}

void	ft_sky_update(char **world)
{
	char	star[48] = "O0.....+++++*****.....+++++*****.....+++++*****";
	int		y;	
	int		x;	

	y = 0;
	while (world[y])
	{
		x = 0;
		while (world[y][x])	
		{
			if (ft_foundchar(star, world[y][x]))
			{
				world[y][x] = star[rand() % ft_strlen(star)];
				if (x > 1)
					ft_improve_star(world, y, x);
			}
			x++;
		}
		y++;
	}
}
