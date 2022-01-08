/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbox.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:43:49 by sloquet           #+#    #+#             */
/*   Updated: 2021/12/26 18:43:49 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBOX_H
# define LIBBOX_H

# include <stdlib.h>
# include <stdio.h>

char	***create_box(const int x, const int y, const int z);

size_t	hboxlen(char ***box);

void	display_box(char ***box);

void	destroy_box(char ***box);

#endif
