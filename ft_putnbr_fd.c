/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:51:21 by rteles            #+#    #+#             */
/*   Updated: 2021/11/16 23:14:36 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	a = ' ';
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n > -2147483648 && n < 0)
	{
		a = '-';
		write(fd, &a, 1);
		ft_putnbr_fd(n *= -1, fd);
	}
	else if (n < 10)
	{
		a = n + '0';
		write(fd, &a, 1);
	}
	else if (n > -2147483648 && n <= 2147483647)
	{
		a = (n % 10) + '0';
		ft_putnbr_fd(n /= 10, fd);
		write(fd, &a, 1);
	}
}
