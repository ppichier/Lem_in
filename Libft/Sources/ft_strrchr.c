/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:28:14 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:28:15 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int a;

	a = 0;
	while (s[a] != '\0')
		a++;
	if (c == '\0')
		return ((char *)s + a);
	while (a >= 0)
	{
		if (s[a] == (unsigned char)c)
			return ((char *)s + a);
		else
			a--;
	}
	return (NULL);
}
