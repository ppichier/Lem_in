/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:19:14 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:19:15 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long a;

	a = 0;
	while (a < n)
	{
		if (((unsigned char *)s)[a] == (unsigned char)c)
			return (((unsigned char *)s) + a);
		else
			a++;
	}
	return (NULL);
}
