#ifndef MINISHELL_H
# define MINISHELL_H

typedef enum        e_token_type
{
	and,
	or,
	semicolon,
	redir_left,
	redir_right,
	double_redir_left,
	double_redir_right,
	pipes,
	option_command,
	single_quote,
	double_quote,
	backslash,
	literal,
	variable,
	space,
}	t_token_type;

typedef struct	s_token
{
	int 	type;
	void 	*cmd;
}	t_token;

typedef struct s_builtin
{
	char	*cmd;
	void	(*ptr_fct)();
}	t_builtin;

typedef struct s_redir
{
	t_token_type	type;
	void	(*ptr_fct)();
}	t_redir;

typedef struct		s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_info
{
	t_list			*list_env;
	void			*ptr;
	t_list			*list_input;
	t_list			*list_path;
	char			**tab_var_env;
	int				ret;
}					t_info;

t_info	g_info;

#endif