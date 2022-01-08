/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:54:37 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/03 15:05:29by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbox.h"
#include "get_gps.h"
#include "draw_clusters.h"

static int	error(char *av1)
{
	if (!av1)
		printf("Error : >> invalid position\n");
	else
		printf("Error : '%s' >> invalid position\n", av1);
	return (1);
}

static void	setup_cluster(char ***box)
{
	size_t	h;
	size_t	len;

	h = hboxlen(box);
	len = strlen(box[0][0]);
	for (int z = 0; box[z]; z++)
	{
		for (int y = 0; box[z][y]; y++) {
			for (int x = 0; box[z][y][x]; x++)
				box[z][y][x] = ' ';
			box[z][y][0] = '/';
			box[z][y][14] = '.';
			box[z][y][32] = '.';
			box[z][y][len - 1] = '/';
		}
		for (size_t x = 0; x < len; x++)
			box[z][0][x] = '_';
		box[z][0][0] = ' ';
		box[z][0][len - 2] = ' ';
		box[z][0][len - 1] = ' ';
		for (size_t x = 0; x < len; x++)
			box[z][h - 1][x] = '-';
		box[z][h - 1][len - 1] = ' ';
	}
}

static void	put_target(char ***box, seat gps, char c)
{
	if ((gps.r == 1 || gps.r == 13) && gps.p > 7)
		gps.p += 9;
	else if (gps.r == 9 && gps.p > 13)
		gps.p += 3;
	else if ((gps.r == 9 || gps.r == 8) && gps.p > 6)
		gps.p += 2;
	else if (gps.r == 7 && gps.e == 1 && gps.p > 6)
		gps.p += 1;
	else if (gps.r == 3 && gps.p > 14)
		gps.p += 2;
	else if (gps.r == 3 && gps.p > 7)
		gps.p += 1;
	else if (gps.r == 5 && gps.e != 1 && gps.p > 16)
		gps.p += 1;
	else if (gps.r == 6 && gps.e == 1 && gps.p > 14)
		gps.p += 2;
	else if (gps.r == 6 && gps.e != 1 && gps.p > 14)
		gps.p += 3;
	else if (gps.r == 6 && gps.p > 7)
		gps.p += 1;
	box[3 - gps.e][gps.r][((24 - gps.p) * 2) - 1] = c;
}

void	put_you(char ***box, seat *you)
{
	FILE	*fp;
	int		i;
	char	str[10];

	fp = popen("uname -n", "r");
	if (fp == NULL)
	{
		printf("Failed uname -n\n");
		exit(EXIT_FAILURE);
	}
	fgets(str, 10, fp);
	pclose(fp);
	str[9] = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		i++;
	}
	str[i] = '\0';
	if (getgps(str, you))
		put_target(box, *you, 'o');
}

int	main(int ac, char **av)
{
	char	***box;
	seat	gps;
	seat	you;

	if (ac != 2)
		return (error(0));
	if (!getgps(av[1], &gps))
		return (error(av[1]));
	box = create_box(47, 15, 3);
	if (!box)
	{
		printf("error malloc box\n");
		exit(EXIT_FAILURE);
	}
	setup_cluster(box);
	put_target(box, gps, 'x');
	put_you(box, &you);
	draw_cluster(box, gps, you);
	destroy_box(box);
	return (0);
}
