# # ft_printf
Here a part of printf() is implemented from scratch.
## What it does
- regular characters are just printed.
- '-' and '0' flags affect output.
- field width and precision are taken into account.
- %c print a single character.
- %s print a string of characters.
- %p The void * pointer argument is printed in hexadecimal.
- %d print a decimal (base 10) number.
- %i print an integer in base 10.
- %u print an unsigned decimal (base 10) number.
- %x print a number in hexadecimal (base 16), with lowercase.
- %X print a number in hexadecimal (base 16), with uppercase.
- %% print a percent sign.

It makes no buffering like original printf().

### What Makefile does:
Makefile creates a library: libftprintf.a
