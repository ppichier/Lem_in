/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_x4.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:13:18 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:13:19 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printh_prec1(t_struct *pattern, int len)
{
	if (pattern->width <= len && pattern->precision > len)
	{
		if (ft_strchr(pattern->flag, '#') && !ft_strchr(pattern->flag, '-'))
			ft_put_diese_hex(pattern);
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printh_prec2(t_struct *pattern, int len)
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
		if (ft_strchr(pattern->flag, '#'))
			ft_put_diese_hex(pattern);
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printh_width(t_struct *pattern, int len, uintmax_t nb)
{
	ft_printh_width1(pattern, len, nb);
	ft_printh_width2(pattern, len);
}

void	ft_printh_width1(t_struct *pattern, int len, uintmax_t nb)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision <= len)
	{
		if (ft_strchr(pattern->flag, '#') && (nb != 0 || pattern->conv == 'p'))
			len = len + 2;
		while (len < pattern->width)
		{
			ft_putchar_st(' ', pattern);
			len++;
		}
		if (ft_strchr(pattern->flag, '#') && (nb != 0 || pattern->conv == 'p'))
			ft_put_diese_hex(pattern);
	}
}

void	ft_printh_width2(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision)
	{
		len = (pattern->width - pattern->precision);
		if (ft_strchr(pattern->flag, '#'))
			len = len - 2;
		while (len > 0)
		{
			ft_putchar_st(' ', pattern);
			len--;
		}
		if (ft_strchr(pattern->flag, '#'))
			ft_put_diese_hex(pattern);
	}
	if (pattern->precision > len
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
