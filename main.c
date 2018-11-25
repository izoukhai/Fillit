#include "fillit.h"

int main(int argc, char **argv)
{
	argc = 0;
	t_map *map;
	int fd = open(argv[1], O_RDONLY);
	map = fillit(fd);
}