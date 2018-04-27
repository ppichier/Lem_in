/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   path_e.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 09:53:51 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 09:53:51 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void	ft_path_e(t_struct *pattern)
{
	int				len;

	len = 1;
	if (ft_strchr(pattern->flag, '0') || ft_strchr(pattern->flag, '-'))
		ft_printc_width_0(pattern, len);
	else
		ft_printc_width(pattern, len);
	if (pattern->conv)
		ft_putchar_st(pattern->conv, pattern);
	ft_printc_prec_rev(pattern, len);
}
