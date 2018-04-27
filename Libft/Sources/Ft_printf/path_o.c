/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_o.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 14:24:30 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 14:24:30 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_path_llo(unsigned long long int nb, t_struct *pattern)
{
	char	*str;
	int		len;

	if (ft_strcmp(pattern->size, "hh") == 0
	|| ft_strcmp(pattern->size, "h") == 0)
		nb = ft_path_size_u(nb, pattern);
	str = ft_octal_wrt(nb, pattern);
	len = ft_unint_len_base(nb, 8);
	ft_llo_p1(nb, pattern, len);
	if ((pattern->point != '.')
	|| (pattern->point == '.' && pattern->precision > 0) || nb != 0)
		ft_str_wrt(str, pattern);
	else if (((pattern->point == '.') || (pattern->point == '.'
	&& pattern->precision <= 0))
	&& !ft_strchr(pattern->flag, '#') && pattern->width > len)
		ft_putchar_st(' ', pattern);
	ft_printo_prec_rev(pattern, len);
	if (nb)
		free(str);
}

void	ft_llo_p1(unsigned long long int nb, t_struct *pattern, int len)
{
	if (nb != 0 && ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0)))
		ft_checko_0(pattern, len);
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printo_width_0(pattern, len);
	else
		ft_printo_width(pattern, len, nb);
	ft_printo_prec1(pattern, len);
	ft_printo_prec2(pattern, len);
}

void	ft_path_o(uintmax_t nb, t_struct *pattern)
{
	char	*str;
	int		len;

	if (ft_strcmp(pattern->size, "hh") == 0
	|| ft_strcmp(pattern->size, "h") == 0)
		nb = ft_path_size_u(nb, pattern);
	str = ft_octal_wrt(nb, pattern);
	len = ft_unint_len_base(nb, 8);
	ft_o_p1(nb, pattern, len);
	if ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0) || ft_strchr(pattern->flag, '#') || nb != 0)
		ft_str_wrt(str, pattern);
	else if (((pattern->point == '.') || (pattern->point == '.'
	&& pattern->precision <= 0))
	&& !ft_strchr(pattern->flag, '#') && pattern->width > len)
		ft_putchar_st(' ', pattern);
	ft_printo_prec_rev(pattern, len);
	if (nb)
		free(str);
}

void	ft_o_p1(uintmax_t nb, t_struct *pattern, int len)
{
	if (nb != 0 && ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0)))
		ft_checko_0(pattern, len);
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printo_width_0(pattern, len);
	else
		ft_printo_width(pattern, len, nb);
	ft_printo_prec1(pattern, len);
	ft_printo_prec2(pattern, len);
}
