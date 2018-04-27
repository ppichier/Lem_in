/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:26:29 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:26:32 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long a;

	if (n == 0)
		return (0);
	a = 0;
	while ((s1[a] == s2[a]) && (s1[a]) && (s2[a]) && (a < n - 1))
	{
		a++;
	}
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
