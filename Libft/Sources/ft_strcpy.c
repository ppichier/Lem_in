/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:23:44 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:23:45 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int a;

	a = 0;
	while (src[a])
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (dst);
}
