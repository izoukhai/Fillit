/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 18:11:52 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 18:11:52 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int			get_sqrt(int n)
{
	int tmp;

	tmp = nb / 2;
	while (tmp * tmp > nb)
		tmp--;
	return ((tmp * tmp == nb) ? tmp : tmp + 1);
}

int					solve_map(t_map *map, t_tetri *list)
{
	int				i;
	int				j;

	i = -1;
	while (list)
	{
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
		}
		list = list->next;
	}
}