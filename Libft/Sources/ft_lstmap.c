/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:06:57 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:07:26 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *patern;
	t_list *save;

	if (lst)
	{
		patern = f(lst);
		tmp = ft_lstnew(patern->content, patern->content_size);
		save = tmp;
		lst = lst->next;
	}
	if (f)
	{
		while (lst)
		{
			patern = f(lst);
			tmp->next = ft_lstnew(patern->content, patern->content_size);
			tmp = tmp->next;
			lst = lst->next;
		}
		return (save);
	}
	return (NULL);
}
