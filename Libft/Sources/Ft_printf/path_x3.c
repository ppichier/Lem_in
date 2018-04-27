/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_x3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:13:14 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:13:14 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printh_width_0(t_struct *pattern, int len, uintmax_t nb)
{
	ft_printh_width_03(pattern, len);
	ft_printh_width_03b(pattern, len);
	ft_printh_width_01(pattern, len);
	ft_printh_width_02(pattern, len);
	ft_printh_width_04(pattern, len);
	ft_printh_width_04b(pattern, len, nb);
}

void	ft_printh_width_01(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision < len && pattern->width < pattern->precision)
	{
		if (ft_strchr(pattern->flag, '#'))
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
	if (ft_strchr(pattern->flag, '-') && pattern->width > len
	&& (pattern->width > pattern->precision && pattern->precision > len))
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

void	ft_printh_width_02(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision
	&& !ft_strchr(pattern->flag, '0'))
	{
		len = (pattern->width - pattern->precision);
		if (ft_strchr(pattern->flag, '#'))
			len = len - 2;
		while (len > 0)
		{
			ft_putchar_st('0', pattern);
			len--;
		}
		if (ft_strchr(pattern->flag, '#'))
			ft_put_diese_hex(pattern);
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

void	ft_printh_width_03(t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '0') && pattern->precision > len
	&& pattern->width > len && pattern->width > pattern->precision)
	{
		len = pattern->width - pattern->precision;
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
}

void	ft_printh_width_03b(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '0') && pattern->width > len
	&& pattern->width > pattern->precision && pattern->precision < len
	&& !ft_strchr(pattern->flag, '-'))
	{
		len = pattern->width - len;
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
}
