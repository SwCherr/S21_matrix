#include "s21_matrix.h"

int s21_check_matrix(matrix_t* A) {
  return A != NULL && A->matrix != NULL && A->columns > 0 && A->rows > 0;
}
