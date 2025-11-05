/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:18:52 by MP9               #+#    #+#             */
/*   Updated: 2025/11/05 20:08:07 by MP9              ###   ########.fr       */
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
		usleep(100);
		bit++;
	}
}



int main(int argc, char **argv)
{
	int		pid;
	char	**msg;
	int		i;

	if (argc < 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	i = 0;
	while (msg[i])
		send_char(pid, msg[i++]);
	send_char(pid, '\n');
	return (0);
}
