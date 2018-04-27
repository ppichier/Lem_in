/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hexa.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 12:52:16 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 12:52:17 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

char	*ft_hex_wrt(uintmax_t nb, t_struct *pattern)
{
	char *str;
	char tmp;

	if (nb == 0)
		str = "0";
	else
	{
		str = ft_strnew(1);
		while (nb >= 1)
		{
			tmp = (nb % 16) + 87;
			if (nb % 16 > 9)
				str = ft_strjoin_free(str, ft_strsub(&tmp, 0, 1));
			else
				str = ft_strjoin_free(str, ft_itoa(nb % 16));
			nb = nb / 16;
		}
		if (ft_strchr(pattern->flag, '#') && nb != 0)
		{
			ft_putchar_st('0', pattern);
			ft_putchar_st('x', pattern);
		}
		str = ft_strrev_free(str);
	}
	return (str);
}

char	*ft_maj_hex_wrt(uintmax_t nb, t_struct *pattern)
{
	char *str;
	char tmp;

	if (nb == 0)
		str = "0";
	else
	{
		str = ft_strnew(1);
		while (nb >= 1)
		{
			tmp = (nb % 16) + 55;
			if (nb % 16 > 9)
				str = ft_strjoin_free(str, ft_strsub(&tmp, 0, 1));
			else
				str = ft_strjoin_free(str, ft_itoa(nb % 16));
			nb = nb / 16;
		}
		if (ft_strchr(pattern->flag, '#') && nb != 0)
		{
			ft_putchar_st('0', pattern);
			ft_putchar_st('x', pattern);
		}
		str = ft_strrev_free(str);
	}
	return (str);
}

void	ft_maj_hex_wrt_ll(uintmax_t nb, t_struct *pattern)
{
	char *str;
	char tmp;

	if (nb == 0)
		str = "0";
	else
	{
		str = ft_strnew(1);
		while (nb >= 1)
		{
			tmp = (nb % 16) + 55;
			if (nb % 16 > 9)
				str = ft_strjoin(str, ft_strsub(&tmp, 0, 1));
			else
				str = ft_strjoin(str, ft_itoa(nb % 16));
			nb = nb / 16;
		}
		str = ft_strrev_free(str);
	}
	ft_str_wrt(str, pattern);
}

void	ft_hex_wrt_ll(uintmax_t nb, t_struct *pattern)
{
	char *str;
	char tmp;

	str = "";
	if (nb == 0)
		str = "0";
	else
	{
		str = ft_strnew(1);
		while (nb >= 1)
		{
			tmp = (nb % 16) + 87;
			if (nb % 16 > 9)
				str = ft_strjoin_free(str, ft_strsub(&tmp, 0, 1));
			else
				str = ft_strjoin_free(str, ft_itoa(nb % 16));
			nb = nb / 16;
		}
		str = ft_strrev_free(str);
	}
	ft_str_wrt(str, pattern);
}
