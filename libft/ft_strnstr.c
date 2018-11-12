/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 21:54:23 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 21:54:25 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	if (ft_strlen((char*)needle) == 0)
		return ((char*)haystack);
	i = 0;
	j = 0;
	size = ft_strlen((char*)needle);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (j == size - 1)
				return ((char*)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
