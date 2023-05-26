#include "get_next_line_bonus.h"

char			*get_next_line(int fd);
unsigned char	*ft_buf_check(int fd, unsigned char **buf);
unsigned char	*ft_reader(char *result, int fd, unsigned char **buf, char *s1);

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

unsigned char	*ft_reader(char *result, int fd, unsigned char **buf, char *s1)
{
	char			*c;

	while (read(fd, s1, BUFFER_SIZE) || !ft_strchr(s1, '\0'))
	{
		s1[BUFFER_SIZE] = '\0';
		c = ft_strchr(s1, '\n');
		if (c)
		{
			result = ft_strjoin(result, ft_substr(s1, 0, c - s1 + 1));
			buf[fd] = (unsigned char *)ft_substr(s1, c - s1 + 1, BUFFER_SIZE);
			free(s1);
			return ((unsigned char *)result);
		}
		else
			result = ft_strjoin(result, s1);
	}
	if (s1)
	{
		buf[fd] = NULL;
		free(s1);
		return ((unsigned char *)result);
	}
	free(s1);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char					*stock;
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
	stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (stock == NULL)
		return (NULL);
	result = ft_reader((char *)result, fd, buf, stock);
	return ((char *)result);
}
