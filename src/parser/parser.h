/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:53:27 by taehokim          #+#    #+#             */
/*   Updated: 2021/05/19 21:01:04 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define TOKEN_NOT_SPECIFIED	0
# define TOKEN_INT				1
# define TOKEN_DOUBLE			2
# define TOKEN_NAME				3
# define TOKEN_NEWLINE			5
# define TOKEN_COMMA			6
# define TOKEN_END				100

# define ERR_READ 					101
# define ERR_FILE_OPEN				102
# define ERR_FILE_CLOSE				103
# define ERR_PARSE					104
# define ERR_STR_ALLOC				105
# define ERR_STR_PUSH_CHAR_ALLOC	106
# define ERR_TOKEN_CONSUME			107

# define BUF_SIZE	100

int				is_digit(char c);
int				is_no_zero_digit(char c);
int				is_alpha(char c);
int				is_c_name(char c);
int				one_of(char c, const char *list);

typedef int				t_token_type;
typedef unsigned long	t_ul;

typedef struct	s_filereader
{
	const char	*path;
	int			fd;
	int			pos;
	char		buf[BUF_SIZE];
	int			eof_reached;
	int			eof_reached_len;
	int			c_col;
	int			c_row;
}				t_filereader;

int				file_open(int *fd, const char *path);
int				safe_file_close(void);
int				make_frpos_safe(t_filereader *fr);
t_filereader	fr(const char *path);

typedef struct	s_str
{
	t_ul	len;
	t_ul	max;
	char	*ptr;
}				t_str;

t_str			create_str(void);
int				is_same_str(t_str left, const char *right);
void			destroy_str(t_str *str);
const char		*raw(t_str str);
void			assign_str(t_str *str, t_str other);
void			concat_str(t_str *target, t_str source);
void			assign_chs(t_str *str, const char *raw);
t_str			duplicate_str_with_range(t_str str, t_ul start, t_ul end);
t_str			duplicate_str(t_str str);
t_str			create_str_from_raw(const char *raw);
void			str_push_char(t_str *str, char c);
void			str_push_chars(t_str *str, const char *s);
void			str_push_double(t_str *str, double num, unsigned int round);
void			str_push_long(t_str *str, long num);
void			write_str(t_str str);

typedef struct	s_token
{
	int				file_row;
	int				file_col;
	t_str			str;
	t_token_type	type;
}				t_token;

t_token			create_token(void);

typedef struct	s_tokenizer
{
	t_token		current_token;
	t_str		reading;
	t_ul		unresolved_row;
	t_ul		unresolved_col;
	char		unresolved_char;
}				t_tokenizer;

t_tokenizer		create_tokenizer(void);
void			token_consume(void);
t_token			token_lookahead(void);
void			init_tokenizer(void);
int				init_reading(char c);

void			skip_blank(void);
char			fr_read_track(void);
int				confirm_trial_value(t_token_type type, char next, t_str value);
int				confirm_trial(t_token_type type, char next);
int				confirm_trial_init_next(t_token_type type);
void			reading_push_char(char c);
int				iterate_double(char c);

int				try_token_name(void);
int				try_token_number(void);
int				try_token_int(void);
int				try_token_comma(void);
int				try_token_newline(void);
int				try_token_end(void);

typedef void	(*t_err_handler)(void *);
typedef struct	s_parser
{
	t_filereader	fr;
	t_tokenizer		tknzr;
	t_err_handler	custom_err_handler;
	void			*err_arg;
}				t_parser;

t_filereader	fr(const char *path);

t_str			expect_type(t_token_type type);
long			expect_int_range(long min, long max);
double			expect_number_range(double min, double max);
double			expect_number(void);

# define INITIAL_STR_LEN 10

void			init_parser(const char *path);
void			init_parser_fd(int fd, const char *name);
void			finish_parser(void);
void			set_parser_err_handler(void (*func)(void *), void *err_arg);
t_parser		*parser(void);

t_token			next_token(void);

long			str_to_long(t_str str);
double			str_to_double(t_str str);

void			abort_parser(const char *msg, int errcode);
void			abort_file(const char *msg, int errcode);
void			abort_parser_range(double min, double max);
void			abort_parser_type(t_token_type type);
void			abort_tokenizer(void);

#endif
