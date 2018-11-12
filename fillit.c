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

void				fillit(int fd)
{
	t_tetri			*list;
	int				i = -1;
	if ((list = create_tetri()) == NULL)
		return;
	i = count_tetris(fd);
	printf("%d\n", i);
	i += 1;
	while (--i)
		get_all_tetri(fd, &list);
	i = -1;
	while (++i < 4)
		printf("%s\n", list->tab[i]);
}
