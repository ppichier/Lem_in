/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:17:05 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:17:08 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	size_t	a;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (content == 0)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content_size = content_size;
		list->content = malloc(sizeof(content) * content_size);
		a = 0;
		while (a < content_size)
		{
			((unsigned char *)list->content)[a] = ((unsigned char*)content)[a];
			a++;
		}
	}
	list->next = NULL;
	return (list);
}
