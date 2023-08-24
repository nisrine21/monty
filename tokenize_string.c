#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - takes a string and seperates its words
 *
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, a, b = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (b < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[b] = malloc((wordLen + 1) * sizeof(char));
		if (words[b] == NULL)
		{
			while (b >= 0)
			{
				b--;
				free(words[b]);
			}
			free(words);
			return (NULL);
		}
		a = 0;
		while (a < wordLen)
		{
			words[b][a] = *(str + a);
			a++;
		}
		words[b][a] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		b++;
	}
	words[b] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_delim - checks if stream has delimitor char
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
	int u = 0;

	while (delims[u])
	{
		if (delims[u] == ch)
			return (1);
		u++;
	}
	return (0);
}

/**
 * get_word_length - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit words
 *
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, t = 0;

	while (*(str + t))
	{
		if (is_delim(str[t], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[t], delims))
			break;
		t++;
	}
	return (wLen);
}

/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, c = 0;

	while (*(str + c))
	{
		if (is_delim(str[c], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		c++;
	}
	return (wc);
}

/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int v = 0;

	while (*(str + v))
	{
		if (is_delim(str[v], delims))
			pending = 1;
		else if (pending)
			break;
		v++;
	}
	return (str + v);
}
