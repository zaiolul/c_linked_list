#include <stdio.h>
#include <stdlib.h>

/*Gets input of length LEN from stdin, prints TEXT to stdout*/
char *get_input_line(char *text, int len)
{
	if (text != NULL) {
		printf("%s \n", text);
	}
	printf("> ");

	size_t size   = len;
	char *line    = (char *)malloc(sizeof(char *) * len);
	int charCount = getdelim(&line, &size, '\n', stdin);

	if (charCount < 0) {
		printf("Skaitymo klaida");
		return NULL;
	}

	remove_endline(&line, charCount);
	return line;
}

/*Checks if STR contains only integer characters*/
int check_number(char *str)
{
	char *temp = str;
	while (*temp != '\0') {
		if (*temp > 57 || *temp < 48) {
			return 0;
		}
		temp++;
	}
	return 1;
}

/*Remove all endline characters from STR*/
void remove_endline(char **str, int n)
{
	for (int i = n - 1; i > 0; i--) {
		if ((*str)[i] == '\n') {
			(*str)[i] = '\0';
		}
	}
}
