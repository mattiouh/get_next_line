/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:08:48 by mpalombi          #+#    #+#             */
/*   Updated: 2023/02/09 14:29:23 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stc_str, char *c)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stc_str)
	{
		stc_str = (char *)malloc(1 * sizeof(char));
		stc_str[0] = '\0';
	}
	if (!stc_str || !c)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(stc_str) + ft_strlen(c)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stc_str)
		while (stc_str[++i] != '\0')
			str[i] = stc_str[i];
	while (c[j] != '\0')
		str[i++] = c[j++];
	str[ft_strlen(stc_str) + ft_strlen(c)] = '\0';
	free(stc_str);
	return (str);
}

char	*ft_getline(char *stc_str)

{
	int		i;
	char	*str;

	i = 0;
	if (!stc_str[i])
		return (NULL);
	while (stc_str[i] != '\n' && stc_str[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stc_str[i] && stc_str[i] != '\n')
	{
		str[i] = stc_str[i];
		i++;
	}
	if (stc_str[i] == '\n')
	{
		str[i] = stc_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_stc_str(char *stc_str)

{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stc_str[i] && stc_str[i] != '\n')
		i++;
	if (!stc_str[i])
	{
		free(stc_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stc_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stc_str[i])
		str[j++] = stc_str[i++];
	str[j] = '\0';
	free(stc_str);
	return (str);
}
