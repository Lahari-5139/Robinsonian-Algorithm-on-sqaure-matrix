#include "column_matrix.h"
#include "matrix_main.h"

column_matrix::column_matrix(int n) : Matrix(n,n,getIndentity(n))
{
    permutation_map = new int[n];
    for(int i=0;i<n;i++)
    {
        permutation_map[i] = i;
    } 
}

void column_matrix::mapit(int index,int value)
{
    this->set_matrix(getIndentity(this->getcolumns()),this->getcolumns(),this->getcolumns());
    for(int i=0;i < this->getcolumns(); i++) 
    {
        permutation_map[i] = i;
    }
    int position;
    int column_swap = permutation_map[index];
    for(int i=0;i < this->getrows(); i++)
    {
        if(permutation_map[i] == value)
        {
            position = i;
            break;
        }
    }
    permutation_map[position] = column_swap;
    permutation_map[index] = value;
    this->get_my_matrix()[column_swap][index] = 0;
    this->get_my_matrix()[value][position] = 0;
    this->get_my_matrix()[column_swap][position] = 1;
    this->get_my_matrix()[value][index] = 1;
}

Matrix column_matrix::permutate(Matrix M)
{
    Matrix permuted_matrix =  multiplication(M,*this);
    return permuted_matrix;
}

