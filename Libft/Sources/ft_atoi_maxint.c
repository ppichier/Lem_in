/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_maxint.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 16:21:55 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/27 16:21:57 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

intmax_t	ft_atoi_maxint(const char *str)
{
	intmax_t a;
	intmax_t resultat;
	intmax_t neg;

	neg = 1;
	resultat = 0;
	a = 0;
	while ((str[a] == '\t') || (str[a] == '\n') || (str[a] == '\r')
			|| (str[a] == '\v') || (str[a] == '\f') || (str[a] == ' '))
		a++;
	if (str[a] == '-')
		neg = -1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		resultat = resultat * 10;
		resultat = resultat + (str[a] - 48);
		a++;
	}
	return (resultat * neg);
}
