/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_room.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:49:42 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 18:49:43 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static	int	ft_check_intmax_stock(char **stock)
{
	intmax_t x;
	intmax_t y;

	x = ft_atoi_maxint(stock[1]);
	y = ft_atoi_maxint(stock[2]);
	if (x > 2147483647 || x < 0)
		return (0);
	if (y > 2147483647 || y < 0)
		return (0);
	return (1);
}

static	int	ft_check_room_stock(char **stock)
{
	int i;
	int j;

	i = 1;
	while (stock[i])
	{
		j = 0;
		while (stock[i][j])
		{
			if (!ft_isdigit(stock[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (0);
	if (!ft_check_intmax_stock(stock))
		return (0);
	return (1);
}

static	int	ft_check_same_name(char **stock, t_struct_r *room, t_struct_h *hive)
{
	int i;

	i = 0;
	if (hive->nb_s >= 1)
	{
		while (i < hive->nb_s)
		{
			if (ft_strcmp(room[i].name, stock[0]) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

static	int	ft_check_same_coor(char **stock, t_struct_r *room, t_struct_h *hive)
{
	int i;

	i = 0;
	if (hive->nb_s >= 1)
	{
		while (i < hive->nb_s)
		{
			if ((room[i].x == ft_atoi(stock[1]))
			&& (room[i].y == ft_atoi(stock[2])))
				return (0);
			i++;
		}
	}
	return (1);
}

char		**ft_check_room(char *str, t_struct_r *room, t_struct_h *hive)
{
	char	**stock;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			j = 1;
		i++;
	}
	if (!j)
		return (NULL);
	if (!(stock = ft_strsplit(str, ' ')))
		return (NULL);
	if (stock[0][0] == 'L' || !(ft_check_room_stock(stock))
	|| !ft_check_same_name(stock, room, hive)
	|| !ft_check_same_coor(stock, room, hive))
	{
		ft_free_stock(stock);
		return (NULL);
	}
	ft_create_print_map(hive, str);
	return (stock);
}
