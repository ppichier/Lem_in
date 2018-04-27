/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 19:52:37 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 19:52:39 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strrev(char const *str)
{
	int		a;
	int		len;
	char	*newstr;

	a = 0;
	len = ft_strlen(str);
	newstr = malloc(sizeof(char) * len + 1);
	len--;
	while (len >= 0)
		newstr[a++] = str[len--];
	newstr[a] = '\0';
	return (newstr);
}
