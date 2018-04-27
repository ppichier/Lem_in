/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:22:26 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:22:28 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int a;

	if (s == NULL)
		return ;
	else
	{
		a = 0;
		while (s[a])
		{
			ft_putchar_fd(s[a], fd);
			a++;
		}
	}
}
