/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_i_d2.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:06:58 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:06:58 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

int		ft_int_len_base(intmax_t nb, int base)
{
	int count;

	if (nb < 0)
		nb = (nb * -1);
	if (nb == 0)
		return (1);
	count = 0;
	while (nb >= 1)
	{
		count++;
		nb = nb / base;
	}
	return (count);
}

void	ft_put_sign(intmax_t nb, t_struct *pattern)
{
	if (nb >= 0)
		ft_putchar_st('+', pattern);
	else
		ft_putchar_st('-', pattern);
}

void	ft_printd_prec_rev(t_struct *pattern, int len)
{
	int a;

	a = pattern->width - pattern->precision;
	if (ft_strchr(pattern->flag, '-') && pattern->width > len &&
	(pattern->width > pattern->precision && (ft_strchr(pattern->flag, '+'))))
		a = a - 1;
	if (pattern->precision > len && pattern->width > len
		&& ft_strchr(pattern->flag, '-')
	&& pattern->width > pattern->precision)
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

int		ft_unint_len_base(uintmax_t nb, int base)
{
	int count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb >= 1)
	{
		count++;
		nb = nb / base;
	}
	return (count);
}
