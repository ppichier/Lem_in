/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   i_d_path.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 13:43:04 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 13:43:05 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_path_i_d(intmax_t nb, t_struct *pattern)
{
	int	len;

	if (ft_strcmp(pattern->size, "hh") == 0
	|| ft_strcmp(pattern->size, "h") == 0)
		nb = ft_path_size_d(nb, pattern);
	len = ft_int_len_base(nb, 10);
	if (nb <= -1)
		pattern->flag = ft_strjoin(pattern->flag, "+");
	if ((pattern->point != '.')
	|| (pattern->point == '.' && pattern->precision >= 0))
		ft_check_sign(nb, pattern, len);
	if (ft_strchr(pattern->flag, '0') || (ft_strchr(pattern->flag, '-')))
		ft_printd_width_0(nb, pattern, len);
	else
		ft_printd_width(nb, pattern, len);
	ft_printd_prec(nb, pattern, len);
	if ((pattern->point != '.')
	|| (pattern->point == '.' && pattern->precision > 0) || nb != 0)
		ft_putnbr_max_count(nb, pattern);
	else if (((pattern->point == '.')
	|| (pattern->point == '.' && pattern->precision <= 0))
	&& !ft_strchr(pattern->flag, '#') && pattern->width > len)
		ft_putchar_st(' ', pattern);
	ft_printd_prec_rev(pattern, len);
}

void	ft_printd_prec(intmax_t nb, t_struct *pattern, int len)
{
	ft_printd_prec1(nb, pattern, len);
	ft_printd_prec2(nb, pattern, len);
	ft_check_space(nb, pattern);
}

int		ft_path_size_d(intmax_t nb, t_struct *pattern)
{
	if (ft_strcmp(pattern->size, "hh") == 0
	&& (pattern->conv == 'd' || pattern->conv == 'i'))
	{
		nb = nb % 256;
		if (nb > 127 && nb < 255)
			nb = nb - 256;
		else if (nb < -128 && nb < 0)
			nb = nb + 256;
	}
	else if ((ft_strcmp(pattern->size, "h") == 0
	&& (pattern->conv == 'd' || pattern->conv == 'i'))
	|| (ft_strcmp(pattern->size, "hh") == 0
	&& pattern->conv == 'D'))
	{
		nb = nb % 65536;
		if (nb > 32767 && nb < 65535)
			nb = nb - 65536;
		else if (nb < -32768 && nb < 0)
			nb = nb + 65536;
	}
	return (nb);
}

void	ft_check_space(intmax_t nb, t_struct *pattern)
{
	if (ft_strchr(pattern->flag, ' ') && !ft_strchr(pattern->flag, '+')
	&& !ft_strchr(pattern->flag, '-') && pattern->precision <= 0
	&& pattern->width <= 0 && nb >= 0)
		ft_putchar_st(' ', pattern);
}

void	ft_check_sign(intmax_t nb, t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '+') && pattern->precision <= len
	&& pattern->width <= len)
	{
		ft_put_sign(nb, pattern);
		pattern->width = pattern->width - 1;
	}
	else if ((ft_strchr(pattern->flag, '+') && !ft_strchr(pattern->flag, '-')
	&& ft_strchr(pattern->flag, '-') && pattern->width >= len
	&& pattern->precision >= len))
	{
		ft_put_sign(nb, pattern);
		pattern->width = pattern->width - 1;
	}
	else if ((ft_strchr(pattern->flag, '+')
	&& ft_strchr(pattern->flag, '-') && pattern->width >= len
	&& pattern->precision <= len))
	{
		ft_put_sign(nb, pattern);
		pattern->width = pattern->width - 1;
	}
}
