/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:22:49 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:22:51 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (s1[a])
		a++;
	while (s2[b])
	{
		s1[a] = s2[b];
		a++;
		b++;
	}
	s1[a] = '\0';
	return (s1);
}
