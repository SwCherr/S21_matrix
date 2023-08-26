#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_res = SUCCESS;
  if (A && B && A->matrix && B->matrix) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows && return_res; i++) {
        for (int j = 0; j < A->columns && return_res; j++) {
          return_res = fabs(A->matrix[i][j] - B->matrix[i][j]) < (1e-6);
        }
      }
    } else
      return_res = FAILURE;
  } else
    return_res = FAILURE;
  return return_res;
}
