#include "libft.h"
#include <unistd.h>

char	*append_zeros_after_prefix(char *str, int zeros, const char *prefix)
{
	const int	have_prefix = ft_strchr(prefix, '0') != NULL;
	const char	*zeros = generate_chars('0', zeros);
	char		*content_after_prefix;
	char		*result;

	if (!zeros)
		return (NULL);
	if (!have_prefix)
		return (ft_strjoin(zeros, str));
	content_after_prefix = ft_strdup(str + ft_strlen(prefix));
	if (!content_after_prefix)
	{
		free(zeros);
		return (NULL);
	}
	result = ft_strjoin(prefix, ft_strjoin(zeros, content_after_prefix));
	free(zeros);
	free(content_after_prefix);
	return (result);
}

size_t	ft_putstr(const char *str)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	return (write(1, str, len));
}

static int	ft_numlen_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	itoa_recursive_unsigned(char *str, unsigned int n, int start)
{
	if (n == 0)
	{
		return ;
	}
	itoa_recursive_unsigned(str, n / 10, start - 1);
	str[start] = n % 10 + '0';
}

const char	*ft_itoa_unsigned(unsigned int number)
{
	char	*str;
	int		num_len;

	if (number == 0)
	{
		return (ft_strdup("0"));
	}
	num_len = ft_numlen_unsigned(number);
	str = ft_calloc(num_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	itoa_recursive_unsigned(str, number, num_len - 1);
	return (str);
}
