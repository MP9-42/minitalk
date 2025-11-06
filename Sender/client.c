/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:18:52 by MP9               #+#    #+#             */
/*   Updated: 2025/11/06 18:23:23 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_char(int pid, unsigned char c)
{
	int bit;
	
	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(33);
		bit++;
	}
}

char	*get_words(char **matrix)
{
	int i;
	int i2;
	char *words;

	i = 0;
	if (!matrix)
		return (NULL);
	while (matrix[i])
	{
		while (matrix[i][i2] != '\0')
			i2++;
		i2 = 0; 
		i++;
	}
	words = malloc(sizeof(char) * i + i2 + 1);
	if (!words)
		return (NULL);
	return(words);
}

int main(int argc, char **argv)
{
	int		pid;
	char	*msg;
	int		i;

	if (argc < 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	msg = get_words(&argv[2]);
	msg = parsing(msg, &argv[2]);
	i = 0;
	while (msg[i])
		send_char(pid, msg[i++]);
	send_char(pid, '\n');
	free(msg);
	return (0);
}
