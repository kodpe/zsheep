/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clusters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:06:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/03 16:16:11by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_clusters.h"

static int	xray(seat gps, int e)
{
	if (gps.e == 3 - e && gps.r < 7 && gps.p > 4)
		return (1);
	return (0);
}

static void	putyspaces(int y, char *namefloor)
{
	if (y != 10)
	{
		for (int i = 0; i < 13 - y; i++)
			printf(" ");
	}
	if (y == 10)
	{
		printf("%s", namefloor);
		printf(" ");
	}
}

static void	eputc(int e, char c)
{
	c_colorbool(e, COLOR_E1, COLOR_E2);
	printf("%c", c);
	c_colorbool(e, COLOR_E2, COLOR_E3);
}

static void	draw_inter(char ***box, int e, char *namefloor, seat gps)
{
	char	c, v, b;

	for (int y = 8; y < 15; y++)
	{
		c_colorbool(e, COLOR_E2, COLOR_E3);
		putyspaces(y, namefloor);
		if (y == 14)
		{
			for (int x = 1; x < 8; x++)
				printf("%c", box[e][y][x]);
		}
		else
		{
			for (int x = 0; x < 8; x++)
				printf("%c", box[e][y][x]);
		}
		for (int x = 8; box[e][y][x]; x++)
		{
			c = box[e + 1][y - 8][x - 8];
			v = box[e + 1][y - 8][x - 8 + 1];
			b = box[e + 1][y - 8][x - 8 - 1];
			if (xray(gps, e + 1) && ((c == '/' && y % 2 == 1)
				|| (c == '_' && x % 5 == 0)
				|| (c == '.' && box[e][y][x] == ' ') || (c == 'x')))
				eputc(e, c);
			else if (xray(gps, e + 1) && (y == 14 && (b == 'x' || v == 'x')))
				printf(" ");
			else
				printf("%c", box[e][y][x]);
		}
		c_colorbool(e, COLOR_E1, COLOR_E2);
		printf("%s\n", &box[e + 1][y - 8][39]);
	}
	printf("      %s\n", box[e + 1][7]);
}

static void	draw_cluster_top(char ***box, seat gps)
{
	c_color(COLOR_E3);
	for (int y = 0; y < 8; y++)
	{
		if (y == 1)
		{
			if (gps.e == 2)
				c_color(COLOR_E2);
			if (gps.e == 1)
				c_color(COLOR_E1);
			printf("%s", gps.av);
			for (size_t i = 0; i < 12 - strlen(gps.av); i++)
				printf(" ");
			c_color(COLOR_E3);
		}
		else
		{
			for (int i = 0; i < 13 - y; i++)
				printf(" ");
		}
		printf("%s", box[0][y]);
		printf("\n");
	}
}

static void	draw_cluster_bot(char ***box, seat gps, seat you)
{
	c_color(COLOR_E1);
	for (int y = 8; box[2][y]; y++)
	{
		putyspaces(y, "E1");
		printf("%s", box[2][y]);
		if (y == 12)
		{
			if (you.e == 3)
				c_color(COLOR_E3);
			if (you.e == 2)
				c_color(COLOR_E2);
			if (you.e == 1)
				c_color(COLOR_E1);
			printf("    you o");
			c_color(COLOR_E1);
		}
		if (y == 13)
		{
			if (gps.e == 3)
				c_color(COLOR_E3);
			if (gps.e == 2)
				c_color(COLOR_E2);
			if (gps.e == 1)
				c_color(COLOR_E1);
			printf("  target x");
			c_color(COLOR_E1);
		}
		printf("\n");
	}
	for (int i = 0; i < 34; i++)
		printf(" ");
	printf("Food Truck\n");
}

void	draw_cluster(char ***box, seat gps, seat you)
{
	c_bold();
	draw_cluster_top(box, gps);
	draw_inter(box, 0, "E3", gps);
	draw_inter(box, 1, "E2", gps);
	draw_cluster_bot(box, gps, you);
	c_reset();
}
