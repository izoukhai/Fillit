/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 20:23:25 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 20:23:26 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*res;

	res = (unsigned char*)ptr;
	i = 0;
	while (i < num)
	{
		res[i] = (unsigned char)value;
		i++;
	}
	return (res);
}
