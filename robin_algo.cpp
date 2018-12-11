#include "row_matrix.h"
#include "column_matrix.h"
#include "robin_algo.h"

#include <bits/stdc++.h>
using namespace std;

robin_algo::robin_algo(Matrix _M)
{
    M = _M;
    rows = _M.getrows();
    matrix_R = row_matrix(rows);
    matrix_C = column_matrix(rows);
}

Matrix robin_algo::permutate(row_matrix matrix_R, column_matrix matrix_C, Matrix M)
{
    M = matrix_R.permutate(M);
    M = matrix_C.permutate(M);
    return M;
}

void robin_algo::diagonals()
{

    int index = 0;
    int max = M.get_max_of_upper();
    bool row_direction;

    matrix_R.mapit(index,M.get_row_index(max));
    matrix_C.mapit(index,M.get_column_index(max));

    M = permutate(matrix_R,matrix_C,M);

    max = M.get_max_of_index(index);
    index = index +1;
    int max_rows = M.get_max_of_column(index);
    int max_columns = M.get_max_of_row(index);

    if(M.get_matrix()[max_rows][index] > M.get_matrix()[index][max_columns])
    {
        row_direction = true;
        matrix_R.mapit(index,max_rows);
        M = matrix_R.permutate(M);
    }
    else
    {
        row_direction = false;
        matrix_C.mapit(index,max_columns);
        M = matrix_C.permutate(M);
    }

    int row_index = 2;
    int column_index = 2;
    while(row_index < rows || column_index < rows)
    {
        if(row_direction == true)
        {
            max = M.get_max_of_column(row_index);
            matrix_R.mapit(row_index,max);
            M = matrix_R.permutate(M);
            row_index = row_index+1;
        }
        else
        {
            max = M.get_max_of_row(column_index);
            matrix_C.mapit(column_index,max);
            M = matrix_C.permutate(M);
            column_index = column_index+1;
        }
        row_direction = !row_direction;
    }
}

Matrix robin_algo::get_final_matrix()
{
    return M;
}

// void robin_algo::final_fun(Matrix M)
// {
//     // this->robin_algo(M);
//     this->permutate(matrix_R,matrix_C,M);
//     this->diagonals();
//     cout << this->get_final_matrix();
// }