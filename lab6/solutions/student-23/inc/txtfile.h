#ifndef TXTFILE_H
# define TXTFILE_H

# include "../libft/inc/libft.h"
# include <unistd.h>
# include <fcntl.h>

char	**read_file(const char *filename);
void	free_lines(char **lines);
void	print_lines(char **lines);

char	**replace_substr(char **lines,
			const char *old,
			const char *new_str);


int		count_lines_array(char **lines);

char	*replace_in_line(const char *line,
			const char *old,
			const char *new_str);

#endif