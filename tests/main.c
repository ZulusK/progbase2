#include <check.h>
#include <dlList.h>
#include <university.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(addListToLec_normal) {
	DLList * listA = DLList_create(STUDENT);
	Student * studentsA[3];
	int i;
	for (i = 0; i < 3; i++) {
		studentsA[i] = Student_create(NULL, i, 0);
		DLList_addFirst(listA, STUDENT, studentsA[i]);
	}
	DLList * listB = DLList_create(STUDENT);
	Student * studentsB[3];
	for (i = 0; i < 3; i++) {
		studentsB[i] = Student_create(NULL, i, 1);
		DLList_addFirst(listB, STUDENT, studentsB[i]);
	}
	Lecturer * lec = Lecturer_create("Test", listB);
	for (i = 0; i < 3; i++) {
		ck_assert_int_eq(Lecturer_containsStudent(lec, studentsB[i]), 1);
	}
	Lecturer_addStudentList(lec, listA);
	for (i = 0; i < 3; i++) {
		ck_assert_int_eq(Lecturer_containsStudent(lec, studentsA[i]), 1);
		ck_assert_int_eq(Lecturer_containsStudent(lec, studentsB[i]), 1);
	}
	Lecturer_free(&lec);
	DLList_free(&listA, Student_free);
	DLList_free(&listB, Student_free);
}
END_TEST

START_TEST(addListToLec_intersect) {
	DLList * listA = DLList_create(STUDENT);
	Student * studentsA[4];
	Lecturer * lec = Lecturer_create("test", NULL);
	int i;
	for ( i = 0; i < 4; i++) {
		studentsA[i] = Student_create(NULL, i, 0);
		DLList_addFirst(listA, STUDENT, studentsA[i]);
	}
	for (i = 0; i < 3; i++) {
		Lecturer_addStudent(lec, studentsA[i]);
	}
	Lecturer_addStudentList(lec, listA);
	ck_assert_int_eq(DLList_getLength(Lecturer_getStudentList(lec)), 4);
	Lecturer_free(&lec);
	DLList_free(&listA, Student_free);
}
END_TEST

START_TEST(addListToLec_empty) {
	DLList * listA = DLList_create(STUDENT);
	Lecturer * lec = Lecturer_create("test", NULL);
	Lecturer_addStudentList(lec, listA);
	ck_assert_int_eq(DLList_getLength(Lecturer_getStudentList(lec)), 0);
	Lecturer_free(&lec);
	DLList_free(&listA, Student_free);
}
END_TEST
START_TEST (getNotExistingStudents_listNotEmpty)
{
	DLList * listA = DLList_create(STUDENT);
	DLList * listB = NULL;
	Lecturer * lec = Lecturer_create(NULL, NULL);
	Student * students[6];
	int i;
	for ( i = 0; i < 6; i++) {
		students[i] = Student_create(NULL, i, i);
	}
	//add tudentsto list
	for ( i = 0; i < 6; i++) {
		DLList_addFirst(listA, STUDENT, students[i]);
	}
	for (int i = 3; i < 6; i++) {
		Lecturer_addStudent(lec, students[i]);
	}
	listB = university_getNotExistingStudents(lec, listA);
	ck_assert_int_eq(DLList_getLength(listB), 3);
	for (i = 0; i < DLList_getLength(listB); i++) {
		ck_assert_int_ne(DLList_contains(listB, STUDENT, students[i], Student_compare), 0);
	}
	Lecturer_free(&lec);
	for (i = 0; i < 6; i++) {
		Student_free(students[i]);
	}
	DLList_free(&listA, NULL);
	DLList_free(&listB, NULL);
}
END_TEST

START_TEST (getNotExistingStudents_listEmpty)
{
	DLList * listA = DLList_create(STUDENT);
	DLList * listB = NULL;
	Lecturer * lec = Lecturer_create(NULL, NULL);
	Student * students[3];
	int i;
	for (i = 0; i < 3; i++) {
		students[i] = Student_create(NULL, i, i);
	}
	for ( i = 0; i < 3; i++) {
		Lecturer_addStudent(lec, students[i]);
	}
	listB = university_getNotExistingStudents(lec, listA);
	ck_assert_int_eq(DLList_getLength(listB), 0);

	Lecturer_free(&lec);
	for (i = 0; i < 3; i++) {
		Student_free(students[i]);
	}
	DLList_free(&listA, NULL);
	DLList_free(&listB, NULL);
}
END_TEST

START_TEST (getNotExistingStudents_twoEqualsStudent)
{
	DLList * listA = DLList_create(STUDENT);
	DLList * listB = NULL;
	Lecturer * lec = Lecturer_create(NULL, NULL);
	Student * students[4];
	int i;
	for ( i = 0; i < 3; i++) {
		students[i] = Student_create(NULL, i, i);
	}
	students[3] = Student_create(NULL, 2, 2);

	for ( i = 0; i < 4; i++) {
		DLList_addFirst(listA, STUDENT, students[i]);
	}

	for ( i = 0; i < 3; i++) {
		Lecturer_addStudent(lec, students[i]);
	}
	listB = university_getNotExistingStudents(lec, listA);
	ck_assert_int_eq(DLList_getLength(listB), 0);

	Lecturer_free(&lec);
	for ( i = 0; i < 4; i++) {
		Student_free(students[i]);
	}
	DLList_free(&listA, NULL);
	DLList_free(&listB, NULL);
}
END_TEST


START_TEST (getStudFromCSV_emptyStr)
{
	char * str = "";
	DLList * list = university_getStudentFromCSV(str);
	ck_assert_int_eq(DLList_getLength(list), 0);
	DLList_free(&list, NULL);
}
END_TEST

START_TEST(getStudFromCSV_correctData) {
	DLList * listA = DLList_create(STUDENT);
	DLList_addFirst(listA, STUDENT, Student_create("Dima TUROK", 1.11, 1));
	DLList_addFirst(listA, STUDENT, Student_create(NULL, -12.34, 2));
	DLList_addFirst(listA, STUDENT, Student_create("Ruslan Pro12ge23r 55 Top", 99.99, 3));

	char * csv = university_studentListToCSV(listA);
	DLList * listB = university_getStudentFromCSV(csv);

	free(csv);
	csv=university_studentListToCSV(listB);
	free(csv);
	int i;
	for ( i = 0; i < DLList_getLength(listB); i++) {
		ck_assert_int_eq(DLList_contains(listA, STUDENT, DLList_get(listB, i), Student_compare), 1);
	}
	DLList_free(&listA,Student_free);
	DLList_free(&listB,Student_free);
	
}
END_TEST
START_TEST (getStudFromCSV_IncorrectData)
{
	char * str =
	    "\"DIMA\", 123+, -124.0\n\"KOLYAS,-12,56.2\n";
	DLList * list = university_getStudentFromCSV(str);
	ck_assert_int_eq(DLList_getLength(list), 2);
	ck_assert_str_eq(Student_getName(DLList_get(list, 1)), "KOLYAS,-12,56.2");
	DLList_free(&list, Student_free);
}
END_TEST


START_TEST (studentsToCSV_normal)
{
	Student *stud1 = Student_create("Roma", 1.1, 1);
	Student *stud2 = Student_create("Dima", 2.14, 2);
	Student *stud3 = Student_create("Danya", 3.11, 3);
	Student *stud4 = Student_create("Illya", 4.15, 4);
	DLList * listA = DLList_create(STUDENT);

	DLList_addLast(listA, STUDENT, stud1);
	DLList_addLast(listA, STUDENT, stud2);
	DLList_addLast(listA, STUDENT, stud3);
	DLList_addLast(listA, STUDENT, stud4);

	char * str = university_studentListToCSV(listA);
	char * resultStr = "\"Roma\",1.10,1\n\"Dima\",2.14,2\n\"Danya\",3.11,3\n\"Illya\",4.15,4\n";
	ck_assert_str_eq(str, resultStr);
	free(str);
	DLList_free(&listA, Student_free);
}
END_TEST
START_TEST (studentsToCSV_empty)
{
	DLList * listA = DLList_create(STUDENT);

	char * str = university_studentListToCSV(listA);
	char * resultStr = "";
	ck_assert_str_eq(str, resultStr);
	free(str);
	DLList_free(&listA, Student_free);
}
END_TEST

Suite *test_suite() {
	Suite *s = suite_create("UniversityTest");
	TCase *tc_testGetList;

	tc_testGetList = tcase_create("GetNotExistingStudents");
	tcase_add_test(tc_testGetList, getNotExistingStudents_listNotEmpty);
	tcase_add_test(tc_testGetList, getNotExistingStudents_listEmpty);
	tcase_add_test(tc_testGetList, getNotExistingStudents_twoEqualsStudent);
	suite_add_tcase(s, tc_testGetList);

	TCase *tc_addListToLec;

	tc_addListToLec = tcase_create("GetNotExistingStudents");
	tcase_add_test(tc_testGetList, addListToLec_normal);
	tcase_add_test(tc_testGetList, addListToLec_intersect);
	tcase_add_test(tc_testGetList, addListToLec_empty);
	suite_add_tcase(s, tc_addListToLec);

	TCase *tc_testGetStudentFromStr;

	tc_testGetStudentFromStr = tcase_create("GetNotExistingStudents");
	tcase_add_test(tc_testGetStudentFromStr, getStudFromCSV_emptyStr);
	tcase_add_test(tc_testGetStudentFromStr, getStudFromCSV_IncorrectData);
	tcase_add_test(tc_testGetStudentFromStr, getStudFromCSV_correctData);
	suite_add_tcase(s, tc_testGetStudentFromStr);

	TCase *tc_studToCSV;

	tc_studToCSV = tcase_create("StudentsToCSV");
	tcase_add_test(tc_studToCSV, studentsToCSV_empty);
	tcase_add_test(tc_studToCSV, studentsToCSV_normal);
	suite_add_tcase(s, tc_studToCSV);
	return s;
}

int main() {
	Suite *s = test_suite();
	SRunner *sr = srunner_create(s);
	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_VERBOSE);

	int num_tests_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return num_tests_failed;
}
