
#include "get_next_line.h"

char			*get_next_line(int fd);
unsigned char	*ft_buf_check(int fd, unsigned char **buf);
unsigned char	*ft_reader(char *result, int fd, unsigned char **buf);

unsigned char	*ft_buf_check(int fd, unsigned char **buf)
{
	char			*stock;
	char			*c;
	unsigned char	*result;

	if (buf[fd] == NULL)
		return (NULL);
	c = ft_strchr((char *)buf[fd], '\n');
	if (c)
	{
		stock = (char *)buf[fd];
		buf[fd] = (unsigned char *)ft_substr(stock, c - stock + 1, BUFFER_SIZE);
		result = ((unsigned char *)ft_substr((char *)stock, 0, c - stock + 1));
		return (result);
	}
	else
	{
		return (NULL);
	}
}

unsigned char	*ft_reader(char *result, int fd, unsigned char **buf)
{
	char			*c;
	char			*stock;
	char			*s1;

	stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read(fd, stock, BUFFER_SIZE) || !ft_strchr(stock, '\0'))
	{
		stock[BUFFER_SIZE] = '\0';
		c = ft_strchr(stock, '\n');
		s1 = stock;
		if (c)
		{
			result = ft_strjoin(result, ft_substr(s1, 0, c - s1 + 1));
			buf[fd] = (unsigned char *)ft_substr(s1, c - s1 + 1, BUFFER_SIZE);
			return ((unsigned char *)result);
		}
		else
		{
			result = ft_strjoin(result, s1);
			continue ;
		}
	}
	if (stock)
		return ((unsigned char *)result);
	return (NULL);
}

char	*get_next_line(int fd)
{
	unsigned char			*result;
	static unsigned char	*buf[OPEN_MAX];

	if (fd < 0)
		return (NULL);
	result = ft_buf_check(fd, buf);
	if (result)
		return ((char *)result);
	if (buf[fd])
		result = buf[fd];
	else
	{
		result = malloc(0);
		result[0] = '\0';
	}
	result = ft_reader((char *)result, fd, buf);
	return ((char *)result);
}
