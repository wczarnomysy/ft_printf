# ft_printf

*This project has been made as part of the 42 curriculum by wczarnom.*

## Description

`ft_printf` is a recreation of the C standard library's `printf()`. The goal is to reimplement its core formatting behaviour from scratch, using variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`), without relying on any `printf`-family function from the libc.

The mandatory part implements the following conversions:

| Conversion | Description |
|---|---|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer, printed in hexadecimal (`0x...`) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal, lowercase |
| `%X` | Unsigned hexadecimal, uppercase |
| `%%` | Literal `%` |

`ft_printf` does not manage output buffering itself (each character is written directly via `write`), and it returns the total number of characters printed, matching the original `printf()`'s return value.

## Instructions

### Compilation

```sh
git clone <repo-url>
cd ft_printf
make
```

`make` first builds `libft.a` from the `libft/` directory, then compiles the project sources and archives everything into `libftprintf.a` in the repository root.

### Makefile targets

| Target | Effect |
|---|---|
| `make` / `make all` | Compile all sources and archive into `libftprintf.a` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libftprintf.a` |
| `make re` | Full clean rebuild |

### Using the library

```sh
cc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old (%p)\n", "world", 42, (void *)&main);
    return (0);
}
```

## Resources

### References

- [Linux man pages — printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html)
