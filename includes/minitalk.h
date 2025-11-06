/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:45:25 by MP9               #+#    #+#             */
/*   Updated: 2025/11/06 19:11:39 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <signal.h>
# include <stdlib.h>

void	send_char(int pid, unsigned char c);
void	signal_handler(int siggi, siginfo_t *info, void *ERROR_MSG);
char 	*parsing(char *msg, char **args);
char	*ft_inputjoin(char const *s1, char const *s2);
char	*get_words(char **matrix);
char 	*parsing(char *msg, char **args);
char	*add_to_string(char *str, char c);

#endif