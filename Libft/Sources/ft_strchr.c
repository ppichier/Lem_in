/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:23:04 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:23:05 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int a;

	a = 0;
	while ((char)s[a])
	{
		if ((char)s[a] == (unsigned char)c)
			return ((char*)s + a);
		a++;
	}
	if (c == '\0')
		return ((char*)s + a);
	return (0);
}
