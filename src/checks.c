int		is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-'
			|| c == '+' || c == ' ');
}

int		is_width(char c)
{
	return ('1' <= c && c <= '9');
}

int		is_precision(char c)
{
	return (c == '.' || ('0' <= c && c <= '9'));
}

int		is_size(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
			|| c == 'd' || c == 'i' || c == 'o'
			|| c == 'u' || c == 'x' || c == 'X' || c == 'f');
}

int		is_conv(char c)
{
	return (is_flag(c) || is_width(c) || is_precision(c) || is_size(c) || is_type(c));
}