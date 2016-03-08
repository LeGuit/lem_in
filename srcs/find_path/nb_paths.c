#include "lem_in.h"

int					**init_nbpath_mat(t_data *data)
{
	int				i;
	int				**mat;

	mat = (int **)malloc(data->nbroom * sizeof(int *));
	i = 0;
	while (i < data->nbroom)
	{
		mat[i] = (int *)malloc(data->nbroom * sizeof(int));
		ft_memcpy(mat[i], data->matrix[i]/**sizeof(int)*/);
		i++;
	}
	return (mat);
}

void				square_mat_product(int **mat1, int **mat2, int size)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mat1[i][j] *= mat2[j][i];
			k = 1;
			while (k < size)
			{
				mat[i][j] += mat1[i][k] * mat2[k][j];
				k++
			}
			j++;
		}
		i++;
	}
}


void				nb_path(t_data *data, t_path *path)
{
	int				i;
	int				**mat;			

	mat = init_nbpath_mat(data);
	i = 0;
	while (i < data->nbroom)
	{
		square_mat_product(mat, mat, data->nbroom);
		i++;
	}
	path->nbpath = mat(data->idstart, data->idend);
	if (path->nbpath == 0)
		error_nopath();
}
