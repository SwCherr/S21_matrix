#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_res = OK;
  if (A && B && result && A->matrix && B->matrix) {
    if (A->rows == B->rows && A->columns == B->columns) {
      return_res = s21_create_matrix(A->rows, A->columns, result);
      if (return_res == OK) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      }
    } else
      return_res = CALCULATION_ERR;
  } else
    return_res = INCORRECT_MATRIX;
  return return_res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_res = OK;
  if (A && B && result && A->matrix && B->matrix) {
    if (A->rows == B->rows && A->columns == B->columns) {
      return_res = s21_create_matrix(A->rows, A->columns, result);
      if (return_res == OK) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      } else
        return_res = CALCULATION_ERR;
    } else
      return_res = CALCULATION_ERR;
  } else
    return_res = INCORRECT_MATRIX;
  return return_res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_res = OK;
  if (A && result && A->matrix) {
    return_res = s21_create_matrix(A->rows, A->columns, result);
    if (return_res == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else
      return_res = INCORRECT_MATRIX;
  } else
    return_res = INCORRECT_MATRIX;
  return return_res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_res = OK;
  if (A && B && result && A->matrix && B->matrix) {
    if (A->columns == B->rows) {
      return_res = s21_create_matrix(A->rows, B->columns, result);
      if (return_res == OK) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            double sum_tmp = 0;
            for (int k = 0; k < A->columns; k++) {
              sum_tmp += A->matrix[i][k] * B->matrix[k][j];
            }
            result->matrix[i][j] = sum_tmp;
          }
        }

      } else
        return_res = INCORRECT_MATRIX;
    } else
      return_res = CALCULATION_ERR;
  } else
    return_res = INCORRECT_MATRIX;
  return return_res;
}
