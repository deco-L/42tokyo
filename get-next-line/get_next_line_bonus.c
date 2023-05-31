#include "get_next_line_bonus.h"

char			*get_next_line(int fd);
unsigned char	*ft_buf_check(int fd, char **buf);
unsigned char	*ft_reader(char *result, int fd, unsigned char **buf, char *s1);

unsigned char	*ft_buf_check(int fd, char **buf)
{
	char			*s1;
	char			*c;
	unsigned char	*result;

	if (buf[fd] == NULL)
		return (NULL);
	c = ft_strchr((char *)buf[fd], '\n');
	if (c)
	{
		s1 = (char *)buf[fd];
		buf[fd] = ft_substr(s1, c - s1 + 1, ft_strlen((const char *)buf[fd]));
		result = ((unsigned char *)ft_substr((char *)s1, 0, c - s1 + 1));
		return (result);
	}
	else
	{
		return (NULL);
	}
}

unsigned char	*ft_reader(char *result, int fd, unsigned char **buf, char *s1)
{
	long long		len;
	char			*c;

	len = 1;
	s1[BUFFER_SIZE] = '\0';
	while (len)
	{
		len = read(fd, s1, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		else if (len == 0)
		{
			if (result == NULL)
				return NULL;
			buf[fd] = NULL;
			return ((unsigned char *)result);
		}
		c = ft_strchr(s1, '\n');
		if (c)
		{
			result = ft_strjoin(result, ft_substr(s1, 0, c - s1 + 1));
			buf[fd] = (unsigned char *)ft_substr(s1, c - s1 + 1, len);
			return ((unsigned char *)result);
		}
		else
			result = ft_strjoin(result, ft_substr(s1, 0, len));
	}
	return ((unsigned char *)result);
}

char	*get_next_line(int fd)
{
	char					*stock;
	unsigned char			*result;
	static unsigned char	*buf[20];

	if (fd < 0)
		return (NULL);
	result = ft_buf_check(fd, (char **)buf);
	if (result)
		return ((char *)result);
	if (buf[fd])
		result = buf[fd];
	else
		result = NULL;
	stock = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (stock == NULL)
		return (NULL);
	result = ft_reader((char *)result, fd, buf, stock);
	free(stock);
	return ((char *)result);
}
