/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:56:25 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/22 17:51:57 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

static int  ft_nlen(int n) 
{
    int len;

    len = 0; 
    if (n <= 0) 
        len = 1; 
    while (n != 0) 
    {  
        len++;
        n = n / 10;
    }  
    return (len);
}

char    *ft_itoa(int n) 
{
    char    *str;
    int     num;
    int     len;

    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    num = n; 
    len = ft_nlen(n);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    if (n < 0) 
        num = -num;
    while (len > 0) 
    {  
        len--;
        str[len] = (num % 10) + '0';
        num = num / 10;
    }  
    if (n < 0) 
        str[0] = '-';
    return (str);
}

