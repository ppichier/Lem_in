/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:49:25 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 18:49:28 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static	int	ft_check_start(t_struct_r *room, t_struct_h *hive)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < hive->nb_s)
	{
		if (room[a].type_s == 's')
			b++;
		a++;
	}
	if (b != 1)
		return (1);
	return (0);
}

static	int	ft_check_end(t_struct_r *room, t_struct_h *hive)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < hive->nb_s)
	{
		if (room[a].type_s == 'e')
			b++;
		a++;
	}
	if (b != 1)
		return (1);
	return (0);
}

int			ft_find_end(t_struct_r *room, int a)
{
	int b;
	int c;

	b = -1;
	c = -1;
	if (room[a].mark == 1 || room[a].tour == 1)
		return (0);
	room[a].mark = 1;
	while (++b < room[a].nb_tube)
	{
		if (room[room[a].link[b]].type_s == 'e')
			return (1);
	}
	while (++c < room[a].nb_tube)
	{
		if (room[room[a].link[c]].type_s != 's')
		{
			if (ft_find_end(room, room[a].link[c]))
				return (1);
		}
	}
	return (0);
}

int			ft_find_start(t_struct_r *room, int a)
{
	int b;
	int c;

	b = -1;
	c = -1;
	if (room[a].mark == 1 || room[a].tour == 1)
		return (0);
	room[a].mark = 1;
	while (++b < room[a].nb_tube)
	{
		if (room[room[a].link[b]].type_s == 's')
			return (1);
	}
	while (++c < room[a].nb_tube)
	{
		if (room[room[a].link[c]].type_s != 'e')
		{
			if (ft_find_start(room, room[a].link[c]))
				return (1);
		}
	}
	return (0);
}

int			ft_check_error(t_struct_r *room, t_struct_h *hive)
{
	if (ft_check_end(room, hive))
		return (1);
	if (ft_check_start(room, hive))
		return (1);
	ft_init_turn_to_zero(room, hive);
	if (!(ft_find_end_clear(room, hive->num_room_start, hive)))
		return (1);
	ft_init_mark_to_zero(room, hive);
	ft_init_nbf_to_zero(room, hive);
	return (0);
}
