#ifndef matrix_main_H
#define matrix_main_H
#include <vector>
#include <string>
// #include "dataset.h"
using namespace std;

class Matrix
{
    public:
    Matrix(int ir = 100, int ic = 100);

    Matrix(int rows, int cols,double** vals);//
    void set_matrix(double** m,int,int);//
    double** getIndentity(int n);//
    int getrows();//
    int getcolumns();//
    Matrix multiplication(Matrix M1, Matrix M2);//
    int get_row_index(double value);//
    int get_column_index(double value);//
    double get_max_of_upper();//
    int get_max_of_row(int row);//
    int get_max_of_column(int column);//
    double get_max_of_index(int index);//
    double** get_my_matrix();//

    Matrix& operator= (const Matrix & M);//
    // {
    // return my_matrix;
    // }



    int get_row_size()
    {
        return r;
    }
    int get_column_size()
    {
        return c;
    }
    
    vector<double> get_row_i(int i);
    vector<double> get_column_i(int i);

    vector< vector<double> > get_matrix()
    {
        return matrix;
    }

    double get_value(int i, int j)
    {
        return matrix[i][j];
    }

    void set_value(int i, int j, double value)
    {
        matrix[i][j] = value;
    }

    void push_row(vector<double> temp)
    {
        matrix.push_back(temp);
    }
    
    void re_size(int r, int c);
    void fill_data_from_csv(string filename);
    // void convert_from_dataset(DataSet &ds);
    void output_to_csv(string filename);
    friend ostream& operator<<(ostream &os,const Matrix &m);//

    

    protected:
    int r;
    int c;
    vector< vector<double> > matrix;
    double** my_matrix;
};

#endif