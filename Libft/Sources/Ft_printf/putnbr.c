/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   int.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 12:52:26 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 12:52:27 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_putnbr_max_count(intmax_t nb, t_struct *pattern)
{
	if (nb == -9223372036854775807 - 1)
	{
		ft_putchar_st('9', pattern);
		ft_putnbr_max_count((223372036854775808), pattern);
		return ;
	}
	if (nb < 0)
		nb = nb * (-1);
	if (nb >= 10)
	{
		ft_putnbr_max_count((nb / 10), pattern);
		ft_putnbr_max_count((nb % 10), pattern);
	}
	else
		ft_putchar_st((nb + 48), pattern);
}

void	ft_putnbr_maxun_count(uintmax_t nb, t_struct *pattern)
{
	if (nb >= 10)
	{
		ft_putnbr_maxun_count((nb / 10), pattern);
		ft_putnbr_maxun_count((nb % 10), pattern);
	}
	else
		ft_putchar_st((nb + 48), pattern);
}
