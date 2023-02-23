#include <errno.h>
#include "shell.h"
#include "source.h"
/**
  * unget_char - function for source
  * @src: pointing to a struct
  * Return: 0 or 1
  */
void unget_char(struct source_s *src)
{
	if (src->curpos < 0)
	{
		return;
	}
	src->curpos--;
}
/**
  * next_char - function returns next src char
  * @src: pointer to a struct
  * Return: return 0 or nonzero
  */
char next_char(struct source_s *src)
{
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (-ERRCHAR);
	}
	char c1 = 0;

	if (src->curpos == INIT_SRC_POS)
	{
		src->curpos = -1;
	}
	else
	{
		c1 = src->buffer[src->curpos];
	}
	if (++src->curpos >= src->bufsize)
	{
		src->curpos = src->bufsize;
		return (EOF);
	}
	return (src->buffer[src->curpos]);
}
/**
  * peek_char - function to peek char
  * @src: pointer to stuct
  * Return:  0 or nonzero
  */
char peek_char(struct source_s *src)
{
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (-ERRCHAR);
	}
	long pos = src->curpos;

	if (pos == INIT_SRC_POS)
	{
		pos++;
	}
	pos++;
	if (pos >= src->bufsize)
	{
		return (EOF);
	}
	return (src->buffer[pos]);
}
/**
  * skip_white_spaces - function that skips white spaces
  * @src: pointing to struct
  * Return: nothing
  */
void skip_white_spaces(struct source_s *src)
{
	char c;

	if (!src || !src->buffer)
	{
		return;
	}
	while (((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
	{
		next_char(src);
	}
}
