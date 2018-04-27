/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:22:16 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:22:17 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_putstr(char const *str)
{
	int a;

	if (str == NULL)
		return ;
	else
	{
		a = 0;
		while (str[a])
		{
			ft_putchar(str[a]);
			a++;
		}
	}
}
