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

    while (line[y] && y < 4)
    {
    	x = 0;
        while (line[y][x] && (line[y][x] == '.' || line[y][x] == '#'))
        {
            (y > 0 && line[y][x] == '#' && (line[y - 1][x] == '#')) ? link_counter++ : 0;
            (x > 0 && line[y][x] == '#' && (line [y][x - 1] == '#')) ? link_counter++ : 0;
            (x < 3 && line[y][x] == '#' && (line[y][x + 1] == '#')) ? link_counter++ : 0;
            (y < 3 && line[y][x] == '#' && (line[y + 1][x] == '#')) ? link_counter++ : 0;
            x++;
        }
        y++;
    }
    if (link_counter != 6 && link_counter != 8)
        return (-1);
    return (link_counter);
}

t_tetri             *resolve(t_tetri *list)
{
    t_tetri         *res;
    int             x;
    int             y;
    char            fill;

    fill = 'Z';
    x = y = 0;
    res = create_tetri();
}

static t_tetri      *rev_list(t_tetri *list)
{
    
}

int 				fillit(int fd)
{
	t_tetri			*list;
    int             ret;
    char            fill;

    fill = 'A';
	if ((list = create_tetri()) == NULL)
		return (-1);
	while ((ret = get_all_tetri(fd, &list)) == 1)
	   if (ret == -1)
		  return (-1);
    rev
	while (list->next)
	{
        if (check_map(list->tab) == (-1))
            return (-1);
        list->fill = fill++;
        printf("%c\n", list->fill);
		list = list->next;
	}
    return (1);
}
