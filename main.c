/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarde <bgarde@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:55:35 by bgarde            #+#    #+#             */
/*   Updated: 2025/11/18 09:34:44 by bgarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO CE FICHIER NE DOIT PAS ETRE PUSH

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//########################## IS

void	comp_is(int v1, int	v2)
{
	if ((v1 > 0 && v2 > 0) || (v1 == 0 && v2 == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : %d, %d]""\x1b[0m"" ", v1, v2);
}

void	test_is(char *fname, int (*f)(int), int (*of)(int))
{
	printf("%s | ", fname);
	int i = 0;
	while (i <= 200)
	{
		comp_is(f(i), of(i));
		i++;
	}
	printf("\n\n");
}

//########################## STRLEN

void	comp_strlen(char *str)
{
	size_t	v1 = ft_strlen(str);
	size_t	v2 = strlen(str);

	if (v1 == v2)
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : %zu, %zu]""\x1b[0m"" ", v1, v2);
}

void	test_strlen()
{
	printf("strlen | ");
	comp_strlen("hello \0 hello");
	comp_strlen("\a\b\t\n\v\f\r");
	comp_strlen("hellooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
	comp_strlen("\0");
	printf("\n\n");
}

//########################## MEMSET

void	comp_memset(char *str, int c, size_t size)
{
	char	*tmp1 = strdup(str);
	char	*tmp2 = strdup(str);

	char	*v1 = (char *)ft_memset(tmp1, c, size);
	char	*v2 = (char *)memset(tmp2, c, size);
	
	if (((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0)))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : %s, %s]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_memset()
{
	printf("memset | ");
	comp_memset("hello", 'P', 3);
	comp_memset("\0", 'P', 5);
	comp_memset("helloooooooooooo", '\0', 3);
	comp_memset("hello", 'A', 10);
	comp_memset("hello", '\0', 10);
	comp_memset("hel\0lo", 'A', 10);
	comp_memset("aaaaa\0aaaaaaa", 'b', 3);
	comp_memset("\0", '\0', 3);
	printf("\n\n");
}

//########################## BZERO

void	comp_bzero(char *str, size_t size)
{
	char	*v1 = strdup(str);
	char	*v2 = strdup(str);

	ft_bzero(v1, size);
	bzero(v2, size);
	
	if (((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0)))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : %s, %s]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_bzero()
{
	printf("bzero | ");
	comp_bzero("hello", 3);
	comp_bzero("\0", 5);
	comp_bzero("helloooooooooooo", 3);
	comp_bzero("hello", 10);
	comp_bzero("hello", 10);
	comp_bzero("hel\0lo", 10);
	comp_bzero("aaaaa\0aaaaaaa", 3);
	comp_bzero("\0", 3);
	printf("\n\n");
}

//########################## MEMCPY

void	comp_memcpy(void *dest, const void *src, size_t size)
{
	char	*tmp1 = strdup(dest);
	char	*tmp2 = strdup(dest);

	char	*v1 = (char *)ft_memcpy(tmp1, src, size);
	char	*v2 = (char *)memcpy(tmp2, src, size);
	
	if (((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
		&& ((tmp1 == NULL && tmp2 == NULL) || (tmp1 != NULL && tmp2 != NULL && strcmp(tmp1, tmp2) == 0)))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s ), ( %s , %s )]""\x1b[0m"" ", v1, v2, tmp1, tmp2);
	free(v1);
	free(v2);
}

void	test_memcpy()
{
	printf("memset | ");
	comp_memcpy("hello", "HELOOOO", 3);
	comp_memcpy("\0", "P", 5);
	comp_memcpy("helloooooooooooo", "\0", 3);
	comp_memcpy("hello", "A\0A", 10);
	comp_memcpy("h\0ello", "\0", 10);
	comp_memcpy("hello", "bye", 3);
	comp_memcpy("aaaaa\0aaaaaaa", "b", 3);
	comp_memcpy("\0\0\0\0", "\0\0\0\0", 20);
	comp_memcpy("\0\0\0\0", "A", 3);
	printf("\n\n");
}

//########################## MEMMOVE

void	comp_memmove(void *dest, const void *src, size_t size)
{
	char	*tmp1 = strdup(dest);
	char	*tmp2 = strdup(dest);

	char	*v1 = (char *)ft_memmove(tmp1, src, size);
	char	*v2 = (char *)memmove(tmp2, src, size);
	
	if (((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
		&& ((tmp1 == NULL && tmp2 == NULL) || (tmp1 != NULL && tmp2 != NULL && strcmp(tmp1, tmp2) == 0)))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s ), ( %s , %s )]""\x1b[0m"" ", v1, v2, tmp1, tmp2);
	free(v1);
	free(v2);
}

void	test_memmove()
{
	printf("memmove | ");
	comp_memmove("hello", "HELOOOO", 3);
	comp_memmove("\0", "P", 5);
	comp_memmove("helloooooooooooo", "\0", 3);
	comp_memmove("hello", "A\0A", 10);
	comp_memmove("h\0ello", "\0", 10);
	comp_memmove("hello", "bye", 3);
	comp_memmove("aaaaa\0aaaaaaa", "b", 3);
	comp_memmove("\0\0\0\0", "\0\0\0\0", 20);
	comp_memmove("\0\0\0\0", "A", 3);
	printf("\n\n");
}

//########################## STRLCPY

void	comp_strlcpy(void *dest, const void *src, size_t size)
{
	char	*tmp1 = strdup(dest);
	char	*tmp2 = strdup(dest);

	size_t	v1 = ft_strlcpy(tmp1, src, size);
	size_t	v2 = strlcpy(tmp2, src, size);
	
	if (v1 == v2 && ((tmp1 == NULL && tmp2 == NULL) || (tmp1 != NULL && tmp2 != NULL && strcmp(tmp1, tmp2) == 0)))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(tmp1);
		free(tmp2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %zu , %zu ), ( %s , %s )]""\x1b[0m"" ", v1, v2, tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

void	test_strlcpy()
{
	printf("strlcpy | ");
	comp_strlcpy("hello", "HELOOOO", 3);
	comp_strlcpy("\0", "P", 5);
	comp_strlcpy("helloooooooooooo", "\0", 3);
	comp_strlcpy("hello", "A\0A", 10);
	comp_strlcpy("h\0ello", "\0", 10);
	comp_strlcpy("hello", "bye", 3);
	comp_strlcpy("aaaaa\0aaaaaaa", "b", 3);
	comp_strlcpy("\0\0\0\0", "\0\0\0\0", 20);
	comp_strlcpy("\0\0\0\0", "A", 3);
	printf("\n\n");
}

//########################## STRLCAT

void	comp_strlcat(void *dest, const void *src, size_t size)
{
	char	*tmp1 = strdup(dest);
	char	*tmp2 = strdup(dest);

	size_t	v1 = ft_strlcat(tmp1, src, size);
	size_t	v2 = strlcat(tmp2, src, size);
	
	if (v1 == v2 && ((tmp1 == NULL && tmp2 == NULL) || (tmp1 != NULL && tmp2 != NULL && strcmp(tmp1, tmp2) == 0)))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(tmp1);
		free(tmp2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %zu , %zu ), ( %s , %s )]""\x1b[0m"" ", v1, v2, tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

void	test_strlcat()
{
	printf("strlcat | ");
	comp_strlcat("hello", "HELOOOO", 3);
	comp_strlcat("\0", "P", 5);
	comp_strlcat("helloooooooooooo", "\0", 3);
	comp_strlcat("hello", "A\0A", 10);
	comp_strlcat("h\0ello", "\0", 10);
	comp_strlcat("hello", "bye", 3);
	comp_strlcat("aaaaa\0aaaaaaa", "b", 3);
	comp_strlcat("\0\0\0\0", "\0\0\0\0", 20);
	comp_strlcat("\0\0\0\0", "A", 3);
	printf("\n\n");
}

//########################## TOUPPER

void	comp_toupper(int c)
{
	int	v1 = ft_toupper(c);
	int	v2 = toupper(c);
	
	if (v1 == v2)
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : %d , %d]""\x1b[0m"" ", v1, v2);
}

void	test_toupper()
{
	int	i = 0;
	printf("toupper | ");
	while (i < 200)
	{
		comp_toupper(i);
		i++;
	}
	printf("\n\n");
}

//########################## TOLOWER

void	comp_tolower(int c)
{
	int	v1 = ft_tolower(c);
	int	v2 = tolower(c);
	
	if (v1 == v2)
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : %d , %d]""\x1b[0m"" ", v1, v2);
}

void	test_tolower()
{
	int	i = 0;
	printf("tolower | ");
	while (i < 200)
	{
		comp_toupper(i);
		i++;
	}
	printf("\n\n");
}

//########################## STRCHR

void	comp_strchr(const char *str, int c)
{
	char	*v1 = ft_strchr(str, c);
	char	*v2 = strchr(str, c);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : %s , %s]""\x1b[0m"" ", v1, v2);
}

void	test_strchr()
{
	printf("strchr | ");
	comp_strchr("hello", '\0');
	comp_strchr("\0", 'P');
	comp_strchr("helloooooooooooo", 'o');
	comp_strchr("hello", 0);
	comp_strchr("h\0ello", 0);
	comp_strchr("aaaaa\0aaaaaaa", 'b');
	comp_strchr("\0\0\0\0", '\0');
	comp_strchr("\0\0\0\0", 'A');
	printf("\n\n");
}

//########################## STRRCHR

void	comp_strrchr(const char *str, int c)
{
	char	*v1 = ft_strrchr(str, c);
	char	*v2 = strrchr(str, c);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : %s , %s]""\x1b[0m"" ", v1, v2);
}

void	test_strrchr()
{
	printf("strrchr | ");
	comp_strrchr("hello", '\0');
	comp_strrchr("\0", 'P');
	comp_strrchr("helloooooooooooo", 'o');
	comp_strrchr("hello", 0);
	comp_strrchr("h\0ello", 0);
	comp_strrchr("aaaaa\0aaaaaaa", 'b');
	comp_strrchr("\0\0\0\0", '\0');
	comp_strrchr("\0\0\0\0", 'A');
	printf("\n\n");
}

//########################## STRNCMP

void	comp_strncmp(const char *s1, const char *s2, size_t n)
{
	int	v1 = ft_strncmp(s1, s2, n);
	int	v2 = strncmp(s1, s2, n);
	
	if (v1 == v2 || (v1 > 0 && v2 > 0) || (v1 < 0 && v2 < 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : %d , %d]""\x1b[0m"" ", v1, v2);
}

void	test_strncmp()
{
	printf("strncmp | ");
	comp_strncmp("hello", "hello", 50);
	comp_strncmp("hello", "HELOOOO", 3);
	comp_strncmp("\0", "P", 5);
	comp_strncmp("helloooooooooooo", "\0", 3);
	comp_strncmp("hello", "A\0A", 10);
	comp_strncmp("h\0ello", "\0", 10);
	comp_strncmp("hello", "bye", 3);
	comp_strncmp("aaaaa\0aaaaaaa", "b", 3);
	comp_strncmp("\0\0\0\0", "\0\0\0\0", 20);
	comp_strncmp("\0\0\0\0", "A", 3);
	printf("\n\n");
}

//########################## MEMCHR

void	comp_memchr(const void *src, int c, size_t size)
{
	char	*tmp1 = strdup(src);
	char	*tmp2 = strdup(src);

	char	*v1 = (char *)ft_memchr(tmp1, c, size);
	char	*v2 = (char *)memchr(tmp2, c, size);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(tmp1);
		free(tmp2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(tmp1);
	free(tmp2);
}

void	test_memchr()
{
	printf("memchr | ");
	comp_memchr("hello", 'H', 3);
	comp_memchr("\0", 'P', 5);
	comp_memchr("helloooooooooooo", '\0', 3);
	comp_memchr("hello", 'a', 10);
	comp_memchr("h\0ello", '\0', 10);
	comp_memchr("hello", 'h', 3);
	comp_memchr("aaaaa\0aaaaaaa", 'a', 3);
	comp_memchr("\0\0\0\0", '\0', 20);
	comp_memchr("\0\0\0\0", 'A', 3);
	printf("\n\n");
}

//########################## MEMCMP

void	comp_memcmp(const void *s1, const void *s2, size_t n)
{
	int	v1 = ft_memcmp(s1, s2, n);
	int	v2 = memcmp(s1, s2, n);
	
	if (v1 == v2)
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : ( %d , %d )]""\x1b[0m"" ", v1, v2);
}

void	test_memcmp()
{
	printf("memcmp | ");
	comp_memcmp("hello", "hello", 50);
	comp_memcmp("hello", "HELOOOO", 3);
	comp_memcmp("\0", "P", 5);
	comp_memcmp("helloooooooooooo", "\0", 3);
	comp_memcmp("hello", "A\0A", 10);
	comp_memcmp("h\0ello", "\0", 10);
	comp_memcmp("hello", "bye", 3);
	comp_memcmp("aaaaa\0aaaaaaa", "b", 3);
	comp_memcmp("\0\0\0\0", "\0\0\0\0", 20);
	comp_memcmp("\0\0\0\0", "A", 3);
	printf("\n\n");
}

//########################## STRNSTR

void	comp_strnstr(const void *s1, const void *s2, size_t n)
{
	char	*v1 = ft_strnstr(s1, s2, n);
	char	*v2 = strnstr(s1, s2, n);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
}

void	test_strnstr()
{
	printf("strnstr | ");
	comp_strnstr("hello", "hello", 50);
	comp_strnstr("hello", "HELOOOO", 3);
	comp_strnstr("\0", "P", 5);
	comp_strnstr("helloooooooooooo", "\0", 3);
	comp_strnstr("hello", "A\0A", 10);
	comp_strnstr("h\0ello", "\0", 10);
	comp_strnstr("hello", "bye", 3);
	comp_strnstr("aaaaa\0aaaaaaa", "b", 3);
	comp_strnstr("\0\0\0\0", "\0\0\0\0", 20);
	comp_strnstr("\0\0\0\0", "A", 3);
	printf("\n\n");
}

//########################## ATOI

void	comp_atoi(const char *s)
{
	int	v1 = ft_atoi(s);
	int	v2 = atoi(s);
	
	if (v1 == v2)
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		return ;
	}
	printf("\x1b[31m""[KO : ( %d , %d )]""\x1b[0m"" ", v1, v2);
}

void	test_atoi()
{
	printf("atoi | ");
	comp_atoi("\0");
	comp_atoi("     54648");
	comp_atoi("    + asdasd5546");
	comp_atoi("\0 asdsadasd+dsasdad56445-54");
	comp_atoi("0");
	comp_atoi("2147483647");
	comp_atoi("-2147483648");
	comp_atoi("21474836470");
	comp_atoi("-21474836480");
	comp_atoi("-54");
	comp_atoi("13");
	comp_atoi("+5646");
	comp_atoi("--54654");
	comp_atoi("++");
	comp_atoi("--");
	comp_atoi("+-");
	comp_atoi("         -         35456");
	comp_atoi("dasasdsadasd");
	comp_atoi("         0 dassada2354-6");
	comp_atoi("   +  5646");
	comp_atoi("  -  5 55");
	comp_atoi("-+54");
	comp_atoi("       -56");
	printf("\n\n");
}

//########################## CALLOC

void	comp_calloc(size_t nmemb, size_t size)
{
	char	*v1 = (char *)ft_calloc(nmemb, size);
	char	*v2 = (char *)calloc(nmemb, size);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && memcmp(v1, v2, nmemb * size) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_calloc()
{
	printf("calloc | ");
	comp_calloc(0 ,0);
	comp_calloc(100 ,20);
	comp_calloc(10 ,0);
	comp_calloc(0 ,10);
	comp_calloc(5 ,5);
	printf("\n\n");
}

//########################## STRDUP

void	comp_strdup(const char *str)
{
	char	*v1 = ft_strdup(str);
	char	*v2 = strdup(str);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_strdup()
{
	printf("strdup | ");
	comp_strdup("\0");
	comp_strdup("une dup");
	comp_strdup("hell\0ooooo");
	comp_strdup("\0\0\0\0\0\0\0");
	printf("\n\n");
}

//########################## SUBSTR

void	comp_substr(const char *s, unsigned int start, size_t len, const char *res)
{
	char	*v1 = ft_substr(s, start, len);
	char	*v2 = strdup(res);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_substr()
{
	printf("substr | ");
	comp_substr("hello world", 3, 5, "lo wo");
	comp_substr("\0\0a\0\0", 2, 2, "");
	printf("\n\n");
}

//########################## STRJOIN

void	comp_strjoin(const char *s1, const char *s2, const char *res)
{
	char	*v1 = ft_strjoin(s1, s2);
	char	*v2 = strdup(res);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_strjoin()
{
	printf("strjoin | ");
	comp_strjoin("hello", "world", "helloworld");
	comp_strjoin("\0\0a", "\0\0b",  "\0\0a\0\0b");
	comp_strjoin("aaaaaaaaaaaaaaaaa", "bbbbbbbbbbbbbbbbbbbbb",  "aaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbb");
	printf("\n\n");
}

//########################## STRTRIM

void	comp_strtrim(const char *s1, const char *s2, const char *res)
{
	char	*v1 = ft_strtrim(s1, s2);
	char	*v2 = strdup(res);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_strtrim()
{
	printf("strtrim | ");
	comp_strtrim("hello", "world", "he");
	comp_strtrim("\0\0a", "\0\0b",  "");
	comp_strtrim("aaaaaaaaaaaaaaaaa", "bbbbbbbbbbbbbbbbbbbbb",  "aaaaaaaaaaaaaaaaa");
	comp_strtrim("salut comment ca va", " ",  "salut comment ca va");
	comp_strtrim("AAPPPAAAbououuouPPPA", "APb",  "ououuou");
	printf("\n\n");
}

//########################## SPLIT

void	split_free_all(char **list)
{
	size_t	i;

	if (list == NULL)
		return ;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	comp_split(const char *s1, char c, const char **res)
{
	int	isgood = 1;
	char	**v1 = ft_split(s1, c);

	int	i = 0;
	while (v1[i] != NULL)
	{
		if (strcmp(v1[i], res[i]))
		{
			isgood = 0;
			break;
		}
		i++;
	}
	
	if ((v1 == NULL && res == NULL) || (v1 != NULL && res != NULL && isgood == 1))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		split_free_all(v1);
		return ;
	}
	printf("\x1b[31m""[KO : ( ""\x1b[0m"" ");
	i = 0;
	while (v1[i] != NULL)
	{
		printf("\x1b[31m""%s|""\x1b[0m"" ", v1[i]);
		i++;
	}
	printf("\x1b[31m"" , ""\x1b[0m"" ");
	i = 0;
	while (res[i])
	{
		printf("\x1b[31m""%s|""\x1b[0m"" ", res[i]);
		i++;
	}
	printf("\x1b[31m"" )]""\x1b[0m"" ");
	split_free_all(v1);
}

void	test_split()
{
	printf("split | ");
	char *prop1[100] = {"he", "o", NULL};
	comp_split("hello", 'l', (const char **)prop1);
	char *prop2[100] = {"hell", NULL};
	comp_split("ooohellooo", 'o', (const char **)prop2);
	char *prop3[100] = {NULL};
	comp_split("", 'o', (const char **)prop3);
	char *prop4[100] = {"bonjour comment ca va", NULL};
	comp_split("bonjour comment ca va", '\0', (const char **)prop4);
	char *prop5[100] = {NULL};
	comp_split("\0\0\0\0\0", '\0', (const char **)prop5);
	char *prop6[100] = {"a", "a", NULL};
	comp_split("\0\0a\0\0a\0", '\0', (const char **)prop6);
	printf("\n\n");
}

//########################## ITOA

void	comp_itoa(int value, const char *res)
{
	char	*v1 = ft_itoa(value);
	char	*v2 = strdup(res);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_itoa()
{
	printf("itoa | ");
	comp_itoa(0, "0");
	comp_itoa(2147483647, "2147483647");
	comp_itoa(-2147483648, "-2147483648");
	comp_itoa(6874143, "6874143");
	comp_itoa(-545, "-545");
	printf("\n\n");
}

//########################## STRMAPI

char	f_strmapi(unsigned int i, char c)
{
	if (i < 5)
		return ('A');
	if (c == 'm')
		return ('2');
	return (c);
}

void	comp_strmapi(const char *s, const char *res)
{
	char	*v1 = ft_strmapi(s, &f_strmapi);
	char	*v2 = strdup(res);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_strmapi()
{
	printf("strmapi | ");
	comp_strmapi("0", "A");
	comp_strmapi("2147483647", "AAAAA83647");
	comp_strmapi("bonjour comment ca va", "AAAAAur co22ent ca va");
	comp_strmapi("\0\0\0\0\0\0", "");
	comp_strmapi("hell\0oooo", "AAAA");
	comp_strmapi("simple", "AAAAAe");
	comp_strmapi("     simple", "AAAAAsi2ple");
	printf("\n\n");
}

//########################## STRITERI

void	f_striteri(unsigned int i, char *c)
{
	if (i < 5)
		*c = 'A';
	if (*c == 'm')
		*c = '2';
}

void	comp_striteri(const char *s, const char *res)
{
	char	*v1 = strdup(s);
	char	*v2 = strdup(res);
	ft_striteri(v1, &f_striteri);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	free(v1);
	free(v2);
}

void	test_striteri()
{
	printf("striteri | ");
	comp_striteri("0", "A");
	comp_striteri("2147483647", "AAAAA83647");
	comp_striteri("bonjour comment ca va", "AAAAAur co22ent ca va");
	comp_striteri("\0\0\0\0\0\0", "");
	comp_striteri("hell\0oooo", "AAAA");
	comp_striteri("simple", "AAAAAe");
	comp_striteri("     simple", "AAAAAsi2ple");
	printf("\n\n");
}

//########################## PUTCHAR_FD
/*
void	comp_puchar_fd(const char s, const char *res)
{
	char	*v1 = (char *)malloc(sizeof(char) + 1);
	if (v1 == NULL)
		return ;
	char	*v2 = strdup(res);
	char fd = open("test_file", O_WRONLY);
	if (fd < 0)
	{
		printf("\x1b[31m""[ERROR]""\x1b[0m"" ");
		return ;
	}

	ft_putchar_fd(s, fd);
	close(fd);

	fd = open("test_file", O_WRONLY);
	if (fd < 0)
	{
		printf("\x1b[31m""[ERROR]""\x1b[0m"" ");
		return ;
	}
	read(fd, v1, 1);
	
	if ((v1 == NULL && v2 == NULL) || (v1 != NULL && v2 != NULL && strcmp(v1, v2) == 0))
	{
		printf("\x1B[32m" "[OK]" "\x1b[0m"" ");
		close(fd);
		free(v1);
		free(v2);
		return ;
	}
	printf("\x1b[31m""[KO : ( %s , %s )]""\x1b[0m"" ", v1, v2);
	close(fd);
	free(v1);
	free(v2);
}

void	test_puchar_fd()
{
	printf("puchar_fd | ");
	comp_puchar_fd('A', "A");
	comp_puchar_fd('\0', "\0");
	comp_puchar_fd('1', "1");
	comp_puchar_fd('c', "c");
	printf("\n\n");
}
*/
//##########################

int	main(void)
{
	printf("\n""\x1b[31m""La babinette""\x1b[0m""\n\n");
	test_is("isalpha", ft_isalpha, isalpha);
	test_is("isdigit", ft_isdigit, isdigit);
	test_is("isalnum", ft_isalnum, isalnum);
	test_is("isascii", ft_isascii, ft_isascii); //comparaison bancale
	test_is("isprint", ft_isprint, isprint);
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	//test_puchar_fd();
}