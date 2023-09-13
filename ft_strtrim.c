#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    int	i;
    size_t	len;
    char	*ans;

    i = 0;
    len = ft_strlen(s1);
    ans = 0;
    if (s1 != 0 && set != 0)
    {
		while (s1[i] &&  ft_strchr(set, s1[i]))
			i++;
		/*while (s1[ans -1] && ft_strchr(set, s1[ans -1]))
			ans--;*/
		ans = (char *)malloc(sizeof(char *) * (len + 1));
		if (ans)
			ft_strlcpy(str, &s1[i], len - i + 1);
    }
    return (ans);
}
