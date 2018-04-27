/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_o2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:16:11 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:16:11 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printo_width_03b(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '0') && pattern->width > len
	&& pattern->width > pattern->precision && pattern->precision < len
	&& !ft_strchr(pattern->flag, '-'))
	{
		len = pattern->width - len;
		if (ft_strchr(pattern->flag, '#'))
			len = len - 1;
		while (len > 0)
		{
			ft_putchar_st(' ', pattern);
			len--;
		}
		if (ft_strchr(pattern->flag, '#'))
			ft_put_0_o(pattern);
	}
}

void	ft_printo_width_04(t_struct *pattern, int len)
{
	if (pattern->precision > len
	&& pattern->width > len && pattern->precision == pattern->width
	&& ft_strchr(pattern->flag, '0'))
	{
		if (ft_strchr(pattern->flag, '#'))
			ft_put_0_o(pattern);
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
			ft_put_0_o(pattern);
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printo_width_04b(t_struct *pattern, int len)
{
	if (pattern->width > len && pattern->precision < len
	&& !ft_strchr(pattern->flag, '-'))
	{
		if (ft_strchr(pattern->flag, '#'))
			len = len + 1;
		while (len < pattern->width)
		{
			if (pattern->point == '.' && pattern->precision <= 0)
				ft_putchar_st(' ', pattern);
			else
				ft_putchar_st('0', pattern);
			len++;
		}
		if (ft_strchr(pattern->flag, '#'))
			ft_put_0_o(pattern);
	}
}

void	ft_printo_prec_rev(t_struct *pattern, int len)
{
	int a;

	a = pattern->width - pattern->precision;
	if (ft_strchr(pattern->flag, '-') && pattern->width > len
	&& (pattern->width > pattern->precision && pattern->precision <= len
	&& (ft_strchr(pattern->flag, '#'))))
		a = a - 1;
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

void	ft_put_0_o(t_struct *pattern)
{
	ft_putchar_st('0', pattern);
}
