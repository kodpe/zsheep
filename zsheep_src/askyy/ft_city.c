/*
 *		ft_city.c
 */
 
#include "askyy.h"
#include <stdio.h>
#define DNF "ft_city.c >> "

void	ft_make_rooftop(char **world, int x, int y, int w)
{
	while (w-- > 0)
	{
		if (world[y][x + w] != '|')
			world[y][x + w] = '_';
	}
}

void	ft_make_windows(char **world, int x, int y, int w)
{
	char	widow[8] = "::::::-";
	int		i;

	i = rand() % ft_strlen(widow);
	while (w > 0)
	{
		world[y][x + w] = widow[i];
		w--;
	}
}

void	ft_make_tower(char **world, int x, int y, int h, int w)
{
	ft_make_rooftop(world, x, h, w + 2);
	while (y > h)
	{
		world[y][x] = '|';
		world[y][x + w + 1] = '|';
		ft_make_windows(world, x, y, w);
		y--;
	}
}

int	ft_new_height(int old, int y)
{
	int	h;

	h = 0;
	h = y - ((rand() % y / 6) + (y / 9));
	/*
	printf(DNF"ft_get_height BEFORE WHILE paused.");  
	getchar(); 
	printf("y = %d\n", y);
	printf("last_h = %d\n", old);
	printf("h = %d\n", h);
	*/
	while (h == old)
		h = y - ((rand() % y / 6) + (y / 9));
	return (h);
}

void	ft_make_city(char **world, int x, int i, int y)
{
	//printf(DNF"ft_make_city START paused.");  
	//getchar(); 

	int	size;
	int	h;
	int	w;

	w = 0;
	h = 0;
	size = i + 12;
	while (i + 4 < x && i < size)
	{
		h = ft_new_height(h, y); 
		//printf(DNF"ft_make_city ft_get_height DONE paused.");  
		//getchar(); 
		w = rand() % 3 + 1;
		ft_make_tower(world, i, y, h, w);
		i += w + 1;
	}
	//printf(DNF"ft_make_city END paused.");  
	//getchar(); 
}

void	ft_city(char **world, int x, int y)
{
	int	i;

	i = 0;
	while (i + 4 < x)
	{
		if (rand() % 40 == 0)
		{
			ft_make_city(world, x, i, y);
			i += 12;
		}
		i++;
	}
}
