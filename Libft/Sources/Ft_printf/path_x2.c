/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_x2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:13:10 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:13:10 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printh_width_04(t_struct *pattern, int len)
{
	if (pattern->precision > len
	&& pattern->width > len && pattern->precision == pattern->width
	&& ft_strchr(pattern->flag, '0'))
	{
		if (ft_strchr(pattern->flag, '#'))
			ft_put_diese_hex(pattern);
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
	if (ft_strchr(pattern->flag, '#') && pattern->precision > len
	&& pattern->width > len && pattern->precision == pattern->width)
	{
		if (ft_strchr(pattern->flag, '#'))
			ft_put_diese_hex(pattern);
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printh_width_04b(t_struct *pattern, int len, uintmax_t nb)
{
	if (pattern->width > len && pattern->precision < len
	&& !ft_strchr(pattern->flag, '-'))
	{
		if (pattern->point == '.' && pattern->precision < len)
		{
			if (ft_strchr(pattern->flag, '#') && (nb != 0
				|| pattern->conv == 'p'))
				len = len + 2;
			while (len < pattern->width)
			{
				ft_putchar_st(' ', pattern);
				len++;
			}
			if (ft_strchr(pattern->flag, '#') && (nb != 0
				|| pattern->conv == 'p'))
				ft_put_diese_hex(pattern);
		}
		else
			ft_printh_width_04c(pattern, len, nb);
	}
}

void	ft_printh_width_04c(t_struct *pattern, int len, uintmax_t nb)
{
	if (ft_strchr(pattern->flag, '#') && (nb != 0
		|| pattern->conv == 'p'))
	{
		ft_put_diese_hex(pattern);
		len = len + 2;
	}
	while (len < pattern->width)
	{
		ft_putchar_st('0', pattern);
		len++;
	}
}

void	ft_printh_prec_rev(t_struct *pattern, int len)
{
	int a;

	a = pattern->width - pattern->precision;
	if (ft_strchr(pattern->flag, '-') && pattern->width > len
	&& (pattern->width > pattern->precision && pattern->precision <= len
	&& (ft_strchr(pattern->flag, '#'))))
		a = a - 2;
	if (pattern->precision > len && pattern->width > len
	&& ft_strchr(pattern->flag, '-') && pattern->width > pattern->precision)
	{
		while (a > 0)
		{
			ft_putchar_st(' ', pattern);
			a--;
		}
	}
	if (pattern->width > len && ft_strchr(pattern->flag, '-')
	&& pattern->precision <= len)
	{
		while (len < pattern->width)
		{
			ft_putchar_st(' ', pattern);
			len++;
		}
	}
}

void	ft_put_diese_hex(t_struct *pattern)
{
	if (pattern->conv == 'x' || pattern->conv == 'p')
	{
		ft_putchar_st('0', pattern);
		ft_putchar_st('x', pattern);
	}
	else
	{
		ft_putchar_st('0', pattern);
		ft_putchar_st('X', pattern);
	}
}
