#ifndef FT_SELECT_H

#define FT_SELECT_H

# include "ft_printf.h"
# include <termios.h>
# include <term.h>

# define KEY_SIZE 4
# define ESC 27
# define SPACE 32
# define RET 127
# define UP 183
# define DOWN 184
# define RIGHT 185
# define LEFT 186

typedef struct		s_terminal
{
	struct termios	original;
	struct termios	raw;
	char		**args;
}			t_terminal;

void			config_terminal(int reset, t_terminal *term);
void			listen_keys(t_terminal *term);
int			print_char(int c);

#endif
