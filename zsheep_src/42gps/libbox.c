/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:35:05 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/03 14:21:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbox.h"

char	***create_box(const int x, const int y, const int z)
{
	char	***box;

	box = (char ***)malloc(sizeof(char **) * (z + 1));
	if (!box)
		return (NULL);
	box[z] = NULL;
	for (int iz = 0; iz < z; iz++)
	{
		box[iz] = (char **)malloc(sizeof(char *) * (y + 1));
		if (!box[iz])
			return (NULL);
		box[iz][y] = NULL;
		for (int iy = 0; iy < y; iy++)
		{
			box[iz][iy] = (char *)malloc(sizeof(char) * (x + 1));
			if (!box[iz][iy])
				return (NULL);
			box[iz][iy][x] = 0;
			for (int ix = 0; ix < x; ix++)
				box[iz][iy][ix] = 42;
		}
	}
	return (box);
}

size_t	hboxlen(char ***box)
{
	size_t	h;

	h = 0;
	while (box[0][h])
		h++;
	return (h);
}

void	display_box(char ***box)
{
	int	h;

	h = (int)hboxlen(box) - 1;
	for (int z = 0; box[z]; z++)
	{
		for (int y = 0; box[z][y]; y++)
		{
			for (int i = 0; i < h - y; i++)
				printf(" ");
			printf("%s", box[z][y]);
			printf("\n");
		}
		printf("\n");
	}
}

void	destroy_box(char ***box)
{
	for (int z = 0; box[z]; z++)
	{
		for (int y = 0; box[z][y]; y++)
			free(box[z][y]);
		free(box[z]);
	}
	free(box);
	box = NULL;
}
