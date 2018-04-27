/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:14:59 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:15:01 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

static	int		ft_power(int n)
{
	int res;

	res = 1;
	while (n-- > 0)
		res = res * 10;
	return (res);
}

static	int		ft_intlen(int n)
{
	int a;

	a = 0;
	if (n == 0)
		return (1);
	if (n == -0)
		return (2);
	if (n < 0)
	{
		a++;
		n = n * (-1);
	}
	while (n >= 1)
	{
		a++;
		n = n / 10;
	}
	return (a);
}

static	void	ft_itoaisneg(int *n, int *a)
{
	*n = *n * (-1);
	*a = *a - 1;
}

char			*ft_itoa(int n)
{
	int		a;
	int		b;
	int		tmp;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	b = 0;
	a = ft_intlen(n);
	str = malloc(sizeof(char) * (a + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[b++] = '-';
		ft_itoaisneg(&n, &a);
	}
	while (a-- > 0)
	{
		tmp = (n / (ft_power(a)));
		str[b++] = tmp + 48;
		n = n - (tmp * (ft_power(a)));
	}
	str[b] = '\0';
	return (str);
}
