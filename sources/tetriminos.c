/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetriminos.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/10 17:23:45 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/10 17:23:46 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../headers/fillit.h"

void			add_tetri(t_tetri **list, t_tetri *new)
{
	if (*list && new)
	{
		new->next = *list;
		*list = new;
	}
}

t_tetri			*create_tetri(void)
{
	int			i;
	t_tetri		*res;
	t_point		*pos;

	if ((res = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	if ((res->tab = (char**)malloc(sizeof(char*) * 4)) == NULL)
		return (NULL);
	i = (-1);
	while (++i < 4)
		if ((res->tab[i] = ft_strnew(4)) == NULL)
			return (NULL);
	i = -1;
	while (++i < 4)
	{
		pos = (t_point*)malloc(sizeof(t_point));
		pos->x = -1;
		pos->y = -1;
		res->pos[i] = *pos;
		free(pos);
	}
	res->next = NULL;
	return (res);
}

void			sort_tetri(t_tetri **list)
{
	t_tetri		*tmp;
	t_tetri		*tmp2;
	t_tetri		*tmp3;

	tmp = *list;
	tmp2 = tmp->next;
	tmp->next = NULL;
	while (tmp2)
	{
		tmp3 = tmp2->next;
		tmp2->next = tmp;
		tmp = tmp2;
		tmp2 = tmp3;
	}
	*list = tmp;
}

void			del_tetris(t_tetri **list)
{
	t_tetri		*tmp;
	int			i;

	if (!(*list))
		return ;
	while (*list)
	{
		i = -1;
		tmp = (*list)->next;
		while (++i < 4)
			free((*list)->tab[i]);
		free((*list)->tab);
		free(*list);
		*list = tmp;
	}
}

int				count_tetris(t_tetri *list)
{
	t_tetri		*cur;
	int			res;

	cur = list;
	res = 0;
	while (cur)
	{
		res++;
		cur = cur->next;
	}
	return (res);
}
