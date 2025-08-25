#include <stdio.h>
#include <stdlib.h>

extern unsigned long g_asserts;
extern unsigned long g_passed;
extern unsigned long g_failed;

#define TEST_INIT\
	unsigned long g_asserts;\
	unsigned long g_failed;\
	unsigned long g_passed;\

#ifdef TEST_EXIT_ON_FAILURE
#define ASSERT(expr)\
	if (!(expr)) {\
		printf("\033[31m[ASSERT FAILED]:\033[0m %s\n\tLine: %d\n", #expr, __LINE__);\
		exit(1);\
	} else {\
		g_passed++;\
	}\
	g_asserts++;
#else
#define ASSERT(expr)\
	if (!(expr)) {\
		printf("\033[31m[ASSERT FAILED]:\033[0m %s\n\tLine: %d\n", #expr, __LINE__);\
		g_failed++;\
	} else {\
		g_passed++;\
	}\
	g_asserts++;
#endif

static inline void test_print_results() {
	if (!g_failed) {
		printf("\n\033[32m[ALL %lu ASSERTS PASSED]\033[0m\n", g_asserts);
	} else {
		printf("\n\033[32m[%lu ASSERTS PASSED]\033[0m\n", g_passed);
		printf("\033[31m[%lu ASSERTS FAILED]\033[0m\n", g_failed);
	}
}
