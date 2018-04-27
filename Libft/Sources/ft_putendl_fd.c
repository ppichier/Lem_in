/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:21:31 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:21:33 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	unsigned long a;

	if (s == NULL)
		return ;
	else
	{
		a = 0;
		while (s[a] != '\0')
		{
			ft_putchar_fd(s[a], fd);
			a++;
		}
		ft_putchar_fd('\n', fd);
	}
}
