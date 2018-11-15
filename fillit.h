/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 23:58:51 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 23:58:51 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/includes/get_next_line.h"
# define MALLCHECK(x) if (!x) return (-1);

typedef struct		s_tetri
{
	char			**tab;
	char			fill;
	struct s_tetri	*next;
}					t_tetri;

int					fillit(int fd);
int					check_hashtag(char **line);
void				check_connex(int y, int x, int *lnk, char **line);
void				add_tetri(t_tetri **list, t_tetri *new);
t_tetri				*create_tetri();
int					get_all_tetri(int fd, t_tetri **list);
int					check_map(char **line);
t_tetri				*solve(t_tetri *list);
void				sort_tetri(t_tetri **list);

#endif
