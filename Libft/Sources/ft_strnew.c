/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:27:38 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:27:39 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned long	a;

	a = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (a < size)
	{
		str[a] = '\0';
		a++;
	}
	str[a] = '\0';
	return (str);
}
