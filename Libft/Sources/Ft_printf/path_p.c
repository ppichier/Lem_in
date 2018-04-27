/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_p.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 14:33:46 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 14:33:47 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_path_p(void *adr_ptr, t_struct *pattern)
{
	char	*str;
	int		len;

	pattern->flag = ft_strjoin_free(pattern->flag, ft_strdup("#"));
	str = ft_hex_wrt((unsigned long int)adr_ptr, pattern);
	len = ft_strlen(str);
	ft_p_p1(pattern, len, adr_ptr);
	if ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0))
		ft_str_wrt(str, pattern);
	else if (((pattern->point == '.') || (pattern->point == '.'
	&& pattern->precision <= 0))
	&& !ft_strchr(pattern->flag, '#') && pattern->width > len)
		ft_putchar_st(' ', pattern);
	ft_printh_prec_rev(pattern, len);
	if (ft_strchr(pattern->flag, '#') && (pattern->point == '.')
	&& pattern->precision == 0 && pattern->width == -1)
		ft_put_diese_hex(pattern);
	if ((unsigned long int)adr_ptr)
		free(str);
}

void	ft_p_p1(t_struct *pattern, int len, void *adr_ptr)
{
	if ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0))
		ft_check_diese(pattern, len);
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printh_width_0(pattern, len, (unsigned long int)adr_ptr);
	else
		ft_printh_width(pattern, len, (unsigned long int)adr_ptr);
	ft_printp_prec(pattern, len);
}

void	ft_printp_prec(t_struct *pattern, int len)
{
	ft_printh_prec1(pattern, len);
	ft_printh_prec2(pattern, len);
}
