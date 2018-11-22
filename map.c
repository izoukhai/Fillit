#include "fillit.h"

t_map		*new_map(size_t size)
{
	t_map	*res;
	int		i;
	int		j;

	res = (t_map*)malloc(sizeof(t_map));
	res->tab = (char**)malloc(sizeof(char*) * size);
	res->size = size;
	i = -1;
	while (++i < size)
	{
		res->tab[i] = ft_strnew(size);
		j = -1;
		while (++j < size)
			res->tab[i][j] = '.';
	}
	return (res);
}

void		del_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->size)
		free(map->tab[i]);
	free(map->tab);
	free(map);
}

void		print_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->size)
		ft_putendl(map->tab[i]);
}