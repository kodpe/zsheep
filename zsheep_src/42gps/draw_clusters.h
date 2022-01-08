/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_clusters.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:07:37 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/03 16:23:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_CLUSTERS_H
# define DRAW_CLUSTERS_H

# include <stdio.h>
# include <string.h>
# include "get_gps.h"
# include "colors.h"

# define COLOR_E3 MAGENTA
# define COLOR_E2 CYAN
# define COLOR_E1 GREEN

void	draw_cluster(char ***box, seat gps, seat you);

#endif
