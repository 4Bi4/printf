/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_things_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:56:25 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/22 17:51:57 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, s, 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	unsigned int	num;
	int				count;

	num = nb;
	count = 0;
	if (num < 0)
	{
		num = num * -1;
		count += ft_putchar('-');
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	num;
	int				count

	num = nb;
	count = 0;
	if (num > 9)
	{
		count += ft_putnbr_unsigned(num / 10);
		count += ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar(num + '0');
	return (count)
}
