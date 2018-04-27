/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aurollan_loop.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 17:06:37 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 17:06:39 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

int		ft_direct_pipe(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	while (a < room[hive->num_room_end].nb_tube)
	{
		if (room[hive->num_room_end].link[a] == hive->num_room_start)
		{
			while (room[hive->num_room_start].nb_f > 0)
			{
				room[hive->num_room_start].nb_f =
						room[hive->num_room_start].nb_f - 1;
				room[hive->num_room_end].nb_f =
						room[hive->num_room_end].nb_f + 1;
				ft_printf("L%d-%s ", room[hive->num_room_end].nb_f,
						room[hive->num_room_end].name);
			}
			ft_putchar('\n');
			return (1);
		}
		a++;
	}
	return (0);
}

void	ft_pull_ant(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	ft_sort_path(room, hive);
	if (ft_direct_pipe(room, hive) == 1)
		return ;
	while (room[hive->num_room_end].nb_f < hive->nb_f)
	{
		ft_find_ant(room, hive->num_room_end, hive);
		ft_init_turn_to_zero(room, hive);
		ft_putchar('\n');
		a++;
	}
}
