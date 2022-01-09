/*
 *		ft_mountains.c
 */

#include "askyy.h"

int	ft_check_for_mountains(char **world, int sh, int ab)
{
	if (world[sh][ab - 1] == '\\')
		return (1);
	if (world[sh][ab] == '\\')
		return (1);
	if (world[sh][ab + 1] == '\\')
		return (1);
	return (0);
}

void	ft_create_mountain(char **world, int i, int y, int h)
{
	int	a;
	int	b;
	int	sh;

	for (int k = 0; k <= h; k++)
	{
		a = i + k;
		b = 1 + ( h - k) * 2;
		sh = y - (5 + k);
		if (ft_check_for_mountains(world, sh, a + b) == 1)
			break ;
		world[sh][a] = '/';
		world[sh][a + b] = '\\';
		for (int p = 1; p < b; p++)
		{
			if (rand() % 8 == 0 && p != 1 && p < b - 1 && k < h - 0)
			{
					world[sh][a + p] = '^';
					p++;
			}
			world[sh][a + p] = '$';
		}
	}
}

void	ft_mountains(char **world, int x, int y)
{
	int	h;

	for (int i = 1; i < x; i++)
	{
		if (rand() % 6 == 0)
		{
			h = y / 6 + (rand() % (y / 3));
			if (h * 2 + 1 < x - i)
				ft_create_mountain(world, i, y, h);
		}
		i += 2;
	}
}
