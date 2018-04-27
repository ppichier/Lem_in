/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:27:51 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:27:52 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	a;
	int				b;

	a = 0;
	b = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0')
		return (NULL);
	while ((haystack[a] != '\0') && (a < len))
	{
		b = 0;
		while (haystack[a + b] == needle[b] &&
				(a + b) < len && (haystack[a + b]))
			b++;
		if (needle[b] == '\0')
			return ((char*)haystack + a);
		a++;
	}
	return (NULL);
}
