/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_c2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:03:19 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:03:19 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printc_width_01(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision < len && pattern->width < pattern->precision)
	{
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printc_width_02(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision
	&& !ft_strchr(pattern->flag, '0'))
	{
		len = (pattern->width - pattern->precision);
		while (len > 0)
		{
			ft_putchar_st('0', pattern);
			len--;
		}
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

void	ft_printc_width_03(t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '0') && pattern->precision >= len
	&& pattern->width > len && pattern->width > pattern->precision)
	{
		len = pattern->width - pattern->precision;
		while (len > 0)
		{
			ft_putchar_st('0', pattern);
			len--;
		}
	}
	if (!ft_strchr(pattern->flag, '0') && pattern->width > len
	&& pattern->width > pattern->precision && pattern->precision < len
	&& !ft_strchr(pattern->flag, '-'))
	{
		len = pattern->width - len;
		while (len > 0)
		{
			ft_putchar_st(' ', pattern);
			len--;
		}
	}
}

void	ft_printc_width_04(t_struct *pattern, int len)
{
	if (pattern->precision > len
	&& pattern->width > len && pattern->precision == pattern->width
	&& ft_strchr(pattern->flag, '0'))
	{
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
	if (ft_strchr(pattern->flag, '#') && pattern->precision > len
	&& pattern->width > len && pattern->precision == pattern->width)
	{
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}

void	ft_printc_width_04b(t_struct *pattern, int len)
{
	if (pattern->width > len && pattern->precision < len
	&& !ft_strchr(pattern->flag, '-'))
	{
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
}
