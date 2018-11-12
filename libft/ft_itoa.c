/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 19:27:44 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 19:27:46 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int nb)
{
	char	*ptr;

	if ((ptr = (char*)malloc(sizeof(*ptr) * 2)) == NULL)
		return (NULL);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb > 9)
		ptr = ft_strjoin(ft_itoa(nb / 10), ft_itoa(nb % 10));
	else if (nb >= 0 && nb <= 9)
	{
		ptr[0] = nb + 48;
		ptr[1] = '\0';
	}
	else if (nb < 0)
	{
		ptr[0] = '-';
		ptr[1] = '\0';
		ptr = ft_strjoin(ptr, ft_itoa(nb * -1));
	}
	return (ptr);
}
