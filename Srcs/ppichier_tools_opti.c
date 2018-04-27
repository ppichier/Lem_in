/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ppichier_tools_opti.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 17:19:48 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 13:15:52 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

void	ft_ant_moove(t_struct_r *room, t_struct_h *hive, int orig, int dest)
{
	if (room[dest].type_s != 'e')
		room[dest].pull = 1;
	room[orig].nb_f = room[orig].nb_f - 1;
	room[dest].num_f = room[orig].num_f;
	if (room[orig].type_s == 's')
	{
		room[orig].num_f = room[orig].num_f + 1;
		if (room[orig].num_f > hive->nb_f)
			room[orig].num_f = 0;
	}
	else
		room[orig].num_f = -1;
	if (room[dest].type_s != 'e')
		room[dest].ant_origin = orig;
	room[orig].ant_origin = orig;
	room[dest].nb_f = room[dest].nb_f + 1;
	if (room[dest].num_f >= 0)
		ft_printf("L%d-%s ", room[dest].num_f, room[dest].name);
}

int		ft_short_dfrom_end(t_struct_r *room, t_struct_h *hive, int a)
{
	int b;
	int start;

	b = 0;
	start = hive->num_room_start;
	while (b < room[start].nb_tube)
	{
		if (room[room[start].link[b]].d_from_e != 0)
			break ;
		b++;
	}
	if (room[a].d_from_e == room[room[start].link[b]].d_from_e)
		return (0);
	return (1);
}

void	ft_rclcl_dstart(t_struct_r *room, t_struct_h *hive, int a, int d)
{
	int b;

	b = -1;
	room[hive->num_room_start].mark = 1;
	room[a].mark = 1;
	if (room[a].tour == 1)
		return ;
	if (room[a].type_s != 's')
	{
		if (room[a].d_from_s != 0 && room[a].d_from_s > d + 1)
			room[a].d_from_s = d + 1;
		if (room[a].d_from_s == 0)
			room[a].d_from_s = d + 1;
		if (room[a].type_s == 'e')
			return ;
	}
	while (++b < room[a].nb_tube)
	{
		if (room[room[a].link[b]].mark == 0 ||
				room[room[a].link[b]].d_from_s > d + 1)
			ft_rclcl_dstart(room, hive, room[a].link[b], room[a].d_from_s);
		if (room[a].type_s == 's')
			ft_init_mark_to_zero(room, hive);
	}
}

void	ft_rclcl_dend(t_struct_r *room, t_struct_h *hive, int a, int d)
{
	int b;

	b = -1;
	room[hive->num_room_end].mark = 1;
	room[a].mark = 1;
	if (room[a].tour == 1)
		return ;
	if (room[a].type_s != 'e')
	{
		if (room[a].d_from_e != 0 && room[a].d_from_e > d + 1)
			room[a].d_from_e = d + 1;
		if (room[a].d_from_e == 0)
			room[a].d_from_e = d + 1;
		if (room[a].type_s == 's')
			return ;
	}
	while (++b < room[a].nb_tube)
	{
		if (room[room[a].link[b]].mark == 0 ||
				room[room[a].link[b]].d_from_e > d + 1)
			ft_rclcl_dend(room, hive, room[a].link[b], room[a].d_from_e);
		if (room[a].type_s == 'e')
			ft_init_mark_to_zero(room, hive);
	}
}

int		ft_if_multiple_hant(t_struct_r *room, int a)
{
	int b;
	int cpt;

	b = 0;
	cpt = 0;
	while (b < room[a].nb_tube)
	{
		if (room[room[a].link[b]].nb_f > 0 && room[room[a].link[b]].tour == 0)
			cpt++;
		b++;
	}
	if (cpt >= 2)
		return (1);
	return (0);
}
