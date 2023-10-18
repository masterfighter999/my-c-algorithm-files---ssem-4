#include <stdio.h>
#include <stdlib.h>

char *read(int *len);
void string_matching(char *text, int t_len, char *pattern, int p_len);
int compare(char *text, char *pattern, int lb, int ub);

void main()
{
	char *text, *pattern;
	int t_len, p_len;
	
	text = NULL;
	t_len = 0;
	
	pattern = NULL;
	p_len = 0;
	
	printf("\nEnter the text in which the pattern is to be searched:\n");
	text = read(&t_len);
	
	printf("\nEnter the pattern which is to be to be searched:\n");
	pattern = read(&p_len);
	
	string_matching(text, t_len, pattern, p_len);
}

char *read(int *len)
{
	char *string, ch;
	int n;
	
	n = 0;
	string = NULL;
	scanf("%c", &ch);
	while(ch != '\n')
	{		
		string = realloc(string, (n + 1) * sizeof(char));
		string[n++] = ch;
		
		scanf("%c", &ch);
	}
	
	string = realloc(string, (n + 1) * sizeof(char));
	string[n] = '\0';
	
	*len = n;
	return string;
}

void string_matching(char *text, int t_len, char *pattern, int p_len)
{
	int i, j, flag;
	
	if(p_len > t_len)
	{
		printf("\nThe pattern does not occur in the text.\n");
		return;
	}
	
	flag = 0;
	for(i = 0 ; i <= t_len - p_len ; i++)
	{
		if(compare(text, pattern, i, i + p_len - 1) == 1)
		{
			flag++;
			printf("\nThe pattern occurs in the text with shift %d.\n", i);
		}
	}
	
	if(flag == 0)
		printf("\nThe pattern does not occur in the text.\n");
}

int compare(char *text, char *pattern, int lb, int ub)
{
	int i, j;
	
	j = 0;
	for(i = lb ; i <= ub ; i++)
	{
		if(text[i] != pattern[j++])
			return 0;
	}
	
	return 1;
}
