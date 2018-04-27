/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_i_d5.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:07:11 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:07:11 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_printd_width(intmax_t nb, t_struct *pattern, int len)
{
	ft_printd_width1(nb, pattern, len);
	ft_printd_width2(nb, pattern, len);
}

void	ft_printd_width_0(intmax_t nb, t_struct *pattern, int len)
{
	ft_printd_width_03(nb, pattern, len);
	ft_printd_width_01(nb, pattern, len);
	ft_printd_width_02(nb, pattern, len);
	ft_printd_width_02b(nb, pattern, len);
	ft_printd_width_04(nb, pattern, len);
	ft_printd_width_05(nb, pattern, len);
}

void	ft_printd_width_01(intmax_t nb, t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '-') && pattern->width > len
	&& (pattern->width > pattern->precision && pattern->precision > len))
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
