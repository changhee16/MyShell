/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:01:52 by ccho              #+#    #+#             */
/*   Updated: 2022/01/13 20:14:48 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_word(char *str, int i)
{
	if ((str[i] >= '0') && (str[i] <= '9'))
		return (0);
	else if ((str[i] >= 'a') && (str[i] <= 'z'))
		return (0);
	else if ((str[i] >= 'A') && (str[i] <= 'Z'))
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0) && (str[i] >= 'a') && (str[i] <= 'z'))
			str[i] -= 32;
		if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			if (is_word(str, i - 1) == 1)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
