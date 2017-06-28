
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static volatile int keepRunning = 1;
void sig_fpe(int sig)
{
	keepRunning = 0;
	write(1, "sa va sareter", 13);
}

int main(void)
{
	char chr;
	if (signal(SIGINT, sig_fpe) == SIG_ERR)
	{
		puts("Le gestionnaire de signal pour SIG_FPE n'a pu etre defini.");
	}
	else
	{
		puts("Le gestionnaire de signal pour SIG_FPE a pu etre defini.");
	}
	while(keepRunning)
	{
		read(0, &chr, 1);
		printf("%d\n", chr);
	}
	sleep(3);
	return 0;
}
