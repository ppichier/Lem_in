/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/04 16:01:22 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 16:01:25 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../Includes/libft.h"

int		ft_printf(const char *restrict format, ...)
{
	t_struct	*pattern;
	va_list		ap;
	int			a;
	int			count;

	pattern = NULL;
	a = 0;
	count = 0;
	pattern = ft_create_struct(pattern, &a, &count);
	va_start(ap, format);
	if (ft_printf_loop(pattern, format, ap) == -1)
	{
		ft_free_struct(pattern);
		return (-1);
	}
	va_end(ap);
	a = *pattern->count;
	ft_free_struct(pattern);
	return (a);
}

int		ft_printf_loop(t_struct *pattern,
		const char *restrict format, va_list ap)
{
	while (format[*pattern->a] != '\0' && ft_strcmp(format, "%") != 0)
	{
		if (format[*pattern->a] == '%')
		{
			ft_pattern_struct((format), pattern);
			if (ft_find_path(ap, pattern) == -1)
				return (-1);
			ft_clean_struct(pattern);
		}
		else
		{
			ft_putchar_st(format[*pattern->a], pattern);
			*pattern->a = *pattern->a + 1;
		}
	}
	return (1);
}

void	ft_free_struct(t_struct *pattern)
{
	free(pattern->size);
	free(pattern->flag);
	free(pattern);
}
