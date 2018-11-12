/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strequ.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:13:58 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:13:59 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if ((!s1 || !s2) || (ft_strlen((char*)s1) != ft_strlen((char*)s2)))
		return (0);
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (1);
}
