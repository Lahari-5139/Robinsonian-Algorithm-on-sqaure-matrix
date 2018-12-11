#include "matrix_main.h"
// #include "csvrow.h"
// #include "dataset.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

Matrix::Matrix(const int ir , const int ic)
{
    r = ir;
    c = ic;
}

//to initialize with values
Matrix::Matrix(int rows,int cols,double** values)
{
    this->r = rows;
    this->c = cols;
    my_matrix = new double*[rows];
      for(int i=0;i<rows;i++)
      {
        my_matrix[i] = new double[cols];
      }
    // cout<<"completr constr";      
      this->set_matrix(values,rows,cols);
}

//to set the matrix with the values of given matrix
void Matrix::set_matrix(double** _matrix,int r,int c)
{
    
  for(int i  = 0;i < r; i++)
  {
    for(int j = 0;j < c;j++)
    {
        my_matrix[i][j] = _matrix[i][j];
    }
  }
}

//creates a identity matrix of size n
double** Matrix::getIndentity(int n)
{
    double** values = new double*[n];
    for(int i=0;i<n;i++)
    {
        values[i] = new double[n];
        for(int j=0;j<n;j++){
            if(i==j) values[i][j] = 1;
            else values[i][j] = 0;
        }
    }
    return values;
}

//returns the no of rows
int Matrix::getrows()
{
  return this->r;
}

//returns the no of columns
int Matrix::getcolumns()
{
  return this->c;
}

Matrix Matrix::multiplication(Matrix M1, Matrix M2)
{
    //initialize
    double** values_of_product = new double*[M1.getrows()];
    for(int i=0;i<M1.getrows();i++)
    {
        values_of_product[i] = new double[M2.getcolumns()];
        for(int j=0;j<M2.getcolumns();j++)
        {
            values_of_product[i][j] = 0;
        }
    }
    //multiplication part
    // cout<<M1.get_row_size()<<" "<<M1.get_column_size()<<" "<<M2.get_row_size()<<" "<<M2.get_column_size()<<endl;
    if(M1.getcolumns() == M2.getrows())
    {
        for(int i=0;i<M1.getrows();i++)
        {
            for(int j=0;j<M2.getcolumns();j++)
            {
                for(int k=0;k<M1.getcolumns();k++)
                {
                    // cout<<"in mul"<<i<<" "<<j<<" "<<k<<endl;
                    values_of_product[i][j] = values_of_product[i][j] + ((M1.get_my_matrix()[i][k]) * (M2.get_my_matrix()[k][j]));
                }
            }   
        }
    }

    Matrix product_matrix(M1.getrows(),M2.getcolumns(),values_of_product);
    return product_matrix;
}

//returns max value in the upper triangle 
double Matrix::get_max_of_upper()
{
  double max = this->my_matrix[0][0];
  for(int i=0;i<r;i++)
  {
      for(int j=i;j<c;j++)
      {
        if(my_matrix[i][j] > max) 
        {
            max = my_matrix[i][j];
        }
      }
  }
  return max;
}

// gives the row index in which the value is present
int Matrix::get_row_index(double value)
{
    for(int i=0;i< r; i++)
    {
        for(int j=0;j < c;j++)
        {
            if(my_matrix[i][j]==value)
            {
                return i;
            }
        }
    }
    return -1;
}

// gives the column index in which the value is present
int Matrix::get_column_index(double value)
{
    for(int i=0;i< r; i++)
    {
        for(int j=0;j < c;j++)
        {
            if(my_matrix[i][j]==value)
            {
                return j;
            }
        }
    }
    return -1;
}

//
int Matrix::get_max_of_column(int column)
{
    int max = column;
    for(int i=column;i<r;i++)
    {
        if(this->my_matrix[i][column] > this->my_matrix[max][column])
        {
            max = i;
        } 
    }
    return max;
}

//
int Matrix::get_max_of_row(int row){
    int max = row;
    // cout<<"  int max";
    for(int i=row;i<c;i++)
    {
        if(this->my_matrix[row][i] > this->my_matrix[row][max])
        {
            max = i;
        } 
    }
    return max;
}

//
double Matrix::get_max_of_index(int index)
{
    // cout<<"max index func"<<endl;
    // cout<<this->get_max_of_row(index)<<" " <<index<<" "<<get_max_of_column(index)<<endl;
    // cout<<my_matrix[this->get_max_of_row(index)][index];
    double max_of_rows = this->my_matrix[this->get_max_of_row(index)][index];
    // cout<<this->get_max_of_row(index)<<" " <<index<<" "<<get_max_of_column(index)<<endl;
    double max_of_column = this->my_matrix[index][this->get_max_of_column(index)];
    // cout<<this->get_max_of_row(index)<<" " <<index<<" "<<get_max_of_column(index)<<endl;
    // cout << max_of_rows <<" "<<max_of_column<<endl;
    if(max_of_column > max_of_rows) 
    {
        return max_of_column;
    }
    else
    {
        return max_of_rows;
    } 
}

double** Matrix::get_my_matrix()
{
  return my_matrix;
}


void Matrix::re_size(int r,int c)
{
    matrix.resize(r);
    int i;
    for(i=0;i<r;i++)
    {
        matrix[i].resize(c);
    }

}

// vector<double> Matrix::get_row_i(const int i)
// {
//     return matrix[i];
// }

// vector<double> Matrix::get_column_i(const int i)
// {
//     vector<double> column;
//     for(int j=0;j<matrix.size();j++)
//     {
//         column.push_back(matrix[j][i]);
//     }
//     return column;
// }

// void Matrix::fill_data_from_csv(const string filename)
// {
//     ifstream file(filename);
//     CSVRow row;

//     string firstLine;
//     getline(file, firstLine);

//     string temp("");

//     int i=0;
//     while(firstLine[i]>=48 && firstLine[i]<=57)
//     {
//         temp+=firstLine[i++];
//     }
//     // cout<<temp<<endl;
//     r = stoi(temp);
//     i++;
//     temp="";
//     while(firstLine[i]>=48 && firstLine[i]<=57)
//     {
//         temp+=firstLine[i++];
//     }
//     // cout<<temp<<endl;
//     c = stoi(temp);

//     string line;

//     stringstream lineStream(line);
//     string cell;

//     while(file >> row)
//     {
//         // continue;
//         // cout << "4th Element(" << row[3] << ")\n";
//         Record *r;
//         r = new Record(row.get_vector());
//         // for(int i=0;i<row.get_vector().size();i++)
//             // cout<<row.get_vector()[i]<<" ";
//         // cout<<endl;
//         // .push_back(*r);
//         vector<string> temp1 = r->get_record();
//         vector<double> temp2;
//         for(int i=0;i<temp1.size();i++)
//         {
//             temp2.push_back(stod(temp1[i]));
//         }
//         matrix.push_back(temp2);
//         temp2.clear();
//     }
// }

// void Matrix::convert_from_dataset(DataSet &ds)
// {
//     int n = ds.get_n();
//     for(int i=0;i<ds.no_of_records();i++)
//     {
//         vector<string> temp1;
//         vector<double> temp2;
//         Record *r;

//         r = new Record(ds.get_data_set()[i].get_record());
//         temp1 = r->get_record();
//         // cout<<"lol"<<temp1.size()<<endl;
        
//         for(int i=n;i<temp1.size();i++)
//         {
//             try {
//                 temp2.push_back(stod(temp1[i]));
//             } catch(invalid_argument)
//             {
//                 temp2.push_back((double) stoi(temp1[i]));
//             }
//         }
//         matrix.push_back(temp2);
//         temp2.clear();
//     }
//     r = matrix.size();
//     c = matrix[0].size();
// }

// void Matrix::output_to_csv(const string filename)
// {
//     ofstream file(filename);

//     file<<r<<" "<<c<<endl;
//     for(int i=0;i<matrix.size();i++)
//     {
//         for(int j=0;j<matrix[i].size()-1;j++)
//         {
//             file<<matrix[i][j]<<";";
//         }
//         file<<matrix[i][matrix[i].size()-1]<<endl;
//     }
// }

//ostream to print the grid and is a friend function of the grid class.
ostream& operator<<(ostream &os,const Matrix &m) 
{
  for (int i = 0 ; i < m.r; i++)
    {
      for(int j = 0; j < m.c; j++)
        {
          os<<m.my_matrix[i][j]<<" ";
        }
        os <<endl ;
    }
  return os ;
}


Matrix& Matrix::operator= (const Matrix & M)
{
    r = M.r;
    c = M.c;
    my_matrix = new double*[r] ;
    for (int i = 0 ; i < r ; i++) 
    {
        my_matrix[i] = new double[c] ;
        for(int j=0;j<c;j++) 
        {
            my_matrix[i][j] = M.my_matrix[i][j];
        }
    }
    return *this;
}
