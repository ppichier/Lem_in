/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:12:07 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 20:52:06 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		ft_atoi(const char *str)
{
	int a;
	int resultat;
	int neg;

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
