/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:18:47 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:18:48 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr;

	if (!(ptr = malloc(size)))
		return (0);
	ft_memset(ptr, 0, size);
	return (ptr);
}
