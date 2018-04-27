/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_x.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 14:29:33 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 14:29:34 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_path_llx(unsigned long long int nb, t_struct *pattern)
{
	char	*str;
	int		len;

	if (ft_strcmp(pattern->size, "hh") == 0
	|| ft_strcmp(pattern->size, "h") == 0)
		nb = ft_path_size_u(nb, pattern);
	if (pattern->conv == 'X')
		str = ft_maj_hex_wrt(nb, pattern);
	else
		str = ft_hex_wrt(nb, pattern);
	len = ft_int_len_base(nb, 16);
	ft_llx_p1(nb, pattern, len);
	if ((pattern->point != '.')
	|| (pattern->point == '.' && pattern->precision > 0) || nb != 0)
		ft_str_wrt(str, pattern);
	else if (((pattern->point == '.') || (pattern->point == '.'
	&& pattern->precision <= 0))
	&& !ft_strchr(pattern->flag, '#') && pattern->width > len)
		ft_putchar_st(' ', pattern);
	ft_printh_prec_rev(pattern, len);
	if (nb)
		free(str);
}

void	ft_llx_p1(unsigned long long int nb, t_struct *pattern, int len)
{
	if (nb != 0 && ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0)))
		ft_check_diese(pattern, len);
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printh_width_0(pattern, len, nb);
	else
		ft_printh_width(pattern, len, nb);
	ft_printh_prec1(pattern, len);
	ft_printh_prec2(pattern, len);
}

void	ft_path_x(unsigned int nb, t_struct *pattern)
{
	char	*str;
	int		len;

	if (ft_strcmp(pattern->size, "hh") == 0
	|| ft_strcmp(pattern->size, "h") == 0)
		nb = ft_path_size_u(nb, pattern);
	if (pattern->conv == 'X')
		str = ft_maj_hex_wrt(nb, pattern);
	else
		str = ft_hex_wrt(nb, pattern);
	len = ft_int_len_base(nb, 16);
	ft_x_p1(nb, pattern, len);
	if ((pattern->point != '.')
	|| (pattern->point == '.' && pattern->precision > 0) || nb != 0)
		ft_str_wrt(str, pattern);
	else if (((pattern->point == '.') || (pattern->point == '.'
	&& pattern->precision <= 0))
	&& !ft_strchr(pattern->flag, '#') && pattern->width > len)
		ft_putchar_st(' ', pattern);
	ft_printh_prec_rev(pattern, len);
	if (nb)
		free(str);
}

void	ft_x_p1(unsigned int nb, t_struct *pattern, int len)
{
	if (nb != 0 && ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0)))
		ft_check_diese(pattern, len);
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printh_width_0(pattern, len, nb);
	else
		ft_printh_width(pattern, len, nb);
	ft_printh_prec1(pattern, len);
	ft_printh_prec2(pattern, len);
}

void	ft_check_diese(t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '#') && pattern->precision <= len
	&& pattern->width <= len)
	{
		ft_put_diese_hex(pattern);
		pattern->width = pattern->width - 2;
	}
	if ((ft_strchr(pattern->flag, '#')
	&& ft_strchr(pattern->flag, '-') && (pattern->width >= len
	|| pattern->precision >= len)))
	{
		ft_put_diese_hex(pattern);
		pattern->width = pattern->width - 2;
	}
}
