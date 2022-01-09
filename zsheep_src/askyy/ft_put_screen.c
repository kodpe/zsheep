/*
 *		ft_askyy_put_screen.c
 */

#include "askyy.h"

void	ft_puttop(int x)
{    
	ft_putstr("\n \u250f");
	while (x-- > 0)
		ft_putstr("\u2501");
	ft_putstr("\u2513\n");
}

void	ft_putmid(char *line)
{
	ft_putstr(" \u2503");
	ft_xputstr(line);
	ft_putstr("\u2503\n");
}

void	ft_putbot(int x)
{    
	ft_putstr(" \u2517");
	while (x-- > 0)
		ft_putstr("\u2501");
	ft_putstr("\u251b\n");
}

void	ft_display_reset(int y)
{
	while (y-- > 0)
		ft_putstr("\33[A");
	ft_putstr("\33[2K\r");
}

void	ft_display_screen(char **screen, int x)
{
	ft_puttop(x);
	while (*screen)
		ft_putmid(*screen++);
	ft_putbot(x);
}

void	ft_caption(int x)
{
	ft_putstr("\33[2K\r");
	ft_putqchar(' ', (x - 10) / 2); 
	ft_putstr("ON THE ROAD...");
}

void	ft_tmp(int x, int y, int fps, int du, int k)
{
	ft_putstr("\33[2K\r");
	ft_putstr(" x: ");
	ft_putnbr(x);
	ft_putstr("  y: ");
	ft_putnbr(y);
	ft_putstr("  fps: ");
	ft_putnbr(fps);
	ft_putstr("  time: ");
	ft_putnbr(du);
	ft_putstr("  frames: ");
	ft_putnbr(k);
	ft_putstr("  x*y: ");
	ft_putnbr(x * y);
}
