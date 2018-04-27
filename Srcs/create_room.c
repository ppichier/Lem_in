/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_room.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 18:49:50 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/04 18:49:51 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

static	void	ft_fill_room(t_struct_r *newroom, t_struct_h *hive,
				char **stock, int a)
{
	newroom[a].nb_f = -1;
	newroom[a].num_f = -1;
	newroom[a].d_from_e = 0;
	newroom[a].d_from_s = 0;
	newroom[a].dist = 0;
	newroom[a].tour = 0;
	newroom[a].mark = 0;
	if (hive->num_room_start == a)
	{
		newroom[a].type_s = 's';
		newroom[a].nb_f = hive->nb_f;
		newroom[a].num_f = 0;
	}
	else if (hive->num_room_end == a)
		newroom[a].type_s = 'e';
	else
		newroom[a].type_s = 'i';
	newroom[a].name = ft_strdup(stock[0]);
	newroom[a].x = ft_atoi(stock[1]);
	newroom[a].y = ft_atoi(stock[2]);
	newroom[a].nb_tube = 0;
	newroom[a].link = (int*)malloc(sizeof(int) * 1);
	newroom[a].link[0] = -1;
	newroom[a].ant_origin = a;
	newroom[a].pull = 0;
}

t_struct_r		*ft_create_room(t_struct_r *room, char **stock,
				t_struct_h *hive)
{
	int			a;
	t_struct_r	*tmp;

	a = 0;
	if (!(tmp = malloc(sizeof(t_struct_r) * (hive->nb_s + 1))))
		return (NULL);
	while (a < hive->nb_s)
	{
		tmp[a] = room[a];
		a++;
	}
	free(room);
	hive->nb_s = hive->nb_s + 1;
	ft_fill_room(tmp, hive, stock, a);
	ft_free_stock(stock);
	return (tmp);
}
