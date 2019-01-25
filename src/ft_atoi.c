static int	ft_isspace(char c)
{
	return (c == ' '
			|| c == '\t'
			|| c == '\v'
			|| c == '\n'
			|| c == '\r'
			|| c == '\f');
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *s)
{
	int	neg;
	int	res;

	while (ft_isspace(*s))
		s++;
	neg = (*s == '-');
	if (*s == '-' || *s == '+')
		s++;
	res = 0;
	while (ft_isdigit(*s))
	{
		res *= 10;
		res += (*s - '0');
		s++;
	}
	return (neg ? -res : res);
}