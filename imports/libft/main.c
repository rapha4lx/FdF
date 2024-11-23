/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferro-d <rferro-d@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:45:28 by rferro-d          #+#    #+#             */
/*   Updated: 2024/09/26 15:52:32 by rferro-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[100] = "Learningisfun";
    	char *first, *second;
    	first = str;
    	second = str;
    	printf("Original string :%s\n ", str);
     
    // when overlap happens then it just ignore it
    	memcpy(first + 8, first, 10);
    	printf("memcpy overlap : %s\n ", str);
 
    	// when overlap it start from first position
    	memmove(second + 8, first, 10);
    	printf("memmove overlap : %s\n ", str);	
	return (SUCCESS);
}
