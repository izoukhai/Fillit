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
	while ((*list)->top.x != 0 && ++i < 4)
		(*list)->pos[i].x--;
	i = -1;
	while ((*list)->top.y != 0 && ++i < 4)
		(*list)->pos[i].y--;
}

int					solve_map(t_map *map, t_tetri *list)
{
	int				i;
	int				j;
	int				y;
	int				x;

	i = -1;
	x = 0;
	y = 0;
	while (list)
	{
		move_left(&list);
		i = -1;	
		while (++i < 4)
		{
			if (map->tab[list->pos[i].y][list->pos[i].x] == '.')
				map->tab[list->pos[i].y][list->pos[i].x] = list->fill;
		}
		list = list->next;
	}
	print_map(map);
}
