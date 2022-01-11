/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccho <ccho@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:13:47 by ccho              #+#    #+#             */
/*   Updated: 2022/01/11 18:33:25 by ccho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *num, int n, int flag)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(num[i] + '0');
		i++;
	}
	if (flag == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int	max_check(int *num, int n, int max)
{
	n -= 1;
	while (num[n] == max)
	{
		n--;
		max--;
	}
	return (n);
}

void	init(int *num, int count, int n)
{
	num[count]++;
	while (count < n)
	{
		num[count + 1] = num[count] + 1;
		count++;
	}
}

void	ft_print_combn(int n)
{
	int	num[10];
	int	i;
	int	max;
	int	count;

	max = 9;
	i = 0;
	while (i < n)
	{
		num[i] = i;
		i++;
	}
	while ((num[0] != 10 - n) || (num[n - 1] != 9))
	{
		print(num, n, 1);
		if (num[n - 1] == 9)
		{
			count = max_check(num, n, max);
			init(num, count, n);
		}
		else
			num[n - 1]++;
	}
	print(num, n, 0);
}
