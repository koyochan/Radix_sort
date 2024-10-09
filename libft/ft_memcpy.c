/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:14:28 by kotkobay          #+#    #+#             */
/*   Updated: 2023/10/04 14:18:12 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (src == NULL && dst == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}

/* #include <stdio.h>
#include <string.h>

// ft_memcpyのプロトタイプ宣言
void	*ft_memcpy(void *dst, const void *src, size_t n);

int	main(void)
{
	char src1[50] = "Hello, world!";
	char dst1[50];
	char src2[50] = "Hello, world!";
	char dst2[50];

	ft_memcpy(dst1, src1, 13);
	memcpy(dst2, src2, 13);

	if (memcmp(dst1, dst2, 13) == 0)
	{
		printf("Test1 passed.\n");
	}
	else
	{
		printf("Test1 failed.\n");
	}

	// ゼロバイトのテスト
	ft_memcpy(dst1, src1, 0);
	memcpy(dst2, src2, 0);

	if (memcmp(dst1, dst2, 0) == 0)
	{
		printf("Test2 passed.\n");
	}
	else
	{
		printf("Test2 failed.\n");
	}

	// バイナリデータのテスト
	unsigned char binary_src1[5] = {0x00, 0xFF, 0x00, 0xFF, 0x00};
	unsigned char binary_dst1[5];
	unsigned char binary_src2[5] = {0x00, 0xFF, 0x00, 0xFF, 0x00};
	unsigned char binary_dst2[5];

	ft_memcpy(binary_dst1, binary_src1, 5);
	memcpy(binary_dst2, binary_src2, 5);

	if (memcmp(binary_dst1, binary_dst2, 5) == 0)
	{
		printf("Test3 passed.\n");
	}
	else
	{
		printf("Test3 failed.\n");
	}

	return (0);
} */