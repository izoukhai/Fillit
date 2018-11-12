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

static int		ft_strichr(char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int					count_tetris(int fd)
{
	char *line;
	int counter;
	int	i;

	i = 0;
	counter = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == '\0')
			counter++;
	}
	return (counter);
}

void				get_all_tetri(int fd, t_tetri **list)
{
	t_tetri			*new;
	char			*line;
	int				i;

	i = -1;
	if ((new = create_tetri()) == NULL)
		return;
	while (get_next_line(fd, &line) == 1 && ++i < 4)
	{
		if (ft_strichr(line, '\n') != -1)
		{
			i--;
			continue;
		}
		new->tab[i] = ft_strcpy(new->tab[i], line);
	}
	add_tetri(list, new);
}
