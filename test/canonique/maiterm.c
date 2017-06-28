
#include <stdio.h>
#include "g.h"

int main()
{
	char *s;

	write(1, "$> ", 3);
	s = saisie();
	printf("\n%s\n", s);
}
