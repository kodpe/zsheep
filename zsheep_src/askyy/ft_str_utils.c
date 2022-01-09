/*
 *		ft_str_utils.c
 */

#include "askyy.h"

int	ft_foundchar(char *src, char c)
{
	while (*src)
	{
		if (c == *src)
			return (1);
		src++;
	}
	return (0);
}

void	ft_fill_char_wstr(char *c, char *src)
{
	*c = src[rand() % ft_strlen(src)];
}

void	ft_fill_str_wchar(char *dest, char c)
{
	while (*dest)
		*dest++ = c;
}

void	ft_fill_str_wstr(char *dest, char *src)
{
	while (*dest)
		*dest++ = src[rand() % ft_strlen(src)];
}

void	ft_fill_str_wchar_mod(char *dest, char c, int mod)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		if (i % mod > 0)	
			dest[i] = '$';
		else
			dest[i] = c;
		i++;
	}
}
