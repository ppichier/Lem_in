/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lem_in.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 17:44:16 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 11:06:01 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../Libft/Includes/libft.h"

typedef	struct	s_struct_hive
{
	int		nb_f;
	int		nb_s;
	int		num_room_start;
	int		num_room_end;
	char	**print;
}				t_struct_h;

typedef	struct	s_struct_r
{
	int		ant_origin;
	int		pull;
	int		d_from_e;
	int		d_from_s;
	int		dist;
	int		tour;
	int		mark;
	int		x;
	int		y;
	int		num_f;
	int		nb_f;
	char	*name;
	int		nb_tube;
	int		*link;
	char	type_s;
}				t_struct_r;

/*
** aurollan_algo
*/
void			ft_find_ant(t_struct_r *room, int a, t_struct_h *hive);

/*
** aurollan_loop
*/
int				ft_direct_pipe(t_struct_r *room, t_struct_h *hive);
void			ft_pull_ant(t_struct_r *room, t_struct_h *hive);

/*
** aurollan_refresh_hive
*/
int				ft_nb_ant_to_catch(t_struct_r *room, int a);
void			ft_sort_dfe_tab_rev(t_struct_r *room, int a);
int				ft_find_way(t_struct_r *room, int a, t_struct_h *hive);
void			ft_refresh_hive(t_struct_r *room, t_struct_h *hive);

/*
** aurollan_sort_path
*/
void			ft_calc_dfe(t_struct_r *room, t_struct_h *hive, int a, int c);
void			ft_calc_dfs(t_struct_r *room, t_struct_h *hive, int a, int c);
void			ft_sort_path(t_struct_r *room, t_struct_h *hive);
void			ft_sort_dfs_tab(t_struct_r *room, int a);
void			ft_sort_path_remix(t_struct_r *room, t_struct_h *hive);

/*
** check_error
*/
int				ft_check_error(t_struct_r *room, t_struct_h *hive);
int				ft_find_end(t_struct_r *room, int a);
int				ft_find_start(t_struct_r *room, int a);

/*
** check_room
*/
char			**ft_check_room(char *str, t_struct_r *room, t_struct_h *hive);

/*
** check_tube
*/
char			**ft_check_tube(char *str, t_struct_h *hive, t_struct_r *room);

/*
** clear_roaming
*/
int				ft_find_end_clear(t_struct_r *room, int a, t_struct_h *hive);
int				ft_find_start_clear(t_struct_r *room, int a, t_struct_h *hive);

/*
** create_room
*/
t_struct_r		*ft_create_room(t_struct_r *room,
				char **stock, t_struct_h *hive);

/*
** create_structure
*/
t_struct_r		*ft_create_structure(t_struct_h *hive, t_struct_r *room);

/*
** create_tube
*/
t_struct_r		*ft_link_room(char **stock, t_struct_r *room, t_struct_h *hive);

/*
** free_init
*/
void			ft_free_stock(char **stock);
void			ft_init_mark_to_zero(t_struct_r *room, t_struct_h *hive);
void			ft_init_nbf_to_zero(t_struct_r *room, t_struct_h *hive);
void			ft_init_turn_to_zero(t_struct_r *room, t_struct_h *hive);
int				ft_check_nb_ant(char *str, t_struct_h *hive);

/*
** hive
*/
void			ft_free_hive(t_struct_r *room, t_struct_h *hive);
void			ft_init_hive(t_struct_h *hive);
void			ft_create_print_map(t_struct_h *hive, char *str);
void			ft_print_map(t_struct_h *hive);

/*
** tools
*/
void			ft_print_hive(t_struct_r *room, t_struct_h *hive);

/*
** Pier'antonio ajoute en dessous de ce commentaire
*/
void			ft_pull_ant_ppichier(t_struct_r *room, t_struct_h *hive);
void			ft_link_f_start(t_struct_r *room, t_struct_h *hive,
				int a, int d);
void			ft_link_f_end(t_struct_r *room, t_struct_h *hive, int a, int d);
void			ft_sort_int_link(t_struct_r *room, int a);
void			ft_sort_start_link(t_struct_r *room, t_struct_h *hive);
int				ft_if_multiple_hant(t_struct_r *room, int a);
int				ft_place_markeur(t_struct_r *room, t_struct_h *hive, int a);
void			ft_ant_moove(t_struct_r *room, t_struct_h *hive,
				int orig, int dest);
void			ft_effective_dfromend_start(t_struct_r *room, t_struct_h *hive);
void			ft_rclcl_dstart(t_struct_r *room, t_struct_h *hive,
				int a, int d);
void			ft_rclcl_dend(t_struct_r *room, t_struct_h *hive, int a, int d);
int				ft_short_dfrom_end(t_struct_r *room, t_struct_h *hive, int a);
void			ft_reorganize_link(t_struct_r *room, t_struct_h *hive);
void			ft_chk_bestdst(t_struct_r *room, t_struct_h *hive,
				int a, int b);
void			ft_initialize_node_to_zero(t_struct_r *room, t_struct_h *hive);
void			ft_initialize_node_to_one(t_struct_r *room,
				t_struct_h *hive, int a);

#endif
