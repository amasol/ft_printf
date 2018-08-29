/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:09:44 by amasol            #+#    #+#             */
/*   Updated: 2017/11/11 19:22:44 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		k;
	int		i;

	i = 0;
	k = 0;
	while (src[k] != '\0')
		k++;
	str = (char*)malloc(sizeof(*str) * (k) + 1);
	if (str == NULL)
		return (NULL);
	while (i < k)
	{
		str[i] = src[i];
		i++;
	}
	str[k] = '\0';
	return (str);
}
