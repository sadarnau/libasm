#include <libasm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

# define STRLEN(x)			printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));

int		ft_strlen(char const *str);

int		main(void)
{
	printf("\n---------------------------ft_strlen---------------------------\n\n");
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "test", (int)strlen("test"), ft_strlen("test"));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "", (int)strlen(""), ft_strlen(""));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "0123456789", (int)strlen("0123456789"), ft_strlen("0123456789"));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "-1", (int)strlen("-1"), ft_strlen("-1"));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "My name is Sam", (int)strlen("My name is Sam"), ft_strlen("My name is Sam"));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "       ", (int)strlen("       "), ft_strlen("       "));
	printf("\n------------------------End of ft_strlen------------------------\n\n\n");


	char buf[100];
	printf("\n---------------------------ft_strcpy---------------------------\n\n");
	printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n\n", "test", strcpy(buf, "test"), ft_strcpy(buf, "test"));
	printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n\n", "(enpty)", strcpy(buf, ""), ft_strcpy(buf, ""));
	printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n\n", "0123456789", strcpy(buf, "0123456789"), ft_strcpy(buf, "0123456789"));
	printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n\n", "My name is Sam", strcpy(buf, "My name is Sam"), ft_strcpy(buf, "My name is Sam"));
	printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n\n", "    ", strcpy(buf, "    "), ft_strcpy(buf, "    "));
	printf("\n------------------------End of ft_strcpy------------------------\n\n\n");


	printf("\n---------------------------ft_strcmp---------------------------\n\n");
	printf("\033[0;31m\"%s\" \"%s\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n\n", "test", "test", strcmp("test", "test"), ft_strcmp("test", "test"));
	printf("\033[0;31m\"\" \"%s\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n\n", "test", strcmp("", "test"), ft_strcmp("", "test"));
	printf("\033[0;31m\"%s\" \"\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n\n", "test", strcmp("test", ""), ft_strcmp("test", ""));
	printf("\033[0;31m\"%s\" \"%s\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n\n", "abcdef123", "abcdef23", strcmp("abcdef123", "abcdef23"), ft_strcmp("abcdef123", "abcdef23"));
	printf("\033[0;31m\"%s\" \"%s\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n\n", "test1", "test", strcmp("test1", "test"), ft_strcmp("test1", "test"));	
	printf("\n------------------------End of ft_strcmp------------------------\n\n\n");

	printf("\n----------------------------ft_write----------------------------\n\n");
	printf("\033[0;31mwrite of \"%s\" in fd = 1 and byte = 4\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%d\033[0m\n\n", "123\\n", write(1, "123\n", 4), ft_write(1, "123\n", 4));	
	printf(" : \033[0;31mwrite of \"%s\" in fd = 1 and byte = 3\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%d\033[0m\n\n", "12 ", write(1, "12 ", 3), ft_write(1, "12 ", 3));	
	printf(" : \033[0;31mwrite of \"%s\" in fd = 1 and byte = 1\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%d\033[0m\n\n", "123456789", write(1, "123456789", 1), ft_write(1, "123456789", 1));	
	printf("\033[0;31mwrite of \"%s\" in fd = 42 and byte = 10\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%d\033[0m\n\n", "abcde", write(42, "abcde", 10), ft_write(42, "abcde", 10));	
	printf("\033[0;31mwrite of \"%s\" in fd = 1 and byte = 0\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%d\033[0m\n", "123", write(1, "123", 0), ft_write(1, "123", 0));	
	printf("\n-------------------------End of ft_write-------------------------\n\n\n");

	char bufb[27];
	int	fd = open("readTest", O_RDONLY);
	printf("\n----------------------------ft_read----------------------------\n\n");
	printf("\033[0;31mread of 6 in readTest\033[0m : read = \033[0;32m\%zd\033[0m\n", read(fd, bufb, 6));	
	printf("%s\n", bufb);
	close(fd);
	fd = open("readTest", O_RDONLY);
	printf("\033[0;31mread of 6 in readTest\033[0m : ft_read = \033[0;32m\%d\033[0m\n", ft_read(fd, bufb, 6));	
	printf("%s\n\n", bufb);
	close(fd);
	fd = open("readTest", O_RDONLY);
	printf("\033[0;31mread of 1000 in readTest\033[0m : read = \033[0;32m\%zd\033[0m\n", read(fd, bufb, 1000));	
	printf("%s\n", bufb);
	close(fd);
	fd = open("readTest", O_RDONLY);
	printf("\033[0;31mread of 1000 in readTest\033[0m : ft_read = \033[0;32m\%d\033[0m\n", ft_read(fd, bufb, 1000));	
	printf("%s\n\n", bufb);
	close(fd);
	printf("\033[0;31mread of 10 in fd = 42 (wrong fd)\033[0m : read = \033[0;32m\%zd\033[0m and ft_read = \033[0;32m\%d\033[0m\n\n", read(42, bufb, 10), ft_read(42, bufb, 10));	
	fd = open("readTest", O_RDONLY);
	printf("\033[0;31mread of 0 in readTest\033[0m : read = \033[0;32m\%zd\033[0m and ft_read = \033[0;32m\%d\033[0m\n", read(fd, bufb, 0), ft_read(fd, bufb, 0));		
	printf("\n-------------------------End of ft_read-------------------------\n\n\n");

	char *tmp, *ft_tmp;
	printf("\n----------------------------ft_strdup----------------------------\n\n");
	printf("\033[0;31m          str = %s\033[0m\n       strdup = %s\nand ft_strdup = %s\n\n", "123456789", tmp = strdup("123456789"), ft_tmp = ft_strdup("123456789"));
	free (tmp);
	free(ft_tmp);
	printf("\033[0;31m          str = \"\"\033[0m\n       strdup = %s\nand ft_strdup = %s\n\n",tmp = strdup(""), ft_tmp = ft_strdup(""));
	free (tmp);
	free(ft_tmp);
	printf("\033[0;31m          str = %s\033[0m\n       strdup = %s\nand ft_strdup = %s\n", "No idea on how to test this...", tmp = strdup("No idea on how to test this..."), ft_tmp = ft_strdup("No idea on how to test this..."));
	free (tmp);
	free(ft_tmp);
	printf("\n-------------------------End of ft_strdup-------------------------\n\n\n");

	return (0);
}