/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 23:58:40 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 21:44:40 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int					check_map(char **line)
{
	int				y;
	int				x;
	int				link_counter;

	y = 0;
	x = 0;
	link_counter = 0;
	if (check_hashtag(line) != 4)
		return (-1);
	while (line[y] && y < 4)
	{
		x = 0;
		while (line[y][x] && (line[y][x] == '.' || line[y][x] == '#'))
		{
			check_connex(y, x, &link_counter, line);
			x++;
		}
		y++;
	}
	if (link_counter != 6 && link_counter != 8)
		return (-1);
	return (link_counter);
}

t_tetri				*solve(t_tetri *list)
{
	t_tetri			*res;

	if ((res = create_tetri()) == NULL)
		return (NULL);
	while (list)
	{
		printf("%c\n", list->fill);
		list = list->next;
	}
	return (res);
}

int					fillit(int fd)
{
	t_tetri			*list;
	t_tetri			*res;
	t_tetri			*old;
	int				ret;
	char			fill;

	fill = 'A';
	MALLCHECK((list = create_tetri()));
	while ((ret = get_all_tetri(fd, &list)))
		if (ret == -1)
			return (-1);
	sort_tetri(&list);
	list = list->next;
	old = list;
	while (list)
	{
		if (check_map(list->tab) == -1)
			return (-1);
		list->fill = fill++;
		list = list->next;
	}
	res = solve(old);
	return (1);
}
