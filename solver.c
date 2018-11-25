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

static int			get_sqrt(int nb)
{
	int tmp;

	tmp = nb / 2;
	while (tmp * tmp > nb)
		tmp--;
	return ((tmp * tmp == nb) ? tmp : tmp + 1);
}

static void			move_left(t_tetri **list)
{
	int i;

	i = -1;
	if ((*list)->top.x != 0)
	{
		(*list)->top.x--;
		while (++i < 4)
			(*list)->pos[i].x--;
		move_left(list);
	}
	if ((*list)->top.y != 0)
	{
		(*list)->top.y--;
		while (++i < 4)
			(*list)->pos[i].y--;
		move_left(list);
	}
}

static void			print_pos(t_tetri *list)
{
	int i = -1;

	while (++i < 4)
		printf("%c: x: %d, y: %d\n", list->fill, list->pos[i].x, list->pos[i].y);
}

int					solve_map(t_map *map, t_tetri *list)
{
	t_point			pos;

	pos.y = -1;
	if (list == NULL)
		return (1);
	while (++pos.y < map->size)
	{
		pos.x = -1;
		while (++pos.x < map->size)
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

t_map			*solve(t_tetri *list)
{
	t_tetri 	*cur;
	t_map 		*res;
	int 		size;

	cur = list;
	size = get_sqrt(count_tetris(list) * 4);
	res = new_map(size);
	while (!solve_map(res, cur))
	{
		size++;
		del_map(&res);
		res = new_map(size);
	}
	print_map(res);
	return (res);
}
