/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ppichier.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:50:12 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 13:18:34 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static int	ft_nbtube_start_end(t_struct_r *room, t_struct_h *hive, int a)
{
	int nb_tubes_start;
	int nb_tubes_end;
	int b;
	int x;

	nb_tubes_start = room[hive->num_room_start].nb_tube;
	nb_tubes_end = room[hive->num_room_end].nb_tube;
	b = 0;
	x = 0;
	if (nb_tubes_start <= nb_tubes_end)
		return (1);
	while (b < room[hive->num_room_start].nb_tube)
	{
		if (room[room[hive->num_room_start].link[b]].d_from_e == 0)
			x++;
		if (room[hive->num_room_start].link[b] == a)
		{
			if (b - x >= nb_tubes_end)
				return (0);
		}
		b++;
	}
	return (1);
}

static int	ft_avoid_wrg_path(t_struct_r *room, int a, int b)
{
	int i;

	i = 0;
	b = room[a].link[b];
	while (i < room[b].nb_tube)
	{
		if (room[room[b].link[i]].d_from_e < room[b].d_from_e &&
				room[room[b].link[i]].tour == 0)
			return (0);
		if (room[room[b].link[i]].type_s == 'e')
			return (0);
		i++;
	}
	if (room[b].d_from_e >= room[a].d_from_e)
		return (1);
	return (0);
}

static int	ft_potentially_moove(t_struct_r *room, t_struct_h *hive,
									int a, int b)
{
	if (room[a].type_s == 'e')
		ft_ant_moove(room, hive, room[a].link[b], a);
	else if (!ft_short_dfrom_end(room, hive, a) &&
			room[room[a].link[b]].type_s == 's' && room[a].nb_f <= 0)
		ft_ant_moove(room, hive, room[a].link[b], a);
	else if (room[room[a].link[b]].type_s == 's' && room[a].type_s != 'e' &&
		ft_short_dfrom_end(room, hive, a) == 1 && room[a].nb_f <= 0)
	{
		if (room[hive->num_room_start].nb_f >= room[a].d_from_e - 1 &&
				ft_nbtube_start_end(room, hive, a))
			ft_ant_moove(room, hive, room[a].link[b], a);
	}
	else if (room[a].nb_f <= 0 && ft_if_multiple_hant(room, a))
		ft_place_markeur(room, hive, a);
	else if (room[a].nb_f <= 0 && a != room[room[a].link[b]].ant_origin)
	{
		if (room[room[a].link[b]].nb_tube > 2)
		{
			if (ft_avoid_wrg_path(room, a, b))
				ft_ant_moove(room, hive, room[a].link[b], a);
		}
		else
			ft_ant_moove(room, hive, room[a].link[b], a);
	}
	return (1);
}

static void	ft_start_algo(t_struct_r *room, t_struct_h *hive, int a)
{
	int b;
	int j;
	int c;

	b = -1;
	j = -1;
	if (room[a].type_s != 's')
		room[a].tour = 1;
	if (room[a].type_s == 's' || room[hive->num_room_end].nb_f == hive->nb_f)
		return ;
	if (room[a].type_s == 'e' && room[room[a].link[0]].type_s == 's')
	{
		while (room[room[a].link[0]].nb_f > 0)
			ft_ant_moove(room, hive, room[a].link[0], a);
		return ;
	}
	while (++b < room[a].nb_tube)
	{
		c = room[a].link[b];
		if (room[c].nb_f > 0 && room[c].pull == 0 && room[c].type_s != 'e')
			ft_potentially_moove(room, hive, a, b);
		if (room[c].tour == 0 && a != room[c].ant_origin &&
				room[c].nb_tube >= 2 && room[c].nb_f <= 0)
			ft_start_algo(room, hive, room[a].link[b]);
	}
}

void		ft_pull_ant_ppichier(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	room[hive->num_room_start].num_f = 1;
	ft_link_f_start(room, hive, hive->num_room_start, 0);
	ft_init_turn_to_zero(room, hive);
	ft_link_f_end(room, hive, hive->num_room_end, 0);
	ft_init_turn_to_zero(room, hive);
	while (a < hive->nb_s)
	{
		ft_sort_int_link(room, a);
		a++;
	}
	ft_sort_start_link(room, hive);
	while (room[hive->num_room_end].nb_f < hive->nb_f)
	{
		ft_start_algo(room, hive, hive->num_room_end);
		ft_putchar('\n');
		ft_init_turn_to_zero(room, hive);
	}
}
