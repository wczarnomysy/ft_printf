# Libft - My custom C library

*Este proyecto ha sido creado como parte del currículo de 42 por wczarnom.*

## Description

Libft is a project that recreates the internal logic of standard C library functions without relying on external dependencies, while adding extra utility functions to remain useful in future projects. The objective is to build a personal toolkit from scratch and deepen understanding of low-level memory management, pointer arithmetic, and data manipulation.

## Instructions

### Compilation

```sh
git clone <repo-url>
cd libft
make
```

`make` produces `libft.a` in the same directory.

### Linking against your project

```sh
cc -Wall -Wextra -Werror your_file.c libft.a -o your_program
```

### Makefile targets

| Target | Effect |
|---|---|
| `make` / `make all` | Compile all sources and archive into `libft.a` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libft.a` |
| `make re` | Full clean rebuild |

### Running the test suite

```sh
cd tests
make run
```

Memory-leak check on Linux:

```sh
make valgrind
```

Memory-leak check on macOS:

```sh
make leaks
```

## Library Overview

### Character Classification (Returns 1 for true, 0 for false)

| Function | Prototype | Description |
|---|---|---|
| `ft_isalpha` | `int ft_isalpha(int c)` | Checks if `c` is a letter |
| `ft_isdigit` | `int ft_isdigit(int c)` | Checks if `c` is a decimal digit |
| `ft_isalnum` | `int ft_isalnum(int c)` | Checks if `c` is alphanumeric |
| `ft_isascii` | `int ft_isascii(int c)` | Checks if `c` is a 7-bit ASCII character (0–127) |
| `ft_isprint` | `int ft_isprint(int c)` | Checks if `c` is printable (ASCII: 32–126) |

### Character Conversion

| Function | Prototype | Description |
|---|---|---|
| `ft_toupper` | `int ft_toupper(int c)` | Converts lowercase letter to uppercase |
| `ft_tolower` | `int ft_tolower(int c)` | Converts uppercase letter to lowercase |

### Raw Memory Manipulation

| Function | Prototype | Description |
|---|---|---|
| `ft_memset` | `void *ft_memset(void *s, int c, size_t n)` | Fills `n` bytes at `s` with byte `c`; returns `s` |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Zeroes `n` bytes at `s` |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest` (areas must not overlap); returns `dest` |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n)` | Copies `n` bytes from `src` to `dest`, handles overlap; returns `dest` |
| `ft_memchr` | `void *ft_memchr(const void *s, int c, size_t n)` | Scans `n` bytes of `s` for the first occurrence of byte `c`, returning a pointer to it or NULL |
| `ft_memcmp` | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Compares `n` bytes of `s1` and `s2` as unsigned chars; returns the difference of the first differing bytes |

### Basic Memory Management 

| Function | Prototype | Description |
|---|---|---|
| `ft_calloc` | `void *ft_calloc(size_t nmemb, size_t size)` | Allocates `nmemb × size` zero-initialised bytes; NULL on overflow/failure |

### String Parsing

| Function | Prototype | Description |
|---|---|---|
| `ft_strlen` | `size_t ft_strlen(const char *s)` |  Computes the length of the string `s`; returns the number of characters without the terminating null byte (`\0`) |
| `ft_strchr` | `char *ft_strchr(const char *s, int c)` | Searches for the first occurrence of character `c` (converted to char) in `s`; returns a pointer to the matched character, or NULL if not found (searching for `\0` returns a pointer to the terminator) |
| `ft_strrchr` | `char *ft_strrchr(const char *s, int c)` | Searches for the last occurrence of character `c` (converted to char) in `s`; returns a pointer to the matched character, or NULL if not found (searching for `\0` returns a pointer to the terminator) |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares up to `n` bytes of `s1` and `s2` as unsigned chars; returns 0 if identical, or the difference between the first differing characters |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | Locates the first occurrence of string `little` inside the first `len` characters of string `big`; returns `big` if `little` is empty, a pointer to the first character of the sub-string inside `big` if found, or NULL if not found |
| `ft_atoi` | `int ft_atoi(const char *nptr)` | Converts the initial valid digits of `nptr` to an integer; returns the converted value |

### String Manipulation

| Function | Prototype | Description |
|---|---|---|
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` | Copies up to `dstsize - 1` characters from `src` to `dst`, guaranteeing NUL-termination if `dstsize > 0`; returns the total length of `src` |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` | Appends `src` to `dst` (up to `dstsize - 1`), guaranteeing NUL-termination; returns the initial length of `dst` (capped at `dstsize`) plus the length of `src` |
| `ft_strdup` | `char *ft_strdup(const char *s)` | Allocates heap memory and duplicates the string `s`; returns a pointer to the new string, or NULL if the allocation fails |

### Advanced String Formatting & Heap Operations

| Function | Prototype | Description |
|---|---|---|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Reserva memoria con `malloc` y devuelve una subcadena de `s` que empieza en el índice `start` con una longitud máxima de `len` (si `start` supera la longitud de `s`, devuelve una cadena vacía); devuelve `NULL` si la asignación falla |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Reserva memoria con `malloc` y devuelve una nueva cadena resultante de la concatenación de `s1` y `s2`; devuelve NULL si la asignación de memoria falla o si alguna de las cadenas es NULL |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Allocates and returns a copy of `s1` with all leading and trailing characters found in `set` removed; returns a fresh empty string if all characters are trimmed, or NULL if the allocation fails |
| `ft_split` | `char **ft_split(char const *s, char c)` | Allocates and returns a NULL-terminated array of strings obtained by splitting `s` using the character `c` as a delimiter; returns the array of strings, or NULL if any memory allocation fails |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Allocates and returns a new string built by applying function `f` to each character of string `s`; returns the newly created string, or NULL if the allocation fails |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char *))` | Applies function `f` to each character of string `s` in place by passing its index and memory address |
| `ft_itoa` | `char *ft_itoa(int n)` | Allocates and returns a null-terminated string representing the integer `n` (safely handling negative numbers and limits); returns the new string, or NULL if the allocation fails |

### File-Descriptor Output

| Function | Prototype | Description |
|---|---|---|
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Writes the character `c` to the specified file descriptor `fd`|
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Writes the string `s` to the specified file descriptor `fd` (safely does nothing if `s` is NULL) |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Writes the string `s` to the specified file descriptor `fd`, immediately followed by a newline character (`\n`) |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Writes the decimal representation of the integer `n` to the specified file descriptor `fd` (safely handles `INT_MIN` and negative values) |

### Linked List

The library exposes a singly-linked list type:

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}   t_list;
```

`content` is a generic `void *` so the list can hold any type. The caller is responsible for providing a suitable `del` callback wherever ownership of content must be transferred.

| Function | Prototype | Description |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Allocates heap memory for a new node, initializing its content with `content` and setting `next` to NULL; returns the new node, or NULL if allocation fails |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Inserts the node `new` at the beginning (head) of the list pointed to by `lst` |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Appends the node `new` at the end (tail) of the list pointed to by `lst` |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Counts the elements in a list; returns the total number of nodes in `lst` (returns 0 if `lst` is NULL) |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Iterates to the final element of the list; returns a pointer to the last node, or NULL if `lst` is NULL |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees the memory of the node `lst` by applying the function `del` to its content and running `free` on the node itself; does not free the `next` pointer |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees every node in the list starting at `*lst` using `del` and `free`; sets the pointer `*lst` to NULL at the end |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Iterates over the entire list `lst` and applies the function `f` to the content of each node |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Creates a new list by applying `f` to each node's content; returns the new list, or NULL if any allocation fails (clearing partial memory with `del`) or if `lst` is NULL |

## Resources

### References

**Linux Man Pages** — Official documentation for standard libc functions (`man 3 strlen`, etc.): https://man7.org/linux/man-pages/
