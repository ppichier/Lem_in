/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aurollan_sort_path.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 17:39:56 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 17:39:57 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

void		ft_calc_dfe(t_struct_r *room, t_struct_h *hive, int a, int c)
{
	int b;

	b = -1;
	if (a == hive->num_room_start)
		return ;
	room[a].mark = 1;
	while (++b < room[a].nb_tube)
	{
		if (room[room[a].link[b]].d_from_e <= 0
			&& room[room[a].link[b]].type_s != 'e')
			room[room[a].link[b]].d_from_e = room[a].d_from_e + 1;
		if ((room[a].d_from_e + 1 < room[room[a].link[b]].d_from_e)
			&& room[room[a].link[b]].tour == 0)
		{
			room[room[a].link[b]].d_from_e = room[a].d_from_e + 1;
			ft_calc_dfe(room, hive, room[a].link[b], a);
		}
		if (room[room[a].link[b]].type_s != 'e' && room[room[a].link[b]].type_s
			!= 's' && room[a].link[b] != c && room[room[a].link[b]].mark == 0
			&& room[room[a].link[b]].tour == 0)
			ft_calc_dfe(room, hive, room[a].link[b], a);
	}
}

void		ft_calc_dfs(t_struct_r *room, t_struct_h *hive, int a, int c)
{
	int b;

	b = -1;
	if (a == hive->num_room_end)
		return ;
	room[a].mark = 1;
	while (++b < room[a].nb_tube)
	{
		if (room[room[a].link[b]].d_from_s <= 0 &&
			room[room[a].link[b]].type_s != 's')
			room[room[a].link[b]].d_from_s = room[a].d_from_s + 1;
		if ((room[a].d_from_s + 1 < room[room[a].link[b]].d_from_s)
			&& room[room[a].link[b]].tour == 0)
		{
			room[room[a].link[b]].d_from_s = room[a].d_from_s + 1;
			ft_calc_dfs(room, hive, room[a].link[b], a);
		}
		if (room[room[a].link[b]].type_s != 'e' && room[room[a].link[b]].type_s
			!= 's' && room[a].link[b] != c && room[room[a].link[b]].mark == 0
			&& room[room[a].link[b]].tour == 0)
			ft_calc_dfs(room, hive, room[a].link[b], a);
	}
}

void		ft_sort_dfs_tab(t_struct_r *room, int a)
{
	int b;
	int c;

	b = 0;
	while (b < room[a].nb_tube)
	{
		c = b + 1;
		while (c < room[a].nb_tube)
		{
			if (room[room[a].link[b]].d_from_s > room[room[a].link[c]].d_from_s)
				ft_swap(&room[a].link[b], &room[a].link[c]);
			c++;
		}
		b++;
	}
}

void		ft_sort_path_remix(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	room[hive->num_room_end].d_from_s = -1;
	ft_calc_dfs(room, hive, hive->num_room_start, hive->num_room_end);
	ft_init_mark_to_zero(room, hive);
	room[hive->num_room_start].d_from_e = -1;
	ft_calc_dfe(room, hive, hive->num_room_end, hive->num_room_start);
	ft_init_mark_to_zero(room, hive);
	while (a < hive->nb_s)
	{
		if (room[a].type_s == 'i' && room[a].tour == 0)
		{
			ft_sort_dfs_tab(room, a);
		}
		a++;
	}
}

void		ft_sort_path(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	room[hive->num_room_end].d_from_s = -1;
	ft_calc_dfs(room, hive, hive->num_room_start, hive->num_room_end);
	ft_init_mark_to_zero(room, hive);
	room[hive->num_room_start].d_from_e = -1;
	ft_calc_dfe(room, hive, hive->num_room_end, hive->num_room_start);
	ft_init_mark_to_zero(room, hive);
	while (a < hive->nb_s)
	{
		ft_sort_dfs_tab(room, a);
		room[a].dist = room[a].d_from_e + room[a].d_from_s;
		a++;
	}
}
