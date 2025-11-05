/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:28:53 by MP9               #+#    #+#             */
/*   Updated: 2025/11/05 21:20:03 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char *parsing(char *msg, char **args)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 1;
	if (!args[i2])
	{
		ft_strlcpy(msg, args[i], ft_strlen(args[i]) + 1);
		return (msg);
	}
	msg = ft_inputjoin(args[i], args[i2]);
	i2++;
	while (args[i2])
	{
		msg = ft_inputjoin(msg, args[i2]);
		i2++;
	}
	return(msg);
}

char	*ft_inputjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	len;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	joinstr = (char *)malloc(sizeof(char) * (len + 2));
	if (!joinstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		joinstr[i] = s1[i];
		i++;
	}
	joinstr[i] = 32;
	while (s2[i2] != '\0')
	{
		i++;
		joinstr[i] = s2[i2];
		i2++;
	}
	joinstr[++i] = '\0';
	return (joinstr);
}