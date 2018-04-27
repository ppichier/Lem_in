/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ppichier_opti.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:50:17 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 13:08:51 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

void	ft_sort_int_link(t_struct_r *room, int a)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < room[a].nb_tube - 1)
	{
		j = i + 1;
		while (j < room[a].nb_tube)
		{
			if (room[room[a].link[i]].d_from_s > room[room[a].link[j]].d_from_s)
			{
				tmp = room[a].link[i];
				room[a].link[i] = room[a].link[j];
				room[a].link[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_link_f_start(t_struct_r *room, t_struct_h *hive, int a, int d)
{
	int b;

	b = -1;
	room[hive->num_room_start].tour = 1;
	room[a].tour = 1;
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
		if (room[room[a].link[b]].tour == 0 ||
				room[room[a].link[b]].d_from_s > d + 1)
			ft_link_f_start(room, hive, room[a].link[b], room[a].d_from_s);
		if (room[a].type_s == 's')
			ft_init_turn_to_zero(room, hive);
	}
}

void	ft_link_f_end(t_struct_r *room, t_struct_h *hive, int a, int d)
{
	int b;

	b = -1;
	room[hive->num_room_end].tour = 1;
	room[a].tour = 1;
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
		if (room[room[a].link[b]].tour == 0 ||
			room[room[a].link[b]].d_from_e > d + 1)
			ft_link_f_end(room, hive, room[a].link[b], room[a].d_from_e);
		if (room[a].type_s == 'e')
			ft_init_turn_to_zero(room, hive);
	}
}

void	ft_effective_dfromend_start(t_struct_r *room, t_struct_h *hive)
{
	int start;
	int b;

	b = 0;
	start = hive->num_room_start;
	while (b < room[start].nb_tube)
	{
		if (room[room[start].link[b]].d_from_e > 0)
		{
			room[start].d_from_e = room[room[start].link[b]].d_from_e + 1;
			return ;
		}
		b++;
	}
}

void	ft_sort_start_link(t_struct_r *room, t_struct_h *hive)
{
	int i;
	int j;
	int tmp;
	int start;

	start = hive->num_room_start;
	i = 0;
	while (i < room[start].nb_tube - 1)
	{
		j = i + 1;
		while (j < room[start].nb_tube)
		{
			if (room[room[start].link[i]].d_from_e >
					room[room[start].link[j]].d_from_e)
			{
				tmp = room[start].link[i];
				room[start].link[i] = room[start].link[j];
				room[start].link[j] = tmp;
			}
			j++;
		}
		i++;
	}
	ft_effective_dfromend_start(room, hive);
}
