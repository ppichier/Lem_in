/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:28:57 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:28:58 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	char			*str;

	if (s == NULL)
		return (NULL);
	else
	{
		a = 0;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		while (a < len)
		{
			str[a] = s[start];
			start++;
			a++;
		}
		str[a] = '\0';
		return (str);
	}
}
