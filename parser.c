/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 00:05:28 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 00:05:28 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int					check_hashtag(char **line, t_tetri **piece)
{
	int				y;
	int				x;
	int				res;
	int				i;

	res = 0;
	y = -1;
	i = 0;
	while (line[++y] && y < 4)
	{
		x = -1;
		while (line[y][++x])
			if (line[y][x] == '#')
			{
				(*piece)->pos[i].x = x + 1;
				(*piece)->pos[i].y = y + 1;
				i++;
				res++;
			}
	}
	(*piece)->top = get_top(*piece);
	/*printf("TOP.X: %d\n", (*piece)->top.x);
	printf("TOP.Y: %d\n", (*piece)->top.y);*/
	return (res);
}

void				check_connex(int y, int x, int *lnk, char **line)
{
	(y >= 1 && line[y][x] == '#' && (line[y - 1][x] == '#')) ?
		(*lnk)++ : *lnk;
	(x >= 1 && line[y][x] == '#' && (line[y][x - 1] == '#')) ?
		(*lnk)++ : *lnk;
	(x <= 3 && line[y][x] == '#' && (x < 3 && (line[y][x + 1] == '#'))) ?
		(*lnk)++ : *lnk;
	(y <= 3 && line[y][x] == '#' && (y < 3 && (line[y + 1][x] == '#'))) ?
		(*lnk)++ : *lnk;
}

static int			strsearch(char *str)
{
	while (*str)
	{
		if (*str != '.' && *str != '#')
			return (0);
		str++;
	}
	return (1);
}

static int			check_error(char *line, int x, int max)
{
	if (max > 26)
		return (-1);
	if (x % 5 == 0 && ft_strlen(line) != 0)
		return (-1);
	if (ft_strlen(line) != 4 && (x % 5 != 0))
		return (-1);
	if (!strsearch(line) && (x % 5) != 0)
		return (-1);
	return (0);
}

int					get_all_tetri(int fd, t_tetri **list)
{
	char			*line;
	t_tetri			*cur;
	int				x;
	static int		max = 1;
	int				curr;

	if ((cur = create_tetri()) == NULL)
		return(-1);
	curr = -1;
	x = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (check_error(line, x, max) == -1)
			return (-1);
		if (x++ % 5 == 0 && ++max)
		{
			add_tetri(list, cur);
			return (1);
		}
		cur->tab[++curr] = line;
	}
	if ((x - 1) % 5 == 0)
		return (-1);
	add_tetri(list, cur);
	return (0);
}
