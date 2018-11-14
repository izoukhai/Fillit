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
<<<<<<< HEAD
    	x = 0;
        while (line[y][x] && (line[y][x] == '.' || line[y][x] == '#'))
        {
            if (line[y][x] == '#' && (line[y - 1][x] == '#' && y > 0))
            	link_counter++;
            if (line[y][x] == '#' && (line [y][x - 1] == '#' && x > 0))
            	link_counter++;
            if (line[y][x] == '#' && (line[y][x + 1] == '#' && x < 4))
            	link_counter++;
            if (line[y][x] == '#' && (line[y + 1][x] == '#' && y < 4))
                link_counter++;
            x++;
        }
        y++;
=======
        
>>>>>>> 1ff7dbf4cde9add91a563d06ee369423b4077026
    }
    printf("%d\n", link_counter);
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
        int res = check_map(list->tab);
		printf("%d: %s\n", res, list->tab[i]);
		list = list->next;
	}
}
