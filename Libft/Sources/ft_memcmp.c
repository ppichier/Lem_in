/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:19:27 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:19:29 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long a;

	if ((unsigned char *)s1 == (unsigned char*)s2)
		return (0);
	a = 0;
	while (a < n)
	{
		if (((unsigned char *)s1)[a] != ((unsigned char *)s2)[a])
			return (((unsigned char *)s1)[a] - ((unsigned char *)s2)[a]);
		else
			a++;
	}
	return (((unsigned char *)s1)[a - 1] - ((unsigned char *)s2)[a - 1]);
}
