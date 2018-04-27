/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:26:43 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:26:45 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long a;

	a = 0;
	while ((src[a]) && (a < len))
	{
		dst[a] = src[a];
		a++;
	}
	while (a < len)
	{
		dst[a] = '\0';
		a++;
	}
	return (dst);
}
