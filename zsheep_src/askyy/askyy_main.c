/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   askyy_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:33:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/09 03:00:42 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "askyy.h"
#include <stdio.h>
#define DNF "askyy_main.c >> "

void	ft_free_array(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free (a[i]);
		i++;
	}
	free (a);
}

void	ft_screen_update(char **world, char **futur, int x, int f)
{
	int	y;
	int	i;

	y = 0;
	while (world[y])
	{
		i = 0;
		while (i + 1 < x)
		{
			world[y][i] = world[y][i + 1];
			i++;
		}
		world[y][i] = futur[y][f];
		y++;
	}
}

void	ft_make_fix_world(char **w, int x, int y) 
{
	//printf(DNF"ft_make_fix_world START paused.");  
	//getchar(); 

	//printf(DNF"ft_make_fix_world DO ft_make_road paused.");  
	//getchar(); 
	ft_make_road(w, y);

	//printf(DNF"ft_make_fix_world DO ft_make_grass paused.");  
	//getchar(); 
	ft_make_grass(w, y);

	//printf(DNF"ft_make_fix_world DO ft_mountains paused.");  
	//getchar(); 
	ft_mountains(w, x, y);

	//printf(DNF"ft_make_fix_world DO ft_make_city paused.");  
	//getchar(); 
	ft_city(w, x, y - 5);

	//printf(DNF"ft_make_fix_world DO ft_sky_init paused.");  
	//getchar(); 
	ft_sky_init(w);

	//printf(DNF"ft_make_fix_world END paused.");  
	//getchar(); 
}

/*
	int		x; // length in cm
	int		y; // height in cm

	x && y >= 6 
	x 6 - 53
	y 6 - 28
*/
#include <sys/ioctl.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		x;
	int		y;
	int		fps;
	char	**w;

	struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    //ioctl(STDOUT_FILENO, 0x5413, &window);

    //printf ("columns %d\n", window.ws_col);
    //printf ("lines %d\n", window.ws_row);
	x = window.ws_col;
	y = window.ws_row;
	if (x < 32|| y < 16) {
		printf("> askyy error\n> window too small\n    (%dx%d)\n", x, y);
		printf("\n> minimum size is\n    (32x16)\n");
		return (0);
	}
	x = window.ws_col - 3;
	y = window.ws_row - 4;
	//printf("x %d\ny %d\n", x, y);
	//printf("Paused. WHILE step < remake\n");
	//getchar();

	/*
	if (!ft_get_screen_size(ac, av, &x, &y))
		return (0);
	*/

	srand(time(NULL));
	//x *= 5.2;
	//y *= 2.5;
	fps = x * 100;

	// printf("x %d\ny %d\nfps %d\n", x, y, fps);
	// exit(EXIT_SUCCESS);

	char	**futur;
	int	f;
	int	k;
	int	step = 0;
	int remake = 1;
	while (step < remake)
	{
		w = ft_init_screen(x, y);
		//printf("Paused. WHILE step < remake\n");
		//getchar();
		ft_make_fix_world(w, x, y); // add fix obj

		futur = ft_init_screen(x, y);
		ft_make_fix_world(futur, x, y);
		f = 0;
		k = 0;
		while (k < fps)
		{
			ft_screen_update(w, futur, x, f);
			f++;
			/* objets animés */
			if (k % 4 == 0)
				ft_sky_update(w);
			ft_make_car(w, y - 3, x);
			ft_display_screen(w, x);
			ft_caption(x);
			//ft_tmp(x, y, fps, remake - step, k);
			ft_display_reset(y + 3);
			k++;
			usleep(1000000 / (30 * 1.5)); // 1.5 s
			usleep(1000000 / 30); // one second
			//usleep(1000000); // one second
			if (f == x)
			{
				ft_free_array(futur);
				futur = ft_init_screen(x, y);
				ft_make_fix_world(futur, x, y);
				f = 0;
			}
		}
		//usleep(1000000 / 30); // one second
		step++;

		/* world free */
		ft_free_array(w);
		ft_free_array(futur);
	}
	return (0);
}


/*

   __/_o_o_\____   
   '-o--------o-'


     /\
  || || ||
  || || || 
   \\||//
     ||
     ||

   /\
   /  \
   /    \
   / _  _ \     /\
 /   O    \   /  \
/  p qp q  \ /    \

`"``'"`"''``"'''`"```""""'"''
`"```"`"`'``'"``"``''"'`"'"`'
GAZON {34, 39, 96} 


   char obj[50] = "+  *  .  °  o  O  '  ~  , -"

   spaces objects

   + / * / . / -0- / ° / o / O / ' / .
	. 
    o
	'

   VOLCANO
	//usleep(1000000 / 60); // 60 fps
	//usleep(1000000); // one second
	//usleep(1000000 / 10); // one second

    |
   -O-
    |

   ovo / vov / -°- / -)- / -(- / ]o[ / }o{ / )o( /

   'T' / 

   _/\_
   \/\/

 */
