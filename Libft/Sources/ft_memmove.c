/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:20:11 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:20:13 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int a;

	a = len - 1;
	if (((unsigned char *)src) < ((unsigned char *)dst))
	{
		while (a >= 0)
		{
			((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
			a--;
		}
		return (dst);
	}
	else
	{
		a = 0;
		while (len != 0)
		{
			((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
			len--;
			a++;
		}
		return (dst);
	}
	return (dst);
}
