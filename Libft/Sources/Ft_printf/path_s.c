/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 14:18:40 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 14:18:41 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_path_s(char *str, t_struct *pattern)
{
	int		len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (len > pattern->precision && pattern->precision > 0)
		len = pattern->precision;
	if (pattern->precision == 0)
		len = 0;
	ft_s_p1(pattern, len);
	if ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0))
		ft_strwrt(str, pattern);
	ft_printc_prec_rev(pattern, len);
}

void	ft_s_p1(t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '0'))
		ft_printc_width_0(pattern, len);
	else
		ft_printc_width(pattern, len);
	ft_printc_prec2(pattern, len);
}

int		ft_path_ws(int *nb, t_struct *pattern)
{
	int		len;

	len = 0;
	if (nb == 0)
	{
		ft_str_wrt("(null)", pattern);
		return (1);
	}
	if (nb)
		len = ft_wstrlen(nb);
	if (len > pattern->precision && pattern->precision > 0)
		len = ft_calc_len(nb, pattern);
	if (pattern->precision == 0)
		len = 0;
	if (ft_check_error_strwc(nb, len) == -1)
		return (-1);
	ft_ws_p1(pattern, len);
	if ((pattern->point != '.') || (pattern->point == '.'
	&& pattern->precision > 0))
		ft_putwstr(nb, pattern);
	ft_printc_prec_rev(pattern, len);
	return (1);
}

void	ft_ws_p1(t_struct *pattern, int len)
{
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printc_width_0(pattern, len);
	else
		ft_printc_width(pattern, len);
	ft_printc_prec2(pattern, len);
}

void	ft_printc_prec2(t_struct *pattern, int len)
{
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width > pattern->precision)
	{
		while (len < pattern->precision)
		{
			ft_putchar_st(' ', pattern);
			len++;
		}
	}
	if (!ft_strchr(pattern->flag, '-') && pattern->width > len
	&& pattern->precision > len && pattern->width < pattern->precision)
	{
		while (len < pattern->width)
		{
			ft_putchar_st(' ', pattern);
			len++;
		}
	}
}
