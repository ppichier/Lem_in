/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_u.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 12:44:48 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 12:44:49 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_path_u(int nb, t_struct *pattern)
{
	int			len;
	uintmax_t	nbu;

	if (ft_strcmp(pattern->size, "hh") == 0
	|| ft_strcmp(pattern->size, "h") == 0)
		nb = ft_path_size_u(nb, pattern);
	nbu = 0;
	if (nb < 0)
		nbu = 4294967296 + nb;
	else
		nbu = nb;
	len = ft_unint_len_base(nbu, 10);
	if (ft_strchr(pattern->flag, '0') || (ft_strchr(pattern->flag, '-')))
		ft_printd_width_0(nbu, pattern, len);
	else
		ft_printd_width(nbu, pattern, len);
	ft_printd_prec1(nbu, pattern, len);
	ft_printd_prec2(nbu, pattern, len);
	if ((pattern->point != '.')
	|| (pattern->point == '.' && pattern->precision > 0) || nb != 0)
		ft_putnbr_maxun_count(nbu, pattern);
	ft_printd_prec_rev(pattern, len);
}

void	ft_path_lu(uintmax_t nb, t_struct *pattern)
{
	int len;

	len = ft_unint_len_base(nb, 10);
	if (ft_strchr(pattern->flag, '0') || (ft_strchr(pattern->flag, '-')))
		ft_printd_width_0(nb, pattern, len);
	else
		ft_printd_width(nb, pattern, len);
	ft_printd_prec1(nb, pattern, len);
	ft_printd_prec2(nb, pattern, len);
	if ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0))
		ft_putnbr_maxun_count(nb, pattern);
	ft_printd_prec_rev(pattern, len);
}

void	ft_path_llu(intmax_t nb, t_struct *pattern)
{
	int			len;
	uintmax_t	nbu;

	nbu = 0;
	if (nb < 0)
		nbu = nb;
	else
		nbu = nb;
	len = ft_unint_len_base(nb, 10);
	if (ft_strchr(pattern->flag, '0') || (ft_strchr(pattern->flag, '-')))
		ft_printd_width_0(nb, pattern, len);
	else
		ft_printd_width(nb, pattern, len);
	ft_printd_prec1(nb, pattern, len);
	ft_printd_prec2(nb, pattern, len);
	if ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0))
		ft_putnbr_maxun_count(nbu, pattern);
	ft_printd_prec_rev(pattern, len);
}

int		ft_path_size_u(intmax_t nb, t_struct *pattern)
{
	if (ft_strcmp(pattern->size, "hh") == 0
	&& (pattern->conv == 'u' || pattern->conv == 'o'
	|| pattern->conv == 'x' || pattern->conv == 'X'))
	{
		nb = nb % 256;
		if (nb > 127 && nb < 255)
			nb = nb - 256;
		if (nb < 0)
			nb = 256 + nb;
	}
	else if ((ft_strcmp(pattern->size, "h") == 0
	&& (pattern->conv == 'u' || pattern->conv == 'o'
	|| pattern->conv == 'X' || pattern->conv == 'x'))
	|| (ft_strcmp(pattern->size, "hh") == 0
	&& (pattern->conv == 'U' || pattern->conv == 'O')))
	{
		nb = nb % 65536;
		if (nb > 32767 && nb < 65535)
			nb = nb - 65536;
		if (nb < 0)
			nb = nb + 65536;
	}
	return (nb);
}
