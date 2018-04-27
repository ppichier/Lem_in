/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_i_d3.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:07:02 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:07:03 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printd_width_02(intmax_t nb, t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision
	&& !ft_strchr(pattern->flag, '0'))
	{
		len = (pattern->width - pattern->precision);
		if (ft_strchr(pattern->flag, '+'))
			len = len - 1;
		while (len > 0)
		{
			ft_putchar_st('0', pattern);
			len--;
		}
		if (ft_strchr(pattern->flag, '+'))
			ft_put_sign(nb, pattern);
	}
}

void	ft_printd_width_02b(intmax_t nb, t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '-') && pattern->width > len
	&& (pattern->width < pattern->precision && pattern->precision > len))
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

void	ft_printd_width_03(intmax_t nb, t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '0') && pattern->precision > len
	&& pattern->width > len && pattern->width > pattern->precision)
	{
		len = pattern->width - pattern->precision;
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
}

void	ft_printd_width_04(intmax_t nb, t_struct *pattern, int len)
{
	if (pattern->precision > len
	&& pattern->width > len && pattern->precision == pattern->width
	&& ft_strchr(pattern->flag, '0'))
	{
		if (ft_strchr(pattern->flag, '+'))
			ft_put_sign(nb, pattern);
		while (len < pattern->width)
		{
			ft_putchar_st('0', pattern);
			len++;
		}
	}
	if (ft_strchr(pattern->flag, '+') && pattern->precision > len
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

void	ft_printd_width_05(intmax_t nb, t_struct *pattern, int len)
{
	if (pattern->width > len && pattern->precision < len
	&& !ft_strchr(pattern->flag, '-'))
	{
		if (ft_strchr(pattern->flag, '+'))
		{
			ft_put_sign(nb, pattern);
			len = len + 1;
		}
		if (ft_strchr(pattern->flag, ' '))
		{
			ft_putchar_st(' ', pattern);
			len = len + 1;
		}
		while (len < pattern->width)
		{
			if (pattern->conv == 'd' || pattern->conv == 'D'
			|| pattern->conv == 'i' || pattern->precision == -1)
				ft_putchar_st('0', pattern);
			else
				ft_putchar_st(' ', pattern);
			len++;
		}
	}
}
