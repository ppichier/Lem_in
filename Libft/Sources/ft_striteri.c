/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striteri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:24:53 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:24:54 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int a;

	if (s == NULL || f == NULL)
		return ;
	else
	{
		a = 0;
		while (s[a] != '\0')
		{
			f(a, &s[a]);
			a++;
		}
	}
}
