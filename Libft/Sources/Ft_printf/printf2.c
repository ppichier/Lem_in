/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:20:22 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:20:23 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

int		ft_check_char_w(char c)
{
	if (c == 'C' || c == 'S' || c == 'c' || c == 's')
		return (1);
	return (0);
}

int		ft_find_path(va_list ap, t_struct *pattern)
{
	if (ft_check_char_int(pattern->conv) == 1)
	{
		ft_check_int(va_arg(ap, intmax_t), pattern);
		return (1);
	}
	else if (ft_check_char_un(pattern->conv) == 1)
	{
		ft_check_un(va_arg(ap, uintmax_t), pattern);
		return (1);
	}
	else if (pattern->conv == 'p')
	{
		ft_path_p(va_arg(ap, void*), pattern);
		return (1);
	}
	else if (ft_check_char_w(pattern->conv) == 1)
	{
		if (ft_check_wswc(va_arg(ap, intmax_t), pattern) == -1)
			return (-1);
		return (1);
	}
	else
		ft_path_e(pattern);
	return (0);
}

int		ft_check_wswc(intmax_t nb, t_struct *pattern)
{
	if (pattern->conv == 'S' || (ft_strchr(pattern->size, 'l')
	&& pattern->conv == 's'))
	{
		if (ft_path_ws((wchar_t*)nb, pattern) == -1)
			return (-1);
	}
	else if (pattern->conv == 'C' || (ft_strcmp(pattern->size, "l") == 0
	&& pattern->conv == 'c'))
	{
		if (ft_path_wc((wchar_t)nb, pattern) == -1)
			return (-1);
	}
	else if (pattern->conv == 's')
		ft_path_s((char *)nb, pattern);
	else if (pattern->conv == 'c')
		ft_path_c((int)nb, pattern);
	return (1);
}

void	ft_check_int(intmax_t nb, t_struct *pattern)
{
	if ((pattern->conv == 'd' || pattern->conv == 'D' || pattern->conv == 'i')
	&& (ft_strcmp(pattern->size, "ll") == 0
	|| ft_strcmp(pattern->size, "l") == 0 || ft_strcmp(pattern->size, "j") == 0
	|| ft_strcmp(pattern->size, "z") == 0))
		ft_path_i_d(nb, pattern);
	else if (pattern->conv == 'D' || ((pattern->conv == 'd'
	|| pattern->conv == 'i') && ft_strcmp(pattern->size, "l") == 0))
		ft_path_i_d((long int)nb, pattern);
	else if (pattern->conv == 'd' || pattern->conv == 'i')
		ft_path_i_d((int)nb, pattern);
}

void	ft_check_un(uintmax_t nb, t_struct *pattern)
{
	if ((pattern->conv == 'U' || pattern->conv == 'u') &&
	(ft_strcmp(pattern->size, "ll") == 0 || ft_strcmp(pattern->size, "j") == 0
	|| ft_strcmp(pattern->size, "z") == 0))
		ft_path_llu(nb, pattern);
	else if (pattern->conv == 'U' || (pattern->conv == 'u'
	&& ft_strcmp(pattern->size, "l") == 0))
		ft_path_lu((long int)nb, pattern);
	else if (pattern->conv == 'u')
		ft_path_u((int)nb, pattern);
	else if ((pattern->conv == 'o' || pattern->conv == 'O')
	&& (ft_strcmp(pattern->size, "ll") == 0
	|| ft_strcmp(pattern->size, "l") == 0 || ft_strcmp(pattern->size, "j") == 0
	|| ft_strcmp(pattern->size, "z") == 0))
		ft_path_llo((intmax_t)nb, pattern);
	else if (pattern->conv == 'O' || (pattern->conv == 'o'
	&& ft_strchr(pattern->flag, 'l')))
		ft_path_wo((long int)nb, pattern);
	else if (pattern->conv == 'o')
		ft_path_o((unsigned int)nb, pattern);
	else if ((pattern->conv == 'X' || pattern->conv == 'x') && (ft_strcmp(
	pattern->size, "ll") == 0 || ft_strcmp(pattern->size, "l") == 0 ||
	ft_strcmp(pattern->size, "j") == 0 || ft_strcmp(pattern->size, "z") == 0))
		ft_path_llx(nb, pattern);
	else if (pattern->conv == 'X' || pattern->conv == 'x')
		ft_path_x((unsigned int)nb, pattern);
}
