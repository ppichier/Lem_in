/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_c3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:03:24 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:03:25 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printc_width1(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision <= len)
	{
		while (len < pattern->width)
		{
			ft_putchar_st(' ', pattern);
			len++;
		}
	}
}

void	ft_printc_width2(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision)
	{
		len = (pattern->width - pattern->precision);
		while (len > 0)
		{
			ft_putchar_st(' ', pattern);
			len--;
		}
	}
	if (pattern->precision > len
	&& pattern->width > len && pattern->precision == pattern->width)
	{
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printc_prec_rev(t_struct *pattern, int len)
{
	int a;

	a = pattern->width - len;
	if (pattern->precision > len && pattern->width > len &&
	ft_strchr(pattern->flag, '-') && pattern->width < pattern->precision)
	{
		while (a > 0)
		{
			ft_putchar_st(' ', pattern);
			a--;
		}
	}
	ft_printc_prec_rev1(pattern, len);
}

void	ft_printc_prec_rev1(t_struct *pattern, int len)
{
	int a;

	a = pattern->width - len;
	if (pattern->precision > len && pattern->width > len &&
	ft_strchr(pattern->flag, '-') && pattern->width > pattern->precision)
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
