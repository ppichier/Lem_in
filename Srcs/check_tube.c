/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_tube.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:49:34 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 17:06:02 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static	int	ft_check_link_name(char *tmp, t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	while (a < hive->nb_s)
	{
		if (strcmp(tmp, room[a].name) == 0)
			return (1);
		a++;
	}
	return (0);
}

static	int	ft_count_char(char *str, char c)
{
	int a;
	int count;

	a = 0;
	count = 0;
	while (str[a])
	{
		if (str[a] == c)
			count++;
		a++;
	}
	return (count);
}

char		**ft_check_tube(char *str, t_struct_h *hive, t_struct_r *room)
{
	int		a;
	char	**stock;

	a = 0;
	if (ft_count_char(str, '-') != 1)
		return (NULL);
	if (!(stock = ft_strsplit(str, '-')))
		return (NULL);
	while (stock[a])
		a++;
	if ((a != 2) || (strcmp(stock[0], stock[1]) == 0) ||
		(ft_check_link_name(stock[0], room, hive) == 0) ||
		(ft_check_link_name(stock[1], room, hive) == 0))
	{
		ft_free_stock(stock);
		return (NULL);
	}
	ft_create_print_map(hive, str);
	return (stock);
}
