#include "unity_fixture.h"

static	void	runAllTests(void)
{
	RUN_TEST_GROUP(stack_create);
	RUN_TEST_GROUP(stack_destroy);
	RUN_TEST_GROUP(stack_push);
	RUN_TEST_GROUP(stack_pop);
	RUN_TEST_GROUP(stack_swap);
	RUN_TEST_GROUP(stack_rotate_up);
	RUN_TEST_GROUP(stack_rotate_down);
	RUN_TEST_GROUP(pswap_create);
}

int	main(int argc, const char **argv)
{
	return UnityMain(argc, argv, runAllTests);
}
