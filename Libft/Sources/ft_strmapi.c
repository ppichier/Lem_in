/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:26:01 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:26:02 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[a] != '\0')
		a++;
	str = (char *)malloc(sizeof(char) * (a + 1));
	if (str == NULL)
		return (NULL);
	while (s[b] != '\0')
	{
		str[b] = f(b, s[b]);
		b++;
	}
	str[b] = '\0';
	return (str);
}
