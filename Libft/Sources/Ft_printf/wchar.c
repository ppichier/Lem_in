/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 17:13:14 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/11 17:13:15 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_putwchar(wchar_t nb, t_struct *pattern)
{
	wchar_t	a;
	wchar_t	b;
	int		len;

	len = ft_int_len_base(nb, 2);
	if (len <= 7)
		ft_putchar_st(nb, pattern);
	else if (len >= 8 && len <= 11)
	{
		*pattern->count = *pattern->count + 2;
		a = (nb >> 6) | 0xC0;
		write(1, &a, 1);
		b = nb & 0xBF;
		if (ft_int_len_base(b, 2) < 8)
			b = b + 0x80;
		write(1, &b, 1);
	}
	else if (len >= 12 && len <= 16)
		ft_putwchar3(nb, pattern);
	else if (len >= 17 && len <= 21)
		ft_putwchar4(nb, pattern);
}

void	ft_putwchar3(wchar_t nb, t_struct *pattern)
{
	wchar_t	a;
	wchar_t	b;
	wchar_t	c;

	*pattern->count = *pattern->count + 3;
	a = 0xE0 + (nb >> 12);
	write(1, &a, 1);
	b = (nb >> 6) & 0xBF;
	if (ft_int_len_base(b, 2) < 8)
		b = b + 0x80;
	write(1, &b, 1);
	c = nb & 0xBF;
	if (ft_int_len_base(c, 2) < 8)
		c = c + 0x80;
	write(1, &c, 1);
}

void	ft_putwchar4(wchar_t nb, t_struct *pattern)
{
	wchar_t	a;
	wchar_t	b;
	wchar_t	c;
	wchar_t	d;

	*pattern->count = *pattern->count + 4;
	a = 0xF0 + (nb >> 18);
	write(1, &a, 1);
	b = (nb >> 12) & 0xBF;
	if (ft_int_len_base(b, 2) < 8)
		b = b + 0x80;
	write(1, &b, 1);
	c = (nb >> 6) & 0xBF;
	if (ft_int_len_base(c, 2) < 8)
		c = c + 0x80;
	write(1, &c, 1);
	d = nb & 0xBF;
	if (ft_int_len_base(d, 2) < 8)
		d = d + 0x80;
	write(1, &d, 1);
}

void	ft_putwstr(wchar_t *tab, t_struct *pattern)
{
	int a;
	int len;

	a = 0;
	len = ft_wstrlen(tab);
	if (pattern->precision > 0 && len >= pattern->precision)
		ft_putwstr1(tab, pattern);
	else
	{
		while (tab[a])
		{
			if (MB_CUR_MAX == 1 && (tab[a] >= 127 && tab[a] <= 255))
				ft_putchar_st(tab[a], pattern);
			else
				ft_putwchar(tab[a], pattern);
			a++;
		}
	}
}

void	ft_putwstr1(wchar_t *tab, t_struct *pattern)
{
	int tmp;
	int b;
	int a;

	a = 0;
	b = 0;
	tmp = ft_wcharlen(tab[a]);
	while ((b + tmp) <= pattern->precision && tab[a])
	{
		if (MB_CUR_MAX == 1 && (tab[a] >= 127 && tab[a] <= 255))
			ft_putchar_st(tab[a], pattern);
		else
			ft_putwchar(tab[a], pattern);
		b = b + ft_wcharlen(tab[a]);
		a++;
		if (tab[a])
			tmp = ft_wcharlen(tab[a]);
	}
}
