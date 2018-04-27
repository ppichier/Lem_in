/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_tube.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:49:55 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 18:49:56 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static	int		ft_check_double_link(char *name, int a,
				t_struct_r *room)
{
	int b;

	b = 0;
	while (b < room[a].nb_tube)
	{
		if (ft_strcmp(room[room[a].link[b]].name, name) == 0)
			return (1);
		b++;
	}
	return (0);
}

static	void	ft_add_link(char *name, int a,
				t_struct_r *room, t_struct_h *hive)
{
	int *tmp;
	int b;
	int c;

	b = 0;
	c = 0;
	if (!(tmp = malloc(sizeof(int) * (room[a].nb_tube + 1))))
		return ;
	while (b < room[a].nb_tube)
	{
		tmp[b] = room[a].link[b];
		b++;
	}
	while (c < hive->nb_s)
	{
		if (ft_strcmp(name, room[c].name) == 0)
		{
			tmp[b] = c;
			break ;
		}
		c++;
	}
	free(room[a].link);
	room[a].link = tmp;
}

t_struct_r		*ft_link_room(char **stock, t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = -1;
	while (++a < hive->nb_s)
	{
		if (ft_strcmp(stock[0], room[a].name) == 0)
		{
			if (ft_check_double_link(stock[1], a, room))
				return (room);
			ft_add_link(stock[1], a, room, hive);
			room[a].nb_tube = room[a].nb_tube + 1;
			break ;
		}
	}
	a = -1;
	while (++a < hive->nb_s)
	{
		if (ft_strcmp(stock[1], room[a].name) == 0)
		{
			ft_add_link(stock[0], a, room, hive);
			room[a].nb_tube = room[a].nb_tube + 1;
			break ;
		}
	}
	return (room);
}
