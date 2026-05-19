# ft_printf

> A custom implementation of the standard printf function in C

<div align="center">

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)
![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge)

</div>

---

## Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Supported Conversions](#supported-conversions)
- [Flags and Modifiers](#flags-and-modifiers)
- [Compilation](#compilation)
- [Testing](#testing)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Implementation Details](#implementation-details)
- [Author](#author)

---

## About

**ft_printf** is a reimplementation of the standard C library function `printf`, developed as part of the 42 School curriculum. This project deepens understanding of variadic functions, format parsing, and output formatting.

### Learning Objectives

- Master variadic functions (`va_start`, `va_arg`, `va_end`)
- Parse and interpret complex format strings
- Handle multiple data types and conversions
- Implement flags, width, and precision modifiers
- Manage edge cases and error handling

### Key Features

- 100% Norminette compliant
- No memory leaks (tested with Valgrind)
- Bonus part completed (all flags, width, precision, length modifiers)
- Modular architecture for easy maintenance
- Comprehensive error handling

---

## Features

### Mandatory Part

| Feature | Description |
|---------|-------------|
| **Conversions** | `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%` |
| **Return Value** | Number of characters printed |
| **Error Handling** | Proper handling of NULL pointers and allocation failures |

### Bonus Part

| Feature | Description |
|---------|-------------|
| **Flags** | `-` (left-justify), `0` (zero-padding), `+` (force sign), ` ` (space), `#` (alternate form) |
| **Width** | Minimum field width |
| **Precision** | Precision for numbers and strings |
| **Length Modifiers** | `hh`, `h`, `l`, `ll`, `j`, `z`, `t` |

---

## Installation

### Prerequisites

| Tool | Minimum Version | Purpose |
|------|-----------------|---------|
| gcc | 9.0+ | Compilation |
| make | 4.3+ | Build automation |

### Clone the Repository

```bash
git clone https://github.com/dbouizem/ft_printf.git
cd ft_printf
```

### Compile the Library

```bash
# Mandatory part only
make

# With bonus features
make bonus

# Compile test program
make program

# Cleanup
make clean      # Remove .o files
make fclean     # Remove .o files and libftprintf.a
make re         # Recompile everything
```

The compilation generates **libftprintf.a** (static library).

---

## Usage

### Including ft_printf in Your Project

**Step 1: Add the Header**

```c
#include "ft_printf.h"
```

**Step 2: Compile with the Library**

```bash
gcc -Wall -Wextra -Werror -Iincludes your_program.c -L. -lftprintf -o your_program
```

**Step 3: Use ft_printf**

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: 0x%x\n", 255);
    return (0);
}
```

---

## Supported Conversions

| Specifier | Type | Description |
|-----------|------|-------------|
| `%c` | char | Single character |
| `%s` | char* | String of characters |
| `%p` | void* | Pointer address in hexadecimal |
| `%d` | int | Signed decimal integer |
| `%i` | int | Signed decimal integer (same as %d) |
| `%u` | unsigned int | Unsigned decimal integer |
| `%x` | unsigned int | Unsigned hexadecimal (lowercase) |
| `%X` | unsigned int | Unsigned hexadecimal (uppercase) |
| `%%` | - | Literal '%' character |

---

## Flags and Modifiers

### Flags

| Flag | Description | Example |
|------|-------------|---------|
| `-` | Left-justify within field width | `"%-10s"` → `"hello     "` |
| `0` | Zero-padding for numbers | `"%05d"` → `"00042"` |
| `+` | Always show sign for numbers | `"%+d"` → `"+42"` |
| ` ` (space) | Space before positive numbers | `"% d"` → `" 42"` |
| `#` | Alternate form (0x for hex) | `"%#x"` → `"0x2a"` |

### Width

Minimum field width. If the output is shorter, it will be padded.

```c
ft_printf("%10s", "hello");    // "     hello"
ft_printf("%10d", 42);         // "        42"
```

### Precision

For numbers: minimum number of digits. For strings: maximum characters.

```c
ft_printf("%.5d", 42);         // "00042"
ft_printf("%.3s", "hello");    // "hel"
```

### Length Modifiers

| Modifier | Description | Example |
|----------|-------------|---------|
| `hh` | signed char / unsigned char | `"%hhd"` |
| `h` | short int / unsigned short | `"%hd"` |
| `l` | long int / unsigned long | `"%ld"` |
| `ll` | long long int / unsigned long long | `"%lld"` |
| `j` | intmax_t / uintmax_t | `"%jd"` |
| `z` | size_t | `"%zd"` |
| `t` | ptrdiff_t | `"%td"` |

---

## Compilation

### Makefile

The Makefile contains the following rules:

```bash
make          # Compiles libftprintf.a (mandatory)
make bonus    # Compiles with bonus features
make program  # Compiles test program
make clean    # Removes .o files
make fclean   # Removes .o and libftprintf.a
make re       # fclean + make
```

### Compilation Flags

```makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror
```

---

## Testing

### Included Test Program

Run the included test program that validates all features:

```bash
make program
./program
```

The test program validates:
- All conversion specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`)
- Flag combinations (`-`, `0`, `+`, ` `, `#`)
- Width and precision modifiers
- Edge cases (NULL pointers, empty strings, special characters)
- Length modifiers (`hh`, `h`, `l`, `ll`, `j`, `z`, `t`)

### External Testers

Use these community testers for comprehensive validation:

**Recommended Testers:**

- [printfTester](https://github.com/Tripouille/printfTester) — Comprehensive tester with detailed output
  ```bash
  git clone https://github.com/Tripouille/printfTester.git
  cd printfTester
  make m  # Mandatory part
  make b  # Bonus part
  ```

- [ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester) — Another popular tester
  ```bash
  git clone https://github.com/paulo-santana/ft_printf_tester.git
  cd ft_printf_tester
  make
  ```

- [francinette](https://github.com/xicodomingues/francinette) — Official 42 tester
  ```bash
  # Follow installation instructions on the repo
  francinette ft_printf
  ```

### Manual Testing with printf Comparison

Create a test file to compare output with standard `printf`:

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;

    printf("=== Comparison Test ===\n\n");

    // Test 1: Basic conversions
    ret1 = ft_printf("ft_printf: %d %s %p\n", 42, "test", (void*)0x42);
    ret2 = printf("printf:    %d %s %p\n", 42, "test", (void*)0x42);
    printf("Returns: ft=%d, std=%d\n\n", ret1, ret2);

    // Test 2: Flags and width
    ret1 = ft_printf("ft_printf: [%-10s] [%05d]\n", "left", 42);
    ret2 = printf("printf:    [%-10s] [%05d]\n", "left", 42);
    printf("Returns: ft=%d, std=%d\n\n", ret1, ret2);

    // Test 3: Edge cases
    ret1 = ft_printf("ft_printf: NULL=%s, ptr=%p\n", NULL, NULL);
    ret2 = printf("printf:    NULL=%s, ptr=%p\n", NULL, NULL);
    printf("Returns: ft=%d, std=%d\n\n", ret1, ret2);

    return (0);
}
```

Compile and run:

```bash
gcc -Iincludes test.c -L. -lftprintf -o test
./test
```

### Valgrind Memory Testing

Check for memory leaks:

```bash
# Compile with debug symbols
gcc -g -Iincludes test.c -L. -lftprintf -o test

# Run Valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
```

**Expected result:** No memory leaks, no errors.

### Stress Testing

Test with extreme values:

```c
#include "ft_printf.h"

int main(void)
{
    // Large numbers
    ft_printf("Max int: %d\n", 2147483647);
    ft_printf("Min int: %d\n", -2147483648);
    ft_printf("Max unsigned: %u\n", 4294967295u);

    // Long strings
    ft_printf("%.1000s\n", "Very long string...");

    // Many arguments
    ft_printf("%d %d %d %d %d %d %d %d %d %d\n",
              1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    // Complex format
    ft_printf("%+010.5d\n", 42);
    ft_printf("%-#10.3x\n", 255);

    return (0);
}
```

---

### Note :
Le sujet de ft_printf indique que les segfaults sont interdits, sauf si printf se comporte de la même façon dans les mêmes circonstances.
Or, appeler printf(NULL) est un comportement indéfini selon la norme C (ISO/IEC 9899).
Cela signifie que le résultat peut varier selon les systèmes :

Sur certaines implémentations (comme glibc), printf(NULL) peut afficher (null) ou ne rien faire.

Sur d’autres (comme musl, ou certaines versions de macOS), cela peut provoquer un crash (segfault).

La man page de printf ne garantit jamais que NULL est un format valide. Elle parle uniquement de "character strings", ce qui exclut les pointeurs NULL.

En conséquence, j’ai choisi de ne pas gérer le cas ft_printf(NULL), car il est hors-scope, non défini par la norme, et toléré par le sujet.
Mon comportement — provoquer un crash dans ce cas — est donc acceptable et conforme, car printf lui-même peut crash aussi dans cette situation.

Enfin, il ne s’agit pas d’un bug ou d’un oubli, mais d’un choix volontaire pour rester fidèle au comportement de la fonction standard printf dans un contexte défini par la norme, et non par une implémentation particulière (glibc, musl, etc.).

dépend de la lib utilisée

glibc (souvent) affiche (null)

Mais ce n’est pas une obligation !

Tu n’as pas à copier glibc : tu dois respecter la norme, pas un comportement particulier de telle ou telle lib

---


### Validation Checklist

#### Mandatory Part
- [x] `%c` prints single character
- [x] `%s` prints string (handles NULL)
- [x] `%p` prints pointer in hex
- [x] `%d` and `%i` print signed integers
- [x] `%u` prints unsigned integers
- [x] `%x` prints lowercase hex
- [x] `%X` prints uppercase hex
- [x] `%%` prints literal %
- [x] Returns correct character count
- [x] No memory leaks

#### Bonus Part
- [x] `-` flag (left-justify)
- [x] `0` flag (zero-padding)
- [x] `+` flag (force sign)
- [x] ` ` flag (space before positive)
- [x] `#` flag (alternate form)
- [x] Width modifier works
- [x] Precision modifier works
- [x] Width + Precision combination works
- [x] Length modifiers (`hh`, `h`, `l`, `ll`) work
- [x] All flags combine correctly

#### Edge Cases
- [x] NULL string → `(null)`
- [x] NULL pointer → `(nil)` or `0x0`
- [x] Empty string → (nothing printed)
- [x] Zero value → `0`
- [x] Negative numbers with flags
- [x] Multiple consecutive %
- [x] Invalid format specifiers (undefined behavior accepted)

### Performance Testing

Compare performance with standard `printf`:

```c
#include "ft_printf.h"
#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t start, end;
    double ft_time, std_time;
    int i;

    // Test ft_printf
    start = clock();
    for (i = 0; i < 100000; i++)
        ft_printf("%d %s %x\n", i, "test", i);
    end = clock();
    ft_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Test printf
    start = clock();
    for (i = 0; i < 100000; i++)
        printf("%d %s %x\n", i, "test", i);
    end = clock();
    std_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nft_printf: %.3f seconds\n", ft_time);
    printf("printf:    %.3f seconds\n", std_time);
    printf("Ratio:     %.2fx\n", ft_time / std_time);

    return (0);
}
```

---

## Examples

### Example 1: Basic Conversions

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello World");
    ft_printf("Pointer: %p\n", (void*)0x7fff5fbff710);
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Unsigned: %u\n", 4294967295u);
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Percent: %%\n");

    return (0);
}
```

**Output:**
```
Character: A
String: Hello World
Pointer: 0x7fff5fbff710
Decimal: 42
Unsigned: 4294967295
Hex (lower): ff
Hex (upper): FF
Percent: %
```

### Example 2: Flags and Width

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Left-justified: %-10s|\n", "hello");
    ft_printf("Right-justified: %10s|\n", "hello");
    ft_printf("Zero-padded: %05d\n", 42);
    ft_printf("With sign: %+d\n", 42);
    ft_printf("With space: % d\n", 42);
    ft_printf("Alternate hex: %#x\n", 42);

    return (0);
}
```

**Output:**
```
Left-justified: hello     |
Right-justified:      hello|
Zero-padded: 00042
With sign: +42
With space:  42
Alternate hex: 0x2a
```

### Example 3: Precision

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Precision (int): %.5d\n", 42);
    ft_printf("Precision (string): %.3s\n", "hello");
    ft_printf("Width + Precision: %10.5d\n", 42);

    return (0);
}
```

**Output:**
```
Precision (int): 00042
Precision (string): hel
Width + Precision:      00042
```

### Example 4: Edge Cases

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("NULL string: %s\n", NULL);
    ft_printf("NULL pointer: %p\n", NULL);
    ft_printf("Zero: %d\n", 0);
    ft_printf("Negative: %d\n", -42);
    ft_printf("Max int: %d\n", 2147483647);
    ft_printf("Min int: %d\n", -2147483648);

    return (0);
}
```

**Output:**
```
NULL string: (null)
NULL pointer: (nil)
Zero: 0
Negative: -42
Max int: 2147483647
Min int: -2147483648
```

---

## Project Structure

```
ft_printf/
│
├── includes/
│   ├── ft_printf.h              # Main header
│   └── ft_printf_bonus.h        # Bonus header
│
├── srcs/                        # Mandatory sources
│   ├── ft_printf.c              # Entry point
│   ├── parsing/                 # Format string parsing
│   │   └── parse_format.c
│   ├── handles/                 # Conversion handlers
│   │   ├── handle_char.c
│   │   ├── handle_string.c
│   │   ├── handle_pointer.c
│   │   ├── handle_int.c
│   │   ├── handle_uint.c
│   │   └── handle_hex.c
│   └── utils/                   # Utility functions
│       ├── ft_itoa_print.c
│       ├── ft_ulltoa_base.c
│       ├── ft_print_char.c
│       ├── ft_print_str.c
│       └── ft_print_hex.c
│
├── srcs_bonus/                  # Bonus sources
│   ├── parsing/
│   ├── handles/
│   ├── get_value/
│   ├── applys/
│   └── utils/
│
├── tester/                      # Local tests
│   ├── cheker.c
│   ├── cheker_bonus.c
│   ├── cheker.sh
│   └── eval_notes.txt
│
├── libft/                       # Libft
│
├── Makefile                     # Compilation
├── main.c                       # Test program
├── README.md                    # This file
└── .gitignore                   # Ignored files
```

---

## Implementation Details

### Architecture

The implementation follows a modular architecture:

1. **Parsing Phase** — `parse_format()` reads the format string and populates a `t_printf` structure with flags, width, precision, and conversion type.

2. **Value Extraction** — Variadic arguments are extracted using `va_arg()` based on the conversion type.

3. **Conversion Handlers** — Each conversion specifier (`%c`, `%s`, etc.) has a dedicated handler function.

4. **Modifier Application** — Width, precision, and flags are applied to the converted string.

5. **Output** — The final formatted string is written to stdout.

### Key Data Structure

```c
typedef struct s_printf
{
    int         total;
    int         error;
    va_list     args;
    int         width;
    int         precision;
    int         minus;
    int         zero;
    int         hash;
    int         space;
    int         plus;
    t_length    length;
}   t_printf;
```

### Error Handling

- Returns `-1` on allocation failure
- Sets `data->error` flag to stop processing
- Handlers check error flag before continuing
- Proper cleanup of allocated memory on error

---

## Author

<div align="center">

| [<img src="https://github.com/dbouizem.png" width="100px;"/><br /><sub><b>dbouizem</b></sub>](https://github.com/dbouizem)<br /> |
| :---: |

[![GitHub](https://img.shields.io/badge/GitHub-dbouizem-181717?style=for-the-badge&logo=github)](https://github.com/dbouizem)

</div>

---

## License

This project was completed as part of the 42 School curriculum. It is freely available for educational purposes.

---

<div align="center">

**If this project helped you, feel free to give it a star!**

*Made at 42 Paris*

</div>
