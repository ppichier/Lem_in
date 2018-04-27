/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:29:20 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:29:21 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		a;
	int		b;
	int		c;

	b = 0;
	c = 0;
	a = 0;
	if (s)
	{
		while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
			a++;
		b = (ft_strlen(s) - 1);
		if (a >= b + 1)
			return (ft_strdup(""));
		while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
			b--;
		if (!(str = (char *)malloc(sizeof(char) * (b - a + 2))))
			return (NULL);
		while (a <= b)
			str[c++] = s[a++];
		str[c] = '\0';
		return (str);
	}
	return (NULL);
}
