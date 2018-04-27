/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 15:12:18 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 15:12:19 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

void		ft_struct_flag(t_struct *pattern, const char *restrict str)
{
	while ((str[*(pattern->a)] == '#' || str[*(pattern->a)] == '0'
	|| str[*(pattern->a)] == '+' || str[*(pattern->a)] == '-'
	|| str[*(pattern->a)] == ' ') && str)
	{
		pattern->flag = ft_strjoin_free(pattern->flag,
			ft_strsub(&str[*(pattern->a)], 0, 1));
		*(pattern->a) = *(pattern->a) + 1;
	}
}

void		ft_struct_width(t_struct *pattern, const char *restrict str)
{
	char *tmp;

	tmp = ft_strnew(1);
	while (str[*(pattern->a)] >= '0' && str[*(pattern->a)] <= '9' && str)
	{
		tmp = ft_strjoin_free(tmp, ft_strsub(&str[*(pattern->a)], 0, 1));
		*(pattern->a) = *(pattern->a) + 1;
	}
	if (ft_strcmp("", tmp) != 0)
		pattern->width = ft_atoi(tmp);
	free(tmp);
}

void		ft_struct_prec(t_struct *pattern, const char *restrict str)
{
	char *tmp;

	tmp = ft_strnew(1);
	if (str[*(pattern->a)] == '.')
	{
		pattern->point = '.';
		*(pattern->a) = *(pattern->a) + 1;
		while ((str[*(pattern->a)] >= '0' && str[*(pattern->a)] <= '9')
		&& str)
		{
			tmp = ft_strjoin_free(tmp, ft_strsub(&str[*(pattern->a)], 0, 1));
			*(pattern->a) = *(pattern->a) + 1;
		}
		pattern->precision = ft_atoi(tmp);
		if (ft_strcmp(tmp, "") == 0)
			pattern->precision = 0;
	}
	free(tmp);
}

void		ft_struct_size(t_struct *pattern, const char *restrict str)
{
	while ((str[*(pattern->a)] == 'l' || str[*(pattern->a)] == 'h'
	|| str[*(pattern->a)] == 'j' || str[*(pattern->a)] == 'z') && str)
	{
		pattern->size = ft_strjoin_free(pattern->size,
			ft_strsub(&str[*(pattern->a)], 0, 1));
		*(pattern->a) = *(pattern->a) + 1;
	}
}

void		ft_struct_conv(t_struct *pattern, const char *restrict str)
{
	pattern->conv = str[*(pattern->a)];
	if (str[*(pattern->a)])
		*(pattern->a) = *(pattern->a) + 1;
}
