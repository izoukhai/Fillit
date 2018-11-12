/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:27:08 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:27:09 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*res;

	res = (unsigned char*)ptr;
	while (n--)
		if (*res != (unsigned char)value)
			res++;
		else
			return (res);
	return (NULL);
}
