/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:21:20 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:21:22 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_putendl(char const *s)
{
	unsigned long a;

	if (s == NULL)
		return ;
	else
	{
		a = 0;
		while (s[a] != '\0')
		{
			ft_putchar(s[a]);
			a++;
		}
		ft_putchar('\n');
	}
}
