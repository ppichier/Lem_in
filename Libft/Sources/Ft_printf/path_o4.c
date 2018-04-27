/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_o4.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:16:19 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:16:19 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_checko_0(t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '#') && pattern->precision <= len
	&& pattern->width <= len)
	{
		ft_put_0_o(pattern);
		pattern->width = pattern->width - 1;
	}
	if ((ft_strchr(pattern->flag, '#')
	&& ft_strchr(pattern->flag, '-') && (pattern->width >= len
	|| pattern->precision >= len)))
	{
		ft_put_0_o(pattern);
		pattern->width = pattern->width - 1;
	}
}

void	ft_printo_prec1(t_struct *pattern, int len)
{
	if (pattern->width <= len && pattern->precision > len)
	{
		if (ft_strchr(pattern->flag, '#') && !ft_strchr(pattern->flag, '-'))
		{
			ft_put_0_o(pattern);
			pattern->precision = pattern->precision - 1;
		}
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printo_prec2(t_struct *pattern, int len)
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
			ft_put_0_o(pattern);
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printo_width(t_struct *pattern, int len, uintmax_t nb)
{
	ft_printo_width1(pattern, len, nb);
	ft_printo_width2(pattern, len);
}

void	ft_printo_width1(t_struct *pattern, int len, uintmax_t nb)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision <= len)
	{
		if (ft_strchr(pattern->flag, '#') && nb != 0)
			len = len + 1;
		while (len < pattern->width)
		{
			ft_putchar_st(' ', pattern);
			len++;
		}
		if (ft_strchr(pattern->flag, '#') && nb != 0)
			ft_put_0_o(pattern);
	}
}
