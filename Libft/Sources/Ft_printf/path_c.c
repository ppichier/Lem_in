/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 14:11:41 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 14:11:43 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_path_c(int c, t_struct *pattern)
{
	int				len;
	unsigned char	i;

	i = c;
	len = 1;
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printc_width_0(pattern, len);
	else
		ft_printc_width(pattern, len);
	if ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0))
		ft_putchar_st(c, pattern);
	else if (c == 0)
		ft_putchar_st('\0', pattern);
	ft_printc_prec_rev(pattern, len);
}

int		ft_path_wc(wchar_t c, t_struct *pattern)
{
	int		len;

	if (ft_check_error_wc(c) == -1)
		return (-1);
	len = ft_wcharlen(c);
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printc_width_0(pattern, len);
	else
		ft_printc_width(pattern, len);
	if ((pattern->point != '.')
	|| (pattern->point == '.' && pattern->precision > 0))
	{
		if (MB_CUR_MAX == 1 && (c >= 127 && c <= 255))
			ft_putchar_st(c, pattern);
		else
			ft_putwchar(c, pattern);
	}
	else if (c == 0)
		ft_putchar_st('\0', pattern);
	ft_printc_prec_rev(pattern, len);
	return (1);
}

int		ft_check_error_wc(wchar_t c)
{
	if (c >= 0xd800 && c <= 0xdfff)
		return (-1);
	if (MB_CUR_MAX <= 1 && c > 255)
		return (-1);
	if (c < 0)
		return (-1);
	if (c > 0x10ffff)
		return (-1);
	return (1);
}

void	ft_printc_width(t_struct *pattern, int len)
{
	ft_printc_width1(pattern, len);
	ft_printc_width2(pattern, len);
}

void	ft_printc_width_0(t_struct *pattern, int len)
{
	ft_printc_width_03(pattern, len);
	ft_printc_width_01(pattern, len);
	ft_printc_width_02(pattern, len);
	ft_printc_width_04(pattern, len);
	ft_printc_width_04b(pattern, len);
}
