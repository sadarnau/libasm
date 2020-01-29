#include "libasm.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BUFFER_SIZE 512

void print_list(t_list *list)
{
	int i = 0;

	while (list)
	{
		printf("%d : %s\n", i, list->data);
		list = list->next;
		i++;
	}
}

int		strlen_test(char *str)
{
	int 	ret1;
	int 	ret2;

	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	//printf("strlen : %d / ft_strlen : %d\n", ret1, ret2);
	if (ret1 == ret2)
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	return (1);
}

int		strcpy_test(char *src)
{
	char	dest1[BUFFER_SIZE];
	char	dest2[BUFFER_SIZE];

	bzero(dest1, BUFFER_SIZE);
	bzero(dest2, BUFFER_SIZE);
	ft_strcpy(dest1, src);
	strcpy(dest2, src);
	if (!strcmp(dest1, dest2))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	return (1);
}

int		strcmp_test(char *s1, char *s2)
{
	int 	ret1;
	int 	ret2;

	ret1 = ft_strcmp(s1, s2);
	ret2 = strcmp(s1, s2);
	//printf("strcmp : %d / ft_strcmp : %d\n", ret1, ret2);
	if ((ret1 > 0 && ret2 > 0) || (ret1 < 0 && ret2 < 0) || (ret1 == 0 && ret2 == 0))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	return (1);
}

int		write_test(char *str)
{
	int		ft_write_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_write_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_write_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_write_pipe[1], str, strlen(str));
	ret = read(ft_write_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';

	if (!strcmp(buf, str))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	close(ft_write_pipe[1]);
	close(ft_write_pipe[0]);
	return (1);
}

int		read_test(char *str)
{
	int		ft_read_pipe[2];
	char	buf[BUFFER_SIZE];
	int		ret;

	bzero(buf, BUFFER_SIZE);
	if (pipe(ft_read_pipe) < 0)
		exit(EXIT_FAILURE);
	fcntl(ft_read_pipe[0], F_SETFL, O_NONBLOCK);
	write(ft_read_pipe[1], str, strlen(str));
	ret = ft_read(ft_read_pipe[0], buf, BUFFER_SIZE);
	buf[ret] = '\0';

	if (!strcmp(buf, str))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	close(ft_read_pipe[1]);
	close(ft_read_pipe[0]);
	return (1);
}

int		strdup_test(char *str)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup(str);
	str2 = strdup(str);
	if (!strcmp(str1, str2))
		printf("" GREEN "[OK] " RESET "");
	else
		printf("" RED "[KO] " RESET "");
	free(str1);
	free(str2);
	return (1);
}

int		main(void)
{

	printf("\033[0;31m\"%s\" \"\"\033[0m : strcmp = \033[0;32m\%d\033[0m and ft_strcmp = \033[0;32m\%d\033[0m\n\n", "test", strcmp("\xff", "\xff\xff"), ft_strcmp("\xff", "\xff\xff"));


	printf("\n---------------------------ft_strlen---------------------------\n\n");
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "test", (int)strlen("test"), (int)ft_strlen("test"));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "", (int)strlen(""), (int)ft_strlen(""));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "0123456789", (int)strlen("0123456789"), (int)ft_strlen("0123456789"));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "-1", (int)strlen("-1"), (int)ft_strlen("-1"));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "My name is Sam", (int)strlen("My name is Sam"), (int)ft_strlen("My name is Sam"));
	printf("\033[0;31m\"%s\"\033[0m : strlen = \033[0;32m\%d\033[0m and ft_strlen = \033[0;32m\%d\033[0m\n\n", "       ", (int)strlen("       "), (int)ft_strlen("       "));
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
	printf("\033[0;31mwrite of \"%s\" in fd = 1 and byte = 4\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%zd\033[0m\n\n", "123\\n", write(1, "123\n", 4), ft_write(1, "123\n", 4));	
	printf(" : \033[0;31mwrite of \"%s\" in fd = 1 and byte = 3\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%zd\033[0m\n\n", "12 ", write(1, "12 ", 3), ft_write(1, "12 ", 3));	
	printf(" : \033[0;31mwrite of \"%s\" in fd = 1 and byte = 1\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%zd\033[0m\n\n", "123456789", write(1, "123456789", 1), ft_write(1, "123456789", 1));	
	printf("\033[0;31mwrite of \"%s\" in fd = 42 and byte = 10\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%zd\033[0m\n\n", "abcde", write(42, "abcde", 10), ft_write(42, "abcde", 10));	
	printf("\033[0;31mwrite of \"%s\" in fd = 1 and byte = 0\033[0m : write = \033[0;32m\%zd\033[0m and ft_write = \033[0;32m\%zd\033[0m\n", "123", write(1, "123", 0), ft_write(1, "123", 0));	
	printf("\n-------------------------End of ft_write-------------------------\n\n\n");

	char bufb[28];
	int	fd = open("readTest", O_RDONLY);
	printf("\n----------------------------ft_read----------------------------\n\n");
	printf("\033[0;31mread of 6 in readTest\033[0m : read = \033[0;32m\%zd\033[0m\n", read(fd, bufb, 6));	
	printf("%s\n", bufb);
	close(fd);
	fd = open("readTest", O_RDONLY);
	printf("\033[0;31mread of 6 in readTest\033[0m : ft_read = \033[0;32m\%zd\033[0m\n", ft_read(fd, bufb, 6));	
	printf("%s\n\n", bufb);
	close(fd);
	fd = open("readTest", O_RDONLY);
	printf("\033[0;31mread of 1000 in readTest\033[0m : read = \033[0;32m\%zd\033[0m\n", read(fd, bufb, 1000));	
	printf("%s\n", bufb);
	close(fd);
	fd = open("readTest", O_RDONLY);
	printf("\033[0;31mread of 1000 in readTest\033[0m : ft_read = \033[0;32m\%zd\033[0m\n", ft_read(fd, bufb, 1000));	
	printf("%s\n\n", bufb);
	close(fd);
	printf("\033[0;31mread of 10 in fd = 42 (wrong fd)\033[0m : read = \033[0;32m\%zd\033[0m and ft_read = \033[0;32m\%zd\033[0m\n\n", read(42, bufb, 10), ft_read(42, bufb, 10));	
	fd = open("readTest", O_RDONLY);
	printf("\033[0;31mread of 0 in readTest\033[0m : read = \033[0;32m\%zd\033[0m and ft_read = \033[0;32m\%zd\033[0m\n", read(fd, bufb, 0), ft_read(fd, bufb, 0));		
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
	printf("\n-------------------------End of ft_strdup-------------------------\n\n\n\n");



	printf("" GREEN "\n\n\n\n\n\n\nSolal Dunckel tests for Libasm <3 \n\n\n" RESET "");
	/*
	** FT_STRLEN
	*/
	printf("%-12s :  ", "ft_strlen.s");
	strlen_test("allo");
	strlen_test("");
	strlen_test("on test tout ce qu'on peut mon gars");
	strlen_test("allo \0 mon gars");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	strlen_test("        ");
	printf("\n\n");

	/*
	** FT_STRCPY
	*/
	printf("%-12s :  ", "ft_strcpy.s");
	strcpy_test("abc");
	strcpy_test("");
	strcpy_test("allo mon gars");
	strcpy_test("allo \0 mon gars");
	strcpy_test("ca fou koi allo");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	strcpy_test("        ");
	printf("\n\n");

	/*
	** FT_STRCMP
	*/
	printf("%-12s :  ", "ft_strcmp.s");
	strcmp_test("allo", "allo");
	strcmp_test("abcdef", "zcdef");
	strcmp_test("", "wtf");
	strcmp_test("on test tout ce qu'on peut mon gars", "   ");
	strcmp_test("", "");
	strcmp_test("beta", "");
	strcmp_test("te\0", "\0");
	strcmp_test("\xff", "\xff");
	strcmp_test("\xfe", "\xfe");
	strcmp_test("lol", "1");
	strcmp_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, ed pulvinar nullam.", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n\n");

	/*
	** FT_WRITE
	*/
	printf("%-12s :  ", "ft_write.s");
	write_test("");
	write_test("test");
	write_test("test allo");
	write_test("test allo \0 what");
	printf("\n\n");

	/*
	** FT_READ
	*/

	printf("%-12s :  ", "ft_read.s");
	read_test("allo");
	read_test("allo mon gars");
	read_test("allo \0 mon bars");
	read_test("");
	read_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n\n");

	/*
	** FT_STRDUP
	*/
	printf("%-12s :  ", "ft_strdup.s");
	strdup_test("allo");
	strdup_test("allo wtf");
	strdup_test("");
	strdup_test("allo \0 mon bars");
	strdup_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce tellus metus, finibus quis sagittis quis, volutpat a justo. Nunc et pellentesque quam. Fusce aliquam aliquam libero, sed pulvinar nullam.");
	printf("\n\n\n\n\n\n\n\n");


	t_list	list;
	t_list	list_second;
	t_list	list_third;
	list.data = strdup("Hello, i'm the first");
	list.next = &list_second;
	list_second.data = strdup("I'm the second one");
	list_second.next = &list_third;
	list_third.data = strdup("I'm the third....");
	list_third.next = NULL;
	
	printf("\n---------------------------ft_list_size---------------------------\n\n");
	printf(""RED "The list is :\n" RESET"");
	print_list(&list);
	printf(""GREEN "\nfrom 0 "RESET ", lstSize = %d\n\n", ft_list_size(&list));
	printf(""GREEN "from 1 "RESET ", lstSize = %d\n\n", ft_list_size(&list_second));
	printf(""GREEN "from 2 "RESET ", lstSize = %d\n\n", ft_list_size(&list_third));
	printf(""GREEN "from NULL pointer "RESET ", lstSize = %d\n", ft_list_size(NULL));
	free(list_second.data);
	free(list_third.data);
	printf("\n-------------------------End of ft_list_size-------------------------\n\n\n");

	return (0);
}
