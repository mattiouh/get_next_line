/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalombi <mpalombi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:04:59 by mpalombi          #+#    #+#             */
/*   Updated: 2023/02/09 13:21:26 by mpalombi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_stc(int fd, char *stc_str)

{
	char	*tmp;
	int		rd_bt;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	rd_bt = 1;
	while (!ft_strchr(stc_str, '\n') && rd_bt != 0)
	{
		rd_bt = read(fd, tmp, BUFFER_SIZE);
		if (rd_bt == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[rd_bt] = '\0';
		stc_str = ft_strjoin(stc_str, tmp);
	}
	free(tmp);
	return (stc_str);
}

char	*get_next_line(int fd)

{
	char		*line;
	static char	*stc_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stc_str = ft_read_stc(fd, stc_str);
	if (!stc_str)
		return (NULL);
	line = ft_getline(stc_str);
	stc_str = ft_new_stc_str(stc_str);
	return (line);
}
