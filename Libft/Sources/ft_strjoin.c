/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:25:06 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:25:08 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*str;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else
	{
		a = -1;
		b = 0;
		len = ((ft_strlen((char *)s1)) + (ft_strlen((char*)s2)));
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		while (s1[++a])
			str[a] = s1[a];
		while (s2[b])
			str[a++] = s2[b++];
		str[a] = '\0';
		return (str);
	}
}
