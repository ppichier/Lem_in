/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   char.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 12:52:36 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 20:00:08 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_putchar_st(char c, t_struct *pattern)
{
	*pattern->count = *pattern->count + 1;
	write(1, &c, 1);
}

void	ft_strwrt(char *str, t_struct *pattern)
{
	int b;

	b = 0;
	if (str == NULL)
		return ;
	else
	{
		if (pattern->precision > 0 && (int)ft_strlen(str) > pattern->precision)
		{
			while (b < pattern->precision && str[b])
			{
				ft_putchar_st(str[b], pattern);
				b++;
			}
		}
		else
		{
			while (str[b])
			{
				ft_putchar_st(str[b], pattern);
				b++;
			}
		}
	}
}

void	ft_str_wrt(char *str, t_struct *pattern)
{
	int b;

	b = 0;
	if (str == NULL)
		return ;
	else
	{
		while (str[b])
		{
			ft_putchar_st(str[b], pattern);
			b++;
		}
	}
}
