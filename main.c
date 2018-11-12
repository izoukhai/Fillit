#include "fillit.h"

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	fillit(fd);
}