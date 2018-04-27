/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrev_free.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 16:28:48 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 16:28:58 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strrev_free(char *str)
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
	free(str);
	return (newstr);
}
