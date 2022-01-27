/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:07:21 by ccho              #+#    #+#             */
/*   Updated: 2022/01/26 21:49:49 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_find(char c, char *to_find)
{
	int	j;

	j = 0;
	if (c == '\0')
		return (1);
	while (to_find[j])
	{
		if (c == to_find[j])
			return (1);
		j++;
	}
	return (0);
}

int	count_word(char *str, char *chrset)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (ft_find(str[i], chrset))
		str++;
	while (str[i])
	{
		if (!ft_find(str[i], chrset) && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (ft_find(str[i], chrset))
			flag = 0;
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	while (i < n)
	{
		dest[j] = '\0';
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *chrset)
{
	char	**split_arr;
	int		j;
	int		strlen;

	j = -1;
	split_arr = (char **)malloc(sizeof(char *) * (count_word(str, chrset) + 1));
	if (!(split_arr) || count_word(str, chrset) == 0)
		return (NULL);
	while (*str)
	{
		if (!(ft_find(*str, chrset)))
		{
			strlen = -1;
			while (++strlen > -1 && !(ft_find(*str, chrset)))
				str++;
			split_arr[++j] = (char *)malloc(sizeof(char) * (strlen + 1));
			if (!(split_arr[j]))
				return (NULL);
			split_arr[j] = ft_strncpy(split_arr[j], str - strlen, strlen);
		}
		else
			str++;
	}
	split_arr[j + 1] = 0;
	return (split_arr);
}
