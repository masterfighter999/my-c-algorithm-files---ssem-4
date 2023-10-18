#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefixSuffixArray(char* pat, int M, int* pps) 
{
   int length = 0;
   pps[0] = 0;
   int i = 1;
   while (i < M) 
   {
      if (pat[i] == pat[length]) 
      {
         length++;
         pps[i] = length;
         i++;
      } 
      else 
      {
         if (length != 0)
         	length = pps[length - 1];
         else 
         {
            pps[i] = 0;
            i++;
         }
      }
   }
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
void KMPAlgorithm(char* text, char* pattern) 
{
   int M = strlen(pattern);
   int N = strlen(text);
   int pps[M];
   prefixSuffixArray(pattern, M, pps);
   int i = 0;
   int j = 0;
   while (i < N) 
   {
      if (pattern[j] == text[i]) 
      {
         j++;
         i++;
      }
      if (j == M) 
      {
         printf("\n Found pattern at index %d", i - j);
         j = pps[j - 1];
      }
      else if (i < N && pattern[j] != text[i]) 
      {
         if (j != 0)
         	j = pps[j - 1];
         else
         	i = i + 1;
      }
   }
}

int main() 
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
	
   	printf("\n The pattern is found in the text at the following index : ");
   	KMPAlgorithm(text, pattern);
   	return 0;
}
