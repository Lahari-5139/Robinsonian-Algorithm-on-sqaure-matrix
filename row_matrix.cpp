#include "row_matrix.h"
#include "matrix_main.h"

row_matrix::row_matrix(int n):Matrix(n,n,getIndentity(n))
{
    permutation_map = new int[n];
    for(int i=0;i<n;i++)
    {
        permutation_map[i] = i;
    }
}

void row_matrix::mapit(int index, int value)
{
    this->set_matrix(getIndentity(this->getrows()),this->getrows(),this->getrows());
    for(int i=0;i<this->getrows();i++)
    {
        permutation_map[i] = i;
    } 
    int position;
    int row_swap = permutation_map[index];
    for(int i=0;i < this->getrows(); i++)
    {
        if(permutation_map[i]==value)
        {
            position = i;
            break;
        }
    }
    permutation_map[index] = value;
    permutation_map[position] = row_swap;
    this->get_my_matrix()[index][row_swap] = 0;
    this->get_my_matrix()[position][value] = 0;
    this->get_my_matrix()[position][row_swap] = 1;
    this->get_my_matrix()[index][value] = 1;
}

Matrix row_matrix::permutate(Matrix M)
{
    Matrix permuted_matrix =  multiplication(*this,M);
    return permuted_matrix;
}
