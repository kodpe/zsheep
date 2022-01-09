/*
 *		ft_create_screen.c
 */
#include <stdio.h>
#define DNF "ft_create_screen.c >> "

#include "askyy.h"

/* obsolete
int	ft_get_screen_size(int ac, char **av, int *x, int *y)
{
	if (ac != 3)
		return (0);
	*x = atoi(av[1]);
	*y = atoi(av[2]);
	if (*x < 30 || *y < 30)
		return (0);
	return (1);
}
*/

char	**ft_init_screen(int x, int y)
{
	char	**screen;
	int		i;
	int		k;

	/*
	printf(DNF"ft_init_screen START paused.");  
	getchar(); 
	printf("y %d\n", y);
	*/
	screen = (char **)malloc(sizeof(char *) * (y + 1));
	if (!screen)
		return (0);
	screen[y] = 0;
	i = 0;
	while (i < y)
	{
		screen[i] = (char *)malloc(sizeof(char) * (x + 1));
		if (!screen[i])
			return (0);
		k = 0;
		while (k < x)
			screen[i][k++] = ' ';
		screen[i][x] = 0;
		i++;
	}
	//printf(DNF"ft_init_screen END paused.");  
	//getchar(); 
	return (screen);
}


void	ft_mark_center(char **world, int x, int y)
{
	world[y / 2][x / 2] = '*';
	if (y % 2 == 0)
		world[(y / 2) - 1][x / 2] = '*';
	if (x % 2 == 0)
		world[y / 2][(x / 2) - 1] = '*';
	if (x % 2 == 0 && y % 2 == 0)
		world[(y / 2) - 1][(x / 2) - 1] = '*';
}
