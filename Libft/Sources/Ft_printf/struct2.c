/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 19:20:10 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 19:20:11 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void		ft_pattern_struct(const char *restrict str, t_struct *pattern)
{
	if (str[*(pattern->a)] && str[(*(pattern->a)) + 1])
		*(pattern->a) = *(pattern->a) + 1;
	ft_struct_flag(pattern, str);
	ft_struct_width(pattern, str);
	ft_struct_prec(pattern, str);
	ft_struct_size(pattern, str);
	ft_struct_conv(pattern, str);
}

t_struct	*ft_create_struct(t_struct *pattern, int *a, int *count)
{
	if (!pattern)
		pattern = malloc(sizeof(t_struct));
	pattern->a = a;
	pattern->count = count;
	pattern->flag = ft_strnew(1);
	pattern->width = -1;
	pattern->precision = -1;
	pattern->point = ' ';
	pattern->size = ft_strnew(1);
	pattern->conv = '\0';
	return (pattern);
}

void		ft_clean_struct(t_struct *pattern)
{
	free(pattern->flag);
	pattern->flag = ft_strnew(1);
	pattern->width = -1;
	pattern->precision = -1;
	pattern->point = ' ';
	free(pattern->size);
	pattern->size = ft_strnew(1);
	pattern->conv = '\0';
}
