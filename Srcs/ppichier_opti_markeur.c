/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ppichier_pull_opti.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:50:22 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 14:39:42 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static void		ft_sort_dfrome_node(t_struct_r *room, int a, int *tab)
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
			if (room[tab[i]].d_from_e < room[tab[j]].d_from_e)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static	int		ft_recalcul_all_dist(t_struct_r *room, t_struct_h *hive, int i)
{
	int a;

	a = -1;
	while (++a < hive->nb_s)
	{
		if (a != i)
		{
			room[a].d_from_e = 0;
			room[a].d_from_s = 0;
		}
	}
	room[hive->num_room_end].tour = 0;
	ft_init_mark_to_zero(room, hive);
	ft_rclcl_dstart(room, hive, hive->num_room_start, 0);
	ft_init_mark_to_zero(room, hive);
	ft_rclcl_dend(room, hive, hive->num_room_end, 0);
	ft_init_mark_to_zero(room, hive);
	a = -1;
	while (++a < hive->nb_s)
	{
		if (room[a].type_s != 'e' && room[a].d_from_e == 0)
			room[a].d_from_e = 2000000;
	}
	room[hive->num_room_end].tour = 1;
	return (1);
}

static void		ft_save_true_dist(t_struct_r *room, t_struct_h *hive,
									int *tab_start, int *tab_end)
{
	int i;

	i = 0;
	while (i < hive->nb_s)
	{
		tab_end[i] = room[i].d_from_e;
		tab_start[i] = room[i].d_from_s;
		i++;
	}
}

static void		ft_plus_dinspi(t_struct_r *room, t_struct_h *hive, int a,
								int *sort_dfrome)
{
	int b;

	b = -1;
	while (++b < room[a].nb_tube)
	{
		if (room[sort_dfrome[b]].nb_f > 0 && room[sort_dfrome[b]].type_s != 'e'
			&& room[sort_dfrome[b]].pull == 0)
		{
			ft_ant_moove(room, hive, sort_dfrome[b], a);
			break ;
		}
	}
}

int				ft_place_markeur(t_struct_r *room, t_struct_h *hive, int a)
{
	int	*sort_dfrome;
	int	*true_dist_end;
	int	*true_dist_start;
	int	b;

	b = -1;
	sort_dfrome = (int*)malloc(sizeof(*sort_dfrome) * room[a].nb_tube);
	true_dist_end = (int*)malloc(sizeof(*true_dist_end) * hive->nb_s);
	true_dist_start = (int*)malloc(sizeof(*true_dist_start) * hive->nb_s);
	ft_save_true_dist(room, hive, true_dist_start, true_dist_end);
	ft_recalcul_all_dist(room, hive, a);
	while (++b < room[a].nb_tube)
		sort_dfrome[b] = room[a].link[b];
	ft_sort_dfrome_node(room, a, sort_dfrome);
	ft_plus_dinspi(room, hive, a, sort_dfrome);
	b = -1;
	while (++b < hive->nb_s)
	{
		room[b].d_from_e = true_dist_end[b];
		room[b].d_from_s = true_dist_start[b];
	}
	free(sort_dfrome);
	free(true_dist_end);
	free(true_dist_start);
	return (1);
}
