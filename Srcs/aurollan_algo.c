/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aurollan_algo.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 17:39:43 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 17:39:44 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static	int		ft_send_ant(t_struct_r *room, int a, int b, t_struct_h *hive)
{
	if ((room[a].d_from_e >= room[b].d_from_e) && room[b].type_s == 'i'
		&& room[a].type_s == 'i' && room[b].d_from_e != -1
		&& room[a].dist > room[b].dist && room[b].d_from_s == -1)
		return (0);
	if (room[b].d_from_s != -1 && room[a].type_s == 'i' && room[b].type_s == 'i'
		&& (room[b].dist < room[b].d_from_e + room[b].d_from_s)
		&& (hive->nb_f - room[hive->num_room_start].nb_f +
		room[b].dist - room[b].d_from_s < room[a].d_from_e)
		&& room[b].d_from_e != 2000000)
		return (0);
	if (room[a].d_from_e <= room[b].d_from_e)
		return (1);
	if (room[b].nb_f + room[b].d_from_e > (room[a].dist - room[a].d_from_s + 2)
		&& room[b].nb_f > 0 && room[b].type_s)
		return (1);
	if (room[b].type_s != 's')
		return (1);
	return (0);
}

static	void	ft_pipe_ant(t_struct_r *room, int a, int b, t_struct_h *hive)
{
	if (room[a].type_s != 'e' && ft_send_ant(room, a, b, hive) == 0)
		return ;
	if (room[b].type_s == 's' && room[b].nb_f <= 0)
	{
		if (room[a].type_s != 'e')
			room[a].tour = 1;
		return ;
	}
	if (room[b].type_s == 's')
		room[b].num_f = room[b].num_f + 1;
	room[a].num_f = room[b].num_f;
	room[b].nb_f = room[b].nb_f - 1;
	room[a].nb_f = room[a].nb_f + 1;
	if (room[a].nb_f > 0 && room[a].type_s != 's')
		ft_printf("L%d-%s ", room[a].num_f, room[a].name);
}

static	int		ft_first_start(t_struct_r *room, int a, t_struct_h *hive)
{
	int b;

	b = -1;
	while (++b < room[a].nb_tube && room[a].nb_f == 0)
	{
		if (room[room[a].link[b]].type_s == 's')
		{
			ft_pipe_ant(room, a, room[a].link[b], hive);
			return (1);
		}
	}
	return (0);
}

static	void	ft_roaming(t_struct_r *room, int a, t_struct_h *hive, int b)
{
	if (room[room[a].link[b]].tour == 0 && room[room[a].link[b]].nb_f == 0
		&& room[room[a].link[b]].type_s != 'e'
		&& room[room[a].link[b]]. d_from_s > 0)
	{
		if (ft_find_end_clear(room, room[a].link[b], hive) == 0)
			ft_find_ant(room, room[a].link[b], hive);
		if (ft_find_end_clear(room, room[a].link[b], hive)
			&& (room[a].d_from_e < room[room[a].link[b]].d_from_e))
			ft_find_ant(room, room[a].link[b], hive);
	}
	else if (room[room[a].link[b]].tour == 0
			&& room[room[a].link[b]].nb_f == 1
			&& room[room[a].link[b]].type_s != 'e' && ((room[a].nb_f == 0
			&& room[a].type_s != 'e') || room[a].type_s == 'e')
			&& (room[a].d_from_e < room[room[a].link[b]].d_from_e
			|| room[hive->num_room_end].dist <= room[room[a].link[b]].d_from_e))
	{
		ft_pipe_ant(room, a, room[a].link[b], hive);
		ft_find_ant(room, room[a].link[b], hive);
	}
}

void			ft_find_ant(t_struct_r *room, int a, t_struct_h *hive)
{
	int b;

	b = -1;
	room[a].tour = 1;
	if (room[a].type_s == 's' || ft_first_start(room, a, hive) == 1)
		return ;
	if (room[a].type_s != 'e' && room[a].nb_tube > 2 &&
	ft_nb_ant_to_catch(room, a) > 1)
	{
		ft_refresh_hive(room, hive);
		ft_sort_dfe_tab_rev(room, a);
	}
	while (++b < room[a].nb_tube)
	{
		ft_roaming(room, a, hive, b);
		if (room[a].tour == 1 && room[a].nb_f == 1
			&& ft_find_way(room, a, hive) == 0 && room[a].type_s != 'e')
			return ;
	}
}
