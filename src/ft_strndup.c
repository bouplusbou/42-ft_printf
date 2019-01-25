#include <stdlib.h>

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}