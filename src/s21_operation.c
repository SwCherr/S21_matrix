#include "s21_matrix.h"

void s21_get_minor(matrix_t *A, matrix_t *minor, int cur_row, int cur_col) {
  int row_min = 0;
  int col_min = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (i != cur_row && j != cur_col) {
        minor->matrix[row_min][col_min++] = A->matrix[i][j];
        if (col_min == minor->rows) {
          col_min = 0;
          row_min++;
        }
      }
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (s21_check_matrix(A)) {
    if (A->rows == A->columns && A->rows > 0) {
      if (A->rows == 1)
        *result = A->matrix[0][0];
      else {
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        for (int i = 0, sign = 1; i < A->rows; i++, sign *= -1) {
          s21_get_minor(A, &minor, 0, i);
          double determin = 0;
          s21_determinant(&minor, &determin);
          *result += sign * A->matrix[0][i] * determin;
        }
        s21_remove_matrix(&minor);
      }
    } else
      error = CALCULATION_ERR;
  } else
    error = INCORRECT_MATRIX;
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (s21_check_matrix(A)) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      if (A->rows > 1) {
        matrix_t minor;
        error = s21_create_matrix(A->columns - 1, A->rows - 1, &minor);
        if (error == OK) {
          for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
              s21_get_minor(A, &minor, i, j);
              int sign = ((i + j) % 2 == 0) ? 1 : -1;
              double determin = 0;
              s21_determinant(&minor, &determin);
              result->matrix[i][j] = sign * determin;
            }
          }
        } else
          error = INCORRECT_MATRIX;
        s21_remove_matrix(&minor);
      } else
        result->matrix[0][0] = A->matrix[0][0];
    } else
      error = CALCULATION_ERR;
  } else
    error = INCORRECT_MATRIX;
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (!s21_check_matrix(A)) {
    error = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    error = CALCULATION_ERR;
  } else {
    double det = 0;
    s21_determinant(A, &det);
    if (fabs(det) < 1e-6) {
      error = CALCULATION_ERR;
    } else {
      matrix_t comps = {}, comps_transpose = {};

      s21_calc_complements(A, &comps);
      s21_transpose(&comps, &comps_transpose);
      s21_create_matrix(A->rows, A->rows, result);

      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->rows; j++)
          result->matrix[i][j] = comps_transpose.matrix[i][j] / det;

      s21_remove_matrix(&comps_transpose);
      s21_remove_matrix(&comps);
    }
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_res = OK;
  if (A && result && A->matrix) {
    return_res = s21_create_matrix(A->columns, A->rows, result);
    if (return_res == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    } else
      return_res = INCORRECT_MATRIX;
  } else
    return_res = INCORRECT_MATRIX;
  return return_res;
}