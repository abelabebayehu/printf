#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a single character to stdout.
 * @c: The character to write.
 *
 * Return: On success, the number of characters written (1).
 * On error, -1 is returned.
 */
int _putchar(char c) {
    return write(1, &c, 1);
}

/**
 * _puts - Writes a string to stdout.
 * @str: The string to write.
 *
 * Return: The number of characters written.
 */
int _puts(char *str) {
    int len = 0;

    if (str == NULL) {
        str = "(null)";
    }

    while (*str) {
        _putchar(*str++);
        len++;
    }
    return len;
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...) {
    va_list args;
    int i = 0, count = 0;
    char *str;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            switch (format[i]) {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    str = va_arg(args, char *);
                    count += _puts(str);
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    count += _putchar('%');
                    count += _putchar(format[i]);
                    break;
            }
        } else {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}
