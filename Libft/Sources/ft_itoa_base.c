/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 18:01:11 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/11 18:01:12 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_itoa_base(int nb, int base)
{
	char *str;
	char c;

	str = "";
	if (nb == -2147483648)
		return (str = ft_strjoin(str, "-2147483648"));
	if (nb < 0 && base == 10)
		str = ft_strjoin(str, "-");
	while ((nb / base) >= 1)
	{
		if (nb % base < 10)
			c = (nb % base) + 48;
		else
			c = (nb % base) + 55;
		str = ft_strjoin(str, ft_strsub(&c, 0, 1));
		nb = nb / base;
	}
	if (nb % base < 9)
		c = (nb % base) + 48;
	else
		c = (nb % base) + 55;
	str = ft_strjoin(str, ft_strsub(&c, 0, 1));
	str = ft_strrev(str);
	return (str);
}
