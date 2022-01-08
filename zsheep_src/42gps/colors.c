/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:48:40 by sloquet           #+#    #+#             */
/*   Updated: 2022/01/03 14:33:18 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

void	c_black(void)
{
	PRINT(BLACK);
}

void	c_red(void)
{
	PRINT(RED);
}

void	c_green(void)
{
	PRINT(GREEN);
}

void	c_yellow(void)
{
	PRINT(YELLOW);
}

void	c_blue(void)
{
	PRINT(BLUE);
}

void	c_magenta(void)
{
	PRINT(MAGENTA);
}

void	c_cyan(void)
{
	PRINT(CYAN);
}

void	c_white(void)
{
	PRINT(WHITE);
}

void	c_bold(void)
{
	PRINT(BOLD);
}

void	c_reset(void)
{
	PRINT(NORMAL);
}

void	c_color(char *color)
{
	PRINT(color);
}

void	c_colorbool(int x, char *true_color, char *false_color)
{
	if (x)
		PRINT(true_color);
	else
		PRINT(false_color);
}

void	cprintf(char *color, char *s)
{
	PRINT(NORMAL);
	PRINT(color);
	PRINT(s);
	PRINT(NORMAL);
}

void	cfprintf(char *color, char *format, char *s)
{
	PRINT(color);
	PRINT(format);
	PRINT(s);
	PRINT(NORMAL);
}

void	c_colorpalette(void)
{
	cprintf(BLACK, "The cow jumped over the moon.\n");
	cfprintf(BLACK, BOLD, "The cow jumped over the moon.\n");
	cfprintf(BLACK, ULINE, "The cow jumped over the moon.\n");
	cprintf(RED, "The cow jumped over the moon.\n");
	cfprintf(RED, BOLD, "The cow jumped over the moon.\n");
	cfprintf(RED, ULINE, "The cow jumped over the moon.\n");
	cprintf(GREEN, "The cow jumped over the moon.\n");
	cfprintf(GREEN, BOLD, "The cow jumped over the moon.\n");
	cfprintf(GREEN, ULINE, "The cow jumped over the moon.\n");
	cprintf(YELLOW, "The cow jumped over the moon.\n");
	cfprintf(YELLOW, BOLD, "The cow jumped over the moon.\n");
	cfprintf(YELLOW, ULINE, "The cow jumped over the moon.\n");
	cprintf(BLUE, "The cow jumped over the moon.\n");
	cfprintf(BLUE, BOLD, "The cow jumped over the moon.\n");
	cfprintf(BLUE, ULINE, "The cow jumped over the moon.\n");
	cprintf(MAGENTA, "The cow jumped over the moon.\n");
	cfprintf(MAGENTA, BOLD, "The cow jumped over the moon.\n");
	cfprintf(MAGENTA, ULINE, "The cow jumped over the moon.\n");
	cprintf(CYAN, "The cow jumped over the moon.\n");
	cfprintf(CYAN, BOLD, "The cow jumped over the moon.\n");
	cfprintf(CYAN, ULINE, "The cow jumped over the moon.\n");
	cprintf(WHITE, "The cow jumped over the moon.\n");
	cfprintf(WHITE, BOLD, "The cow jumped over the moon.\n");
	cfprintf(WHITE, ULINE, "The cow jumped over the moon.\n");
}
