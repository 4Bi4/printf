
#include "ft_printf.c"

// %c single character.
// %s string (multiple characters).
// %p pointer (void *) printed in hexadecimal.
// %i number (base 10).
// %d decimal number (base 10).
// %u unsigned decimal number (base 10).
// %x hexadecimal number (base 16) in lowercase.
// %X hexadecimal number (base 16) in uppercase.
// %% print the "%" symbol.

int	ft_type_detect(va_list parameters, char full_str)
{
	int		count;
	char	*base;
	char	*BASE;

	count = 0;
	base = "0123456789abcdef";
	BASE = "0123456789ABCDEF";
	if (full_str == 'c')
		count = ft_putchar(va_arg(parameters, int));
	else if (full_str == 's')
		count = ft_putstr(va_arg(parameters, char *));
	else if (full_str == 'p')
		count = ft_putptr(va_arg(parameters, unsigned long int));
	else if (full_str == 'i')
		count = ft_putnbr(va_arg(parameters, int));
	else if (full_str == 'd')
		count = ft_putnbr(va_arg(parameters, int));
	else if (full_str == 'u')
		count = ft_putnbr_unsigned(va_arg(parameters, unsigned int));
	else if (full_str == 'x')
		count = ft_putnbr_hexadecimal(va_arg(parameters, base));
	else if (full_str == 'X')
		count = ft_putnbr_hexadecimal(va_arg(parameters, BASE));
	else if (full_str == '%')
		count = ft_putchar(full_str);
	return (count);
}

int	ft_printf(char const *full_str, ...)
{
	va_list	parameters;
	int		count;

	count = 0;
	va_start(parameters, full_str)
	while (*full_str)
	{
		if (*full_str == '%')
		{
			full_str++;
			count = ft_type_detect(parameters, *full_str++);
		}
		else
			count = ft_putchar(*full_str++);
	}
	va_end(parameters);
	return (count);
}
