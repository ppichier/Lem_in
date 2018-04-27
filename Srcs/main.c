/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:55:50 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 11:09:52 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

int		main(void)
{
	t_struct_r	*room;
	t_struct_h	*hive;

	room = NULL;
	if (!(hive = (t_struct_h*)malloc(sizeof(t_struct_h))))
		return (0);
	ft_init_hive(hive);
	room = ft_create_structure(hive, room);
	if (ft_check_error(room, hive))
	{
		write(2, "ERROR\n", 6);
		ft_free_hive(room, hive);
		return (0);
	}
	ft_print_map(hive);
	ft_pull_ant(room, hive);
	ft_free_hive(room, hive);
	return (0);
}
