/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 19:44:11 by qrosa             #+#    #+#             */
/*   Updated: 2016/01/21 23:12:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** ----- System Libs -----
*/

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <time.h>

/*
**	Include for getpwuid
*/
# include <pwd.h>

/*
**	Include for getgrgid
*/
# include <grp.h>

/*
**	Include for listxattr
*/
# include <sys/xattr.h>

/*
** ----- Color Terminal-----
*/
# define C_RED		"\033[31m"
# define C_BLUE		"\033[1;34m"
# define C_CYAN		"\033[0;36m"
# define C_ORANGE	"\033[0;33m"
# define C_GREEN	"\033[1;32m"
# define C_NONE		"\033[0m"

/*
** ----- Structure -----
*/
typedef struct passwd	t_user;
typedef struct group	t_group;

typedef struct			s_form
{
	t_user				*owner_c;
	t_group				*group_c;
	size_t				owner;
	size_t				group;
	size_t				size;
	size_t				nb_links;
	size_t				len_blocks;
	blkcnt_t			nb_blocks;
	size_t				nb_node;
	bool				dev;
	bool				stat_m;
}						t_form;

typedef struct			s_opt
{
	bool				a;
	bool				f;
	bool				h;
	bool				l;
	bool				r;
	bool				s;
	bool				t;
	bool				rec;
}						t_opt;

typedef	struct			s_env
{
	int					i;
	int					count;
	char				*opt;
	char				*l_opt;
	int					nb_arg;
	char				**s_arg;
	char				bad_char;
	int					error;
	int					mark;
	bool				mark_b;
	bool				mark_c;
	struct s_form		*form;
	struct s_opt		*opt_s;
	time_t				time_n;
}						t_env;

typedef	struct			s_tree
{
	char				*content;
	size_t				content_size;
	char				*path_name;
	int					stat_m;
	char				type;
	struct stat			t_stat;
	struct s_form		*form;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

/*
** ----- Man ft_get_options -----
** ## t_env->error
** 0 = RAS
** 1 = bad malloc
** 2 = bad short_option
** 3 = bad long_option
** ## t_env->mark
** 0 = RAS
** 1 = no_option;
** 2 = option non-valide
** 3 = "--"
** 4 = "--" && no_option
** bool mark_b  Affichage d'un fichier afin de sauter une ligne
** bool mark_c  Affichage du chemin en recursion
*/

/*
** ----- Parameters -----
*/
# define OPTIONS		"afhlrstR"
# define LONG_OPTIONS 	"all human-readable reverse recursive"
# define SHORT_H		"usage: ls [-Rafhlrst]"
# define LONG_H			" [--all --human-readable --recursive --reverse]"
# define FILE_H			" [file ...]"

/*
** ----- Main Fonctions -----
*/
int						main(int argc, char **argv);
t_env					*ft_parse_arguments(int argc, char **argv);
void					ft_get_options(int argc, char **argv, t_env **e);
void					ls_main(t_env **e, char **argv, int argc);
void					ls_check_options(t_env **e);
t_tree					*ls_construc_tree(t_env **e, char **argv,
	int argc, char *path);

/*
** ----- Options fonctions -----
*/
void					opt_init_env(t_env **e);
bool					opt_is_valid(char *str, t_env **e);
void					opt_exist_letter(char *str, t_env **e, int i, int a);
bool					opt_exist_long(char *str, t_env **e);
void					save_arg(char *str, t_env **e);
void					free_opt(t_env **e);

/*
** ----- Tree fonctions -----
*/
t_tree					*tree_init(t_env **e, char *file_name, char *path);
t_tree					*tree_create_node(t_env **e, char *file_name,
	char *path);
void					tree_add_elem(t_env **e, t_tree **tree, char *name,
	char *path);
void					tree_insert_node_alpha(t_env **e, t_tree **tree,
	char *name, char *path);
void					tree_insert_node_date(t_env **e, t_tree **tree,
	char *name, char *path);
void					tree_insert_node_f(t_env **e, t_tree **tree,
	char *name, char *path);
void					tree_insert_node_alpha_date(t_env **e, t_tree **tree,
	char *name, char *path);
int						ls_strcmp_date(char *new, char *name_node);
int						ls_strcmp_alpha(char *new, char *name_node);
char					*ls_save_path(char *path, char *file_name,
	int i, int a);

/*
** ----- Free fonctions -----
*/
void					ls_free_tree(t_tree **tree);

/*
** ----- Print fonctions -----
*/
void					ls_print_tree_no_opt(t_env **e, t_tree **tree,
	int argc, short mark);
void					ls_print_tree_normal(t_env **e, t_tree **tree,
	int argc, short mark);
void					ls_print_tree_reverse(t_env **e, t_tree **tree,
	int argc, short mark);

void					ls_print_tree_sub_no_opt(t_tree **tree_sub);
void					ls_print_tree_sub_opt(t_env **e, t_tree **tree_sub);
void					ls_print_tree_sub_opt_rev(t_env **e, t_tree **tree_sub);

void					ls_print_node_no_opt_0(t_tree **tree);
void					ls_print_node_no_opt_1(t_env **e, t_tree **tree);
void					ls_print_node_no_opt_2(t_env **e, t_tree **tree,
	int argc);
void					ls_print_node_opt_0(t_tree **tree);
void					ls_print_node_opt_1(t_env **e, t_tree **tree);
void					ls_print_node_opt_2(t_env **e, t_tree **tree, int argc);
void					ls_print_node_opt_3(t_env **e, t_tree **tree, int argc);

void					ls_read_dir(DIR *p_dir, t_env **e, t_tree **tree,
	t_tree **tree_sub);
void					ls_recursive_tree(t_env **e, t_tree **tree_sub,
	bool mark);
void					ls_print_path(char *path);
void					ls_s_opt(t_env **e, t_tree **tree);

/*
**				-- Print Format (long:short | normal:reverse) --
*/
void					ls_print_long_format(t_env **e, t_tree **tree_sub);
void					ls_print_long_format_rev(t_env **e, t_tree **tree_sub);
void					ls_print_short_format(t_env **e, t_tree **tree_sub);
void					ls_print_short_format_rev(t_env **e, t_tree **tree_sub);
void					ls_print_elem(t_env **e, t_tree **tree_sub);

/*
**				-- Print 'l' Format --
*/
void					l_init_form(t_env **e);
void					l_check_max(t_env **e, t_tree **tree);
void					l_print_total(t_env **e);
void					l_copy_number(char *line, char *number, size_t *cpt);

void					l_print_long(t_env **e, t_tree **tree_sub);
void					l_print_long_clair(t_env **e, t_tree **tree_sub);
void					l_print_long_rev(t_env **e, t_tree **tree_sub);
void					l_print_long_clair_rev(t_env **e, t_tree **tree_sub);

void					l_print_line(t_env **e, t_tree **tree);
void					l_print_line_clair(t_env **e, t_tree **tree);

void					l_s_opt(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
char					l_typefile_christmas(mode_t mode);
void					l_right(t_tree **tree, char *line, size_t *cpt);
void					l_acl_extend(t_tree **tree, char *line, size_t *cpt);
void					l_nb_links(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
void					l_owner_name(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
void					l_group_name(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
void					l_min_maj(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
void					l_size_file(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
void					l_time(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
void					l_name(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
void					l_link(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
/*
**					-- Print 'h' Format --
*/
void					h_convert_size(t_env **e, t_tree **tree, char *line,
	size_t *cpt);
void					h_add_space(t_env **e, char *line, size_t *cpt);

/*
** ----- Print Error fonctions -----
*/
void					opt_print_error(char **argv, t_env *e);
void					ls_print_error(int error, char *name);

#endif
