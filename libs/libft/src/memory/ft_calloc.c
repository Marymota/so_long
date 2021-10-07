#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(nmemb * size);
	if (!ret)
		return (0);
	else
	{
		ft_bzero(ret, nmemb * size);
		return (ret);
	}
	return (0);
}
