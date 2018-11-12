/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 21:20:18 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 21:22:52 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		cpt;

	cpt = 0;
	while (cpt < n)
	{
		((unsigned char *)dest)[cpt] = ((unsigned char *)src)[cpt];
		if (((unsigned char *)src)[cpt] == (unsigned char)c)
			return ((void *)(((unsigned char *)dest) + cpt + 1));
		cpt++;
	}
	return (NULL);
}
