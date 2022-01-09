/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   askyy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:23:36 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/09 00:53:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASKYY_H
# define ASKYY_H

#include <time.h>
#include <stdlib.h>
#include <unistd.h>

/*
 *		ft_len.c
 */
int		ft_strlen(char *str);
//int		ft_nbrlen(int nbr);
//int		ft_doublelen(long double db);

/*
 *		ft_put.c
 */
void	ft_putchar(char c);
void	ft_putqchar(char c, int q);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_xputstr(char *str);

/*
 *		ft_put_screen.c
 */
void	ft_puttop(int x);
void	ft_putmid(char *line);
void	ft_putbot(int x);
void	ft_display_reset(int y);
void	ft_display_screen(char **screen, int x);
void	ft_caption(int x);
void	ft_tmp(int x, int y, int fps, int du, int k);

/*
 *		ft_str_utils.c
 */
int		ft_foundchar(char *src, char c);
void	ft_fill_char_wstr(char *c, char *src);
void	ft_fill_str_wchar(char *dest, char c);
void	ft_fill_str_wstr(char *dest, char *src);
void	ft_fill_str_wchar_mod(char *dest, char c, int mod);

/*
 *		ft_tiny_landscape.c
 */
void	ft_make_road(char **world, int y);
void	ft_make_grass(char **world, int y);
void	ft_make_car(char **world, int y, int x);

/*
 *		ft_mountains.c
 */
int		ft_check_for_mountains(char **world, int sh, int ab);
void	ft_create_mountain(char **world, int i, int y, int h);
void	ft_mountains(char **world, int x, int y);

/*
 *		ft_city.c
 */
void	ft_make_rooftop(char **world, int x, int y, int w);
void	ft_make_windows(char **world, int x, int y, int w);
void	ft_make_tower(char **world, int x, int y, int h, int w);
int		ft_new_height(int old, int y);
void	ft_make_city(char **world, int x, int i, int y);
void	ft_city(char **world, int x, int y);

/*
 *		ft_sky.c
 */
int		ft_check_square(char **world, char c, int xpos, int ypos, int size);
void	ft_sky_init(char **world);
void	ft_clean_around_star(char **world, int y, int x);
void	ft_improve_star(char **world, int y, int x);
void	ft_sky_update(char **world);

/*
 *		ft_create_screen.c
 */
int		ft_get_screen_size(int ac, char **av, int *x, int *y);
char	**ft_init_screen(int x, int y);
//void	ft_mark_center(char **world, int x, int y);

#endif
