#include <stdio.h>
#include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int    printchar(char c)
{
    if (write(1, &c, 1) < 0)
        return (-1);
    return (1);
}

int    printstr(char *s)
{
    int    i;

    i = 0;
    if (s)
    {
        while (*s != '\0')
        {
            if (printchar((int)*s) < 0)
                return (-1);
            i++;
            s++;
        }
    }
    else
    {
        if (write (1, "(null)", 6) == -1)
            return (-1);
        i = 6;
    }
    return (i);
}

int    print_digit(long n, int base, char specifier)
{
    int        count;
    char    *symbols;

    if (specifier == 'X')
        symbols = "0123456789ABCDEF";
    else
        symbols = "0123456789abcdef";
    if (n < 0)
    {
        if (write (1, "-", 1) < 0)
            return (-1);
        return (print_digit(-n, base, specifier) + 1);
    }
    else if (n < base)
    {
        return (printchar((int)symbols[n]));
    }
    else
    {
        count = print_digit(n / base, base, specifier);
        if (count < 0)
            return (-1);
        return (count + print_digit(n % base, base, specifier));
    }
}

int    print_address(unsigned long n)
{
    int        count;
    char    *symbols;

    symbols = "0123456789abcdef";
    if (n < 16)
    {
        if (printchar(symbols[n]) < 0)
            return (-1);
        return (1);
    }
    else
    {
        count = print_address(n / 16);
        return (count + print_address(n % 16));
    }
    return (-1);
}

int    ft_form(char specifier, va_list ap)
{
    void    *ptr;

    if (specifier == 'c')
        return (printchar(va_arg(ap, int)));
    else if (specifier == 's')
        return (printstr(va_arg(ap, char *)));
    else if (specifier == 'd' || specifier == 'i')
        return (print_digit((long)(va_arg(ap, int)), 10, specifier));
    else if (specifier == 'u')
        return (print_digit((long)(va_arg(ap, unsigned int)), 10, 'u'));
    else if (specifier == 'x' || specifier == 'X')
        return (print_digit((long)(va_arg(ap, unsigned int)), 16, specifier));
    else if (specifier == 'p')
    {
        ptr = va_arg(ap, void *);
        if (ap != NULL)
        {
            if (write (1, "0x", 2) == -1)
                return (-1);
            return (2 + (print_address((unsigned long)ptr)));
        }
        //else
         //   return (printstr("(null)"));
    }
    return (1);
}

int    ft_printf(const char *format, ...)
{
    int        totals;
    va_list    ap;

    totals = 0;
    va_start(ap, format);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            if (*(++format) == '%')
                totals += printchar('%');
            else
                totals += ft_form(*(format), ap);
            if (totals < 0)
                return (-1);
        }
        else
        {
            if (write(1, format, 1) == -1)
            {
                va_end(ap);
                return (-1);
            }
            totals ++;
        }
        format++;
    }
    return (totals);
    if (totals < 0)
        return (-1);
    va_end(ap);
    return (totals);
}

/*
int main()
{
  
    ft_printf("\n %p ", -1);
    ft_printf("\n %p ", 1);
    ft_printf("\n %p ", 15);
    ft_printf("\n %p ", 16);
    ft_printf("\n %p ", 17);
    ft_printf("\n %p %p ", LONG_MIN, LONG_MAX);
    ft_printf("\n %p %p ", INT_MIN, INT_MAX);
    ft_printf("\n %p %p ", ULONG_MAX, -ULONG_MAX);
    ft_printf("\n %p %p ", 0, 0);
    
    printf("\n %p ", -1);
    printf("\n %p ", 1);
    printf("\n %p ", 15);
    printf("\n %p ", 16);
    printf("\n %p ", 17);
    printf("\n %p %p ", LONG_MIN, LONG_MAX);
    printf("\n %p %p ", INT_MIN, INT_MAX);
    printf("\n %p %p ", ULONG_MAX, -ULONG_MAX);
    printf("\n %p %p ", 0, 0);
    
    int count;
    int variable = 42;

    count = ft_printf("Hello %s\n", "YOU!");
    ft_printf("This prints the amount of letters in Hello You! = : %d\n", count);

    ft_printf("Hello, %s!", "world");
    ft_printf("The value is %d and the address is %p\n", 42, (void*)&variable);
    ft_printf("Hexadecimal: %X, Decimal: %u\n", 255, 12345);
    
    count = printf("Hello %s\n", "YOU!");
    printf("This prints the amount of letters in Hello You! = : %d\n", count);

    printf("Hello, %s!", "world");
    printf("The value is %d and the address is %p\n", 42, (void*)&variable);
    printf("Hexadecimal: %X, Decimal: %u", 255, 12345);
    
    return (0);
}
*/
