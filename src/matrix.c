#include "lem_in.h"

void	matrix_alloc(t_matrix *m, int rooms_q)
{
	int		i;

	m->rooms_q = rooms_q;
	m->reachability_m = ft_memalloc(sizeof(char *) * (rooms_q + 1));
	i = 0;
	while (i < rooms_q)
	{
		m->reachability_m[i] = ft_strnew(rooms_q + 1);
		i++;
	}
}

void	matrix_initialise(t_matrix *m)
{
	m->start_room = -1;
	m->end_room = -1;
}

void	matrix_set_link(t_matrix *m, t_array_list *l, char *r1, char *r2)
{
	int		ind1;
	int		ind2;

	ind1 = al_index_of(l, r1);
	ind2 = al_index_of(l, r2);
	m->reachability_m[ind1][ind2] = 1;
	m->reachability_m[ind2][ind1] = 1;
}