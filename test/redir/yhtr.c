
#include <unistd.h>

int main(void)
{
	int fd[2];
	char s[4];

	pipe(fd);
	write(*(fd + 1), "ngb", 3);
	write(1, "fd", 2);
	read(0, &s, 1);
	read(*(fd), &s, 4);
	write(1, s, 4);
}
