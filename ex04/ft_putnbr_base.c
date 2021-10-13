/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:13:41 by coder             #+#    #+#             */
/*   Updated: 2021/10/14 01:21:51 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count ++;
	return (count);
}

int	ft_check(char *str)
{
	int	i_count;
	int	o_count;
	int	flag;

	o_count = 0;
	flag = 0;
	while (str[o_count] != '\0' && flag == 0)
	{
		i_count = 0;
		if (str[o_count] == '-' || str[o_count] == '+')
			flag ++;
		while (str[i_count] != '\0' && flag == 0)
		{
			if (i_count != o_count && str[i_count] == str[o_count])
				flag ++;
			i_count ++;
		}
		o_count ++;
	}
	return (flag);
}

void	ft_pos_comput(int num, char *base, int val)
{
	int	div;
	int	mod;

	if (num > 0)
	{
		div = num / val;
		ft_pos_comput(div, base, val);
		mod = num % val;
		write(1, &base[mod], 1);
	}
}

void	ft_neg_check(int num, char *base, int val)
{
	if (num < val && num >= 0)
	{
		write(1, &base[num / val], 1);
		write(1, &base[num % val], 1);
	}
	else
		ft_pos_comput(num, base, val);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n_base;

	n_base = ft_strlen(base);
	if (n_base < 2 || ft_check(base) > 0)
		return ;
	else if (nbr == 0)
		write(1, &base[nbr], 1);
	else if (nbr < n_base && nbr > 0)
	{
		write(1, &base[nbr / n_base], 1);
		write(1, &base[nbr % n_base], 1);
	}
	else if (nbr > 0)
		ft_pos_comput(nbr, base, n_base);
	else
	{
		nbr *= -1;
		write(1, "-", 1);
		ft_neg_check(nbr, base, n_base);
	}
}

// int	main(void)
// {
// 	int		num;
// 	char	str[] = "0123456789abcdef";

// 	num = 5763;
// 	ft_putnbr_base(num, str);
// 	return (0);
// }
