/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hive.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 17:16:52 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 17:16:53 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/lem_in.h"

void	ft_init_hive(t_struct_h *hive)
{
	hive->nb_f = 0;
	hive->nb_s = 0;
	hive->num_room_start = -1;
	hive->num_room_end = -1;
	hive->print = (char **)malloc(sizeof(char *) * 1);
	hive->print[0] = NULL;
}

void	ft_free_hive(t_struct_r *room, t_struct_h *hive)
{
	int a;

	a = 0;
	while (a < hive->nb_s)
	{
		free(room[a].name);
		free(room[a].link);
		a++;
	}
	a = 0;
	while (hive->print[a])
	{
		free(hive->print[a]);
		a++;
	}
	free(hive->print);
	free(room);
	free(hive);
}

void	ft_create_print_map(t_struct_h *hive, char *str)
{
	char	**tmp;
	int		a;

	a = 0;
	while (hive->print[a])
		a++;
	tmp = (char **)malloc(sizeof(char *) * (a + 2));
	tmp[a + 1] = NULL;
	tmp[a] = ft_strdup(str);
	a = 0;
	while (hive->print[a])
	{
		tmp[a] = hive->print[a];
		a++;
	}
	free(hive->print);
	hive->print = tmp;
}

void	ft_print_map(t_struct_h *hive)
{
	int a;

	a = 0;
	while (hive->print[a])
	{
		ft_printf("%s\n", hive->print[a]);
		a++;
	}
	ft_putchar('\n');
}
