#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
  int cols; //колонны
  int rows; //строки
  double *data; //хранит адрес указателя, который хранит адрес объекта в памяти
} Matrix;

double get_item (Matrix matrix, int row, int col)
{
  return matrix.data[matrix.cols * row + col];
}

void set_item (Matrix matrix, int row, int col, double value)
{
    matrix.data[matrix.cols * row + col] = value;
}

void print_matrix (Matrix matrix)
{
    for (int row = 0; row < matrix.rows; row++)
    {
        for (int col = 0; col < matrix.cols; col++)
        {
            printf ("%g ", get_item (matrix, row, col));
        }
        printf ("\n");
    }
}

Matrix create_matrix (int rows, int cols, double initVal)
{
  Matrix matrix = {cols, rows, malloc (cols * rows * sizeof (double))};
  for (int row = 0; row < rows; row++)
  {
      for (int col = 0; col < cols; col++)
      {
	  set_item (matrix, row, col, initVal);
      }
  }
  return matrix;
}



Matrix multiply_matrix (Matrix A, Matrix B)
{
  Matrix result = create_matrix(B.rows, B.cols, 0);
  double sum;
  for (int resrow = 0; resrow < B.rows; resrow++)
  {
      for (int rescol = 0; rescol < B.cols; rescol++)
      {
          sum = 0.0;
          for (int i = 0; i < A.cols; i++)
          {
              sum += get_item (A, resrow, i) * get_item (B, i, rescol);
          }
          set_item (result, resrow, rescol, sum);
	  }
  }
  return result;
}

Matrix createEye (int size)
{
  Matrix A = create_matrix(size, size, 0);
  for (int i = 0; i < A.rows; i++)
  {
      for (int j = 0; j < A.cols; j++)
      {
    	  if (i == j)
    	  {
    	      set_item (A, i, j, 1);
    	   }
    	}
    }
  return A;
}

Matrix multiply_scalar (Matrix A, double k)
{
    Matrix result = create_matrix(A.rows, A.cols, 0);
    for (int i = 0; i < A.rows; i++)
    {
      for (int j = 0; j < A.cols; j++)
      {
    	  set_item(result,i,j,get_item(A,i,j)*k);
      }
    }
    return result;
}

Matrix subtract_matrix (Matrix A, Matrix B)
{
    Matrix result = create_matrix(A.rows, A.cols, 0);
    for(int i = 0; i<A.rows; i++)
    {
        for(int j = 0; j<A.cols; j++)
        {
            set_item(result,i,j,get_item(A,i,j) - get_item(B,i,j));
        }
    }
    return result;
}

Matrix abs_matrix(Matrix A)
{
    Matrix result = create_matrix(A.rows, A.cols, 0);
    for(int i = 0; i<A.rows;i++)
    {
        for(int j = 0; j<A.cols;j++)
        {
            set_item(result,i,j,fabs(get_item(A,i,j))); //fabs ищет модуль
        }
    }
    return result;
}

double find_max_item(Matrix A)
{
    double result = 0;
    double current_item;
    for(int i = 0; i<A.rows;i++)
    {
        for(int j = 0; j<A.cols;j++)
        {
            current_item = get_item(A,i,j);
            if(result<current_item)
            {
                result = current_item;
            }
        }
    }
    return result;
}

int main ()
{
{
  int size;
  system("chcp 1251");
  system("cls");
  printf ("Введите размерность матрицы\n");
  scanf ("%d", &size);
  double eps = 1e6;
  int num_iter = 0;
  double tau = 1e-02;
  Matrix XN = create_matrix(size, 1, 0);
  Matrix A = createEye(size);
  Matrix X = create_matrix(size, 1, 1);
  Matrix B = multiply_matrix(A, X);
  while (eps > 1e-03)
  {
      Matrix XN1 = subtract_matrix(XN, multiply_scalar(subtract_matrix(multiply_matrix(A, XN), B), tau));
      eps = find_max_item(abs_matrix(subtract_matrix(XN,XN1)));
      num_iter++;
      XN = XN1;
      printf ("%d %g\n", num_iter, eps);
  }
  print_matrix(XN);
}
  return 0;
}