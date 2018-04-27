/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf3.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:20:26 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:20:26 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

int		ft_check_char(char c)
{
	if (c == 'i' || c == 'd' || c == 'o' || c == 'u'
	|| c == 'D' || c == 'O' || c == 'U' || c == 'x'
	|| c == 'X' || c == 'S' || c == 's' || c == 'p')
		return (1);
	return (0);
}

int		ft_check_char_int(char c)
{
	if (c == 'i' || c == 'd' || c == 'D')
		return (1);
	return (0);
}

int		ft_check_char_un(char c)
{
	if (c == 'o' || c == 'u' || c == 'O' || c == 'U' || c == 'x'
	|| c == 'X')
		return (1);
	return (0);
}
