#include "ft_select.h"

static void		check_params(int argc)
{
	if (argc < 2)
	{
		ft_printf("usage: ft_select [file ...]\n");
		exit (0);
	}
}

static void		display_loop(t_terminal *term)
{
	while (1)
	{
		tputs(tgetstr("cr", NULL), 1, print_char);	
		tputs(tgetstr("cd", NULL), 1, print_char);
		display_arguments(term);
		listen_keys(term);
	}
}

int			main(int argc, char **argv)
{
	t_terminal	*term;

	(void)argv;
	check_params(argc);
	term = malloc(sizeof(t_terminal));
	if (!term)
		exit(1);
	tcgetattr(2, &term->original);
	term->raw = term->original;
	term->args = ++argv;
	term->length = --argc;
	term->cursor = 0;
	term->select = (char *)malloc(sizeof(char) * argc);
	if (!term->select)
	{
		free(term);
		exit(1);
	}
	ft_bzero(term->select, argc);
	config_terminal(0, term);
	display_loop(term);
}
