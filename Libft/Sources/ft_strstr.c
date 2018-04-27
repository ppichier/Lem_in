/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:28:42 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:28:43 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0')
		return (NULL);
	while (haystack[a])
	{
		c = a;
		while (haystack[c] == needle[b])
		{
			c++;
			b++;
			if (needle[b] == '\0')
				return ((char *)haystack + a);
		}
		a++;
		b = 0;
	}
	return (NULL);
}
