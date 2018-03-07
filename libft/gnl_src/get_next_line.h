
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_llist
{
	int				fd;
	char			*buff;
	struct s_llist	*next;
}					t_llist;

typedef struct		s_operator
{
	char			*to_free;
	char			*temp;
	char			*n;
}					t_operator;

int					get_next_line(const int fd, char **line);

#endif
