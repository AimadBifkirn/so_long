/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abifkirn <abifkirn@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:31:24 by abifkirn          #+#    #+#             */
/*   Updated: 2025/02/27 14:08:31 by abifkirn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	lenn(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*alloc(char *t, int n, int len)
{
	if (n >= 0)
		t = (char *)malloc(sizeof(char) * (len + 1));
	else
		t = (char *)malloc(sizeof(char) * (len + 2));
	if (t == NULL)
		return (NULL);
	if (n == 0)
	{
		t[0] = '0';
		t[len] = '\0';
	}
	else if (n < 0)
	{
		t[0] = '-';
		t[len + 1] = '\0';
		n = -n;
	}
	else if (n > 0)
		t[len--] = '\0';
	while (n > 0)
	{
		t[len--] = n % 10 + '0';
		n = n / 10;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*t;

	len = lenn(n);
	t = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (alloc(t, n, len));
}
