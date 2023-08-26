#include "s21_tests.h"

START_TEST(equals_test_1) {
  matrix_t result = {}, mat_1 = {};
  s21_create_matrix(2, 3, &result);
  s21_create_matrix(2, 3, &mat_1);

  mat_1.matrix[0][0] = 9;
  mat_1.matrix[0][1] = 0;
  mat_1.matrix[0][2] = -123;
  mat_1.matrix[1][0] = 33;
  mat_1.matrix[1][1] = 44;
  mat_1.matrix[1][2] = -99;

  result.matrix[0][0] = 9;
  result.matrix[0][1] = 0;
  result.matrix[0][2] = -123;
  result.matrix[1][0] = 33;
  result.matrix[1][1] = 44;
  result.matrix[1][2] = -99;

  ck_assert_int_eq(s21_eq_matrix(&mat_1, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(equals_test_2) {
  matrix_t result = {}, mat_1 = {};
  s21_create_matrix(2, 3, &result);
  result.matrix[0][0] = 0;
  result.matrix[0][1] = 1;
  result.matrix[0][2] = 2;
  result.matrix[1][0] = 3;
  result.matrix[1][1] = 4;
  result.matrix[1][2] = 5;
  s21_create_matrix(2, 3, &mat_1);
  s21_generate_matrix(&mat_1);
  ck_assert_int_eq(s21_eq_matrix(&mat_1, &result), SUCCESS);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(equals_test_3) {
  matrix_t result = {}, mat_1 = {};
  s21_create_matrix(3, 2, &result);
  result.matrix[0][0] = 5;
  result.matrix[0][1] = 6;
  result.matrix[1][0] = 4;
  result.matrix[1][1] = 6;
  result.matrix[2][0] = 3;
  result.matrix[2][1] = 6;
  s21_create_matrix(3, 2, &mat_1);
  s21_generate_matrix(&mat_1);
  ck_assert_int_eq(s21_eq_matrix(&mat_1, &result), FAILURE);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(equals_test_4) {
  matrix_t result = {}, mat_1 = {};
  s21_create_matrix(2, 1, &result);
  s21_create_matrix(2, 2, &mat_1);
  s21_generate_matrix(&mat_1);
  ck_assert_int_eq(s21_eq_matrix(&mat_1, &result), FAILURE);
  s21_remove_matrix(&mat_1);
  s21_remove_matrix(&result);
}
END_TEST

Suite *equals_tests() {
  Suite *suite = suite_create("____EQUALS____");
  TCase *tcase = tcase_create("matrix_tc");

  tcase_add_test(tcase, equals_test_1);
  tcase_add_test(tcase, equals_test_2);
  tcase_add_test(tcase, equals_test_3);
  tcase_add_test(tcase, equals_test_4);

  suite_add_tcase(suite, tcase);
  return suite;
}