/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:16:52 by adoat             #+#    #+#             */
/*   Updated: 2018/09/03 18:27:59 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr[10];
	int		i;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	i = 10;
	while (n >= 0)
	{
		nbr[--i] = n % 10;
		n = (n - (n % 10)) / 10;
		if (n == 0)
			break ;
	}
	while (i < 10)
		ft_putchar_fd(nbr[++i - 1] + 48, fd);
	return ;
}
