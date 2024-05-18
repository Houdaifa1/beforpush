#include "push_swap.h"


long	ft_atoi(char *str, char **arr)
{
	int	i;
	int	symbol;
	long	outcome;

	i = 0;
	symbol = 1;
	outcome = 0;
	if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			ft_free_arr(arr, 1);
		if (str[i] == '-')
			symbol = symbol * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		outcome = outcome * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		ft_free_arr(arr, 1);
	return (outcome * symbol);
}

