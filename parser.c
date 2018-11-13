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

static int			check_error(char *line, int x)
{
	if (x % 5 == 0 && ft_strlen(line) != 0)
		return (-1);
	if (ft_strlen(line) != 4 && (x % 5 >= 1 && x % 5 <= 4))
		return (-1);
	return (0);
}

int					get_all_tetri(int fd, t_tetri **list)
{
	char			*line;
	t_tetri			*cur;
	int				x;
	int				curr;

	x = 1;
	cur = create_tetri();
	curr = -1;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (check_error(line, x) == -1)
			return (-1);
		if (x % 5 == 0)
		{
			add_tetri(list, cur);
			return (1);
		}
		cur->tab[++curr] = line;
		x++;
	}
	add_tetri(list, cur);
	return (0);
}
