#include "ft_printf.h"

int	ft_putnbr_hexadecimal(unsigned long int nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_putnbr_hexadecimal(nb / 16, base);
		count += ft_putchar(base[nb % 16]);
	}
	else
		count += ft_putchar(base[nb]);
	return (count);
}

int	ft_putptr(unsigned long int nb)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	ft_putstr("0x");
	if (nb >= 16)
	{
		count += ft_putnbr_hexadecimal((nb / 16), base);
		count += ft_putchar(base[nb % 16]);
	}
	else
		count += ft_putchar(base[nb]);
	return (count)
}
