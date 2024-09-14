#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;
  if (rows > 0 && columns > 0 && result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
      }
    } else
      error = INCORRECT_MATRIX;
  } else
    error = INCORRECT_MATRIX;
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    if (A->matrix) {
      for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i]) free(A->matrix[i]);
      }
      free(A->matrix);
      A->matrix = NULL;
    }
    A->rows = 0;
    A->columns = 0;
  }
}