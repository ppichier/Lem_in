/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clear_roaming.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 17:14:40 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 17:14:41 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

int			ft_find_end_clear(t_struct_r *room, int a, t_struct_h *hive)
{
	if (ft_find_end(room, a) == 1)
	{
		ft_init_mark_to_zero(room, hive);
		return (1);
	}
	ft_init_mark_to_zero(room, hive);
	return (0);
}

int			ft_find_start_clear(t_struct_r *room, int a, t_struct_h *hive)
{
	if (ft_find_start(room, a) == 1)
	{
		ft_init_mark_to_zero(room, hive);
		return (1);
	}
	ft_init_mark_to_zero(room, hive);
	return (0);
}
