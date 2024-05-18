#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	y;

	i = 0;
	j = 0;
	y = 0;
	if (s1 == NULL)
	{
		s1 = ft_calloc(1, 1);
		y = 1;
	}
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!join)
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = ' ';
	join[i + 1] = '\0';
	if (y == 1)
		free((void *)s1);
	return (join);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_free_arr(char **arr, int e)
{
	int n;
	n = 0;
	while (arr[n])
	{
		free(arr[n]);
		n++;
	}
	free (arr);
	if (e == 1)
	{
        write(2, "Error\n", 6);
		exit(1);
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count > 0 && size > 0 && (count * size) / count != size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
