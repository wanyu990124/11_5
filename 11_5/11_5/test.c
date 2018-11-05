#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_nnumbers(int columns[], int max);
void rearrange(char*output, char const*intput, int n_columns, int const columns[]);

int main(void) {
	int n_columns;
	int columns[MAX_COLS];
	char intput[MAX_INPUT];
	char output[MAX_INPUT];
	int input=0;
	n_columns = read_column_nnumbers(columns, MAX_COLS);
	while (gets(input) != NULL) {
		printf("Original input:%s\n", input);
		rearrange(output, input, n_columns, columns);
		printf("Rerrange line:%s\n", output);
	}
	return EXIT_SUCCESS;
}
int read_column_nnumbers(int columns[], int max) {
	int num = 0;
	int ch;
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
		num += 1;
	if (num % 2 != 0) {
		puts("Last column number is not paired");
		exit("EXIT_FAILURE");
	}
	while ((ch = getchar()) != EOF && ch != '\n')
		;
	return num;
}
void rearrange(char*output, char const*input, int n_columns, int const columns[]) {
	int col;
	int output_col;
	int len;
	len = strlen(input);
	output_col = 0;
	for (col = 0; col < n_columns; col += 2) {
		int nchars = columns[col + 1] - columns[col] + 1;
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
			break;
		if (output_col + nchars>MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		strncp(output_col + output, input + columns[col], nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}

int main() {
	char str[20];
	int i = 0;
	int count = 0;
	printf("ÇëÊäÈëÒ»´®×Ö·û:\n");
	scanf("%s", &str[20]);
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			i++;
			count++;
		}
	}
	printf("´óÐ´×ÖÄ¸¸öÊýÎª:%d\n", count);


	int i, j;
	char s[20], ch;
	printf("ÇëÊäÈëÒ»´®×Ö·û:\n");
	gets(s);
	printf("ÇëÊäÈëÉ¾³ýµÄ×Ö·û:\n");
	ch = getchar();
	for (i = 0; i <= strlen(s) - 1; i++) {
		if (s[i] == ch) {
			for (j = i; j <= 9; j++) {
				s[j] = s[j + 1];
			}
			s[j] = '\0';
		}
		printf("É¾³ýºóµÄ×Ö·ûÎª:\n");
		puts(s);
	}

	char str[20];
	int i;
	gets(str);
	puts(str);
	for (i = 0; str[20] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;
			puts(str);
		}
	}

	int password[1024] = { 0 };
	int i = 123456;
	printf("ÇëÊäÈëÃÜÂë:\n");
	scanf("%d", &password);
	if (strcmp(password,"i") == 0) {
		printf("µÇÂ½³É¹¦\n");
	}
	else {
		printf("µÇÂ½Ê§°Ü\n");
	}
	system("pause");
	return 0;
}