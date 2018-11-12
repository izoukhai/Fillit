/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:47:12 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:47:13 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (!ptr1 && !ptr2)
		return (0);
	str1 = (unsigned char*)ptr1;
	str2 = (unsigned char*)ptr2;
	while (str1[i] == str2[i] && i < n - 1)
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
