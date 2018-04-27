/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:24:17 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:24:18 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = 0;
	while (s1[a])
		a++;
	str = malloc(sizeof(char) * (a + 1));
	if (str == NULL)
		return (NULL);
	while (s1[b])
	{
		str[b] = s1[b];
		b++;
	}
	str[b] = '\0';
	return (str);
}
