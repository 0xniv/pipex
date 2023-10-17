#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (5 == argc)
	{
		ft_printf("%s\n", "In");
	}
	else
		ft_printf("%s\n", "Not In");
	return (0);
}
