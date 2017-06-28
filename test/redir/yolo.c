
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *c;

	c = "0123456789qwertyuio";
	fd = open("/dev/fd/1");
	write(fd, "123\n", 4);
	write(1, (char*)(fd + c), 1);
}
