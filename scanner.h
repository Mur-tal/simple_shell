#ifndef SCANNER_H
#define SCANNER_H

/**
 * struct token_s - EOF token to indicate end of imput
 *
 * struct source_s - source of imput
 * @src: the source
 * @text_len: length of token text
 * @text: token text
 *
 * Return: 0
 */

struct token_s
{
	struct source_s *src;   /* source of imput */
	int    text_len;           /* length of token text */
	char   *text;             /* token text */
};

/*EOF token to indicate the end of imput */
extern struct token_s eof_token;
struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);
#endif

