/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnequ.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:27:00 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:27:03 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned long	a;

	a = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!n)
		return (1);
	else
	{
		while ((s1[a] == s2[a]) && (s1[a]) && s2[a] && (a < n - 1))
			a++;
		if (((unsigned char)s1[a] - (unsigned char)s2[a]) == 0)
			return (1);
	}
	return (0);
}
