#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name;
	user_name = receive_input();
	user_name = count_characters(user_name);
	show_result(user_name);


	return 0;
}

struct name_count receive_input()
{
	struct name_count temp;
	printf("Input your first name:\n>>");
	scanf("%[^\n]%*c", temp.first);
	printf("Input your last name:\n>>");
	scanf("%[^\n]%*c", temp.last);
	return temp;
}

struct name_count count_characters(struct name_count user_name)
{
	user_name.num = strlen(user_name.first) + strlen(user_name.last);
	return user_name;
}

void show_result(const struct name_count user_name)
{
	printf("Hi, %s %s. Your name has %d characters.", user_name.first, user_name.last, user_name.num);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	find = strchr(st, '\n');
	if (ret_val)
	{
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
