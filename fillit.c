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
