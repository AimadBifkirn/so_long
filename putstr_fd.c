#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}