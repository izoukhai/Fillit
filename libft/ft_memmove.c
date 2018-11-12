/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 21:57:19 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 21:57:20 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *destination, const void *source, size_t num)
{
	char	*c1;
	char	*c2;

	if (destination < source)
		return (ft_memcpy(destination, source, num));
	if (num == 0 || destination == source)
		return (destination);
	c1 = (char*)destination;
	c2 = (char*)source;
	while (num--)
	{
		c1[num] = c2[num];
	}
	return (c1);
}
