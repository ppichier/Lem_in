/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_free.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 19:41:15 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 19:41:16 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
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
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s1[++a])
			str[a] = s1[a];
		while (s2[b])
			str[a++] = s2[b++];
		str[a] = '\0';
		free((char*)s1);
		s1 = NULL;
		free((char *)s2);
		s2 = NULL;
		return (str);
	}
}
