/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:26:16 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:26:17 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int				a;
	unsigned long	b;

	a = 0;
	b = 0;
	while (s1[a])
		a++;
	while ((s2[b]) && (b < n))
	{
		s1[a] = s2[b];
		a++;
		b++;
	}
	s1[a] = '\0';
	return (s1);
}
