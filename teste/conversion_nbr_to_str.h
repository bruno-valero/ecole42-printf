#include "libft.h"

static int nbrlen(long int nbr, int base_len);
static void handle_base(char *result, char *base, int len_nbr, long int number);
static int is_valid_base(char *base);

char *itoa_base(int nbr, char *base)
{
	int is_negative;
	long int number;
	int len_nbr;
	char *result;

	if (!nbr)
		return (ft_strdup("0"));
	if (!is_valid_base(base))
		return (NULL);
	number = (long int)nbr;
	is_negative = 0;
	if (number < 0)
	{
		is_negative = 1;
		number *= -1;
	}
	len_nbr = nbrlen(number, ft_strlen(base)) + is_negative;
	result = (char *)malloc(len_nbr + 1);
	handle_base(result, base, len_nbr, number);
	if (is_negative)
		result[0] = '-';
	result[len_nbr] = '\0';
	return (result);
}

static void handle_base(char *result, char *base, int len_nbr, long int number)
{
	int len_base;

	len_base = ft_strlen(base);
	while (len_nbr--)
	{
		result[len_nbr] = base[number % len_base];
		number /= len_base;
	}
}

static int is_valid_base(char *base)
{
	int i;
	int i_verify_repeated;

	if (!base)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		if (!(base[i] > 32 && base[i] < 127) || (base[i] == '+' || base[i] == '-'))
			return (0);
		i_verify_repeated = i;
		while (base[++i_verify_repeated] != '\0')
			if (base[i] == base[i_verify_repeated])
				return (0);
	}
	if (i < 2)
		return (0);
	return (1);
}

static int nbrlen(long int nbr, int base_len)
{
	int len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}
