/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:19:39 by sloquet           #+#    #+#             */
/*   Updated: 2021/12/27 19:19:39 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_gps.h"

static void	getfloor(char *av, seat *gps)
{
	gps->e = 0;
	if (av[0] == 'e' && av[1] >= '1' && av[1] <= '3' && av[2] == 'r')
		gps->e = av[1] - 48;
}

static void	getrow(char *av, seat *gps)
{
	gps->r = 0;
	if (av[2] != 'r')
		return ;
	if (av[3] >= '1' && av[3] <= '9' && av[4] == 'p')
		gps->r = av[3] - 48;
	if (av[3] == '1' && av[4] >= '0' && av[4] <= '3' && av[5] == 'p')
		gps->r = 10 + av[4] - 48;
}

static void	getseat(char *av, seat *gps)
{
	gps->p = 0;
	if (av[4] == 'p')
	{
		if (av[5] == '1' && av[6] >= '0' && av[6] <= '9' && !av[7])
			gps->p = 10 + av[6] - 48;
		if (av[5] == '2' && av[6] >= '0' && av[6] <= '3' && !av[7])
			gps->p = 20 + av[6] - 48;
		if (av[5] >= '1' && av[5] <= '9' && !av[6])
			gps->p = av[5] - 48;
	}
	if (av[5] == 'p')
	{
		if (av[6] == '1' && av[7] >= '0' && av[7] <= '9' && !av[8])
			gps->p = 10 + av[7] - 48;
		if (av[6] == '2' && av[7] >= '0' && av[7] <= '3' && !av[8])
			gps->p = 20 + av[7] - 48;
		if (av[6] >= '1' && av[6] <= '9' && !av[7])
			gps->p = av[6] - 48;
	}
}

static void	checkseat(seat *gps)
{
	if (gps->p > 21 && (gps->r == 3 || gps->r == 8))
		gps->p = 0;
	if (gps->p > 20 && gps->r == 9)
		gps->p = 0;
	if (gps->p > 14 && (gps->r == 1 || gps->r == 13))
		gps->p = 0;
	if (gps->r == 5)
	{
		if (gps->p == 23 && gps->e != 1)
			gps->p = 0;
	}
	if (gps->r == 6)
	{
		if (gps->p > 20 && gps->e > 1)
			gps->p = 0;
		if (gps->p > 21 && gps->e == 1)
			gps->p = 0;
	}
	if (gps->r == 7)
	{
		if (gps->p == 23 && gps->e == 1)
			gps->p = 0;
	}
}

int	getgps(char *av, seat *gps)
{
	getfloor(av, gps);
	getrow(av, gps);
	getseat(av, gps);
	checkseat(gps);
	if (!gps->e || !gps->r || !gps->p)
		return (0);
	gps->av = av;
	return (1);
}
