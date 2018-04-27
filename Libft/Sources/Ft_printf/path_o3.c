/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_o3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:16:15 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:16:15 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printo_width2(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision)
	{
		len = (pattern->width - pattern->precision);
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
	if (pattern->precision > len
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

void	ft_printo_width_0(t_struct *pattern, int len)
{
	ft_printo_width_03(pattern, len);
	ft_printo_width_03b(pattern, len);
	ft_printo_width_01(pattern, len);
	ft_printo_width_02(pattern, len);
	ft_printo_width_04(pattern, len);
	ft_printo_width_04b(pattern, len);
}

void	ft_printo_width_01(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision < len && pattern->width < pattern->precision)
	{
		if (ft_strchr(pattern->flag, '#'))
		{
			ft_put_0_o(pattern);
			len = len + 1;
		}
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
	if (ft_strchr(pattern->flag, '-') && pattern->width > len
	&& (pattern->width > pattern->precision && pattern->precision > len))
	{
		if (ft_strchr(pattern->flag, '#') && !ft_strchr(pattern->flag, '-'))
			ft_put_0_o(pattern);
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printo_width_02(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision
	&& !ft_strchr(pattern->flag, '0'))
	{
		len = (pattern->width - pattern->precision);
		if (ft_strchr(pattern->flag, '#'))
			len = len - 1;
		while (len > 0)
		{
			ft_putchar_st('0', pattern);
			len--;
		}
		if (ft_strchr(pattern->flag, '#'))
			ft_put_0_o(pattern);
	}
	if (ft_strchr(pattern->flag, '-') && pattern->width > len
	&& (pattern->width < pattern->precision && pattern->precision > len))
	{
		while (len < pattern->precision)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printo_width_03(t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '0') && pattern->precision > len
	&& pattern->width > len && pattern->width > pattern->precision)
	{
		len = pattern->width - pattern->precision;
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
