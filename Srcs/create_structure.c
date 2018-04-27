/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_structure.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:49:59 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 12:27:10 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static int			ft_ckeck_diese(char *str)
{
	if (ft_strcmp("##start", str) == 0 || ft_strcmp("##end", str) == 0
		|| str[0] == '#')
		return (1);
	else
		return (0);
}

static int			ft_check_first_line(char **str, t_struct_h *hive)
{
	while (get_next_line(0, &str[0]) == 1)
	{
		if (str[0][0] == '#' && ft_strcmp("##start", str[0]) != 0 &&
				ft_strcmp("##end", str[0]) != 0)
		{
			ft_create_print_map(hive, str[0]);
			free(str[0]);
		}
		else if (ft_check_nb_ant(str[0], hive) > 0)
		{
			free(str[0]);
			return (1);
		}
		else
		{
			free(str[0]);
			return (0);
		}
	}
	return (1);
}

static	void		ft_check_start_or_end(char **str, t_struct_h *hive)
{
	if (ft_strcmp("##start", str[0]) == 0)
	{
		hive->num_room_start = hive->nb_s;
		ft_create_print_map(hive, str[0]);
	}
	else if (ft_strcmp("##end", str[0]) == 0)
	{
		hive->num_room_end = hive->nb_s;
		ft_create_print_map(hive, str[0]);
	}
	else if (str[0][0] == '#')
		ft_create_print_map(hive, str[0]);
}

static	t_struct_r	*ft_read_lines(t_struct_r *room,
					t_struct_h *hive, char **stock, int *a)
{
	char *str;

	while (get_next_line(0, &str) == 1)
	{
		if (ft_ckeck_diese(str))
			ft_check_start_or_end(&str, hive);
		else if ((stock = ft_check_room(str, room, hive)) && a[1] == 0)
		{
			a[0]++;
			room = ft_create_room(room, stock, hive);
		}
		else if ((stock = ft_check_tube(str, hive, room)) && a[0] > 0)
		{
			a[1]++;
			room = ft_link_room(stock, room, hive);
			ft_free_stock(stock);
		}
		else
		{
			free(str);
			break ;
		}
		free(str);
	}
	return (room);
}

t_struct_r			*ft_create_structure(t_struct_h *hive, t_struct_r *room)
{
	char	**stock;
	char	*str;
	int		a[2];

	stock = NULL;
	a[0] = 0;
	a[1] = 0;
	if (!ft_check_first_line(&str, hive))
		return (NULL);
	room = ft_read_lines(room, hive, stock, a);
	return (room);
}
