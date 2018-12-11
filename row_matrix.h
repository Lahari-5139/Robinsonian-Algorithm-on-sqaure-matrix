#ifndef row_matrix_H_
#define row_matrix_H_

#include <iostream>
#include <string>
#include"matrix_main.h"

class row_matrix : public Matrix
{
    protected:
        int* permutation_map;
    public:
        row_matrix(){}
        row_matrix(int n);
        void mapit(int index,int val);
        Matrix permutate(Matrix M);

        //operator overloading
        row_matrix& operator= (const row_matrix & M)
        {
            permutation_map = new int[M.r];
            for(int i=0;i < M.r;i++)
            {
                this->permutation_map[i] = M.permutation_map[i];
            }
            this->r = M.r;
            this->c = M.c;

            my_matrix = new double*[r];
            for(int i=0;i<r;i++)
            {
                my_matrix[i] = new double[c];
            }

            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    my_matrix[i][j] = M.my_matrix[i][j];
                }
            }
        }
};

#endif