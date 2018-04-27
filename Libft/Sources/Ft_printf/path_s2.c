/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_s2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:11:50 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:11:51 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

int		ft_wstrlen(wchar_t *nb)
{
	int len;
	int	a;

	len = 0;
	a = 0;
	while (nb[a])
	{
		if (ft_int_len_base(nb[a], 2) <= 7
		|| (MB_CUR_MAX == 1 && (nb[a] >= 127 && nb[a] <= 255)))
			len = len + 1;
		else if (ft_int_len_base(nb[a], 2) >= 8
		&& ft_int_len_base(nb[a], 2) <= 11)
			len = len + 2;
		else if (ft_int_len_base(nb[a], 2) >= 12
		&& ft_int_len_base(nb[a], 2) <= 16)
			len = len + 3;
		else if (ft_int_len_base(nb[a], 2) >= 17
		&& ft_int_len_base(nb[a], 2) <= 21)
			len = len + 4;
		a++;
	}
	return (len);
}

int		ft_calc_len(int *tab, t_struct *pattern)
{
	int len;
	int a;
	int tmp;

	a = 0;
	len = 0;
	tmp = ft_wcharlen(tab[a]);
	while (((len + tmp) <= pattern->precision) && tab[a])
	{
		len = len + ft_wcharlen(tab[a]);
		a++;
		if (tab[a])
			tmp = ft_wcharlen(tab[a]);
	}
	return (len);
}

int		ft_check_error_strwc(wchar_t *tab, int len)
{
	int a;
	int c;

	a = 0;
	while (len > 0)
	{
		c = tab[a];
		if (c >= 0xd800 && c <= 0xdfff)
			return (-1);
		if (MB_CUR_MAX <= 1 && c > 255)
			return (-1);
		if (c < 0 || len == -1)
			return (-1);
		if (c > 0x10ffff)
			return (-1);
		a++;
		len = len - ft_wcharlen(tab[a]);
	}
	return (1);
}
