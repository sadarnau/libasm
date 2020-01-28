#include <libasm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


# define STRLEN(x)			printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));

int		ft_strlen(char const *str);

int		main(void)
{
	// printf("\n------------------------ft_strlen------------------------\n\n");
	// printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n", "test", (int)strlen("test"), ft_strlen("test"));
	// printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n", "", (int)strlen(""), ft_strlen(""));
	// printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n", "0123456789", (int)strlen("0123456789"), ft_strlen("0123456789"));
	// printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n", "-1", (int)strlen("-1"), ft_strlen("-1"));
	// printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n", "My name is Sam", (int)strlen("My name is Sam"), ft_strlen("My name is Sam"));
	// printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n", "       ", (int)strlen("       "), ft_strlen("       "));
	// printf("\n---------------------End of ft_strlen---------------------\n\n\n");


	// char buf[100];
	// printf("\n------------------------ft_strcpy------------------------\n\n");
	// printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n", "test", strcpy(buf, "test"), ft_strcpy(buf, "test"));
	// printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n", "(enpty)", strcpy(buf, ""), ft_strcpy(buf, ""));
	// printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n", "0123456789", strcpy(buf, "0123456789"), ft_strcpy(buf, "0123456789"));
	// printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n", "My name is Sam", strcpy(buf, "My name is Sam"), ft_strcpy(buf, "My name is Sam"));
	// printf("\033[0;31m\"%s\"\033[0m : strcpy = \033[0;32m\%s\033[0m and ft_strcpy = \033[0;32m\%s\033[0m\n", "    ", strcpy(buf, "    "), ft_strcpy(buf, "    "));
	// printf("\n---------------------End of ft_strcpy---------------------\n\n\n");


	// printf("\n------------------------ft_strcmp------------------------\n\n");
	// printf("\033[0;31m\"%s\" \"%s\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n", "test", "test", strcmp("test", "test"), ft_strcmp("test", "test"));
	// printf("\033[0;31m\"\" \"%s\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n", "test", strcmp("", "test"), ft_strcmp("", "test"));
	// printf("\033[0;31m\"%s\" \"\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n", "test", strcmp("test", ""), ft_strcmp("test", ""));
	// printf("\033[0;31m\"%s\" \"%s\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n", "abcdef123", "abcdef23", strcmp("abcdef123", "abcdef23"), ft_strcmp("abcdef123", "abcdef23"));
	// printf("\033[0;31m\"%s\" \"%s\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n", "test1", "test", strcmp("test1", "test"), ft_strcmp("test1", "test"));	
	// printf("\n---------------------End of ft_strcmp---------------------\n\n\n");

	printf("%d\n", ft_write(1, "ab\n", 9));
	printf("%d\n", write(1, "ab\n", 9));

	return (0);
}