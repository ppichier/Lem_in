/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 17:31:29 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 17:01:44 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

void	ft_init_nbf_to_zero(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	while (a < hive->nb_s)
	{
		if (room[a].type_s != 's')
			room[a].nb_f = 0;
		a++;
	}
}

void	ft_free_stock(char **stock)
{
	int i;

	i = 0;
	while (stock[i])
	{
		free(stock[i]);
		i++;
	}
	free(stock);
}

void	ft_init_turn_to_zero(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	while (a < hive->nb_s)
	{
		room[a].tour = 0;
		room[a].pull = 0;
		a++;
	}
}

void	ft_init_mark_to_zero(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	while (a < hive->nb_s)
	{
		room[a].mark = 0;
		a++;
	}
}

int		ft_check_nb_ant(char *str, t_struct_h *hive)
{
	int			a;
	intmax_t	nb;

	a = 0;
	while (str[a])
	{
		if (ft_isdigit(str[a]))
			a++;
		else
			return (0);
	}
	nb = ft_atoi_maxint(str);
	if (nb > 2147483647)
		return (0);
	hive->nb_f = ft_atoi(str);
	ft_create_print_map(hive, str);
	return (a);
}
