/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wchar2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:01:53 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:01:53 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

int		ft_wcharlen(wchar_t nb)
{
	int len;

	len = 0;
	if (ft_int_len_base(nb, 2) <= 7 ||
	(MB_CUR_MAX == 1 && (nb >= 127 && nb <= 255)))
		len = len + 1;
	else if (ft_int_len_base(nb, 2) >= 8 && ft_int_len_base(nb, 2) <= 11)
		len = len + 2;
	else if (ft_int_len_base(nb, 2) >= 12 && ft_int_len_base(nb, 2) <= 16)
		len = len + 3;
	else if (ft_int_len_base(nb, 2) >= 17 && ft_int_len_base(nb, 2) <= 21)
		len = len + 4;
	return (len);
}
