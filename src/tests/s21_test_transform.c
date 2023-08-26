#include "s21_tests.h"

START_TEST(transpose_test_1) {
  matrix_t result = {}, mat_1 = {}, m_trans = {};
  s21_create_matrix(2, 3, &mat_1);
  s21_generate_matrix(&mat_1);
  s21_create_matrix(3, 2, &result);
  result.matrix[0][0] = 0;
  result.matrix[0][1] = 3;
  result.matrix[1][0] = 1;
  result.matrix[1][1] = 4;
  result.matrix[2][0] = 2;
  result.matrix[2][1] = 5;
  ck_assert_int_eq(s21_transpose(&mat_1, &m_trans), OK);
  ck_assert_int_eq(s21_eq_matrix(&m_trans, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&m_trans);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_test_1) {
  matrix_t mat_1 = {}, comps = {};
  s21_create_matrix(2, 3, &mat_1);
  s21_generate_matrix(&mat_1);
  ck_assert_int_eq(s21_calc_complements(&mat_1, &comps), CALCULATION_ERR);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&comps);
}

END_TEST

START_TEST(complements_test_2) {
  matrix_t result = {}, mat_1 = {}, comps = {};
  s21_create_matrix(3, 3, &mat_1);
  mat_1.matrix[0][0] = 3;
  mat_1.matrix[0][1] = 5;
  mat_1.matrix[0][2] = 6;
  mat_1.matrix[1][0] = 7;
  mat_1.matrix[1][1] = 8;
  mat_1.matrix[1][2] = 9;
  mat_1.matrix[2][0] = 3;
  mat_1.matrix[2][1] = 2;
  mat_1.matrix[2][2] = 1;
  s21_create_matrix(3, 3, &result);
  result.matrix[0][0] = -10;
  result.matrix[0][1] = 20;
  result.matrix[0][2] = -10;
  result.matrix[1][0] = 7;
  result.matrix[1][1] = -15;
  result.matrix[1][2] = 9;
  result.matrix[2][0] = -3;
  result.matrix[2][1] = 15;
  result.matrix[2][2] = -11;
  ck_assert_int_eq(s21_calc_complements(&mat_1, &comps), OK);
  ck_assert_int_eq(s21_eq_matrix(&comps, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&comps);
  s21_remove_matrix(&result);
}

END_TEST

START_TEST(determinant_test_1) {
  matrix_t mat_1 = {};
  s21_create_matrix(5, 2, &mat_1);
  s21_generate_matrix(&mat_1);
  double det;
  ck_assert_int_eq(s21_determinant(&mat_1, &det), CALCULATION_ERR);
  s21_remove_matrix(&mat_1);
}

END_TEST

START_TEST(determinant_test_2) {
  matrix_t mat_1 = {};
  s21_create_matrix(3, 3, &mat_1);
  mat_1.matrix[0][0] = 3;
  mat_1.matrix[0][1] = 5;
  mat_1.matrix[0][2] = 6;
  mat_1.matrix[1][0] = 7;
  mat_1.matrix[1][1] = 8;
  mat_1.matrix[1][2] = 9;
  mat_1.matrix[2][0] = 3;
  mat_1.matrix[2][1] = 2;
  mat_1.matrix[2][2] = 1;
  double det, result = 10;
  ck_assert_int_eq(s21_determinant(&mat_1, &det), OK);
  ck_assert_int_eq(fabs(det - result) < 1e-6, 1);
  s21_remove_matrix(&mat_1);
}

END_TEST

START_TEST(inverse_test_1) {
  matrix_t result = {}, mat_1 = {}, m_res = {};
  s21_create_matrix(3, 3, &mat_1);
  mat_1.matrix[0][0] = 4;
  mat_1.matrix[0][1] = 1;
  mat_1.matrix[0][2] = 2;
  mat_1.matrix[1][0] = 11;
  mat_1.matrix[1][1] = 5;
  mat_1.matrix[1][2] = 5;
  mat_1.matrix[2][0] = 3;
  mat_1.matrix[2][1] = 9;
  mat_1.matrix[2][2] = 2;
  s21_create_matrix(3, 3, &result);
  result.matrix[0][0] = -5 / 3.0;
  result.matrix[0][1] = 16 / 21.0;
  result.matrix[0][2] = -5 / 21.0;
  result.matrix[1][0] = -1 / 3.0;
  result.matrix[1][1] = 2 / 21.0;
  result.matrix[1][2] = 2 / 21.0;
  result.matrix[2][0] = 4;
  result.matrix[2][1] = -11 / 7.0;
  result.matrix[2][2] = 3 / 7.0;
  ck_assert_int_eq(s21_inverse_matrix(&mat_1, &m_res), OK);
  ck_assert_int_eq(s21_eq_matrix(&m_res, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&m_res);
  s21_remove_matrix(&result);
}

END_TEST

START_TEST(inverse_test_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_inverse_matrix(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 1.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = -5.0 / 23.0;
  X.matrix[1][1] = -121.0 / 23.0;
  X.matrix[1][2] = 2.0 / 23.0;
  X.matrix[1][3] = 1.0 / 23.0;
  X.matrix[2][0] = -18.0 / 23.0;
  X.matrix[2][1] = -379.0 / 46.0;
  X.matrix[2][2] = 19.0 / 46.0;
  X.matrix[2][3] = -25.0 / 46.0;
  X.matrix[3][0] = 53.0 / 69.0;
  X.matrix[3][1] = 1061.0 / 138.0;
  X.matrix[3][2] = -47.0 / 138.0;
  X.matrix[3][3] = 19.0 / 46.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}

END_TEST

void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}

START_TEST(inverse_test_3) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);

  res = s21_inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, CALCULATION_ERR);
  s21_remove_matrix(&A);
}

END_TEST

Suite *

transform_tests() {
  Suite *suite = suite_create("____TRANSFORM____");
  TCase *tcase = tcase_create("matrix_tc");

  tcase_add_test(tcase, transpose_test_1);
  tcase_add_test(tcase, complements_test_1);
  tcase_add_test(tcase, complements_test_2);
  tcase_add_test(tcase, determinant_test_1);
  tcase_add_test(tcase, determinant_test_2);
  tcase_add_test(tcase, inverse_test_1);
  tcase_add_test(tcase, inverse_test_2);
  tcase_add_test(tcase, inverse_test_3);

  suite_add_tcase(suite, tcase);
  return suite;
}
