/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_i_d4.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:07:06 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:07:07 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printd_prec1(intmax_t nb, t_struct *pattern, int len)
{
	if (pattern->width <= len && pattern->precision > len)
	{
		if (ft_strchr(pattern->flag, '+') && !ft_strchr(pattern->flag, '-'))
			ft_put_sign(nb, pattern);
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printd_prec2(intmax_t nb, t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision)
	{
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width < pattern->precision)
	{
		if (ft_strchr(pattern->flag, '+'))
			ft_put_sign(nb, pattern);
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printd_width1(intmax_t nb, t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision <= len)
	{
		if (ft_strchr(pattern->flag, '+'))
			len = len + 1;
		while (len < pattern->width)
		{
			ft_putchar_st(' ', pattern);
			len++;
		}
		if (ft_strchr(pattern->flag, '+'))
			ft_put_sign(nb, pattern);
	}
}

void	ft_printd_width2(intmax_t nb, t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision)
	{
		len = (pattern->width - pattern->precision);
		if (ft_strchr(pattern->flag, '+'))
			len = len - 1;
		while (len > 0)
		{
			ft_putchar_st(' ', pattern);
			len--;
		}
		if (ft_strchr(pattern->flag, '+'))
			ft_put_sign(nb, pattern);
	}
	if (pattern->precision > len
	&& pattern->width > len && pattern->precision == pattern->width)
	{
		if (ft_strchr(pattern->flag, '+'))
			ft_put_sign(nb, pattern);
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}
