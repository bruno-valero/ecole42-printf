#include "libft.h"
#include "printf.h"

char	*itoa_base(int nbr, char *base)
{
	int			is_negative;
	long int	number;
	int			len_nbr;
	char		*result;

	if (!is_valid_base(base))
		return (NULL);
	if (!nbr)
		return (ft_strdup("0"));
	number = (long int)nbr;
	is_negative = 0;
	if (number < 0)
	{
		is_negative = 1;
		number *= -1;
	}
	len_nbr = nbrlen((unsigned long)number, ft_strlen(base)) + is_negative;
	result = (char *)malloc(len_nbr + 1);
	if (!result)
		return (NULL);
	handle_base(result, base, len_nbr, (unsigned long)number);
	if (is_negative)
		result[0] = '-';
	result[len_nbr] = '\0';
	return(result);
}

char	*utoa_base(unsigned int nbr, char *base)
{
	int			len_nbr;
	char		*result;

	if (!is_valid_base(base))
		return (NULL);
	if (!nbr)
		return (ft_strdup("0"));
	len_nbr = nbrlen((unsigned long)nbr, ft_strlen(base));
	result = (char *)malloc(len_nbr + 1);
	if (!result)
		return (NULL);
	handle_base(result, base, len_nbr, (unsigned long)nbr);
	result[len_nbr] = '\0';
	return(result);
}

char	*ultoa_base(unsigned long nbr, char *base)
{
	int			len_nbr;
	char		*result;

	if (!is_valid_base(base))
		return (NULL);
	if (!nbr)
		return (ft_strdup("0"));
	len_nbr = nbrlen(nbr, ft_strlen(base));
	result = (char *)malloc(len_nbr + 1);
	if (!result)
		return (NULL);
	handle_base(result, base, len_nbr, nbr);
	result[len_nbr] = '\0';
	return(result);
}

char	*ptoa(va_list args)
{
	void	*ptr_value;

	ptr_value = NULL;
	ptr_value = va_arg(args, void *);
	if (!ptr_value)
		return (ft_strdup("(nil)"));
	return (ultoa_base((unsigned long)ptr_value, "0123456789abcdef"));
}
