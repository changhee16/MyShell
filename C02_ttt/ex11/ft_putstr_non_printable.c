/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:02:10 by ccho              #+#    #+#             */
/*   Updated: 2022/01/13 20:13:20 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	change_hex(unsigned int num)
{
	if (num > 16)
	{
		change_hex(num / 16);
		change_hex(num % 16);
	}
	else if (num >= 10)
		ft_putchar(num - 10 + 'a');
	else
		ft_putchar(num + 48);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	*pstr;

	pstr = (unsigned char *)str;
	i = 0;
	while (pstr[i] != '\0')
	{
		if ((pstr[i] < 32) || (pstr[i] >= 127))
		{
			ft_putchar('\\');
			if (pstr[i] < 16)
				ft_putchar('0');
			change_hex(pstr[i]);
		}
		else
			ft_putchar(pstr[i]);
		i++;
	}
}
