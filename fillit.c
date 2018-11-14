/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 23:58:40 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 23:58:41 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int        check_map(char **line)
{
    int y;
    int x;
    int link_counter;

    y = 0;
    x = 0;
    link_counter = 0;

    while (line[y])
    {
        while (line[y][x] && (line[y][x] == '.' || line[y][x] == '#'))
        {
            if (line[y][x] == '#' && (line[y - 1][x] == '#' && x y > 0) ||
             (line [y][x - 1] == '#' && x > 0) ||
             (line[y][x + 1] == '#' && x < 4) || (line[y + 1][x] == '#' && y < 4))
                link_counter++;
            x++;
        }
        y++;
    }
    if (link_counter != 6 && link_counter != 8)
        return (-1);
    return (link_counter);
}

void				fillit(int fd)
{
	t_tetri			*list;
	int i = -1;
	int j = 0;
	int	ret;
	if ((list = create_tetri()) == NULL)
		return;
	while ((ret = get_all_tetri(fd, &list)) == 1)
		;
	if (ret == -1)
		return;
	while (list->next)
	{
		i = -1;
		while (list->tab[++i] && i < 4)
			printf("%s\n", list->tab[i]);
		j++;
		list = list->next;
	}
}
