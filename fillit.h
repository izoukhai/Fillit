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

#include "libft/includes/get_next_line.h"

typedef struct		s_tetri
{
	char			**tab;
	struct s_tetri	*next;
}					t_tetri;

t_tetri				*create_tetri();
void				get_all_tetri(int fd, t_tetri **list);
void				add_tetri(t_tetri **list, t_tetri *new);
void				fillit();
int					count_tetris(int fd);
int					check_tetri();
