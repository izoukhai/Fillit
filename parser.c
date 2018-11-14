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

static int			strsearch(char *str, char c)
{
	while (*str++)
		if (*str == c)
			return (1);
	return (0);
}

static int			check_error(char *line, int x, int max)
{
	if (max > 26)
		return (-1);
	if (x % 5 == 0 && ft_strlen(line) != 0)
		return (-1);
	if (ft_strlen(line) != 4 && (x % 5 != 0))
		return (-1);
	if (!strsearch(line, '.') && !strsearch(line, '#') && (x % 5) != 0)
		return (-1);
	return (0);
}

int					get_all_tetri(int fd, t_tetri **list)
{
	char			*line;
	t_tetri			*cur;
	int				x = 1;
	static int		max = 1;
	int				curr;
	int				res;

	cur = create_tetri();
	curr = -1;
	x = 1;
	while ((res = get_next_line(fd, &line)) == 1)
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
	if (res == 0 && x-1 % 5 == 0)
		return (-1);
	add_tetri(list, cur);
	return (0);
}
