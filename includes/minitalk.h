/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:45:25 by MP9               #+#    #+#             */
/*   Updated: 2025/11/04 19:29:47 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <signal.h>
# include <stdlib.h>


void	send_char(int pid, unsigned char c);
void	signal_handler(int sig, siginfo_t *info, void *context);



#endif