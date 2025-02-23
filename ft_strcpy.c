#include "so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	dest = malloc (sizeof(char) * ft_strlen(src) + 1);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}