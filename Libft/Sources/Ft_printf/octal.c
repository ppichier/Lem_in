/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   octal.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 12:52:08 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 12:52:09 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

char	*ft_octal_wrt(uintmax_t nb, t_struct *pattern)
{
	char *str;

	if (nb == 0)
		str = "0";
	else
	{
		str = ft_strnew(1);
		while (nb >= 1)
		{
			str = ft_strjoin_free(str, ft_itoa(nb % 8));
			nb = nb / 8;
		}
		if ((ft_strchr(pattern->flag, '#') && nb != 0)
		|| (ft_strchr(pattern->flag, '#') && (pattern->point == '.')
		&& pattern->precision == 0 && pattern->width == -1))
			ft_putchar_st('0', pattern);
		str = ft_strrev_free(str);
	}
	return (str);
}
