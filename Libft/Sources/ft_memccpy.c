/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:19:01 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:19:02 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memccpy(void *restrict dst, const void
		*restrict src, int c, size_t n)
{
	int a;

	a = 0;
	while (n-- != 0)
	{
		((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
		if (((unsigned char *)dst)[a] == (unsigned char)c)
			return (dst + a + 1);
		a++;
	}
	return (NULL);
}
