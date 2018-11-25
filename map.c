#include "fillit.h"

t_map		*new_map(size_t size)
{
	t_map	*res;
	size_t	i;
	size_t	j;

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

void		del_map(t_map **map)
{
	size_t	i;

	i = -1;
	while (++i < (*map)->size)
		free((*map)->tab[i]);
	free((*map)->tab);
	free(*map);
}

void		print_map(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->size)
		ft_putendl(map->tab[i]);
}

int			check_pmap(t_tetri *piece, t_map *map, t_point pos)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (pos.y + piece->pos[i].y - piece->pos[0].y >= (int)map->size ||
				pos.x + piece->pos[i].x - piece->pos[0].x >= (int)map->size)
			return (0);
		if (map->tab[pos.y + piece->pos[i].y - piece->pos[0].y]
			[pos.x + piece->pos[i].x - piece->pos[0].x] != '.')
			return (0);
	}
	pmap(piece, map, pos, piece->fill);
	return (1);
}

void		pmap(t_tetri *piece, t_map *map, t_point pos, char c)
{
	int		i;

	i = -1;
	while (++i < 4)
		map->tab[pos.y + piece->pos[i].y - piece->pos[0].y]
		[pos.x + piece->pos[i].x - piece->pos[0].x] = c;
}
