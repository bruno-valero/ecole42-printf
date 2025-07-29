#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

typedef struct	param_data
{
	char	*content;
	int		length;
}	flag_translation;

void	*free_str_array(char **strarr, int idx);
int		str_array_len(char **strarr);
void	print_char(char c, int *print_count);
void	print_str(char *str, int *print_count);
char	**get_valid_flags();
int		is_valid_flag(char *flag);
char	*get_corresponding_flag(char *flag);
void	handle_base(char *result, char *base, int len_nbr, unsigned long number);
int		is_valid_base(char *base);
int		nbrlen(unsigned long nbr, int base_len);
char	*itoa_base(int nbr, char *base);
char	*utoa_base(unsigned int nbr, char *base);
char	*ultoa_base(unsigned long nbr, char *base);
char	*ptoa(va_list args);
char	*make_tranlation(char *flag, va_list args);
char	*handle_input_text(char *str, va_list args, int *print_count);

#endif
