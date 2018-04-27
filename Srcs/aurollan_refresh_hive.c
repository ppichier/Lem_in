/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aurollan_refresh_hive.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 17:39:56 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 17:39:57 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

int		ft_find_way(t_struct_r *room, int a, t_struct_h *hive)
{
	int b;

	b = 0;
	while (b < room[a].nb_tube)
	{
		if (ft_find_start_clear(room, room[a].link[b], hive))
		{
			ft_init_mark_to_zero(room, hive);
			return (1);
		}
		b++;
	}
	ft_init_mark_to_zero(room, hive);
	return (0);
}

int		ft_nb_ant_to_catch(t_struct_r *room, int a)
{
	int b;
	int count;

	b = 0;
	count = 0;
	while (b < room[a].nb_tube)
	{
		if (room[room[a].link[b]].type_s == 'i'
			&& room[room[a].link[b]].tour == 0
			&& room[room[a].link[b]].nb_f == 1
			&& room[a].d_from_e < room[room[a].link[b]].d_from_e)
			count++;
		b++;
	}
	return (count);
}

void	ft_sort_dfe_tab_rev(t_struct_r *room, int a)
{
	int b;
	int c;

	b = 0;
	while (b < room[a].nb_tube)
	{
		c = b + 1;
		while (c < room[a].nb_tube)
		{
			if (room[room[a].link[b]].d_from_e <
				room[room[a].link[c]].d_from_e)
			{
				ft_swap(&room[a].link[b], &room[a].link[c]);
			}
			c++;
		}
		b++;
	}
}

void	ft_refresh_hive(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	if (ft_find_end_clear(room, hive->num_room_start, hive))
	{
		while (a < hive->nb_s)
		{
			if (room[a].type_s == 'i' && room[a].tour == 0)
			{
				room[a].d_from_e = -1;
				room[a].d_from_s = -1;
			}
			a++;
		}
		ft_sort_path_remix(room, hive);
		a = 0;
		while (a < hive->nb_s)
		{
			if (room[a].d_from_e == -1 && room[a].d_from_s != -1)
				room[a].d_from_e = 2000000;
			a++;
		}
	}
}
