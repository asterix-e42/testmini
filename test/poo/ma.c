
#include <stdio.h>
#include "poo.h"

int main(int ac, char **av)
{
	int te;

	printf("%d\n", get_my_int());
	set_my_int(9);
	printf("%d\n", get_my_int());
}
