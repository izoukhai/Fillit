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

int					fillit(int fd);
void				add_tetri(t_tetri **list, t_tetri *new);
t_tetri				*create_tetri();
int					get_all_tetri(int fd, t_tetri **list);
int					check_map(char **line);