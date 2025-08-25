#include <stdio.h>
#include <stdlib.h>

/** Global variable to store the number of executed asserts. */
extern unsigned long g_asserts;
/** Global variable to store the number of asserts that passed. */
extern unsigned long g_passed;
/** Global variable to store the number of asserts that failed. */
extern unsigned long g_failed;

/** Initializes global variables. */
#define TEST_INIT\
	unsigned long g_asserts;\
	unsigned long g_failed;\
	unsigned long g_passed;\

#ifdef TEST_EXIT_ON_FAILURE
/** \brief Tests a condition and updates global variables. 
 * Prints information about the failed condition and exits the program on failure. */
#define ASSERT(expr)\
	if (!(expr)) {\
		printf("\033[31m[ASSERT FAILED]:\033[0m %s\n\tFile: %s\n\tLine: %d\n", #expr, __FILE__, __LINE__);\
		exit(1);\
	} else {\
		g_passed++;\
	}\
	g_asserts++;
#else
/** \brief Tests a condition and updates global variables. 
 * Prints information about the failed condition on failure. */
#define ASSERT(expr)\
	if (!(expr)) {\
		printf("\033[31m[ASSERT FAILED]:\033[0m %s\n\tFile: %s\n\tLine: %d\n", #expr, __FILE__, __LINE__);\
		g_failed++;\
	} else {\
		g_passed++;\
	}\
	g_asserts++;
#endif

/** Prints the test results. */
static inline void test_print_results() {
	if (!g_failed) {
		printf("\n\033[32m[ALL %lu ASSERTS PASSED]\033[0m\n", g_asserts);
	} else {
		printf("\n\033[32m[%lu ASSERTS PASSED]\033[0m\n", g_passed);
		printf("\033[31m[%lu ASSERTS FAILED]\033[0m\n", g_failed);
	}
}
