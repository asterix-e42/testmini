#include "tent.h"
#include "libft.h"

int main(int ac, char **av, char **env)
{
	char *s;
	char **str;

	variable(0)->init("env");
	variable(0)->init("ent");
	s = "fi=gfd";
	variable(0)->add("ent", &s, 1);
	s = "fo=";
	variable(0)->add("ent", env, -1);
	variable(0)->init("ent");
	variable(0)->print("ent", NULL);
	//ft_putendl(variable(0)->chop("ent", "fi"));
	str = variable(0)->chop_all("ent");
	variable(0)->unset("ent", NULL);
	//write(1, "1", 1);
	//ft_putstr(*(str + 26));
	variable(0)->init("ent");
	variable(0)->add("ent", str, -1);
	//write(1, "1", 1);
	//ft_putendl(variable(0)->chop("ent", "fi"));
	variable(0)->print("ent", NULL);
	variable(0)->chop_all("ent");
	while(1);
}
