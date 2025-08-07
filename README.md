# ft_printf

This project is part of the 42 school curriculum. The objective is to implement a simplified version of the `printf` function in C, capable of handling various format specifiers.

## Libft Usage

This project uses functions from the [`libft`](https://github.com/bruno-valero/ecole42-libft) library, which was previously developed as part of the 42 cursus. Although `libft` is not an external dependency (it is included in the `libft/` folder and compiled automatically by the Makefile), its use is essential for the implementation of this project. You can check the original repository here: [ecole42-libft](https://github.com/bruno-valero/ecole42-libft).

## Objective

Recreate the behavior of the `printf` function using only allowed functions in the 42 school standards. This includes handling of characters, strings, integers, unsigned integers, hexadecimal numbers, and pointers.

## Compilation

To compile and test the `ft_printf` function:

```bash
make
```

## Usage

```c
#include "ft_printf.h"

ft_printf("Hello %s!", "world");
```

## Format Specifiers Implemented

- `%c` – Character  
- `%s` – String  
- `%p` – Pointer address  
- `%d` or `%i` – Signed decimal integer  
- `%u` – Unsigned decimal integer  
- `%x` – Hexadecimal (lowercase)  
- `%X` – Hexadecimal (uppercase)  
- `%%` – A literal percent sign  

## Bonus Part

Although this project was built with a structure ready to support the bonus part (handling flags such as `-`, `0`, `.`, `#`, space, and `+`), I decided **not to implement the bonus features**. The reason is that, despite being an interesting extension, the bonus requires significantly more time and complexity than the mandatory part, which I preferred to allocate to other learning priorities at this stage.

Still, the codebase is organized in a way that would make implementing the bonus part relatively straightforward in the future if desired.

## Evaluation Criteria

- Correctness of output  
- Memory handling (no leaks)  
- Adherence to 42 coding standards  
- Project organization and readability  

## Notes

This project is an excellent opportunity to understand variadic functions in C, low-level formatting, and dynamic memory handling. Once validated, `ft_printf` can be added to `libft` for reuse in future C projects.