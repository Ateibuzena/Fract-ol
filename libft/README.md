# 🛠️ LIBFT - Enhanced C Standard Library

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-42-green.svg)](https://github.com/42School/norminette)

## 📖 Description

**libft** is a comprehensive C library that reimplements essential standard library functions while adding powerful custom utilities. This project goes beyond the basic 42 curriculum requirements, providing a robust foundation for C programming with enhanced memory management, string processing, and I/O operations.

## ✨ Features

### 🔤 **ASCII & Character Operations**
- Character classification (`ft_isalpha`, `ft_isdigit`, `ft_isprint`, etc.)
- Case conversion utilities (`ft_toupper`, `ft_tolower`)
- Extended whitespace detection (`ft_isspace`)

### 🧠 **Memory Management**
- Safe memory manipulation (`ft_memset`, `ft_memcpy`, `ft_memmove`)
- Dynamic allocation utilities (`ft_calloc`, `ft_realloc`)
- Advanced double pointer management (`ft_freedouble`, `ft_freedouble_array`)

### 🔗 **String Processing**
- Comprehensive string operations (copy, concatenate, compare, search)
- Advanced string utilities (`ft_split`, `ft_strjoin`, `ft_strtrim`)
- Custom string cleaning functions (`ft_strclean`, `ft_clean_double`)
- Robust number parsing (`ft_atoi`, `ft_strtol`, `ft_strisnumber`)

### 📝 **I/O Operations**
- File descriptor utilities (`ft_putchar_fd`, `ft_putstr_fd`, `ft_putnbr_fd`)
- **Custom printf implementation** with full format specifier support
- **get_next_line** for efficient line-by-line file reading

### 🔗 **Data Structures**
- Complete linked list implementation with manipulation functions
- Optimized structures for internal operations

## 🏗️ Project Structure

```
libft/
├── libft.h                 # Main header file
├── Makefile               # Build configuration
├── README.md              # This file
└── src/
    ├── d_ascii/           # Character classification & conversion
    ├── d_fds/             # File descriptor operations
    ├── d_get_next_line/   # Line reading utilities
    ├── d_lists/           # Linked list operations
    ├── d_memory/          # Memory management functions
    ├── d_printf/          # Custom printf implementation
    ├── d_strings/         # String manipulation utilities
    └── *.c                # Additional utility functions
```

## 🚀 Key Highlights

### 🎯 **Custom Printf Implementation**
Full-featured printf with support for:
- `%c` (characters), `%s` (strings), `%d`/`%i` (integers)
- `%u` (unsigned), `%x`/`%X` (hexadecimal), `%p` (pointers)
- Modular design with function pointers for extensibility

### 📖 **get_next_line**
Efficient file reading utility that:
- Reads files line by line regardless of buffer size
- Handles multiple file descriptors simultaneously
- Memory-optimized with configurable buffer size

### 🧮 **Advanced Memory Utilities**
- `ft_realloc`: Safe memory reallocation
- Double pointer management for 2D arrays
- Partial memory cleanup functions for error handling

### 🔧 **Extended String Operations**
- `ft_split`: Split strings with custom delimiters
- `ft_strclean`: Remove specific characters from strings
- `ft_clean_double`: Clean character arrays in double pointers

## 🛠️ Custom Data Types

| Type | Purpose |
|------|---------|
| `t_size` | Unsigned integer type definition |
| `t_numbers` | Multi-purpose counter structure |
| `t_split` | Internal structure for string splitting |
| `t_list` | Linked list node structure |
| `t_Itoa` | Integer to string conversion helper |
| `t_format` | Printf format handler structure |
| `t_fdnode` | File descriptor node for get_next_line |

## 🔧 Compilation & Usage

### Building the Library
```bash
make        # Compile the basic library
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild everything
```

### Using in Your Project
```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello, libft!");
    ft_printf("String length: %d\n", ft_strlen(str));
    free(str);
    return (0);
}
```

Compile with:
```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lft
```

## 📊 Function Categories

- **ASCII Functions**: 6 functions for character operations
- **Memory Functions**: 7 core memory manipulation utilities
- **String Functions**: 20+ comprehensive string operations
- **I/O Functions**: 4 file descriptor utilities + printf + get_next_line
- **List Functions**: 9 linked list manipulation functions
- **Utility Functions**: 10+ additional helper functions

## 🎓 Educational Value

This library demonstrates:
- **Memory Management**: Safe allocation, deallocation, and manipulation
- **Data Structures**: Linked list implementation and usage
- **Algorithm Implementation**: String processing and number conversion
- **Modular Design**: Function pointers and structured programming
- **Error Handling**: Robust input validation and edge case management

## 📜 42 School Standards

- Follows the 42 Norm coding standard
- No memory leaks (validated with valgrind)
- Comprehensive error handling
- Optimized for performance and readability

---

*Built with ❤️ at 42 School*

## Author

- Ana Zubieta
- Student at 42 Málaga - Fundación Telefónica
- GitHub: ateibuzena
- Email: ena.ateibuz@gmail.com
