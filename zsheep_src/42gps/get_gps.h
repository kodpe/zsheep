/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gps.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:20:31 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/03 14:52:31 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_GPS_H
# define GET_GPS_H

typedef struct seat
{
	char	*av;
	int		e;
	int		r;
	int		p;
}	seat;

int	getgps(char *av, seat *gps);

#endif
