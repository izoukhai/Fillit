/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 18:11:52 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 05:46:46 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int			get_sqrt(int nb)
{
	int				tmp;

	tmp = nb / 2;
	while (tmp * tmp > nb)
		tmp--;
	return ((tmp * tmp == nb) ? tmp : tmp + 1);
}

int					solve_map(t_map *map, t_tetri *list)
{
	t_point			pos;

	pos.y = -1;
	if (list == NULL)
		return (1);
	while (++pos.y < (int)map->size)
	{
		pos.x = -1;
		while (++pos.x < (int)map->size)
		{
			if (check_pmap(list, map, pos))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					pmap(list, map, pos, '.');
			}
		}
	}
	return (0);
}

t_map				*solve(t_tetri *list)
{
	t_tetri			*cur;
	t_map			*res;
	int				size;

	cur = list;
	size = get_sqrt(count_tetris(list) * 4);
	res = new_map(size);
	while (!solve_map(res, cur))
	{
		size++;
		del_map(&res);
		res = new_map(size);
	}
	return (res);
}
