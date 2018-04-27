/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:23:32 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:23:33 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int a;

	a = 0;
	while ((s1[a] == s2[a]) && (s1[a] != '\0') && (s2[a] != '\0'))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
