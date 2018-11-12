/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 18:09:34 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 18:09:34 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*save;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		save = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = save;
	}
	*alst = NULL;
}
