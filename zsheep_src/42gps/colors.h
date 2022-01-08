/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:43:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/03 14:32:25 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdio.h>

# define PRINT printf
# define ESC "\033["

# define NORMAL 	ESC "0m"
# define BOLD 		ESC "1m"
# define ULINE 		ESC "4m"

# define BLACK		ESC "30m"
# define RED		ESC "31m"
# define GREEN 		ESC "32m"
# define YELLOW 	ESC "33m"
# define BLUE 		ESC "34m"
# define MAGENTA	ESC "35m"
# define CYAN		ESC "36m"
# define WHITE 		ESC	"37m"

void	c_black(void);
void	c_red(void);
void	c_green(void);
void	c_yellow(void);
void	c_blue(void);
void	c_magenta(void);
void	c_cyan(void);
void	c_white(void);
void	c_bold(void);
void	c_reset(void);

void	c_color(char *color);
void	c_colorbool(int x, char *true_color, char *false_color);

void	cprintf(char *color, char *s);
void	cfprintf(char *color, char *format, char *s);

void	c_colorpalette(void);

#endif
