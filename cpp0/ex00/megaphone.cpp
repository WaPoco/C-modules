#include <iostream>

int	main(int argc, char **args)
{
	int	i;
	int	j;
	char	c;

	i = 1;
	if (argc - 1 == 0)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << "\n";
	}
	while (i < argc)
	{
		j = 0;
		while (args[i][j])
		{
			c = args[i][j];
			if (args[i][j] >= 97 && args[i][j] <= 122)
				c -= 32;
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << "\n";
	return (0);
}
