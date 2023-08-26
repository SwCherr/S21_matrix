#include "s21_tests.h"

START_TEST(sum_test_1) {
  matrix_t result = {};
  matrix_t mat_1 = {};
  matrix_t mat_2 = {};
  matrix_t m_res = {};
  s21_create_matrix(2, 2, &mat_1);
  s21_create_matrix(2, 2, &mat_2);
  s21_create_matrix(2, 2, &result);

  mat_1.matrix[0][0] = 2;
  mat_1.matrix[0][1] = 3;
  mat_1.matrix[1][0] = 4;
  mat_1.matrix[1][1] = 5;

  mat_2.matrix[0][0] = 2;
  mat_2.matrix[0][1] = 3;
  mat_2.matrix[1][0] = 4;
  mat_2.matrix[1][1] = 5;

  result.matrix[0][0] = 4;
  result.matrix[0][1] = 6;
  result.matrix[1][0] = 8;
  result.matrix[1][1] = 10;

  for (int i = 0; i < mat_1.rows; i++) {
    for (int j = 0; j < mat_2.columns; j++) {
      result.matrix[i][j] = mat_1.matrix[i][j] + mat_2.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_sum_matrix(&mat_1, &mat_2, &m_res), OK);
  ck_assert_int_eq(s21_eq_matrix(&m_res, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&m_res);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_test_2) {
  matrix_t mat_1 = {};
  matrix_t mat_2 = {};
  matrix_t m_res = {};
  s21_create_matrix(1, 3, &mat_1);
  s21_create_matrix(2, 3, &mat_2);
  s21_generate_matrix(&mat_1);
  s21_generate_matrix(&mat_2);
  ck_assert_int_eq(s21_sum_matrix(&mat_1, &mat_2, &m_res), CALCULATION_ERR);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
}
END_TEST

START_TEST(sub_test_1) {
  matrix_t result = {};
  matrix_t mat_1 = {};
  matrix_t mat_2 = {};
  matrix_t m_res = {};
  s21_create_matrix(3, 3, &mat_1);
  s21_create_matrix(3, 3, &mat_2);
  s21_generate_matrix(&mat_1);
  s21_generate_matrix(&mat_2);
  s21_create_matrix(3, 3, &result);

  for (int i = 0; i < mat_1.rows; i++) {
    for (int j = 0; j < mat_2.columns; j++) {
      result.matrix[i][j] = mat_1.matrix[i][j] - mat_2.matrix[i][j];
    }
  }

  ck_assert_int_eq(s21_sub_matrix(&mat_1, &mat_2, &m_res), OK);
  ck_assert_int_eq(s21_eq_matrix(&m_res, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&m_res);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_test_2) {
  matrix_t mat_1 = {};
  matrix_t mat_2 = {};
  matrix_t m_res = {};
  s21_create_matrix(4, 3, &mat_1);
  s21_create_matrix(2, 3, &mat_2);
  s21_generate_matrix(&mat_1);
  s21_generate_matrix(&mat_2);
  ck_assert_int_eq(s21_sub_matrix(&mat_1, &mat_2, &m_res), CALCULATION_ERR);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
}
END_TEST

START_TEST(mult_number_test_1) {
  matrix_t result = {};
  matrix_t mat_1 = {};
  matrix_t m_res = {};
  s21_create_matrix(3, 4, &mat_1);
  s21_create_matrix(3, 4, &result);

  mat_1.matrix[0][0] = 2;
  mat_1.matrix[0][1] = 3;
  mat_1.matrix[1][0] = 4;
  mat_1.matrix[1][1] = 5;

  result.matrix[0][0] = 25.284;
  result.matrix[0][1] = 37.926;
  result.matrix[1][0] = 50.568;
  result.matrix[1][1] = 63.210;

  double number = 12.642;
  for (int i = 0; i < mat_1.rows; i++) {
    for (int j = 0; j < mat_1.columns; j++) {
      result.matrix[i][j] = mat_1.matrix[i][j] * number;
    }
  }

  ck_assert_int_eq(s21_mult_number(&mat_1, number, &m_res), OK);
  ck_assert_int_eq(s21_eq_matrix(&m_res, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&m_res);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_test_1) {
  matrix_t result = {};
  matrix_t mat_1 = {};
  matrix_t mat_2 = {};
  matrix_t m_res = {};
  s21_create_matrix(3, 2, &mat_1);
  s21_create_matrix(2, 3, &mat_2);
  s21_create_matrix(3, 3, &result);

  //             1 4    1 -1  1    9 11 17
  // C = A × B = 2 5  × 2  3  4 = 12 13 22
  //             3 6              15 15 27

  mat_1.matrix[0][0] = 1;
  mat_1.matrix[0][1] = 4;
  mat_1.matrix[1][0] = 2;
  mat_1.matrix[1][1] = 5;
  mat_1.matrix[2][0] = 3;
  mat_1.matrix[2][1] = 6;

  mat_2.matrix[0][0] = 1;
  mat_2.matrix[0][1] = -1;
  mat_2.matrix[0][2] = 1;
  mat_2.matrix[1][0] = 2;
  mat_2.matrix[1][1] = 3;
  mat_2.matrix[1][2] = 4;

  result.matrix[0][0] = 9;
  result.matrix[0][1] = 11;
  result.matrix[0][2] = 17;
  result.matrix[1][0] = 12;
  result.matrix[1][1] = 13;
  result.matrix[1][2] = 22;
  result.matrix[2][0] = 15;
  result.matrix[2][1] = 15;
  result.matrix[2][2] = 27;

  ck_assert_int_eq(s21_mult_matrix(&mat_1, &mat_2, &m_res), OK);
  ck_assert_int_eq(s21_eq_matrix(&m_res, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&mat_2);
  s21_remove_matrix(&m_res);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_test_2) {
  matrix_t result = {};
  matrix_t mat_1 = {};
  matrix_t m_res = {};
  s21_create_matrix(3, 2, &mat_1);
  s21_create_matrix(3, 3, &result);

  ck_assert_int_eq(s21_mult_matrix(&mat_1, NULL, &m_res), INCORRECT_MATRIX);
  ck_assert_int_eq(s21_eq_matrix(&m_res, &result), FAILURE);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&m_res);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_test_3) {
  matrix_t mat_1 = {};
  matrix_t mat_2 = {};
  matrix_t m_res = {};
  s21_create_matrix(7, 2, &mat_1);
  s21_create_matrix(3, 3, &mat_2);

  ck_assert_int_eq(s21_mult_matrix(&mat_1, &mat_2, &m_res), CALCULATION_ERR);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&m_res);
}
END_TEST

Suite *arithmetic_tests() {
  Suite *suite = suite_create("____ARITHMETIC____");
  TCase *tcase = tcase_create("matrix_tc");

  tcase_add_test(tcase, sum_test_1);
  tcase_add_test(tcase, sum_test_2);
  tcase_add_test(tcase, sub_test_1);
  tcase_add_test(tcase, sub_test_2);
  tcase_add_test(tcase, mult_number_test_1);
  tcase_add_test(tcase, mult_test_1);
  tcase_add_test(tcase, mult_test_2);
  tcase_add_test(tcase, mult_test_3);

  suite_add_tcase(suite, tcase);
  return suite;
}
