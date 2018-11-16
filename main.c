#include "fillit.h"

int main(int argc, char **argv)
{
	argc = 0;
	int fd = open(argv[1], O_RDONLY);
	printf("return: %d", fillit(fd));
}