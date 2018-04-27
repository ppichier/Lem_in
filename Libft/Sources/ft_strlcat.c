/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:25:20 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:25:22 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t		i;
	size_t		t1;
	size_t		t2;

	i = 0;
	t1 = ft_strlen(d);
	t2 = ft_strlen(s);
	if (n <= t1)
		return (t2 + n);
	while (*d++ && i < (n - 1))
		i++;
	d--;
	while (*s && i < n - 1)
	{
		*d++ = *s++;
		i++;
	}
	*d = '\0';
	return (t1 + t2);
}
