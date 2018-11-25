/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 05:33:45 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 05:34:13 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [target_file]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(map = fillit(fd)))
	{
		ft_putendl("error");
		return (0);
	}
	print_map(map);
	return (0);
}
