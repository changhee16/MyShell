/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:15:38 by ccho              #+#    #+#             */
/*   Updated: 2022/01/16 17:18:26 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	g_count;
int	g_i;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	change_hex(long long int num)
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

void	count_addr(long long int num)
{
	if (num > 16)
	{
		count_addr(num / 16);
		count_addr(num % 16);
	}
	else if (num >= 10)
		g_count++;
	else
		g_count++;
}

void	print_hex(char *str)
{
	while (g_count < 16)
	{
		ft_putchar('0');
		g_count++;
	}
	g_i = 2;
	ft_putchar(':');
	ft_putchar(' ');
	while (g_i < 18)
	{
		if (str[g_i - 2] != '\0')
		{
			ft_putchar("0123456789abcdef"[(unsigned)str[g_i - 2] / 16]);
			ft_putchar("0123456789abcdef"[(unsigned)str[g_i - 2] % 16]);
			ft_putchar("0123456789abcdef"[(unsigned)str[g_i - 1] / 16]);
			ft_putchar("0123456789abcdef"[(unsigned)str[g_i - 1] % 16]);
			ft_putchar(' ');
		}
		else
			write(1, "     ", 5);
		g_i += 2;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long long int	padder;
	char			*str;

	g_count = 0;
	padder = (long long int)addr;
	str = addr;
	count_addr(padder);
	if (size != 0)
	{
		change_hex(padder);
		print_hex(str);
		g_i = 0;
		while (str[g_i] != '\0')
		{
			if ((str[g_i] < 32) || (str[g_i] >= 127))
				ft_putchar('.');
			else
				ft_putchar(str[g_i]);
			g_i++;
		}
		ft_putchar('\n');
	}
	return (addr);
}
