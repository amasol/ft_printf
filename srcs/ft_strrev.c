/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 11:55:19 by amasol            #+#    #+#             */
/*   Updated: 2018/08/29 11:55:20 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_strrev(const char *s)
{
	int		len;
	int		i;
	char	*result;

	len = ft_strlen(s);
	i = 0;
	if (!(result = (char *)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (len--)
		result[i++] = s[len];
	result[i] = '\0';
	return (result);
}