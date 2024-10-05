/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkutilko <zkutilko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:49:14 by zkutilko          #+#    #+#             */
/*   Updated: 2024/10/02 21:53:44 by zkutilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL) // Pokud je s1 NULL, vrátíme pouze s2
		return (ft_strdup(s2)); // Použijeme ft_strdup, abychom duplikovali s2
	if (s2 == NULL) // Pokud je s2 NULL, vrátíme s1
		return (ft_strdup(s1)); // Použijeme ft_strdup, abychom duplikovali s1

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);

	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char str1[] = "Hello";
// 	char str2[] = "thereasdasdas";
// 	char *c;

// 	c = ft_strjoin(str1, str2);
// 	free(c);
// 	printf("%s", c);
// }
